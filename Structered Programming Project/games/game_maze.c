#pragma once

#include "game_components/game_utility.c"
#include "game_mixmatch.c"

typedef struct
{
    int x, y;
    int current_map;
    int lives;
    int navigation_delay;
    int detection_delay;
    int respawn_delay;
    int has_gatepass;
    int has_database_room_access[3];
    int location_left;
    int door_accessed;
    int busted;
} Maze_Player;

int play_maze(void);

void maze_markVisibleArea(int logic_map[][55], int p_x, int p_y);

void maze_accessed_door_message(void);
void maze_no_gatepass_message(void);
void maze_achieved_gatepass_message(void);
void maze_hacked_security_system_message(void);
int maze_hacking_security_system_game(void);
void maze_validating_database_room_access_message(int room_num);
void maze_validated_database_room_access_message(int room_num);
void maze_accessed_database_room_message(int room_num, int confirmation);
void maze_cracked_database_message(void);
void maze_cracking_database_animation(void);
void maze_location_remaining_message(void);

void maze_collision_message(int player_lives);

    int maze_game_difficulty = 0;

//game messages & animations---------------------
void maze_accessed_door_message(void)
{
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

    char text1[28] = "< ALREADY ACCESSED A DOOR >";

    for(int k = 0; k < 27; k++)
    {
        main_screen[24][63 + k] = text1[k];
    }

    show_main_screen();
    delay(888888888);

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

void maze_no_gatepass_message(void)
{
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

    char text1[28] = "      < NO GATEPASS >      ";

    for(int k = 0; k < 27; k++)
    {
        main_screen[24][63 + k] = text1[k];
    }

    show_main_screen();
    delay(888888888);

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

void maze_achieved_gatepass_message(void)
{
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

    char text1[28] = "   < GATEPASS ACHIEVED >   ";
    char text2[10] = "[ ENTER ]";

    for(int k = 0; k < 27; k++)
    {
        main_screen[23][63 + k] = text1[k];
    }

    for(int k = 0; k < 9; k++)
    {
        main_screen[27][72 + k] = text2[k];
    }

    show_main_screen();
    pressEnterToContinue();

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

void maze_hacked_security_system_message(void)
{
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

    char text1[28] = "< SECURITY SYSTEM HACKED > ";
    char text2[10] = "[ ENTER ]";

    for(int k = 0; k < 27; k++)
    {
        main_screen[23][63 + k] = text1[k];
    }

    for(int k = 0; k < 9; k++)
    {
        main_screen[27][72 + k] = text2[k];
    }

    show_main_screen();
    pressEnterToContinue();

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

int maze_hacking_security_system_game(void)
{
    initialize_main_screen();

    srand(time(0));

    transition();
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

    char text1[33] = "INITIATING SYSTEM PROTOCOL . . .";

    for(int k = 1; k < 33; k++)
    {
        for(int l = 0; l < k; l++)
        {
            main_screen[24][77 - (k / 2) + l] = text1[l];
        }

        show_main_screen();
        delay(55555555);
    }

    for(int k = 0; k < 3; k++)
    {
        main_screen[24][88] = '.';
        main_screen[24][90] = ' ';
        main_screen[24][92] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[24][88] = '.';
        main_screen[24][90] = '.';
        main_screen[24][92] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[24][88] = '.';
        main_screen[24][90] = '.';
        main_screen[24][92] = '.';
        show_main_screen();
        delay(188888888);
    }

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    mixmatch_game_difficulty = maze_game_difficulty;

    instruction_index = 7;
    auto_instruction_view();

    int stat = play_mixmatch();

    instruction_index = 6;

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

    char text2[2][28] = {"      < HACK FALIED >      ", "    < HACK SUCCESSFUL >    "};
    char text3[10] = "[ ENTER ]";

    for(int k = 0; k < 27; k++)
    {
        main_screen[23][63 + k] = text2[stat][k];
    }

    for(int k = 0; k < 9; k++)
    {
        main_screen[27][72 + k] = text3[k];
    }

    show_main_screen();
    pressEnterToContinue();

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    transition();
    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
    return stat;
}

void maze_validating_database_room_access_message(int room_num)
{
    initialize_main_screen();

    srand(time(0));

    transition();
    initialize_main_screen();

    clear_main_screen(51, 14, 8, 5);
    setMessageBox(51, 14, 4, 1);
    show_main_screen();
    delay(188888888);

    clear_main_screen(45, 13, 20, 8);
    setMessageBox(45, 13, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(30, 9, 52, 16);
    setMessageBox(30, 9, 48, 12);
    show_main_screen();
    delay(188888888);

    char text1[30] = "FETCHING ACCESS CONTROL . . .";
    char text2[30] = " < ACCESS CONTROL FETCHED >  ";

    for(int k = 1; k < 30; k++)
    {
        for(int l = 0; l < k; l++)
        {
            main_screen[16][57 - (k / 2) + l] = text1[l];
        }

        show_main_screen();
        delay(55555555);
    }

    for(int k = 0; k < 3; k++)
    {
        main_screen[16][67] = '.';
        main_screen[16][69] = ' ';
        main_screen[16][71] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[16][67] = '.';
        main_screen[16][69] = '.';
        main_screen[16][71] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[16][67] = '.';
        main_screen[16][69] = '.';
        main_screen[16][71] = '.';
        show_main_screen();
        delay(188888888);
    }

    for(int k = 0; k < 29; k++)
    {
        main_screen[16][43 + k] = text2[k];
    }

    show_main_screen();
    delay(55555555);

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

    char text3[28];

    sprintf(text3, " - - DATABASE SECTOR %d - - ", room_num);

    char text4[28] = "  VALIDATING ACCESS . . .  ";
    char text5[28] = "   < ACCESS VALIDATED >    ";
    char text6[10] = "[ ENTER ]";

    for(int k = 0; k < 27; k++)
    {
        main_screen[23][63 + k] = text3[k];
    }

    for(int k = 1; k < 28; k++)
    {
        for(int l = 0; l < k; l++)
        {
            main_screen[25][77 - (k / 2) + l] = text4[l];
        }

        show_main_screen();
        delay(55555555);
    }

    for(int k = 0; k < 3; k++)
    {
        main_screen[25][84] = '.';
        main_screen[25][86] = ' ';
        main_screen[25][88] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[25][84] = '.';
        main_screen[25][86] = '.';
        main_screen[25][88] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[25][84] = '.';
        main_screen[25][86] = '.';
        main_screen[25][88] = '.';
        show_main_screen();
        delay(188888888);
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[25][63 + k] = text5[k];
    }

    for(int k = 0; k < 9; k++)
    {
        main_screen[28][71 + k] = text6[k];
    }

    show_main_screen();
    pressEnterToContinue();

    transition();
    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

void maze_validated_database_room_access_message(int room_num)
{
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

    char text1[28];

    sprintf(text1, " - - DATABASE SECTOR %d - - ", room_num);

    char text2[28] = "   < ACCESS VALIDATED >    ";
    char text3[10] = "[ ENTER ]";

    for(int k = 0; k < 27; k++)
    {
        main_screen[23][63 + k] = text1[k];
        main_screen[25][63 + k] = text2[k];
    }

    for(int k = 0; k < 9; k++)
    {
        main_screen[28][71 + k] = text3[k];
    }

    show_main_screen();
    pressEnterToContinue();

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

void maze_accessed_database_room_message(int room_num, int confirmation)
{
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

    char text1[28];

    sprintf(text1, " - - DATABASE SECTOR %d - - ", room_num);

    char text2[2][28] = {"     > ACCESS DENIED <     ", "    > ACCESS GRANTED <     "};

    for(int k = 0; k < 27; k++)
    {
        main_screen[23][63 + k] = text1[k];
        main_screen[25][63 + k] = text2[confirmation][k];
    }

    show_main_screen();
    delay(888888888);

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

void maze_cracked_database_message(void)
{
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

    char text1[28] = "< FILE TRANSFER COMPLETED >";
    char text2[10] = "[ ENTER ]";

    for(int k = 0; k < 27; k++)
    {
        main_screen[23][63 + k] = text1[k];
    }

    for(int k = 0; k < 9; k++)
    {
        main_screen[27][72 + k] = text2[k];
    }

    show_main_screen();
    pressEnterToContinue();

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

void maze_cracking_database_animation(void)
{
    initialize_main_screen();

    srand(time(0));

    transition();
    initialize_main_screen();

    clear_main_screen(51, 22, 8, 5);
    setMessageBox(51, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    clear_main_screen(45, 21, 20, 8);
    setMessageBox(45, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(30, 17, 52, 16);
    setMessageBox(30, 17, 48, 12);
    show_main_screen();
    delay(188888888);

    char text1[26] = "SCANNING THE SYSTEM . . .";
    char text2[26] = "   < SCAN COMPLETED >    ";

    for(int k = 1; k < 26; k++)
    {
        for(int l = 0; l < k; l++)
        {
            main_screen[24][56 - (k / 2) + l] = text1[l];
        }

        show_main_screen();
        delay(55555555);
    }

    for(int k = 0; k < 3; k++)
    {
        main_screen[24][64] = '.';
        main_screen[24][66] = ' ';
        main_screen[24][68] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[24][64] = '.';
        main_screen[24][66] = '.';
        main_screen[24][68] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[24][64] = '.';
        main_screen[24][66] = '.';
        main_screen[24][68] = '.';
        show_main_screen();
        delay(188888888);
    }

    for(int k = 0; k < 25; k++)
    {
        main_screen[24][44 + k] = text2[k];
    }

    show_main_screen();
    delay(55555555);

    clear_main_screen(71, 12, 8, 5);
    setMessageBox(71, 12, 4, 1);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 11, 20, 8);
    setMessageBox(65, 11, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(50, 7, 52, 16);
    setMessageBox(50, 7, 48, 12);
    show_main_screen();
    delay(188888888);

    char text3[31] = "COLLECTING THE META DATA . . .";
    char text4[31] = "  < COLLECTION COMPLETED >    ";

    for(int k = 1; k < 31; k++)
    {
        for(int l = 0; l < k; l++)
        {
            main_screen[14][78 - (k / 2) + l] = text3[l];
        }

        show_main_screen();
        delay(55555555);
    }

    for(int k = 0; k < 3; k++)
    {
        main_screen[14][88] = '.';
        main_screen[14][90] = ' ';
        main_screen[14][92] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[14][88] = '.';
        main_screen[14][90] = '.';
        main_screen[14][92] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[14][88] = '.';
        main_screen[14][90] = '.';
        main_screen[14][92] = '.';
        show_main_screen();
        delay(188888888);
    }

    for(int k = 0; k < 30; k++)
    {
        main_screen[14][63 + k] = text4[k];
    }

    show_main_screen();
    delay(55555555);

    clear_main_screen(81, 30, 8, 5);
    setMessageBox(81, 30, 4, 1);
    show_main_screen();
    delay(188888888);

    clear_main_screen(75, 29, 20, 8);
    setMessageBox(75, 29, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(60, 25, 52, 16);
    setMessageBox(60, 25, 48, 12);
    show_main_screen();
    delay(188888888);

    char text5[28] = "TRANSFERING ALL FILES . . .";
    char text6[28] = "  < TRANSFER COMPLETED >   ";

    main_screen[34][72] = 201;
    main_screen[35][72] = 200;
    main_screen[34][100] = 187;
    main_screen[35][100] = 188;

    for(int k = 0; k < 27; k++)
    {
        main_screen[34][73 + k] = 196;
        main_screen[35][73 + k] = 196;
    }

    for(int k = 1; k < 28; k++)
    {
        for(int l = 0; l < k; l++)
        {
            main_screen[31][86 - (k / 2) + l] = text5[l];
        }

        show_main_screen();
        delay(55555555);
    }

    for(int k = 0; k < 8; k++)
    {
        main_screen[31][95] = '.';
        main_screen[31][97] = ' ';
        main_screen[31][99] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[31][95] = '.';
        main_screen[31][97] = '.';
        main_screen[31][99] = ' ';
        show_main_screen();
        delay(188888888);

        main_screen[31][95] = '.';
        main_screen[31][97] = '.';
        main_screen[31][99] = '.';
        show_main_screen();
        delay(188888888);

        int l;

        if(k == 0) l = 0;
        else if(k == 1) l = 7;
        else if(k == 2) l = 16;
        else if(k < 6) l = 21;
        else l = 27;

        for(int m = 0; m < l; m++)
        {
            main_screen[34][73 + m] = 220;
            main_screen[35][73 + m] = 223;
        }
    }

    clear_main_screen(60, 25, 52, 16);
    setMessageBox(60, 25, 48, 12);

    for(int k = 0; k < 27; k++)
    {
        main_screen[31][73 + k] = text6[k];
    }

    char text7[10] = "[ ENTER ]";

    for(int k = 0; k < 9; k++)
    {
        main_screen[35][81 + k] = text7[k];
    }

    show_main_screen();
    pressEnterToContinue();

    transition();
    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

void maze_location_remaining_message(void)
{
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

    char text1[28] = "   < LOCATION REMAINING >  ";

    for(int k = 0; k < 27; k++)
    {
        main_screen[24][63 + k] = text1[k];
    }

    show_main_screen();
    delay(888888888);

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

void maze_collision_message(int player_lives)
{
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

    char text1[28] = "    YOU GOT IDENTIFIED!    ", text2[28];

    for(int k = 0; k < 27; k++)
    {
        main_screen[23][63 + k] = text1[k];
    }

    sprintf(text2,   "- - LIVES REMAINING: %2d - -", player_lives + 1);

    for(int k = 0; k < 27; k++)
    {
        main_screen[25][63 + k] = text2[k];
    }

    show_main_screen();
    delay(888888888);

    sprintf(text2,   "- - LIVES REMAINING: %2d - -", player_lives);

    for(int k = 0; k < 27; k++)
    {
        main_screen[25][63 + k] = text2[k];
    }

    show_main_screen();
    delay(888888888);

    clear_main_screen(50, 17, 52, 16);
    setMessageBox(65, 21, 16, 4);
    show_main_screen();
    delay(188888888);

    clear_main_screen(65, 21, 20, 8);
    setMessageBox(71, 22, 4, 1);
    show_main_screen();
    delay(188888888);

    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);
}

void maze_markVisibleArea(int logic_map[][55], int p_x, int p_y)
{
    if(p_x < 0 || p_x > 54 || p_y < 0 || p_y > 54 || logic_map[p_y][p_x] != 0) return;

    logic_map[p_y][p_x] = 1;

    maze_markVisibleArea(logic_map, p_x + 1, p_y);
    maze_markVisibleArea(logic_map, p_x - 1, p_y);
    maze_markVisibleArea(logic_map, p_x, p_y + 1);
    maze_markVisibleArea(logic_map, p_x, p_y - 1);
}

int play_maze(void)
{
    initialize_main_screen();
    setGameViewport(17, 6, 110, 32);

    Maze_Player player = {1, 2, 0, (7 - (maze_game_difficulty * 2)), 0, 0, 0, 0, {0, 0, 0}, (2 + maze_game_difficulty), 0, 0};

    char map[4][55][56] =
    {
        {
            "#######################################################",
            "#              EL                        ER        #  #",
            "#                                                  ^  #",
            "#     ER                    EL                     #  #",
            "###############################################    #  #",
            "5#                         #                       #   ",
            "6^                      T3 # ED                 EU #   ",
            "7#                         #                       #   ",
            "#################<>####    #    #######################",
            "#    #                     #                  #       #",
            "# ED #    EU     ED     T2 #                  #       #",
            "#    ^                     #                  #       #",
            "#    #####################################    #    #  #",
            "#            #             #                  #    #  #",
            "#         ED ^ EL          # ED            EU #    #  #",
            "#            #             #                  #    #  #",
            "#            #     ER      #    ###############    #  #",
            "#            #             #                       #  #",
            "#     EU     #          EL #         ER         EU #  #",
            "#            #             #                       #  #",
            "#####################<>#############################  #",
            "# {==} |?!!?| {==} #       #    #|?$**$?|          #  #",
            "#      ddIObb      #       #    #%%-S1-%%          #  #",
            "# {==}        {==} #       ^    #                EL#  #",
            "t                  p       #    #        ED        #  #",
            "# {==}        {==} #C     c#    #                  #  #",
            "#                  #O     O#    #  ER              #  #",
            "# {==}        {==} #       #    #                  #  #",
            "t                  p       #    #               EU #  #",
            "# {==}        {==} #       # EU ^           EL     #  #",
            "#                  #C     c#    #                  #   ",
            "# {==}        {==} #O     O#####################<>#####",
            "t                  p       #    #            #C   c#   ",
            "#                  #       # ED # ED      ED #O   O#  #",
            "#                  #       #    ^            #     #  #",
            "###G1############### EU    #    #            #     #  #",
            "#    #    #    #T4         #    #            #     #  #",
            "# ED #    # ED #           #    #     EU     ^     #  #",
            "#    #    ^    #           #    #            #     #  #",
            "#    #    #    #           #    ####################  #",
            "#    #    #    #           #    #       #          #  #",
            "#    #    #    #           #    #       ^ ED       #  #",
            "#    #    #    #        ED #    #C     c#          #  #",
            "#    ^    #                #    #O     O#          #  #",
            "#    # EU # ER             #    #       #       EL #  #",
            "#    #    #                #    #       #          #   ",
            "########################<>##    #C     c##<>###########",
            "#              #           #    #O     O#              ",
            "#           EL # ER        #    ^       # ER           ",
            "#              ^           #    #       #              ",
            "# ER           ########################################",
            "#              #                        #              ",
            "#           EL #           EL           #          EL  ",
            "#              ^                        #              ",
            "#####################################  ##    ##########"
        },
        {
            "#######################################################",
            "#  #            #   TD   #    #    #    #    #        #",
            "#  ^ ED      ED #        # ED #    # ED #    ^ ER     #",
            "#  #            # ED     ^    #    #    #    #        #",
            "#  #            #        #    #    #    #    #     EL #",
            "   #            #        #    #    #    #    #        #",
            "   #     EU     ^        #    #    ^    ^    # ER     #",
            "   #            #        #    #    #    #    #        #",
            "#################        #    ######    ######     EL #",
            "#                     EU #    # ER           #        #",
            "# ER                     #    ^              # ER     #",
            "#                        #    #           EL #        #",
            "#  ##############        ###########    #########<>####",
            "#  #            #        #    #    #    #    #        #",
            "#  #            #        #  K #    ^    ^    # ED     #",
            "#  #            #        #    #    #    #    #        #",
            "#  # EU  ED  EU #        #    #    #    #    #        #",
            "#  #            #        #    #    # EU #    #        #",
            "#  #            # EU     #    #    #    #    #   ER   #",
            "#  #            #             #    #    #    #        #",
            "#  ##<>######<>#################<>############        #",
            "#  # ED  #  ER                            EL #        #",
            "#  #     #                                   #     EU #",
            "#  #     #           EL          ER          #        #",
            "#  #     ##########################################<>##",
            "#  #     #             #       |?  ?|       #    #    #",
            "#  #     #ED           #  ED  |?!++!?|      #    #    #",
            "#  #     #             #      %%-MO-%%      #    ###  #",
            "#  #     #    ######<>##                    #    #    #",
            "#  # EU  #    #        #TR    EU            #    #    #",
            "   #     #    #     ED #                    #    #ED###",
            "#######  #    #        #ER                  # EU #    #",
            "      #  #    # ER     #                    ^    #    #",
            "##<>###  #    #        #                  EL#    #    #",
            "#        #    #        #                    #  ###    #",
            "#        #    #        #                    #    #  EU#",
            "#        #    #     EL #            ED      #    #    #",
            "# ED     #    #        #                    ###  #    #",
            "#        #    # EU     #                EU  #    #    #",
            "#        #    #        #              TU    #    #    #",
            "#    EU  #    ##<>###########################  ###    #",
            "#        #    #                #    #TR          #    #",
            "##########    # ER             #    #            #  ED#",
            "# ER          #                #    # ER         #    #",
            "#             #             EL #    #            #    #",
            "           EL #                ^    #     EU     #    #",
            "################################    #            #    #",
            " ER                              EL #     EL     #    #",
            "                                    ^            #    #",
            "            EL        ER            #            #    #",
            "####    ########    ########    ##################    #",
            "            EL        ER                    #     EU  #",
            "                                            #         #",
            " ER                              EL         #         #",
            "#############################################    ######"
        },
        {
            "#####################################<>##    ##########",
            "#  #  #  #  #  #                        #             #",
            "#  ^  #  ^  #  #     {==}      {==}     #             #",
            "#  #  #  #  #  t                        p             #",
            "#  #     #  #  #   {==}          {==}   ###############",
            "#  #######  #  t                        p|?$**$?|     #",
            "#           #  #         |?!!?|         #%%-S0-%%     #",
            "#  #######  #  # {==}    ddIObb    {==} #        TH   #",
            "#  #  #  #  #  #                        #             #",
            "#  ^  #  ^  #  t                        p             #",
            "####     ####  #   {==}          {==}   #             #",
            "#     #     #  t                        p   TV        #",
            "#  #  #  #  #  #     {==}      {==}     #             #",
            "#  #######  #  #                        ##<>#######<>##",
            "#           #  #                        #        #    #",
            "#  #######  #  ############G0############  ####  #    #",
            "#              #TV#  #  #         #           #  t    p",
            "##<>########<>##  #  #  #         ##########  #  #    #",
            "#    #    #    #  #  #  #TH       #           #  #    #",
            "#    #    #    #  #  #  ########  ######<>#####  t    p",
            "#    #    ^    #  #  ^         #  #        #  ^  #    #",
            "#    #    #    #  #  #  #####  ^  ##<>######  #  #    #",
            "#  ####<>###<>##  #  #  #      #  #        t  p  t    p",
            "#  #      #    #  #  #  #  #   #  ######<>##  #  #    #",
            "#  ^      #    ^     #  #  #####  #        t  p  #    #",
            "#  #      #    #     #TV       #  #   ######  #  #    #",
            "#  ###########################x##x#####  #    #  #    #",
            "#  #      #TD#                        #  ^    #  #     ",
            "#  #  #####<>#####      ############  #  #    #  #    #",
            "#  #  #          #      #          #  #  ##<>##########",
            "#  #  ^          #      #          ^  #  #     #      #",
            "#  #  #       TV #      #  TV      #  t  p  #  #  #####",
            "#  t  p          #      #          ####  #  #  #      #",
            "#  #  #          #      #          ^TL#  #  #  #####  #",
            "#  t  p          #      #          ####  #            #",
            "#  #  #  TH      #      #      TH  #  t  p  #  ########",
            "#  t  p          #      #          ^  #  #  #         #",
            "#  #  #          #      #          #  #  #  ###########",
            "#  #  ##<>########      ############  #  #            #",
            "#  #  #              #TH              t  p  ####  ##  #",
            "#  #  #             ##                #  #     #  #   #",
            "t  p  #           TV#                 #  ####  #  #   #",
            "#  #  ############      ###############  #  #  #  #####",
            "#  #  #          #      #          #  #  #     #      #",
            "#  #  ^          #      #          ^  #  ##############",
            "t  p  #  TH      #      #      TH  #  #  #            #",
            "#  ####          #      #          t  p  #    ######  #",
            "#  #TR^          #      #          #  #  #    #       #",
            "#  ####          #      #          t  p  #    #  ######",
            "t  p  #      TV  #      #  TV      #  #  #    #       #",
            "#  #  #          #      ^          t  p  ##<>##########",
            "#  #  #          #      #          #  #  #             ",
            "#  ^  ##x##x##<>##      #####<>#####  ^  #             ",
            "#  #             #          #TU#      #  #             ",
            "#######################################################"
        },
        {
            "#############################################    ######",
            "#    #        #          #  #          #    #         #",
            "#ED  ^  ED T3 #          #  #          # ED #C       c#",
            "#    #        # EU       #  ^       ED #    #O       O#",
            "#    #        #          #  #          #    #####<>####",
            "#    #      EL#    EU    #  #    ED    #    #         #",
            "#    #        #          ^  #          #    #      ED #",
            "#    #        #       EU #  # ED       ^    #         #",
            "#    #ER      #          #  #          #    # ER      #",
            "#    #        ##<>######################    #         #",
            "#    #             #    #    #    #    #    #         #",
            "#    #          EL #    # ED #    # ED #    #         #",
            "#    #             #    ^    #    ^    #    #         #",
            "#    ###############    #    #    #    #    #      EL #",
            "#    #             #    #    ^    #    ^    #         #",
            "#    #TR    EL     ^ EU #    # EU #    #    # EU      #",
            "#    #             #    #    #    #    #    #         #",
            "#    #   ED        ################################<>##",
            "#    #             #                    #             #",
            "#    #TR       EU  # ER              EL # ED    ED    #",
            "#    #             ^                    ^             #",
            "#    ####################################             #",
            "#                                       #             #",
            "#  EU ER             ER              EL #    EU    EU #",
            "#                                       #             #",
            "#######x######x######x######x########<>################",
            "#{==}     {==}        {==}     {==}#    # |?$**$?| #  #",
            "#              |?!!?|              #    # %%-S2-%% #ED#",
            "#  {==} {==}   ddIObb   {==} {==}  ###  #        EL#  #",
            "#                                  #    #          #  #",
            "#{==}     {==}        {==}     {==}#ED  #ER        #  #",
            "#                                  #  ###          ^  #",
            "#                                  #    #        EL#  #",
            "#                                  #    #          #  #",
            "#################################G2#  EU#ER        #  #",
            "#    #              #T4            #    #          #  #",
            "#    #           ED #              #    #####<>#####  #",
            "#    ^              #              #  ED#C        c#  #",
            "#    ###########    #    ###########    #O        O#  #",
            "#    #    #C       c#    #      ED #    #          #  #",
            "#    # ED #O       O#    #         #    #        EL#  #",
            "#    #    ^         #    #         #    #          #  #",
            "#    #    ###########  ED#    #    #    #####<>#####  #",
            "#    #                   #    #    #    #C        c#  #",
            "#    #                EL #    #    ^    #O        O#  #",
            "#    #                   # EU #    #EU  #          #  #",
            "#    ######################<>############ER        #  #",
            "# EU #ER                              EL#          #  #",
            "#    #                                  #        EL#  #",
            "#    ^          EL          ER          ^          #  #",
            "####################################################  #",
            " ER                       ER                      EL  #",
            "             ER                        EL             #",
            "  ER                      EL                       EL #",
            "#######################################################"
        }
    };

    if(maze_game_difficulty == 1) map[3][27][0] = '^';

    char gameview_bp[55][55];

    int logic_map[55][55];

    int enemy_movement_delay = 0;

    int trap_trigger = 0;
    int trap_set_delay = 0;

    while(1)
    {
        //preparing the gameview blueprint
        for(int i = 0; i < 55; i ++)
        {
            for(int j = 0; j < 55; j++)
            {
                gameview_bp[i][j] = ' ';
            }
        }

        for(int i = 0; i < 55; i ++)
        {
            for(int j = 0; j < 55; j++)
            {
                if(map[player.current_map][i][j] == 'E')
                {
                    gameview_bp[i][j] = '(';
                    gameview_bp[i][j + 1] = ')';

                    if(map[player.current_map][i][j + 1] == 'U')
                    {
                        for(int k = 1; k < 3; k++)
                        {
                            if(map[player.current_map][i - k][j] == ' ')
                            {
                                gameview_bp[i - k][j] = '.';
                            }
                            else break;
                        }

                        for(int k = 1; k < 3; k++)
                        {
                            if(map[player.current_map][i - k][j + 1] == ' ')
                            {
                                gameview_bp[i - k][j + 1] = ',';
                            }
                            else break;
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == 'D')
                    {
                        for(int k = 1; k < 3; k++)
                        {
                            if(map[player.current_map][i + k][j] == ' ')
                            {
                                gameview_bp[i + k][j] = '.';
                            }
                            else break;
                        }

                        for(int k = 1; k < 3; k++)
                        {
                            if(map[player.current_map][i + k][j + 1] == ' ')
                            {
                                gameview_bp[i + k][j + 1] = ',';
                            }
                            else break;
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == 'R')
                    {
                        for(int k = 1; k < 5; k++)
                        {
                            if(map[player.current_map][i][j + k + 1] == ' ')
                            {
                                gameview_bp[i][j + k + 1] = ';';
                            }
                            else break;
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == 'L')
                    {
                        for(int k = 1; k < 5; k++)
                        {
                            if(map[player.current_map][i][j - k] == ' ')
                            {
                                gameview_bp[i][j - k] = ';';
                            }
                            else break;
                        }
                    }

                    j++;
                }
                else if(map[player.current_map][i][j] == 'T')
                {
                    gameview_bp[i][j] = '/';
                    gameview_bp[i][j + 1] = '\\';

                    if(map[player.current_map][i][j + 1] == 'U')
                    {
                        for(int k = 1; map[player.current_map][i - k][j] == ' '; k++)
                        {
                            gameview_bp[i - k][j] = '\'';
                        }

                        for(int k = 1; map[player.current_map][i - k][j + 1] == ' '; k++)
                        {
                            gameview_bp[i - k][j + 1] = '"';
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == 'D')
                    {
                        for(int k = 1; map[player.current_map][i + k][j] == ' '; k++)
                        {
                            gameview_bp[i + k][j] = '\'';
                        }

                        for(int k = 1; map[player.current_map][i + k][j + 1] == ' '; k++)
                        {
                            gameview_bp[i + k][j + 1] = '"';
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == 'L')
                    {
                        for(int k = 1; map[player.current_map][i][j - k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j - k] = ':';
                            else gameview_bp[i][j - k] = ';';
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == 'R')
                    {
                        for(int k = 1; map[player.current_map][i][j + 1 + k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j + 1 + k] = ';';
                            else gameview_bp[i][j + 1 + k] = ':';
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == '1')
                    {
                        for(int k = 1; map[player.current_map][i - k][j] == ' '; k++)
                        {
                            gameview_bp[i - k][j] = '\'';
                        }

                        for(int k = 1; map[player.current_map][i - k][j + 1] == ' '; k++)
                        {
                            gameview_bp[i - k][j + 1] = '"';
                        }

                        for(int k = 1; map[player.current_map][i][j + 1 + k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j + 1 + k] = ';';
                            else gameview_bp[i][j + 1 + k] = ':';
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == '2')
                    {
                        for(int k = 1; map[player.current_map][i - k][j] == ' '; k++)
                        {
                            gameview_bp[i - k][j] = '\'';
                        }

                        for(int k = 1; map[player.current_map][i - k][j + 1] == ' '; k++)
                        {
                            gameview_bp[i - k][j + 1] = '"';
                        }

                        for(int k = 1; map[player.current_map][i][j - k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j - k] = ':';
                            else gameview_bp[i][j - k] = ';';
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == '3')
                    {
                        for(int k = 1; map[player.current_map][i + k][j] == ' '; k++)
                        {
                            gameview_bp[i + k][j] = '\'';
                        }

                        for(int k = 1; map[player.current_map][i + k][j + 1] == ' '; k++)
                        {
                            gameview_bp[i + k][j + 1] = '"';
                        }

                        for(int k = 1; map[player.current_map][i][j - k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j - k] = ':';
                            else gameview_bp[i][j - k] = ';';
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == '4')
                    {
                        for(int k = 1; map[player.current_map][i + k][j] == ' '; k++)
                        {
                            gameview_bp[i + k][j] = '\'';
                        }

                        for(int k = 1; map[player.current_map][i + k][j + 1] == ' '; k++)
                        {
                            gameview_bp[i + k][j + 1] = '"';
                        }

                        for(int k = 1; map[player.current_map][i][j + 1 + k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j + 1 + k] = ';';
                            else gameview_bp[i][j + 1 + k] = ':';
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == 'V' && trap_trigger < 2)
                    {
                        for(int k = 1; map[player.current_map][i - k][j] == ' '; k++)
                        {
                            gameview_bp[i - k][j] = '\'';
                        }

                        for(int k = 1; map[player.current_map][i - k][j + 1] == ' '; k++)
                        {
                            gameview_bp[i - k][j + 1] = '"';
                        }

                        for(int k = 1; map[player.current_map][i + k][j] == ' '; k++)
                        {
                            gameview_bp[i + k][j] = '\'';
                        }

                        for(int k = 1; map[player.current_map][i + k][j + 1] == ' '; k++)
                        {
                            gameview_bp[i + k][j + 1] = '"';
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == 'H' && trap_trigger < 2)
                    {
                        for(int k = 1; map[player.current_map][i][j - k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j - k] = ':';
                            else gameview_bp[i][j - k] = ';';
                        }

                        for(int k = 1; map[player.current_map][i][j + 1 + k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j + 1 + k] = ';';
                            else gameview_bp[i][j + 1 + k] = ':';
                        }
                    }
                    else if(map[player.current_map][i][j + 1] == 'O' && trap_trigger == 2)
                    {
                        for(int k = 1; map[player.current_map][i - k][j] == ' '; k++)
                        {
                            gameview_bp[i - k][j] = '\'';
                        }

                        for(int k = 1; map[player.current_map][i - k][j + 1] == ' '; k++)
                        {
                            gameview_bp[i - k][j + 1] = '"';
                        }

                        for(int k = 1; map[player.current_map][i + k][j] == ' '; k++)
                        {
                            gameview_bp[i + k][j] = '\'';
                        }

                        for(int k = 1; map[player.current_map][i + k][j + 1] == ' '; k++)
                        {
                            gameview_bp[i + k][j + 1] = '"';
                        }

                        for(int k = 1; map[player.current_map][i][j - k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j - k] = ':';
                            else gameview_bp[i][j - k] = ';';
                        }

                        for(int k = 1; map[player.current_map][i][j + 1 + k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j + 1 + k] = ';';
                            else gameview_bp[i][j + 1 + k] = ':';
                        }
                    }

                    j++;
                }
                else if(map[player.current_map][i][j] != ' ')
                {
                    gameview_bp[i][j] = map[player.current_map][i][j];

                    if(map[player.current_map][i][j] == 't' && trap_trigger > 1)
                    {
                        for(int k = 1; map[player.current_map][i][j + k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i][j + k] = ';';
                            else gameview_bp[i][j + k] = ':';
                        }
                    }
                    else if(map[player.current_map][i][j] == 'x' && trap_trigger > 1)
                    {
                        for(int k = 1; map[player.current_map][i + k][j] == ' '; k++)
                        {
                            gameview_bp[i + k][j] = '_';
                        }
                    }
                    else if(map[player.current_map][i][j] == 'C' && map[player.current_map][i + 1][j] == 'O')
                    {
                        for(int k = 1; map[player.current_map][i + 1][j + k] == ' '; k++)
                        {
                            if(k % 2 == 0) gameview_bp[i + 1][j + k] = ';';
                            else gameview_bp[i + 1][j + k] = ':';
                        }
                    }
                }
            }
        }

        //preparing the logic map
        for(int i = 0; i < 55; i ++)
        {
            for(int j = 0; j < 55; j++)
            {
                if(map[player.current_map][i][j] == '#'
                   || map[player.current_map][i][j] == '<'
                   || map[player.current_map][i][j] == '>'
                   || map[player.current_map][i][j] == '^'
                   || map[player.current_map][i][j] == 't'
                   || map[player.current_map][i][j] == 'p'
                   || map[player.current_map][i][j] == 'x'
                   || map[player.current_map][i][j] == 'G')
                {
                    logic_map[i][j] = -1;

                    if(map[player.current_map][i][j] == 'G')
                    {
                        logic_map[i][j + 1] = -1;
                        j++;
                    }
                }
                else logic_map[i][j] = 0;
            }
        }

        //collision detection
        if(player.respawn_delay == 0 && (gameview_bp[player.y][player.x] != ' ' || gameview_bp[player.y][player.x + 1] != ' ')) player.detection_delay++;
        else player.detection_delay = 0;

        if(player.detection_delay == 25) player.busted = 1;

        //after-respawn delay
        if(player.respawn_delay != 0) player.respawn_delay--;

        //setting the player position
        gameview_bp[player.y][player.x] = '[';
        gameview_bp[player.y][player.x + 1] = ']';

        //marking the visible area through logic map
        maze_markVisibleArea(logic_map, player.x, player.y);

        //clearing previous game view
        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 110; j++)
            {
                main_screen[10 + i][20 + j] = ' ';
            }
        }

        //setting next gameview
        int mapFocusY;

        if(player.y - 7 <= 0) mapFocusY = 0;
        else if(player.y + 7 >= 54) mapFocusY = 40;
        else mapFocusY = player.y - 7;

        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 55; j++)
            {
                if(player.current_map != 2 || (player.x - 4 <= j && j <= player.x + 5 && player.y - 2 <= mapFocusY + i && mapFocusY + i <= player.y + 2)
                                           || (player.x - 6 <= j && j <= player.x + 7 && player.y - 1 <= mapFocusY + i && mapFocusY + i <= player.y + 1)
                                           || (player.x - 2 <= j && j <= player.x + 3 && player.y - 3 <= mapFocusY + i && mapFocusY + i <= player.y + 3))
                {
                    if(logic_map[mapFocusY + i][j] != 0)
                    {
                        if(gameview_bp[mapFocusY + i][j] == '#')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 219;

                            if(mapFocusY + i + 1 < 55 &&
                              ( gameview_bp[mapFocusY + i + 1][j] == '#'
                                || gameview_bp[mapFocusY + i + 1][j] == '^'
                                || gameview_bp[mapFocusY + i + 1][j] == 'v'
                                || gameview_bp[mapFocusY + i + 1][j] == 't'
                                || gameview_bp[mapFocusY + i + 1][j] == 'p'
                                || logic_map[mapFocusY + i + 1][j] == 0 ) )
                            {
                                main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 219;
                                main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 219;
                            }
                            else
                            {
                                main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 177;
                                main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 177;
                            }
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '<')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 205;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 187;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 197;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 182;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '>')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 201;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 205;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 199;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 197;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '^' || gameview_bp[mapFocusY + i][j] == 'v')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 198;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 181;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 200;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 188;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'G')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 205;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 203;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 191;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 215;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 205;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 187;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 218;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 186;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '[')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = ']';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 220;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 222;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 187;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == ']')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 220;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = '[';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 201;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 221;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '(')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 218;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 220;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 222;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 200;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == ')')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 220;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 191;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 187;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 221;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '/')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = '>';
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '\\')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = '<';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 219;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 't')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 220;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 223;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'p')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 220;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 223;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 219;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'x')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 221;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 222;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'K')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 223;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 222;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'C')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 220;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = ' ';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = gameview_bp[mapFocusY + i + 1][j];
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 219;

                            if(i != 14)
                            {
                                i++;

                                main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                                main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 219;
                                main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 177;
                                main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 221;

                                i--;
                            }
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'c')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = ' ';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 220;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = gameview_bp[mapFocusY + i + 1][j];

                            if(i != 14)
                            {
                                i++;

                                main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                                main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 219;
                                main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 222;
                                main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 177;

                                i--;
                            }
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '{')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = '[';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 254;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 186;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 185;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '=')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 254;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 254;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 178;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 178;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '}')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 254;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = ']';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 204;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 186;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '|')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = '.';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 196;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 221;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 178;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 196;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = '.';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 178;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 179;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '!')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 205;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 205;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 178;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 178;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '?')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = '.';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 196;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 179;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 178;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 196;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = '.';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 178;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 222;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '+')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = '.';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = ' ';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 186;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 191;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = ' ';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = '.';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 218;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 186;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '$')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 218;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 196;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 191;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 218;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 191;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = ' ';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 218;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 196;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '*')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = ' ';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 218;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 218;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 196;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 196;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 191;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 191;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 218;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'd')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 211;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 191;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 222;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 220;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 191;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 213;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = '/';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 223;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'b')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 184;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 218;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 223;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = '\\';

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 218;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 189;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 220;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 221;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '%')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 198;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 220;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 221;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 220;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 220;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 181;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 220;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 222;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '-')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 220;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 220;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 196;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 196;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'M')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 213;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 196;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = '\\';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 176;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 196;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 184;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 176;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = '/';
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'S')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = '/';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 176;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 222;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 220;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 176;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = '\\';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 220;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 221;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == 'I')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 191;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 205;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = '\\';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 176;

                            j++;

                            main_screen[10 + (2 * i)][20 + (2 * j)] = 205;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 218;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 176;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = '/';
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '5')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 'E';
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '6')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 'X';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 'I';
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '7')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 'T';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 219;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 219;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '.')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = ' ';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 176;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = ' ';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 176;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == ',')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 176;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = ' ';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 176;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = ' ';
                        }
                        else if(gameview_bp[mapFocusY + i][j] == ';')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = ' ';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = ' ';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 176;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 176;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == ':')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = ' ';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = ' ';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 178;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 178;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '\'')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = ' ';
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 176;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = ' ';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 178;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '"')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 176;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = ' ';
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 178;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = ' ';
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '_')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 178;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 178;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 176;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 176;
                        }
                    }
                    else
                    {
                        main_screen[10 + (2 * i)][20 + (2 * j)] = 178;
                        main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 178;
                        main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 178;
                        main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 178;
                    }
                }
                else
                {
                    if(logic_map[mapFocusY + i][j] != 0)
                    {
                        if(gameview_bp[mapFocusY + i][j] == '#'
                           || gameview_bp[mapFocusY + i][j] == 't'
                           || gameview_bp[mapFocusY + i][j] == 'p'
                           || gameview_bp[mapFocusY + i][j] == 'x')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 177;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 177;

                            if(mapFocusY + i + 1 < 55 &&
                              ( gameview_bp[mapFocusY + i + 1][j] == '#'
                                || gameview_bp[mapFocusY + i + 1][j] == '^'
                                || gameview_bp[mapFocusY + i + 1][j] == 'v'
                                || gameview_bp[mapFocusY + i + 1][j] == 't'
                                || gameview_bp[mapFocusY + i + 1][j] == 'p'
                                || logic_map[mapFocusY + i + 1][j] == 0 ) )
                            {
                                main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 177;
                                main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 177;
                            }
                            else
                            {
                                main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 176;
                                main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 176;
                            }
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '<')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 205;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 187;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 197;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 182;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '>')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 201;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 205;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 199;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 197;
                        }
                        else if(gameview_bp[mapFocusY + i][j] == '^' || gameview_bp[mapFocusY + i][j] == 'v')
                        {
                            main_screen[10 + (2 * i)][20 + (2 * j)] = 198;
                            main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 181;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 200;
                            main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 188;
                        }
                    }
                    else
                    {
                        main_screen[10 + (2 * i)][20 + (2 * j)] = 176;
                        main_screen[10 + (2 * i)][20 + (2 * j) + 1] = 176;
                        main_screen[10 + (2 * i) + 1][20 + (2 * j)] = 176;
                        main_screen[10 + (2 * i) + 1][20 + (2 * j) + 1] = 176;
                    }
                }
            }
        }

        //updating player stat
        for(int k = 0; k < 110; k++)
        {
            main_screen[9][20 + k] = 196;
            main_screen[40][20 + k] = 196;
        }

        char text1[22] = "[ LOCATIONS LEFT:   ]";

        for(int k = 0; k < 21; k++)
        {
            main_screen[9][21 + k] = text1[k];
        }

        main_screen[9][39] = '0' + player.location_left;

        char text2[13] = "[ LIVES:   ]";

        for(int k = 0; k < 12; k++)
        {
            main_screen[9][117 + k] = text2[k];
        }

        main_screen[9][126] = '0' + player.lives;

        if(player.current_map == 0)
        {
            char map_0_name[15] = "[ NORTH WING ]";

            for(int k = 0; k < 14; k++)
            {
                main_screen[40][115 + k] = map_0_name[k];
            }
        }
        else if(player.current_map == 1)
        {
            char map_1_name[17] = "[ CONTROL WING ]";

            for(int k = 0; k < 16; k++)
            {
                main_screen[40][113 + k] = map_1_name[k];
            }
        }
        else if(player.current_map == 2)
        {
            char map_2_name[19] = "[ ABANDONED WING ]";

            for(int k = 0; k < 18; k++)
            {
                main_screen[40][111 + k] = map_2_name[k];
            }
        }
        else if(player.current_map == 3)
        {
            char map_3_name[15] = "[ SOUTH WING ]";

            for(int k = 0; k < 14; k++)
            {
                main_screen[40][115 + k] = map_3_name[k];
            }
        }

        //viewing the screen
        show_main_screen();

        //game over condition
        if(player.lives == 0) return 0;

        if(player.busted)
        {
            player.lives--;
            player.respawn_delay = 400;
            player.detection_delay = 0;
            player.busted = 0;

            maze_collision_message(player.lives);
        }

        if(player.x == 1 && player.y == 6 && player.current_map == 0)
        {
            if(player.location_left == 0)
            {
                delay(4111111111);
                return 1;
            }
            else
            {
                map[player.current_map][player.y - 1][player.x] = '#';
                map[player.current_map][player.y][player.x] = '^';

                player.x++;
                player.door_accessed = 0;

                maze_location_remaining_message();
            }
        }

        //closing the accessed doors
        if(player.door_accessed)
        {
            if(player.door_accessed == 1 && map[player.current_map][player.y + 1][player.x - 1] == '<' && map[player.current_map][player.y + 1][player.x + 2] == '>')
            {
                map[player.current_map][player.y + 1][player.x - 1] = '#';
                map[player.current_map][player.y + 1][player.x + 2] = '#';

                map[player.current_map][player.y + 1][player.x] = '<';
                map[player.current_map][player.y + 1][player.x + 1] = '>';

                player.door_accessed = 0;
            }
            else if(player.door_accessed == 2 && map[player.current_map][player.y - 1][player.x - 1] == '<' && map[player.current_map][player.y - 1][player.x + 2] == '>')
            {
                map[player.current_map][player.y - 1][player.x - 1] = '#';
                map[player.current_map][player.y - 1][player.x + 2] = '#';

                map[player.current_map][player.y - 1][player.x] = '<';
                map[player.current_map][player.y - 1][player.x + 1] = '>';

                player.door_accessed = 0;
            }
            else if(player.door_accessed == 3 && map[player.current_map][player.y - 1][player.x + 2] == 'v')
            {
                map[player.current_map][player.y - 1][player.x + 2] = '#';

                map[player.current_map][player.y][player.x + 2] = '^';

                player.door_accessed = 0;
            }
            else if(player.door_accessed == 4 && map[player.current_map][player.y - 1][player.x - 1] == 'v')
            {
                map[player.current_map][player.y - 1][player.x - 1] = '#';

                map[player.current_map][player.y][player.x - 1] = '^';

                player.door_accessed = 0;
            }
            else if(player.door_accessed == 5 && map[player.current_map][player.y + 1][player.x - 2] == 'G')
            {
                for(int k = 0; k < 3; k++)
                {
                    if(map[player.current_map][player.y + 1][player.x - 1] == (char)('0' + k))
                    {
                        map[player.current_map][player.y + 1][player.x - 2] = '#';
                        map[player.current_map][player.y + 1][player.x - 1] = '#';

                        map[player.current_map][player.y + 1][player.x] = 'G';
                        map[player.current_map][player.y + 1][player.x + 1] = (char)('0' + k);
                        break;
                    }
                }

                player.door_accessed = 0;
            }
            else if(player.door_accessed == 6 && map[player.current_map][player.y - 1][player.x - 2] == 'G')
            {
                for(int k = 0; k < 3; k++)
                {
                    if(map[player.current_map][player.y - 1][player.x - 1] == (char)('0' + k))
                    {
                        map[player.current_map][player.y - 1][player.x - 2] = '#';
                        map[player.current_map][player.y - 1][player.x - 1] = '#';

                        map[player.current_map][player.y - 1][player.x] = 'G';
                        map[player.current_map][player.y - 1][player.x + 1] = (char)('0' + k);
                        break;
                    }
                }

                player.door_accessed = 0;
            }
        }

        //player navigation
        if(player.navigation_delay == 25)
        {
            if(GetAsyncKeyState(VK_UP) & 0x8000)
            {
                if(player.y == 0)
                {
                    if(player.current_map == 2) player.current_map = 0;
                    else if(player.current_map == 3) player.current_map = 1;

                    player.y = 54;

                    if(player.current_map == 0 && player.x == 37)
                    {
                        map[2][0][36] = '#';
                        map[2][0][39] = '#';

                        map[2][0][37] = '<';
                        map[2][0][38] = '>';

                        player.door_accessed = 0;
                    }
                }
                else if(map[player.current_map][player.y - 1][player.x] == ' ' && map[player.current_map][player.y - 1][player.x + 1] == ' ') player.y--;
            }
            else if(GetAsyncKeyState(VK_DOWN) & 0x8000)
            {
                if(player.y == 54)
                {
                    if(player.current_map != 0 || player.x != 37)
                    {
                        if(player.current_map == 0) player.current_map = 2;
                        else if(player.current_map == 1) player.current_map = 3;

                        player.y = 0;
                    }
                }
                else if(map[player.current_map][player.y + 1][player.x] == ' ' && map[player.current_map][player.y + 1][player.x + 1] == ' ') player.y++;
            }
            else if(GetAsyncKeyState(VK_LEFT) & 0x8000)
            {
                if(player.x == 0)
                {
                    if(player.current_map == 1) player.current_map = 0;
                    else if(player.current_map == 3) player.current_map = 2;

                    player.x = 53;

                    if(player.current_map == 2 && player.y == 27)
                    {
                        map[3][26][0] = '#';
                        map[3][28][0] = '#';

                        map[3][27][0] = '^';

                        player.door_accessed = 0;
                    }
                }
                else if(map[player.current_map][player.y][player.x - 1] == ' ') player.x--;
            }
            else if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
            {
                if(player.x + 1 == 54)
                {
                    if(player.current_map != 2 || player.y != 27)
                    {
                        if(player.current_map == 0) player.current_map = 1;
                        else if(player.current_map == 2) player.current_map = 3;

                        player.x = 0;
                    }
                }
                else if(map[player.current_map][player.y][player.x + 2] == ' ') player.x++;
            }
            else if(GetAsyncKeyState(VK_SPACE) & 0x8000)
            {
                //accessing regular room doors
                if(map[player.current_map][player.y - 1][player.x] == '<' && map[player.current_map][player.y - 1][player.x + 1] == '>')
                {
                    if(player.has_gatepass == 0)
                    {
                        maze_no_gatepass_message();
                    }
                    else if(player.door_accessed != 0)
                    {
                        maze_accessed_door_message();
                    }
                    else
                    {
                        map[player.current_map][player.y - 1][player.x] = ' ';
                        map[player.current_map][player.y - 1][player.x + 1] = ' ';

                        map[player.current_map][player.y - 1][player.x - 1] = '<';
                        map[player.current_map][player.y - 1][player.x + 2] = '>';

                        player.door_accessed = 1;
                    }
                }
                else if(map[player.current_map][player.y + 1][player.x] == '<' && map[player.current_map][player.y + 1][player.x + 1] == '>')
                {
                    if(player.has_gatepass == 0)
                    {
                        maze_no_gatepass_message();
                    }
                    else if(player.door_accessed != 0)
                    {
                        maze_accessed_door_message();
                    }
                    else
                    {
                        map[player.current_map][player.y + 1][player.x] = ' ';
                        map[player.current_map][player.y + 1][player.x + 1] = ' ';

                        map[player.current_map][player.y + 1][player.x - 1] = '<';
                        map[player.current_map][player.y + 1][player.x + 2] = '>';

                        player.door_accessed = 2;
                    }
                }
                else if(map[player.current_map][player.y][player.x - 1] == '^')
                {
                    if(player.has_gatepass == 0)
                    {
                        maze_no_gatepass_message();
                    }
                    else if(player.door_accessed != 0)
                    {
                        maze_accessed_door_message();
                    }
                    else
                    {
                        map[player.current_map][player.y][player.x - 1] = ' ';

                        map[player.current_map][player.y - 1][player.x - 1] = 'v';

                        player.door_accessed = 3;
                    }
                }
                else if(map[player.current_map][player.y][player.x + 2] == '^')
                {
                    if(player.has_gatepass == 0)
                    {
                        maze_no_gatepass_message();
                    }
                    else if(player.door_accessed != 0)
                    {
                        maze_accessed_door_message();
                    }
                    else
                    {
                        map[player.current_map][player.y][player.x + 2] = ' ';

                        map[player.current_map][player.y - 1][player.x + 2] = 'v';

                        player.door_accessed = 4;
                    }
                }
                //accessing database room doors
                else if(map[player.current_map][player.y - 1][player.x] == 'G')
                {
                    if(player.door_accessed != 0)
                    {
                        maze_accessed_door_message();
                    }
                    else
                    {
                        for(int k = 0; k < 3; k++)
                        {
                            if(map[player.current_map][player.y - 1][player.x + 1] == (char)('0' + k))
                            {
                                if(player.has_database_room_access[k])
                                {
                                    map[player.current_map][player.y - 1][player.x] = ' ';
                                    map[player.current_map][player.y - 1][player.x + 1] = ' ';

                                    map[player.current_map][player.y - 1][player.x - 2] = 'G';
                                    map[player.current_map][player.y - 1][player.x - 1] = (char)('0' + k);

                                    maze_accessed_database_room_message(k, 1);

                                    player.door_accessed = 5;
                                }
                                else
                                {
                                    maze_accessed_database_room_message(k, 0);
                                }

                                break;
                            }
                        }
                    }
                }
                else if(player.door_accessed == 0 && map[player.current_map][player.y + 1][player.x] == 'G')
                {
                    if(player.door_accessed != 0)
                    {
                        maze_accessed_door_message();
                    }
                    else
                    {
                        for(int k = 0; k < 3; k++)
                        {
                            if(map[player.current_map][player.y + 1][player.x + 1] == (char)('0' + k) && player.has_database_room_access[k])
                            {
                                map[player.current_map][player.y + 1][player.x] = ' ';
                                map[player.current_map][player.y + 1][player.x + 1] = ' ';

                                map[player.current_map][player.y + 1][player.x - 2] = 'G';
                                map[player.current_map][player.y + 1][player.x - 1] = (char)('0' + k);

                                player.door_accessed = 6;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    for(int i = -1; i < 2; i++)
                    {
                        int access_point_found = 0;

                        for(int j = -1; j < 3; j++)
                        {
                            if(i == 0 && j == 0) j += 2;

                            //getting the gatepass
                            if(map[player.current_map][player.y + i][player.x + j] == 'K')
                            {
                                map[player.current_map][player.y + i][player.x + j] = ' ';
                                player.has_gatepass = 1;

                                maze_achieved_gatepass_message();

                                access_point_found = 1;
                            }
                            //hacking the system security
                            else if(map[player.current_map][player.y + i][player.x + j] == 'M')
                            {
                                if(map[player.current_map][player.y + i][player.x + j + 1] == 'X')
                                {
                                    maze_hacked_security_system_message();
                                }
                                else
                                {
                                    int stat = maze_hacking_security_system_game();

                                    if(stat == -1) return -1;

                                    if(stat == 1)
                                    {
                                        map[player.current_map][player.y + i][player.x + j + 1] = 'X';

                                        //turning off the cameras
                                        for(int k = 0; k < 4; k++)
                                        {
                                            for(int i = 0; i < 55; i++)
                                            {
                                                for(int j = 0; j < 55; j++)
                                                {
                                                    if(map[k][i][j] == 'C' || map[k][i][j] == 'c')
                                                    {
                                                        map[k][i + 1][j] = 'X';
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            //getting database room access
                            else if(map[player.current_map][player.y + i][player.x + j] == 'S')
                            {
                                if(map[player.current_map][player.y + i][player.x + j + 1] == 'X'
                                   || map[player.current_map][player.y + i][player.x + j + 1] == 'Y'
                                   || map[player.current_map][player.y + i][player.x + j + 1] == 'Z')
                                {
                                    maze_validated_database_room_access_message(map[player.current_map][player.y + i][player.x + j + 1] - 'X');
                                }
                                else
                                {
                                    for(int k = 0; k < 3; k++)
                                    {
                                        if(map[player.current_map][player.y + i][player.x + j + 1] == (char)('0' + k))
                                        {
                                            maze_validating_database_room_access_message(map[player.current_map][player.y + i][player.x + j + 1] - '0');

                                            player.has_database_room_access[k] = 1;

                                            map[player.current_map][player.y + i][player.x + j + 1] = (char)('X' + k);

                                            break;
                                        }
                                    }
                                }

                                access_point_found = 1;
                            }
                            //cracking the database
                            else if(map[player.current_map][player.y + i][player.x + j] == 'I')
                            {
                                if(map[player.current_map][player.y + i][player.x + j + 1] == 'X')
                                {
                                    maze_cracked_database_message();
                                }
                                else
                                {
                                    maze_cracking_database_animation();
                                    map[player.current_map][player.y + i][player.x + j + 1] = 'X';

                                    player.location_left--;
                                }

                                access_point_found = 1;
                            }

                            if(access_point_found) break;
                        }

                        if(access_point_found) break;
                    }
                }
            }
            //accessing ingame menu
            else if(GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            {
                int feedback = ingame_menu_screen();

                if(feedback == 1) return -1;
            }

            player.navigation_delay = 0;
        }
        else player.navigation_delay++;

        //moving enemies
        if(enemy_movement_delay == 150)
        {
            for(int i = 0; i < 55; i++)
            {
                for(int j = 0; j < 55; j++)
                {
                    if(map[player.current_map][i][j] == 'E')
                    {
                        if(map[player.current_map][i][j + 1] == 'U')
                        {
                            if(map[player.current_map][i - 1][j] == ' ' && map[player.current_map][i - 1][j + 1] == ' ')
                            {
                                map[player.current_map][i][j] = ' ';
                                map[player.current_map][i][j + 1] = ' ';

                                map[player.current_map][i - 1][j] = 'E';
                                map[player.current_map][i - 1][j + 1] = 'U';
                            }
                            else
                            {
                                map[player.current_map][i][j + 1] = 'D';

                                logic_map[i][j] = 2;
                            }
                        }
                        else if(map[player.current_map][i][j + 1] == 'L')
                        {
                            if(map[player.current_map][i][j - 1] == ' ')
                            {
                                map[player.current_map][i][j + 1] = ' ';

                                map[player.current_map][i][j - 1] = 'E';
                                map[player.current_map][i][j] = 'L';
                            }
                            else
                            {
                                map[player.current_map][i][j + 1] = 'R';

                                logic_map[i][j] = 2;
                            }
                        }
                    }
                }
            }

            for(int i = 54; i >= 0; i--)
            {
                for(int j = 54; j >= 0; j--)
                {
                    if(map[player.current_map][i][j] == 'E' && logic_map[i][j] != 2)
                    {
                        if(map[player.current_map][i][j + 1] == 'D')
                        {
                            if(map[player.current_map][i + 1][j] == ' ' && map[player.current_map][i + 1][j + 1] == ' ')
                            {
                                map[player.current_map][i][j] = ' ';
                                map[player.current_map][i][j + 1] = ' ';

                                map[player.current_map][i + 1][j] = 'E';
                                map[player.current_map][i + 1][j + 1] = 'D';
                            }
                            else map[player.current_map][i][j + 1] = 'U';
                        }
                        else if(map[player.current_map][i][j + 1] == 'R')
                        {
                            if(map[player.current_map][i][j + 2] == ' ')
                            {
                                map[player.current_map][i][j] = ' ';

                                map[player.current_map][i][j + 1] = 'E';
                                map[player.current_map][i][j + 2] = 'R';
                            }
                            else map[player.current_map][i][j + 1] = 'L';
                        }
                    }
                }
            }

            enemy_movement_delay = 0;
        }
        else enemy_movement_delay++;

        //setting the trap trigger
        if(trap_set_delay == 150)
        {
            if(trap_trigger == 3) trap_trigger = 0;
            else trap_trigger++;

            if(trap_trigger < 2)
            {
                for(int i = 0; i < 55; i++)
                {
                    for(int j = 0; j < 55; j++)
                    {
                        if(map[player.current_map][i][j] == 'H') map[player.current_map][i][j] = 'V';
                        else if(map[player.current_map][i][j] == 'V') map[player.current_map][i][j] = 'H';
                    }
                }
            }

            trap_set_delay = 0;
        }
        else trap_set_delay++;
    }

    return 0;
}

