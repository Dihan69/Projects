#pragma once

#include "game_components/game_utility.c"

typedef struct
{
    int pos_x, pos_y;
} ss_Player;

int play_swarm_survive(void);

void ss_set_game_screen(void);

void ss_initialize_background(char background[][75]);
void ss_set_background(char background[][75]);

int ss_game_flow(ss_Player * player, ss_Player * enemy, int enemy_count, char background[][75], int * game_running, int * enemy_move_delay);

int ss_navigation(ss_Player * player);
void ss_set_player_position(int x, int y);

void ss_enemy_generation(ss_Player * enemy, int enemy_count);
void ss_move_enemy(ss_Player * enemy, int enemy_count, ss_Player * player);
void ss_set_enemy_position(ss_Player * enemy, int enemy_count);

void ss_collision_sequence(ss_Player * player);

    int ss_game_difficulty = 0;

int play_swarm_survive(void)
{
    initialize_main_screen();

    srand(time(0));

    ss_set_game_screen();

    ss_Player player = {37, 6}, enemy[15];
    ss_set_player_position(37, 6);

    char background[25][75];
    ss_initialize_background(background);

    int enemy_count = 0;
    int result=0;

    int target;

    if(ss_game_difficulty == 0) target = 7;
    else target = 13;

    int game_running = 1;

    int navigation_delay = 0;
    int enemy_generation_delay = 0;
    int enemy_move_delay = 0;

    while(game_running)
    {
        show_main_screen();

        if(enemy_generation_delay == 2000)
        {
            //ending sequence
            if(enemy_count == target)
            {
                delay(3000000000);
                return 1;
            }

            ss_enemy_generation(enemy, enemy_count);

            enemy_count++;

            enemy_generation_delay = 0;
        }
        else enemy_generation_delay++;

        if(navigation_delay == 10)
        {
            result = ss_navigation(&player);

            if(result == -1)
                return -1;

            navigation_delay = 0;
        }
        else navigation_delay++;

        result = ss_game_flow(&player, enemy, enemy_count, background, &game_running, &enemy_move_delay);

        if(result == 0) break;
    }

    return 0;
}

void ss_set_game_screen(void)
{
    setGameViewport(34, 3, 75, 25);
    setGameInstructionTab(35, 37, 75, 5);

    //setting instructions
    char instructions[75] = "                         !!! SURVIVE THE SWARM !!!                         ";

        for(int j = 0; j < 75; j++)
        {
            main_screen[41][37 + j] = instructions[j];
        }
}

void ss_initialize_background(char background[][75])
{
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 75; j++)
        {
            background[i][j] = ' ';
        }
    }
}

void ss_set_background(char background[][75])
{
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 75; j++)
        {
            main_screen[6 + i][37 + j] = background[i][j];
        }
    }
}

int ss_game_flow(ss_Player * player, ss_Player * enemy, int enemy_count, char background[][75], int * game_running, int * enemy_move_delay)
{
    ss_set_background(background);

    if(*enemy_move_delay == (90 - (enemy_count - 1) * 5))
    {
        ss_move_enemy(enemy, enemy_count, player);

        *enemy_move_delay = 0;
    }
    else (*enemy_move_delay)++;

    ss_set_enemy_position(enemy, enemy_count);

    if(main_screen[player->pos_y][player->pos_x] == ' ' && main_screen[player->pos_y][player->pos_x + 1] == ' ')
    {
        ss_set_player_position(player->pos_x, player->pos_y);
    }
    else
    {
        ss_collision_sequence(player);

        delay(3000000000);

        *game_running = 0;
        return 0;
    }

    return 1;
}

int ss_navigation(ss_Player * player)
{
    if(GetAsyncKeyState(VK_UP) & 0x8000)
    {
        if(player->pos_y > 6)
        {
            player->pos_y--;
        }
    }
    else if(GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        if(player->pos_y < 30)
        {
            player->pos_y++;
        }
    }
    else if(GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        if(player->pos_x > 37)
        {
            player->pos_x--;
        }
    }
    else if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        if(player->pos_x < 110)
        {
            player->pos_x++;
        }
    }
      else if(GetAsyncKeyState(VK_ESCAPE) & 0X8000)
    {
        int feedback = ingame_menu_screen();

        if(feedback == 1) return -1;
    }

    return 0;
}

void ss_set_player_position(int x, int y)
{
    main_screen[y][x] = 219;
    main_screen[y][x + 1] = 219;
}

void ss_enemy_generation(ss_Player * enemy, int enemy_count)
{
    switch(rand() % 4)
    {
    case 0:
        enemy[enemy_count].pos_x = 37 +(rand() % 5);
        enemy[enemy_count].pos_y = 6 + (rand() % 25);
        break;

    case 1:
        enemy[enemy_count].pos_x = 37 + (rand() % 74);
        enemy[enemy_count].pos_y = 6 + (rand() % 5);
        break;

    case 2:
        enemy[enemy_count].pos_x = 107 + (rand() % 5);
        enemy[enemy_count].pos_y = 6 + (rand() % 25);
        break;

    case 3:
        enemy[enemy_count].pos_x = 37 + (rand() % 74);
        enemy[enemy_count].pos_y = 20 + (rand() % 5);
        break;
    }
}

void ss_move_enemy(ss_Player * enemy, int enemy_count, ss_Player * player)
{
    for(int i = 0; i < enemy_count; i++)
    {
        enemy[i].pos_x = player->pos_x + (3 * (enemy[i].pos_x - player->pos_x) / 4);
        enemy[i].pos_y = player->pos_y + (3 * (enemy[i].pos_y - player->pos_y) / 4);
    }
}

void ss_set_enemy_position(ss_Player * enemy, int enemy_count)
{
    for(int i = 0; i < enemy_count; i++)
    {
        if(main_screen[enemy[i].pos_y][enemy[i].pos_x] == ' ' && main_screen[enemy[i].pos_y][enemy[i].pos_x + 1] == ' ')
        {
            main_screen[enemy[i].pos_y][enemy[i].pos_x] = '[';
            main_screen[enemy[i].pos_y][enemy[i].pos_x + 1] = ']';
        }
    }
}

void ss_collision_sequence(ss_Player * player)
{
    main_screen[player->pos_y][player->pos_x] = 178;
    main_screen[player->pos_y][player->pos_x + 1] = 178;
    show_main_screen();

    delay(1500000000);
    main_screen[player->pos_y][player->pos_x] = 177;
    main_screen[player->pos_y][player->pos_x + 1] = 177;
    show_main_screen();

    delay(1500000000);
    main_screen[player->pos_y][player->pos_x] = 176;
    main_screen[player->pos_y][player->pos_x + 1] = 176;
    show_main_screen();

    delay(1500000000);
    main_screen[player->pos_y][player->pos_x] = 177;
    main_screen[player->pos_y][player->pos_x + 1] = 177;
    show_main_screen();

    delay(1500000000);
    main_screen[player->pos_y][player->pos_x] = 178;
    main_screen[player->pos_y][player->pos_x + 1] = 178;
    show_main_screen();
}
