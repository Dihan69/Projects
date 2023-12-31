#pragma once

#include "user_info_handler.h"
#include "main_screen_utility.c"

void load_user_info(void)
{
    FILE * fp = fopen(USER_GAMEDATA, "r");

    if(fp == NULL)
    {
        show_error_screen();
    }

    fscanf(fp, "game current level = %d\n", &User.current_level);
    fscanf(fp, "game played = %d times", &User.times_played);

    fclose(fp);

    if(User.current_level < 1 || User.current_level > 9 || User.times_played < 0) show_error_screen();
}

void save_user_info(void)
{
    FILE * fp = fopen(USER_GAMEDATA, "w");

    if(fp == NULL)
    {
        show_error_screen();
    }

    fprintf(fp, "game current level = %d\n", User.current_level);
    fprintf(fp, "game played = %d times", User.times_played);

    fclose(fp);
}
