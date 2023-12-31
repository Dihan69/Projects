#include "menu_components/menu_components.c"
#include "chapters/chapters.c"
#include "games/games.c"

void main_menu(void);
void main_menu_navigation(Wordbox * wb, int * wb_hi_in, int * main_menu_running);

void chapters_menu(void);
void chapters_menu_navigation(Wordbox * wb, int * wb_hi_in, int * chapters_menu_running);

int chapter_selection(int chapter_index);

void reset_screen(void);

int main(void)
{
    main_menu();
    return 0;
}

void main_menu(void)
{
    SetConsoleTitle("IIRUS v1.0.0");
    window_fullscreen();

    load_user_info();

    startup_credits();
    if(User.times_played == 0) story_chapter_00(0);
    startup_animation();

    User.times_played++;

    Wordbox main_menu_wb[5];
    create_main_menu_wordboxes(main_menu_wb);

    set_menu_screen(main_menu_wb, 5);

    int wordbox_highlighter_index = 0;
    set_highlight(main_menu_wb, wordbox_highlighter_index);

    int main_menu_running = 1;

    while(main_menu_running)
    {
        show_main_screen();
        main_menu_navigation(main_menu_wb, &wordbox_highlighter_index, &main_menu_running);
    }

    save_user_info();
}

void main_menu_navigation(Wordbox * wb, int * wb_hi_in, int * main_menu_running)
{
    system("pause>nul");

    if((GetAsyncKeyState(VK_UP) & 0x8000) && (*wb_hi_in != 0))
    {
        remove_highlight(wb, *wb_hi_in);

        (*wb_hi_in)--;

        set_highlight(wb, *wb_hi_in);
    }
    else if((GetAsyncKeyState(VK_DOWN) & 0x8000) && (*wb_hi_in != 4))
    {
        remove_highlight(wb, *wb_hi_in);

        (*wb_hi_in)++;

        set_highlight(wb, *wb_hi_in);
    }
    else if(GetAsyncKeyState(VK_RETURN) & 0x8000)
    {
        transition();

        switch(*wb_hi_in)
        {
            case 0:
                if(User.current_level < 8)
                {
                    int feedback;

                    while(1)
                    {
                       feedback = chapter_selection(User.current_level);

                       if(feedback == 1)
                       {
                           User.current_level++;
                           save_user_info();
                       }
                       else break;
                    }
                }
                else chapters_completed_screen();
                break;

            case 1:
                chapters_menu();
                break;

            case 2:
                credits_screen();
                break;

            case 3:
                reset_screen();
                break;

            case 4:
                *main_menu_running = 0;
                system("cls");
                break;
        }

        create_main_menu_wordboxes(wb);
        set_menu_screen(wb, 5);
        set_highlight(wb, *wb_hi_in);
    }
}

void chapters_menu(void)
{
    Wordbox chapters_menu_wb[9];
    create_chapters_menu_wordboxes(chapters_menu_wb);

    set_menu_screen(chapters_menu_wb, User.current_level);

    //adding the "back" button
    for(int j = 0; chapters_menu_wb[8].word[j] != '\0'; j++)
    {
        main_screen[chapters_menu_wb[8].y + 2][chapters_menu_wb[8].x + 1 + j] = chapters_menu_wb[8].word[j];
    }

    int wordbox_highlighter_index = 0;
    set_highlight(chapters_menu_wb, wordbox_highlighter_index);

    int chapters_menu_running = 1;

    while(chapters_menu_running)
    {
        show_main_screen();
        chapters_menu_navigation(chapters_menu_wb, &wordbox_highlighter_index, &chapters_menu_running);
    }
}

void chapters_menu_navigation(Wordbox * wb, int * wb_hi_in, int * chapters_menu_running)
{
    system("pause>nul");

    if(GetAsyncKeyState(VK_UP) & 0x8000)
    {
        if(*wb_hi_in == 8)
        {
            remove_highlight(wb, *wb_hi_in);

            *wb_hi_in = User.current_level - 1;

            set_highlight(wb, *wb_hi_in);
        }
        else if(*wb_hi_in > 0)
        {
            remove_highlight(wb, *wb_hi_in);

            (*wb_hi_in)--;

            set_highlight(wb, *wb_hi_in);
        }
    }
    else if(GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        if(*wb_hi_in == (User.current_level - 1))
        {
            remove_highlight(wb, *wb_hi_in);

            *wb_hi_in = 8;

            set_highlight(wb, *wb_hi_in);
        }
        else if(*wb_hi_in < 8)
        {
            remove_highlight(wb, *wb_hi_in);

            (*wb_hi_in)++;

            set_highlight(wb, *wb_hi_in);
        }
    }
    else if(GetAsyncKeyState(VK_RETURN) & 0x8000)
    {
        transition();

        if(*wb_hi_in == 8)
        {
            *chapters_menu_running = 0;
            return;
        }
        else
        {
            chapter_selection(*wb_hi_in);
        }

        set_menu_screen(wb, User.current_level);

        //adding the "back" button
        for(int j = 0; wb[8].word[j] != '\0'; j++)
        {
            main_screen[wb[8].y + 2][wb[8].x + 1 + j] = wb[8].word[j];
        }

        set_highlight(wb, *wb_hi_in);
    }
}

int chapter_selection(int chapter_index)
{
    int feedback = 0;

    if(chapter_index == 0)
    {
        story_chapter_00(1);
    }
    else if(chapter_index == 1)
    {
        story_chapter_01_part_01();

        ping_pong_game_difficulty = game_difficulty_set_screen();
        instruction_index = 0;
        auto_instruction_view();

        game_start_screen();

        while(1)
        {
            feedback = play_ping_pong();

            if(feedback == 1)
            {
                story_chapter_01_part_02();
                return 1;
            }
            else if(feedback == -1 || game_restart_screen() == 1) return 0;
        }
    }
    else if(chapter_index == 2)
    {
        story_chapter_02_part_01();

        CnEp1_game_difficulty = game_difficulty_set_screen();

        instruction_index = 1;
        auto_instruction_view();

        game_start_screen();

        while(1)
        {
            feedback = play_collect_and_escape_part_01();

            if(feedback == 1)
            {
                story_chapter_02_part_02();
                break;
            }
            else if(feedback == -1 || game_restart_screen() == 1) return 0;
        }

        CnEp2_game_difficulty = game_difficulty_set_screen();

        instruction_index = 2;
        auto_instruction_view();

        game_start_screen();

        while(1)
        {
            feedback = play_collect_and_escape_part_02();

            if(feedback >= 0)
            {
                story_chapter_02_part_03();
                break;
            }
            else if(feedback == -1) return 0;
        }

        ss_game_difficulty = CnEp2_game_difficulty;

        instruction_index = 3;
        auto_instruction_view();

        game_start_screen();

        int bad = feedback;

        while(1)
        {
            feedback = play_collect_and_escape_part_03(bad);

            if(feedback == 1)
            {
                story_chapter_02_part_04();
                break;
            }
            else if(feedback == -1) return 0;
        }

        CnEp4_game_difficulty = game_difficulty_set_screen();

        instruction_index = 4;
        auto_instruction_view();

        game_start_screen();

        while(1)
        {
            feedback = play_collect_and_escape_part_04();

            if(feedback == 1)
            {
                story_chapter_02_part_05();
                return 1;
            }
            else if(feedback == -1 || game_restart_screen() == 1) return 0;
        }
    }
    else if(chapter_index == 3)
    {
        story_chapter_03_part_01();

        tower_defense_game_difficulty = game_difficulty_set_screen();

        instruction_index = 5;
        auto_instruction_view();

        game_start_screen();

        while(1)
        {
            feedback = play_tower_defense();

            if(feedback == 1)
            {
                story_chapter_03_part_02();
                return 1;
            }
            else if(feedback == -1 || game_restart_screen() == 1) return 0;
        }
    }
    else if(chapter_index == 4)
    {
        story_chapter_04_part_01();

        maze_game_difficulty = game_difficulty_set_screen();

        instruction_index = 6;
        auto_instruction_view();

        game_start_screen();

        while(1)
        {
            feedback = play_maze();

            if(feedback == 1)
            {
                story_chapter_04_part_02();
                return 1;
            }
            else if(feedback == -1 || game_restart_screen() == 1) return 0;
        }
    }
    else if(chapter_index == 5)
    {
        story_chapter_05_part_01();

        fps_game_difficulty = game_difficulty_set_screen();

        instruction_index = 8;
        auto_instruction_view();

        game_start_screen();

        while(1)
        {
            feedback = play_fps();

            if(feedback == 1)
            {
                story_chapter_05_part_02();
                return 1;
            }
            else if(feedback == -1 || game_restart_screen() == 1) return 0;
        }
    }
    else if(chapter_index == 6)
    {
        story_chapter_06_part_01();

        run_game_difficulty = game_difficulty_set_screen();

        instruction_index = 9;
        auto_instruction_view();

        game_start_screen();

        while(1)
        {
            feedback = play_run();

            if(feedback == 1)
            {
                story_chapter_06_part_02();
                return 1;
            }
            else if(feedback == -1 || game_restart_screen() == 1) return 0;
        }
    }
    else if(chapter_index == 7)
    {
        story_chapter_07_part_01();

        spacewar_game_difficulty = game_difficulty_set_screen();

        instruction_index = 10;
        auto_instruction_view();

        game_start_screen();

        while(1)
        {
            feedback = play_spacewar();

            if(feedback == 1)
            {
                story_chapter_07_part_02();
                return 1;
            }
            else if(feedback == -1 || game_restart_screen() == 1) return 0;
        }
    }
}

void reset_screen(void)
{
    initialize_main_screen();

    clear_main_screen(71, 22, 8, 5);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(50, 17, 48, 12);
    show_main_screen();
    delay(188888888);

    int selection = 0;

    char text1[3][40] = {"           !!!  WARNING  !!!          " , "- - Do you want to reset the game? - -", "[doing this will erase all saved data]"};
    char option_name[2][29] = {"        <]  NO   [>         ", "        <]  YES  [>         "};
    char text2[10] = "[ ENTER ]";

    for(int k = 0; k < 39; k++)
    {
        main_screen[20][57 + k] = text1[0][k];
        main_screen[22][57 + k] = text1[1][k];
        main_screen[24][57 + k] = text1[2][k];
    }

    for(int k = 0; k < 9; k++)
    {
        main_screen[29][72 + k] = text2[k];
    }

    while(1)
    {
        for(int k = 0; k < 28; k++)
        {
            main_screen[26][63 + k] = option_name[selection][k];
        }

        show_main_screen();

        if(GetAsyncKeyState(VK_RIGHT) & 0x8000) selection = 1;
        else if(GetAsyncKeyState(VK_LEFT) & 0x8000) selection = 0;
        else if(GetAsyncKeyState(VK_RETURN) & 0x8000) break;
    }

    if(selection == 1 && User.current_level == 8)
    {
        story_chapter_08_part_01();

        instruction_index = 11;
        auto_instruction_view();

        int feedback;

        while(1)
        {
            feedback = play_snake_spinoff();

            if(feedback == 1)
            {
                story_chapter_08_part_02();
                break;
            }
            else if(feedback == -1 || game_restart_screen() == 1)
            {
                selection = 0;
                break;
            }
        }
    }

    if(selection == 1)
    {
        User.current_level = 1;
        User.times_played = 0;

        save_user_info();

        clear_main_screen(50, 17, 52, 16);
        setMessageBox(65, 21, 16, 4);
        show_main_screen();
        delay(188888888);

        clear_main_screen(65, 21, 20, 8);
        setMessageBox(71, 22, 4, 1);
        show_main_screen();
        delay(188888888);

        clear_main_screen(71, 22, 8, 5);
        setMessageBox(71, 22, 4, 1);
        show_main_screen();
        delay(188888888);

        clear_main_screen(65, 21, 20, 8);
        setMessageBox(65, 21, 16, 4);
        show_main_screen();
        delay(188888888);

        clear_main_screen(50, 17, 52, 16);
        setMessageBox(50, 17, 48, 12);
        show_main_screen();
        delay(188888888);

        char text3[40] = "   - - The game has been reset - -    ";

        for(int k = 0; k < 39; k++)
        {
            main_screen[24][57 + k] = text3[k];
        }

        show_main_screen();
        delay(4111111111);
    }

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);
}
