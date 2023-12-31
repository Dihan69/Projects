#pragma once

#include "main_screen_utility.c"
#include "user_info_handler.c"
#include "startup_sequence.c"
#include "menu_utility.c"

#include "menu_components.h"

void create_main_menu_wordboxes(Wordbox * wb)
{
    if(User.current_level > 1)
    {
        wb[0].word = "   CONTINUE   ";
    }
    else wb[0].word = "   NEW GAME   ";

    wb[0].x = 67;
    wb[0].y = 10;

    wb[1].word = "   CHAPTERS   ";
    wb[1].x = 67;
    wb[1].y = 16;

    wb[2].word = "   CREDITS    ";
    wb[2].x = 67;
    wb[2].y = 22;

    wb[3].word = "    RESET     ";
    wb[3].x = 67;
    wb[3].y = 28;

    wb[4].word = "     EXIT     ";
    wb[4].x = 67;
    wb[4].y = 34;
}

void create_chapters_menu_wordboxes(Wordbox * wb)
{
    wb[0].word = "  CHAPTER 00  ";
    wb[0].x = 44;
    wb[0].y = 13;

    wb[1].word = "  CHAPTER 01  ";
    wb[1].x = 44;
    wb[1].y = 19;

    wb[2].word = "  CHAPTER 02  ";
    wb[2].x = 44;
    wb[2].y = 25;

    wb[3].word = "  CHAPTER 03  ";
    wb[3].x = 44;
    wb[3].y = 31;

    wb[4].word = "  CHAPTER 04  ";
    wb[4].x = 90;
    wb[4].y = 13;

    wb[5].word = "  CHAPTER 05  ";
    wb[5].x = 90;
    wb[5].y = 19;

    wb[6].word = "  CHAPTER 06  ";
    wb[6].x = 90;
    wb[6].y = 25;

    wb[7].word = "  CHAPTER 07  ";
    wb[7].x = 90;
    wb[7].y = 31;

    wb[8].word = "     BACK     ";
    wb[8].x = 67;
    wb[8].y = 40;
}

void credits_screen(void)
{
    initialize_main_screen();

    char credits[42][60];

    FILE *fp = fopen("text_components/credits.txt", "r");

    for(int i = 0; i < 42; i++)
    {
        for(int j = 0; j < 60; j++)
        {
            fscanf(fp, "%c", &credits[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    for(int i = 0; i < 42; i++)
    {
        for(int j = 0; j < 60; j++)
        {
            main_screen[2 + i][45 + j] = credits[i][j];
        }

        show_main_screen();
        delay(49999999);
    }

    for(int j = 0; j < 14; j++)
    {
        main_screen[45][66 + j] = "     BACK     "[j];
    }

    main_screen[43][65] = 201;
    main_screen[43][80] = 187;
    main_screen[47][65] = 200;
    main_screen[47][80] = 188;

    for(int k = 66; k < 80; k++)
    {
        main_screen[43][k] = 205;
        main_screen[47][k] = 205;
    }

    show_main_screen();
    pressEnterToContinue();
}

void chapters_completed_screen(void)
{
    initialize_main_screen();

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

    char text1[2][36] = {"      !!! CONGRATULATIONS !!!      ", "You have completed all the chapters"};
    char text2[10] = "[ ENTER ]";

    for(int k = 0; k < 35; k++)
    {
        main_screen[22][59 + k] = text1[0][k];
        main_screen[25][59 + k] = text1[1][k];
    }

    for(int k = 0; k < 9; k++)
    {
        main_screen[29][72 + k] = text2[k];
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
}
