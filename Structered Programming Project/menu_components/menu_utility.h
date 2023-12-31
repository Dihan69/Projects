#pragma once

#include <stdio.h>
#include <windows.h>

typedef struct _wordbox
{
    char * word;
    int x, y;
} Wordbox;

void set_menu_screen(Wordbox * menu_wb, int menu_wb_count);

void set_highlight(Wordbox * menu_wb, int wb_hi_in);
void remove_highlight(Wordbox * menu_wb, int wb_hi_in);
