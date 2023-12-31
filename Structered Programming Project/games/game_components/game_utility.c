#pragma once

#include "game_utility.h"
#include "main_screen_utility.c"
#include "instructions/instructions.c"

void game_start_screen(void)
{
    initialize_main_screen();

    int x = 59;
    int y = 21;
    int w = 30;
    int h = 5;

    main_screen[y][x] = 218;
    main_screen[y][x + w + 1] = 191;
    main_screen[y + h + 1][x] = 192;
    main_screen[y + h + 1][x + w + 1] = 217;

    for (int i = y + 1; i < y + h + 1; i++)
    {
        main_screen[i][x] = 179;
        main_screen[i][x + w + 1] = 179;
    }

    for (int j = x + 1; j < x + w + 1; j++)
    {
        main_screen[y][j] = 196;
        main_screen[y + h + 1][j] = 196;
    }

    char text[27] = "   Press ENTER to start   ";

    for(int k = 0; k < 26; k++)
    {
        main_screen[24][62 + k] = text[k];
    }

    show_main_screen();
    pressEnterToContinue();
}

int game_restart_screen(void)
{
    int x = 59;
    int y = 21;
    int w = 30;
    int h = 5;

    main_screen[y][x] = 218;
    main_screen[y][x + w + 1] = 191;
    main_screen[y + h + 1][x] = 192;
    main_screen[y + h + 1][x + w + 1] = 217;

    for (int i = y + 1; i < y + h + 1; i++)
    {
        main_screen[i][x] = 179;
        main_screen[i][x + w + 1] = 179;
    }

    for (int j = x + 1; j < x + w + 1; j++)
    {
        main_screen[y][j] = 196;
        main_screen[y + h + 1][j] = 196;
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 30 ; j++)
        {
            main_screen[22 + i][60 + j] = ' ';
        }
    }

    char text[2][27] =
    {
        " - ] ] ] GAME OVER [ [ [ -",
        "Press ENTER to restart  00"
    };

    for(int k = 0; k < 26; k++)
    {
        main_screen[23][62 + k] = text[0][k];
        main_screen[25][62 + k] = text[1][k];
    }

    int count = 9;

    while(count != -1)
    {
        main_screen[25][87] = 48 + count;

        show_main_screen();

        for(int i = 0; i < 222222222; i++)
        {
            if(GetAsyncKeyState(VK_RETURN) & 0x8000) return 0;
        }

        count--;
    }

    return 1;
}

int game_difficulty_set_screen(void)
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

    int diff_type = 0;

    char text1[3][28] = {"!!! WARNING: GAME AHEAD !!!" , " - select game difficulty -"};
    char diff_names[2][29] = {"        <]  EASY [>         ", "        <]  HARD [>         "};
    char text2[10] = "[ ENTER ]";

    for(int k = 0; k < 27; k++)
    {
        main_screen[21][63 + k] = text1[0][k];
        main_screen[24][63 + k] = text1[1][k];
    }

    for(int k = 0; k < 9; k++)
    {
        main_screen[29][72 + k] = text2[k];
    }

    while(1)
    {
        for(int k = 0; k < 28; k++)
        {
            main_screen[26][63 + k] = diff_names[diff_type][k];
        }

        show_main_screen();

        if(GetAsyncKeyState(VK_RIGHT) & 0x8000) diff_type = 1;
        else if(GetAsyncKeyState(VK_LEFT) & 0x8000) diff_type = 0;
        else if(GetAsyncKeyState(VK_RETURN) & 0x8000) break;
    }

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    return diff_type;
}

int ingame_menu_screen(void)
{
    char secondary_screen[MAIN_SCREEN_HEIGHT][MAIN_SCREEN_WIDTH + 1];

    //initializing secondary screen
    for(int i = 0; i < MAIN_SCREEN_HEIGHT; i++)
    {
        for(int j = 0; j < MAIN_SCREEN_WIDTH + 1; j++)
        {
            if(j == MAIN_SCREEN_WIDTH)
            {
                secondary_screen[i][j] = '\0';
            }
            else if(i == 0 || i == MAIN_SCREEN_HEIGHT - 1 || j == 0 || j == MAIN_SCREEN_WIDTH - 1)
            {
                secondary_screen[i][j] = MAIN_SCREEN_BORDER;
            }
            else
            {
                secondary_screen[i][j] = EMPTY_SPACE;
            }
        }
    }

    //creating options
    Wordbox ingame_menu_wb[3];

    ingame_menu_wb[0].word = "    RESUME    ";
    ingame_menu_wb[0].x = 67;
    ingame_menu_wb[0].y = 10;

    ingame_menu_wb[1].word = " INSTRUCTIONS ";
    ingame_menu_wb[1].x = 67;
    ingame_menu_wb[1].y = 16;

    ingame_menu_wb[2].word = "   MAIN MENU  ";
    ingame_menu_wb[2].x = 67;
    ingame_menu_wb[2].y = 22;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; ingame_menu_wb[i].word[j] != '\0'; j++)
        {
            secondary_screen[ingame_menu_wb[i].y + 2][ingame_menu_wb[i].x + 1 + j] = ingame_menu_wb[i].word[j];
        }
    }

    //initializing the highlighter
    int wb_hi_in = 0;

    //setting highlight
    secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x] = 201;
    secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x + 15] = 187;
    secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x] = 200;
    secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x + 15] = 188;

    for(int k = ingame_menu_wb[wb_hi_in].x + 1; k < ingame_menu_wb[wb_hi_in].x + 15; k++)
    {
        secondary_screen[ingame_menu_wb[wb_hi_in].y][k] = 205;
        secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][k] = 205;
    }

    while(1)
    {
        resetCursorPosition();

        for(int k = 0; k < MAIN_SCREEN_HEIGHT; k++)
        {
            printf("%s\n", secondary_screen[k]);
        }

        system("pause>nul");

        if((GetAsyncKeyState(VK_UP) & 0x8000) && wb_hi_in > 0)
        {
            //removing highlight
            secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x] = EMPTY_SPACE;
            secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x + 15] = EMPTY_SPACE;
            secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x] = EMPTY_SPACE;
            secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x + 15] = EMPTY_SPACE;

            for(int k = ingame_menu_wb[wb_hi_in].x + 1; k < ingame_menu_wb[wb_hi_in].x + 15; k++)
            {
                secondary_screen[ingame_menu_wb[wb_hi_in].y][k] = EMPTY_SPACE;
                secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][k] = EMPTY_SPACE;
            }

            //changing the highlighter index
            wb_hi_in--;

            //setting highlight
            secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x] = 201;
            secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x + 15] = 187;
            secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x] = 200;
            secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x + 15] = 188;

            for(int k = ingame_menu_wb[wb_hi_in].x + 1; k < ingame_menu_wb[wb_hi_in].x + 15; k++)
            {
                secondary_screen[ingame_menu_wb[wb_hi_in].y][k] = 205;
                secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][k] = 205;
            }
        }
        else if((GetAsyncKeyState(VK_DOWN) & 0x8000) && wb_hi_in < 2)
        {
            //removing highlight
            secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x] = EMPTY_SPACE;
            secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x + 15] = EMPTY_SPACE;
            secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x] = EMPTY_SPACE;
            secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x + 15] = EMPTY_SPACE;

            for(int k = ingame_menu_wb[wb_hi_in].x + 1; k < ingame_menu_wb[wb_hi_in].x + 15; k++)
            {
                secondary_screen[ingame_menu_wb[wb_hi_in].y][k] = EMPTY_SPACE;
                secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][k] = EMPTY_SPACE;
            }

            //changing the highlighter index
            wb_hi_in++;

            //setting highlight
            secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x] = 201;
            secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x + 15] = 187;
            secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x] = 200;
            secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x + 15] = 188;

            for(int k = ingame_menu_wb[wb_hi_in].x + 1; k < ingame_menu_wb[wb_hi_in].x + 15; k++)
            {
                secondary_screen[ingame_menu_wb[wb_hi_in].y][k] = 205;
                secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][k] = 205;
            }
        }
        else if(GetAsyncKeyState(VK_RETURN) & 0x8000)
        {
            switch(wb_hi_in)
            {
                case 0:
                    return 0;

                case 1:
                    for(int i = 0; i < MAIN_SCREEN_HEIGHT; i++)
                    {
                        for(int j = 0; j < MAIN_SCREEN_WIDTH; j++)
                        {
                            secondary_screen[i][j] = main_screen[i][j];
                        }
                    }

                    auto_instruction_view();

                    for(int i = 0; i < MAIN_SCREEN_HEIGHT; i++)
                    {
                        for(int j = 0; j < MAIN_SCREEN_WIDTH; j++)
                        {
                            main_screen[i][j] = secondary_screen[i][j];
                        }
                    }

                    //initializing secondary screen
                    for(int i = 0; i < MAIN_SCREEN_HEIGHT; i++)
                    {
                        for(int j = 0; j < MAIN_SCREEN_WIDTH + 1; j++)
                        {
                            if(j == MAIN_SCREEN_WIDTH)
                            {
                                secondary_screen[i][j] = '\0';
                            }
                            else if(i == 0 || i == MAIN_SCREEN_HEIGHT - 1 || j == 0 || j == MAIN_SCREEN_WIDTH - 1)
                            {
                                secondary_screen[i][j] = MAIN_SCREEN_BORDER;
                            }
                            else
                            {
                                secondary_screen[i][j] = EMPTY_SPACE;
                            }
                        }
                    }

                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; ingame_menu_wb[i].word[j] != '\0'; j++)
                        {
                            secondary_screen[ingame_menu_wb[i].y + 2][ingame_menu_wb[i].x + 1 + j] = ingame_menu_wb[i].word[j];
                        }
                    }

                    //setting highlight
                    secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x] = 201;
                    secondary_screen[ingame_menu_wb[wb_hi_in].y][ingame_menu_wb[wb_hi_in].x + 15] = 187;
                    secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x] = 200;
                    secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][ingame_menu_wb[wb_hi_in].x + 15] = 188;

                    for(int k = ingame_menu_wb[wb_hi_in].x + 1; k < ingame_menu_wb[wb_hi_in].x + 15; k++)
                    {
                        secondary_screen[ingame_menu_wb[wb_hi_in].y][k] = 205;
                        secondary_screen[ingame_menu_wb[wb_hi_in].y + 4][k] = 205;
                    }
                    break;

                case 2:
                    return 1;
            }
        }
    }
}
