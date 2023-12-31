#pragma once

#include "game_components/game_utility.c"

typedef struct
{
    int x, y;
    int hit;
    int respawn;
    int bullet_count;
    int lives;
} snake_spinoff_Player;

typedef struct
{
    int hx, hy;
    int length;
    int direction;
    int hit_obstacle;
    int hitpoint;
    int chase_time;
    int cooldown_time;
    int dead;
} snake_spinoff_Snake;

typedef struct
{
    int x, y;
    int type;
    int shadow_duration;
    int deploy_delay;
} snake_spinoff_Tetris;

int play_snake_spinoff(void);

int snake_spinoff_get_next_move(int sx, int sy, int dx, int dy, int map[][52]);

void snake_spinoff_search(int cx, int cy, int g_val, int h_grid[][52], int v_grid[][52], int in_dir, int * dir);

int snake_spinoff_custom_min(int num1, int num2);
void snake_spinoff_custom_swap(int * num1, int * num2);

void snake_spinoff_set_block_shadow(snake_spinoff_Tetris * tetris1, char block_layer[][52]);
void snake_spinoff_block_fade(int x, int y);

int snake_spinoff_custom_min(int num1, int num2)
{
    return ((num1 <= num2) * num1) + ((num2 < num1) * num2);
}

void snake_spinoff_custom_swap(int * num1, int * num2)
{
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void snake_spinoff_search(int cx, int cy, int g_val, int h_grid[][52], int v_grid[][52], int in_dir, int * dir)
{
    if(h_grid[cy][cx] == -2 || *dir != -1) return;

    if(h_grid[cy][cx] == 0)
    {
        *dir = in_dir;
        return;
    }

    g_val++;

    int next_cell_info[4][4] =
    {
        {h_grid[cy + 1][cx] + g_val, cx, cy + 1, 0},
        {h_grid[cy - 1][cx] + g_val, cx, cy - 1, 1},
        {h_grid[cy][cx + 1] + g_val, cx + 1, cy, 2},
        {h_grid[cy][cx - 1] + g_val, cx - 1, cy, 3}
    };

    if(h_grid[cy + 1][cx] == -1)
    {
        next_cell_info[0][0] = h_grid[1][cx] + g_val;
        next_cell_info[0][2] = 1;
    }

    if(h_grid[cy - 1][cx] == -1)
    {
        next_cell_info[1][0] = h_grid[30][cx] + g_val;
        next_cell_info[1][2] = 30;
    }

    if(h_grid[cy][cx + 1] == -1)
    {
        next_cell_info[2][0] = h_grid[cy][1] + g_val;
        next_cell_info[2][1] = 1;
    }

    if(h_grid[cy][cx - 1] == -1)
    {
        next_cell_info[3][0] = h_grid[cy][50] + g_val;
        next_cell_info[3][1] = 50;
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3 - i; j++)
        {
            if(next_cell_info[j][0] > next_cell_info[j + 1][0])
            {
                snake_spinoff_custom_swap(&next_cell_info[j][0], &next_cell_info[j + 1][0]);
                snake_spinoff_custom_swap(&next_cell_info[j][1], &next_cell_info[j + 1][1]);
                snake_spinoff_custom_swap(&next_cell_info[j][2], &next_cell_info[j + 1][2]);
                snake_spinoff_custom_swap(&next_cell_info[j][3], &next_cell_info[j + 1][3]);
            }
        }
    }

    if(v_grid[next_cell_info[0][2]][next_cell_info[0][1]] == 0)
    {
        v_grid[next_cell_info[0][2]][next_cell_info[0][1]] = 1;
        snake_spinoff_search(next_cell_info[0][1], next_cell_info[0][2], g_val, h_grid, v_grid, next_cell_info[0][3], dir);
    }

    if(v_grid[next_cell_info[1][2]][next_cell_info[1][1]] == 0)
    {
        v_grid[next_cell_info[1][2]][next_cell_info[1][1]] = 1;
        snake_spinoff_search(next_cell_info[1][1], next_cell_info[1][2], g_val, h_grid, v_grid, next_cell_info[1][3], dir);
    }

    if(v_grid[next_cell_info[2][2]][next_cell_info[2][1]] == 0)
    {
        v_grid[next_cell_info[2][2]][next_cell_info[2][1]] = 1;
        snake_spinoff_search(next_cell_info[2][1], next_cell_info[2][2], g_val, h_grid, v_grid, next_cell_info[2][3], dir);
    }

    if(v_grid[next_cell_info[3][2]][next_cell_info[3][1]] == 0)
    {
        v_grid[next_cell_info[3][2]][next_cell_info[3][1]] = 1;
        snake_spinoff_search(next_cell_info[3][1], next_cell_info[3][2], g_val, h_grid, v_grid, next_cell_info[3][3], dir);
    }
}

int snake_spinoff_get_next_move(int sx, int sy, int dx, int dy, int map[][52])
{
    int h_grid[32][52];
    int v_grid[32][52];

    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 52; j++)
        {
            if(i == 0 || i == 31 || j == 0 || j == 51) h_grid[i][j] = -1;
            else if(map[i][j] != 0) h_grid[i][j] = -2;
            else h_grid[i][j] = snake_spinoff_custom_min(50 - abs(sx - j), abs(sx - j)) + snake_spinoff_custom_min(30 - abs(sy - i), abs(sy - i));

            v_grid[i][j] = 0;
        }
    }

    h_grid[sy][sx] = 0;

    int dir = -1;

    snake_spinoff_search(dx, dy, 0, h_grid, v_grid, -1, &dir);

    return dir;
}

void snake_spinoff_set_block_shadow(snake_spinoff_Tetris * tetris1, char block_layer[][52])
{
    for(int i = 1; i < 31; i++)
    {
        for(int j = 1; j < 51; j++)
        {
            block_layer[i][j] = ' ';
        }
    }

    int block_cnt = 4;

    if(tetris1->type == 0)
    {
        for(int k = -3; block_cnt != 0; k++)
        {
            if(tetris1->y + k > 0)
            {
                block_layer[tetris1->y + k][tetris1->x] = 'B';
                block_cnt--;
            }
        }
    }
    else if(tetris1->type == 1)
    {
        for(int k = -2, l = 0; block_cnt != 0; k++)
        {
            if(tetris1->y + k > 0)
            {
                block_layer[tetris1->y + k][tetris1->x] = 'B';
                block_cnt--;

                l++;

                if(l == 1)
                {
                    if(block_layer[tetris1->y + k][tetris1->x + 1] != '#') block_layer[tetris1->y + k][tetris1->x + 1] = 'B';
                    else block_layer[tetris1->y + k][tetris1->x - 1] = 'B';

                    block_cnt--;
                }
            }
        }
    }
    else if(tetris1->type == 2)
    {
        for(int k = -2, l = 0; block_cnt != 0; k++)
        {
            if(tetris1->y + k > 0)
            {
                block_layer[tetris1->y + k][tetris1->x] = 'B';
                block_cnt--;

                l++;

                if(l == 2)
                {
                    if(block_layer[tetris1->y + k][tetris1->x + 1] != '#') block_layer[tetris1->y + k][tetris1->x + 1] = 'B';
                    else block_layer[tetris1->y + k][tetris1->x - 1] = 'B';

                    block_cnt--;
                }
            }
        }
    }
    else if(tetris1->type == 3)
    {
        for(int k = -1; block_cnt != 0; k++)
        {
            if(tetris1->y + k > 0)
            {
                block_layer[tetris1->y + k][tetris1->x] = 'B';
                block_layer[tetris1->y + k + 1][tetris1->x] = 'B';

                if(block_layer[tetris1->y + k][tetris1->x + 1] != '#')
                {
                    block_layer[tetris1->y + k][tetris1->x + 1] = 'B';
                    block_layer[tetris1->y + k + 1][tetris1->x + 1] = 'B';
                }
                else
                {
                    block_layer[tetris1->y + k][tetris1->x - 1] = 'B';
                    block_layer[tetris1->y + k + 1][tetris1->x - 1] = 'B';
                }

                block_cnt = 0;
            }
        }
    }
}

void snake_spinoff_block_fade(int x, int y)
{
    int count = 3;
    char mode[2] = {219, 177};

    while(count)
    {
        main_screen[10 + y][23 + 2 * x] = mode[count % 2];
        main_screen[10 + y][24 + 2 * x] = mode[count % 2];

        show_main_screen();

        delay(777777777);

        count--;
    }
}

int play_snake_spinoff(void)
{
    srand(time(0));

    initialize_main_screen();

    setGameViewport(22, 6, 100, 32);

    main_screen[9][26] = '[';
    main_screen[9][27] = 'L';
    main_screen[9][29] = 'I';
    main_screen[9][31] = 'V';
    main_screen[9][33] = 'E';
    main_screen[9][35] = 'S';
    main_screen[9][36] = ']';
    main_screen[9][37] = ':';
    main_screen[9][38] = '[';
    main_screen[9][50] = ']';

    main_screen[9][93] = '[';
    main_screen[9][94] = 'B';
    main_screen[9][96] = 'U';
    main_screen[9][98] = 'L';
    main_screen[9][100] = 'L';
    main_screen[9][102] = 'E';
    main_screen[9][104] = 'T';
    main_screen[9][106] = 'S';
    main_screen[9][107] = ']';
    main_screen[9][108] = ':';
    main_screen[9][109] = '[';
    main_screen[9][123] = ']';

    for(int k = 0; k < 100; k++)
    {
        main_screen[10][25 + k] = 196;
    }

    char background[32][52];
    char block_layer[32][52];
    char bullet_layer[32][52];

    int logic_map[32][52];

    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 52; j++)
        {
            if(i == 0 || i == 31 || j == 0 || j == 51)
            {
                background[i][j] = '#';
                block_layer[i][j] = '#';
                bullet_layer[i][j] = '#';

                logic_map[i][j] = -1;
            }
            else
            {
                background[i][j] = ' ';
                block_layer[i][j] = ' ';
                bullet_layer[i][j] = ' ';

                logic_map[i][j] = 0;
            }
        }
    }

    for(int k = 0; k < 4; k++)
    {
        int p = !(k % 2);
        int q = k / 2;

        background[p*3 + (!p)*28][q*5 + (!q)*46] = 'B';
        background[p*4 + (!p)*27][q*5 + (!q)*46] = 'B';
        background[p*5 + (!p)*26][q*5 + (!q)*46] = 'B';
        background[p*5 + (!p)*26][q*4 + (!q)*47] = 'B';

        background[p*10 + (!p)*21][q*20 + (!q)*31] = 'B';
        background[p*11 + (!p)*20][q*19 + (!q)*32] = 'B';
        background[p*11 + (!p)*20][q*20 + (!q)*31] = 'B';
        background[p*12 + (!p)*19][q*19 + (!q)*32] = 'B';

        logic_map[p*3 + (!p)*28][q*5 + (!q)*46] = -2;
        logic_map[p*4 + (!p)*27][q*5 + (!q)*46] = -2;
        logic_map[p*5 + (!p)*26][q*5 + (!q)*46] = -2;
        logic_map[p*5 + (!p)*26][q*4 + (!q)*47] = -2;

        logic_map[p*10 + (!p)*21][q*20 + (!q)*31] = -2;
        logic_map[p*11 + (!p)*20][q*19 + (!q)*32] = -2;
        logic_map[p*11 + (!p)*20][q*20 + (!q)*31] = -2;
        logic_map[p*12 + (!p)*19][q*19 + (!q)*32] = -2;
    }

    char game_view[32][52];

    snake_spinoff_Player player1 = {25, 15, 0, 0, 6, 5};

    snake_spinoff_Snake snake1 = {8, 18, 20, 0, 0, 1000, 10000, 5000, 0};

    for(int k = 0; k < 10; k++)
    {
        background[snake1.hy + k][snake1.hx] = 'S';
        background[snake1.hy + 10][snake1.hx + k] = 'S';

        logic_map[snake1.hy + k][snake1.hx] = k + 1;
        logic_map[snake1.hy + 10][snake1.hx + k] = k + 11;
    }

    snake_spinoff_Tetris tetris1 = {player1.x, player1.y, (rand() % 4), 900, 100};

    int navigation_delay = 0;
    int bullet_move_delay = 0;

    int snake_movement_delay = 0;

    int tetris_fall_delay = 0;

    while(1)
    {
        //collision detection
        for(int i = 1; i < 31; i++)
        {
            for(int j = 1; j < 51; j++)
            {
                if(bullet_layer[i][j] == 'U' || bullet_layer[i][j] == 'D' || bullet_layer[i][j] == 'L' || bullet_layer[i][j] == 'R')
                {
                    if(player1.y == i && player1.x == j)
                    {
                        if(!player1.hit)
                        {
                            player1.hit = 1;
                            player1.lives--;
                        }

                        bullet_layer[i][j] = ' ';
                    }
                    else if(background[i][j] == 'S')
                    {
                        if(snake1.chase_time == 0)
                        {
                            if(logic_map[i][j] == 1) snake1.hitpoint -= 10;
                            else snake1.hitpoint -= 5;
                        }
                        else
                        {
                            if(logic_map[i][j] == 1) snake1.hitpoint -= 5;
                            else snake1.hitpoint -= 1;
                        }

                        bullet_layer[i][j] = ' ';
                    }
                    else if(background[i][j] == 'B')
                    {
                        background[i][j] = ' ';

                        bullet_layer[i][j] = ' ';
                    }
                }
            }
        }

        if(snake1.length > (snake1.hitpoint + 49) / 50)
        {
            if(snake1.length != 1)
            {
                int tail_found = 0;

                for(int i = 0; i < 32; i++)
                {
                    for(int j = 0; j < 52; j++)
                    {
                        if(logic_map[i][j] == snake1.length)
                        {
                            logic_map[i][j] = 0;
                            background[i][j] = ' ';

                            tail_found = 1;
                            break;
                        }

                    }

                    if(tail_found) break;
                }

                snake1.length--;
            }
            else snake1.dead = 1;
        }

        //snake head repositioning
        if(snake1.hit_obstacle)
        {
            for(int i = 0; i < 32; i++)
            {
                for(int j = 0; j < 52; j++)
                {
                    if(logic_map[i][j] == snake1.length)
                    {
                        snake1.hy = i;
                        snake1.hx = j;
                    }

                    if(logic_map[i][j] > 0)
                    {
                        logic_map[i][j] = snake1.length - logic_map[i][j] + 1;
                    }
                }
            }

            snake1.hit_obstacle = 0;
        }

        //player spawning
        if(player1.lives && player1.hit)
        {
            player1.x = 1 + (rand() % 50);
            player1.y = 1 + (rand() % 30);

            while(logic_map[player1.y][player1.x] != 0)
            {
                player1.x = 1 + (rand() % 50);
                player1.y = 1 + (rand() % 30);
            }

            player1.hit = 0;
            player1.respawn = 1;
        }

        //game view change
        for(int i = 0; i < 32; i++)
        {
            for(int j = 0; j < 52; j++)
            {
                game_view[i][j] = background[i][j];
            }
        }

        for(int i = 0; i < 32; i++)
        {
            for(int j = 0; j < 52; j++)
            {
                if(bullet_layer[i][j] != ' ') game_view[i][j] = bullet_layer[i][j];
            }
        }

        if(player1.lives != 0) game_view[player1.y][player1.x] = 'P';

        //set the game view
        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 50; j++)
            {
                if(game_view[1 + i][1 + j] == 'P')
                {
                    main_screen[11 + i][25 + 2 * j] = 219;
                    main_screen[11 + i][25 + 2 * j + 1] = 219;
                }
                else if(snake1.chase_time == 0 && tetris1.deploy_delay && block_layer[1 + i][1 + j] == 'B')
                {
                    int mode[2] = {176, 178};

                    main_screen[11 + i][25 + 2 * j] = mode[tetris1.deploy_delay % 2];
                    main_screen[11 + i][25 + 2 * j + 1] = mode[tetris1.deploy_delay % 2];
                }
                else if(game_view[1 + i][1 + j] == 'U' || game_view[1 + i][1 + j] == 'D')
                {
                    main_screen[11 + i][25 + 2 * j] = 222;
                    main_screen[11 + i][25 + 2 * j + 1] = 221;
                }
                else if(game_view[1 + i][1 + j] == 'L' || game_view[1 + i][1 + j] == 'R')
                {
                    main_screen[11 + i][25 + 2 * j] = 254;
                    main_screen[11 + i][25 + 2 * j + 1] = 254;
                }
                else if(game_view[1 + i][1 + j] == 'S')
                {
                    char mode[2] = {178, 177};

                    if(logic_map[i + 1][j + 1] == 1)
                    {
                        main_screen[11 + i][25 + 2 * j] = 219;
                        main_screen[11 + i][25 + 2 * j + 1] = 219;
                    }
                    else
                    {
                        main_screen[11 + i][25 + 2 * j] = mode[snake1.cooldown_time % 2];
                        main_screen[11 + i][25 + 2 * j + 1] = mode[snake1.cooldown_time % 2];
                    }
                }
                else if(game_view[1 + i][1 + j] == 'B')
                {
                    main_screen[11 + i][25 + 2 * j] = '[';
                    main_screen[11 + i][25 + 2 * j + 1] = ']';
                }
                else
                {
                    main_screen[11 + i][25 + 2 * j] = ' ';
                    main_screen[11 + i][25 + 2 * j + 1] = ' ';
                }
            }
        }

        //respawn animation
        if(player1.respawn)
        {
            snake_spinoff_block_fade(player1.x, player1.y);
            player1.respawn = 0;
        }

        //player status update
        for(int k = 0; k < 2 * player1.lives; k += 2)
        {
            main_screen[9][40 + k] = 31;
        }

        for(int k = 2 * player1.lives; k < 10; k += 2)
        {
            main_screen[9][40 + k] = ' ';
        }

        if(player1.bullet_count)
        {
            for(int k = 0; k < 2 * player1.bullet_count; k += 2)
            {
                main_screen[9][111 + k] = 219;
            }

            for(int k = 2 * player1.bullet_count; k < 12; k += 2)
            {
                main_screen[9][111 + k] = ' ';
            }
        }
        else
        {
            main_screen[9][111] = 'R';
            main_screen[9][113] = 'E';
            main_screen[9][115] = 'L';
            main_screen[9][117] = 'O';
            main_screen[9][119] = 'A';
            main_screen[9][121] = 'D';
        }

        show_main_screen();

        //game over
        if(player1.lives == 0) return 0;
        if(snake1.dead)
        {
            snake_spinoff_block_fade(snake1.hx, snake1.hy);

            main_screen[10 + snake1.hy][23 + 2 * snake1.hx] = 'X';
            main_screen[10 + snake1.hy][24 + 2 * snake1.hx] = 'X';

            delay(555555555);
            return 1;
        }

        //navigation
        if(navigation_delay == 10)
        {
            //move player
            if(GetAsyncKeyState(VK_UP) & 0x8000)
            {
                if(background[player1.y - 1][player1.x] == ' ')
                {
                    (player1.y)--;
                }
            }
            else if(GetAsyncKeyState(VK_DOWN) & 0x8000)
            {
                if(background[player1.y + 1][player1.x] == ' ')
                {
                    (player1.y)++;
                }
            }
            else if(GetAsyncKeyState(VK_LEFT) & 0x8000)
            {
                if(background[player1.y][player1.x - 1] == ' ')
                {
                    (player1.x)--;
                }
            }
            else if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
            {
                if(background[player1.y][player1.x + 1] == ' ')
                {
                    (player1.x)++;
                }
            }
            else if(GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            {
                int feedback = ingame_menu_screen();

                if(feedback == 1) return -1;
            }

            //shoot bullet
            if(player1.bullet_count != 0)
            {
                if(GetAsyncKeyState((unsigned short)'W') & 0x8000)
                {
                    if(bullet_layer[player1.y - 1][player1.x] == ' ' && bullet_layer[player1.y - 2][player1.x] == ' ')
                    {
                        bullet_layer[player1.y - 1][player1.x] = 'U';
                        player1.bullet_count--;
                    }
                }
                else if(GetAsyncKeyState((unsigned short)'S') & 0x8000)
                {
                    if(bullet_layer[player1.y + 1][player1.x] == ' ' && bullet_layer[player1.y + 2][player1.x] == ' ')
                    {
                        bullet_layer[player1.y + 1][player1.x] = 'D';
                        player1.bullet_count--;
                    }
                }
                else if(GetAsyncKeyState((unsigned short)'A') & 0x8000)
                {
                    if(bullet_layer[player1.y][player1.x - 1] == ' ' && bullet_layer[player1.y][player1.x - 2] == ' ')
                    {
                        bullet_layer[player1.y][player1.x - 1] = 'L';
                        player1.bullet_count--;
                    }
                }
                else if(GetAsyncKeyState((unsigned short)'D') & 0x8000)
                {
                    if(bullet_layer[player1.y][player1.x + 1] == ' ' && bullet_layer[player1.y][player1.x + 2] == ' ')
                    {
                        bullet_layer[player1.y][player1.x + 1] = 'R';
                        player1.bullet_count--;
                    }
                }
            }

            //reload bullet
            if(GetAsyncKeyState((unsigned short)'R') & 0x8000)
            {
                player1.bullet_count = 6;
            }

            navigation_delay = 0;
        }
        else navigation_delay++;

        //setting the snake movement speed according to the distance
        int duration = 20;

        if(abs(snake1.hx - player1.x) < 3 && abs(snake1.hy - player1.y) < 5) duration = 10;
        else if(abs(snake1.hx - player1.x) < 9 && abs(snake1.hy - player1.y) < 15) duration = 15;

        if(snake1.chase_time)
        {
            snake1.chase_time--;

            //moving the snake
            if(snake_movement_delay >= duration)
            {
                //setting next target position
                int tx, ty;

                if(duration == 10)
                {
                    tx = player1.x;
                    ty = player1.y;
                }
                else
                {
                    tx = player1.x - 1 + (rand() % 3);
                    ty = player1.y - 1 + (rand() % 3);

                    while(logic_map[ty][tx] != 0)
                    {
                        tx = player1.x - 1 + (rand() % 3);
                        ty = player1.y - 1 + (rand() % 3);
                    }
                }

                //getting the next move
                int next_move = snake_spinoff_get_next_move(snake1.hx, snake1.hy, tx, ty, logic_map);

                //snake direction navigation
                if(next_move == 0) snake1.direction = 0;
                else if(next_move == 1) snake1.direction = 1;
                else if(next_move == 2) snake1.direction = 2;
                else if(next_move == 3) snake1.direction = 3;

                int prev_hx = snake1.hx;
                int prev_hy = snake1.hy;

                if(snake1.direction == 0) snake1.hy--;
                else if(snake1.direction == 1) snake1.hy++;
                else if(snake1.direction == 2) snake1.hx--;
                else if(snake1.direction == 3) snake1.hx++;

                if(logic_map[snake1.hy][snake1.hx] == -1)
                {
                    if(snake1.direction == 0) snake1.hy = 30;
                    else if(snake1.direction == 1) snake1.hy = 1;
                    else if(snake1.direction == 2) snake1.hx = 50;
                    else if(snake1.direction == 3) snake1.hx = 1;
                }

                if(logic_map[snake1.hy][snake1.hx] != 0)
                {
                    snake1.hx = prev_hx;
                    snake1.hy = prev_hy;

                    snake1.hit_obstacle = 1;
                }
                else if(snake1.hx == player1.x && snake1.hy == player1.y)
                {
                    for(int i = 0; i < 32; i++)
                    {
                        for(int j = 0; j < 52; j++)
                        {
                            if(logic_map[i][j] > 0) logic_map[i][j]++;
                        }
                    }

                    logic_map[snake1.hy][snake1.hx] = 1;

                    snake1.length++;
                    snake1.hitpoint += 50;

                    player1.hit = 1;
                    player1.lives--;
                }
                else
                {
                    for(int i = 0; i < 32; i++)
                    {
                        for(int j = 0; j < 52; j++)
                        {
                            if(logic_map[i][j] == snake1.length) logic_map[i][j] = 0;
                            else if(logic_map[i][j] > 0) logic_map[i][j]++;
                        }
                    }

                    logic_map[snake1.hy][snake1.hx] = 1;
                }

                snake_movement_delay = 0;
            }
            else snake_movement_delay++;
        }
        else
        {
            snake1.cooldown_time--;

            if(snake1.cooldown_time == 0)
            {
                snake1.chase_time = 10000;
                snake1.cooldown_time = 5000;
            }
        }

        //updating snake status
        for(int i = 0; i < 32; i++)
        {
            for(int j = 0; j < 52; j++)
            {
                if(logic_map[i][j] > 0) background[i][j] = 'S';
                else if(logic_map[i][j] == 0) background[i][j] = ' ';
            }
        }

        //moving the bullets
        if(bullet_move_delay == 10)
        {
            for(int i = 0; i < 32; i++)
            {
                for(int j = 0; j < 52; j++)
                {
                    if(bullet_layer[i][j] == 'U')
                    {
                        bullet_layer[i][j] = ' ';

                        if(bullet_layer[i - 1][j] == ' ') bullet_layer[i - 1][j] = 'U';
                    }
                    else if(bullet_layer[i][j] == 'L')
                    {
                        bullet_layer[i][j] = ' ';

                        if(bullet_layer[i][j - 1] == ' ') bullet_layer[i][j - 1] = 'L';
                    }
                }
            }

            for(int i = 31; i >= 0; i--)
            {
                for(int j = 51; j >= 0; j--)
                {
                    if(bullet_layer[i][j] == 'D')
                    {
                        bullet_layer[i][j] = ' ';

                        if(bullet_layer[i + 1][j] == ' ') bullet_layer[i + 1][j] = 'D';
                    }
                    else if(bullet_layer[i][j] == 'R')
                    {
                        bullet_layer[i][j] = ' ';

                        if(bullet_layer[i][j + 1] == ' ') bullet_layer[i][j + 1] = 'R';
                    }
                }
            }

            bullet_move_delay = 0;
        }
        else bullet_move_delay++;

        //adding tetris block
        if(snake1.chase_time == 0)
        {
            //detecting player movement
            tetris1.x = player1.x;
            tetris1.y = player1.y;

            if(tetris1.shadow_duration)
            {
                tetris1.shadow_duration--;

                //positioning the block shadow
                snake_spinoff_set_block_shadow(&tetris1, block_layer);
            }
            else if(tetris1.deploy_delay)
            {
                tetris1.deploy_delay--;

                if(tetris1.deploy_delay == 0)
                {
                    //deploying the block
                    for(int i = 0; i < 32; i++)
                    {
                        for(int j = 0; j < 52; j++)
                        {
                            if(block_layer[i][j] == 'B')
                            {
                                if(player1.y == i && player1.x == j)
                                {
                                    if(!player1.hit)
                                    {
                                        player1.hit = 1;
                                        player1.lives--;
                                    }
                                }

                                if(background[i][j] == 'B') background[i][j] = ' ';
                                else if(background[i][j] == 'S')
                                {
                                    if(logic_map[i][j] == 1) snake1.hitpoint -= 5;
                                    else snake1.hitpoint -= 1;
                                }
                                else
                                {
                                    background[i][j] = 'B';
                                    logic_map[i][j] = -2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                tetris_fall_delay++;

                if(tetris_fall_delay == 1500)
                {
                    tetris1.shadow_duration = 900;
                    tetris1.deploy_delay = 100;

                    tetris1.type = rand() % 4;

                    tetris_fall_delay = 0;
                }
            }
        }
    }

    return 0;
}
