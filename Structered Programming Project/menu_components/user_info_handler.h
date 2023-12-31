#pragma once

#include <stdio.h>

#define USER_GAMEDATA "save.txt"

struct _user
{
    int times_played;
    int current_level;
} User;

void load_user_info(void);
void save_user_info(void);
