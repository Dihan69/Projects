#pragma once

#include "menu_utility.h"
#include "main_screen_utility.c"

void set_menu_screen(Wordbox * menu_wb, int menu_wb_count)
{
    initialize_main_screen();

    for(int i = 0; i < menu_wb_count; i++)
    {
        for(int j = 0; menu_wb[i].word[j] != '\0'; j++)
        {
            main_screen[menu_wb[i].y + 2][menu_wb[i].x + 1 + j] = menu_wb[i].word[j];
        }
    }
}

void set_highlight(Wordbox * menu_wb, int wb_hi_in)
{
    main_screen[menu_wb[wb_hi_in].y][menu_wb[wb_hi_in].x] = 201;
    main_screen[menu_wb[wb_hi_in].y][menu_wb[wb_hi_in].x + 15] = 187;
    main_screen[menu_wb[wb_hi_in].y + 4][menu_wb[wb_hi_in].x] = 200;
    main_screen[menu_wb[wb_hi_in].y + 4][menu_wb[wb_hi_in].x + 15] = 188;

    for(int k = menu_wb[wb_hi_in].x + 1; k < menu_wb[wb_hi_in].x + 15; k++)
    {
        main_screen[menu_wb[wb_hi_in].y][k] = 205;
        main_screen[menu_wb[wb_hi_in].y + 4][k] = 205;
    }
}

void remove_highlight(Wordbox * menu_wb, int wb_hi_in)
{
    main_screen[menu_wb[wb_hi_in].y][menu_wb[wb_hi_in].x] = EMPTY_SPACE;
    main_screen[menu_wb[wb_hi_in].y][menu_wb[wb_hi_in].x + 15] = EMPTY_SPACE;
    main_screen[menu_wb[wb_hi_in].y + 4][menu_wb[wb_hi_in].x] = EMPTY_SPACE;
    main_screen[menu_wb[wb_hi_in].y + 4][menu_wb[wb_hi_in].x + 15] = EMPTY_SPACE;

    for(int k = menu_wb[wb_hi_in].x + 1; k < menu_wb[wb_hi_in].x + 15; k++)
    {
        main_screen[menu_wb[wb_hi_in].y][k] = EMPTY_SPACE;
        main_screen[menu_wb[wb_hi_in].y + 4][k] = EMPTY_SPACE;
    }
}
