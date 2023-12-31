#pragma once

#include "game_components/game_utility.c"

struct
{
    int x, y;
    int current_direction;
} ping_pong_ball;

int play_ping_pong(void);

void ping_pong_initializeScreen(void);
void ping_pong_setGameView(void);

int  ping_pong_moveHBar(int j);
int ping_pong_moveVBar(int i);

int ping_pong_checkNextDirection(void);
void ping_pong_moveBall(int direction);
void ping_pong_setBallPosition(int x, int y);

    char ping_pong_lvl01g_screen[32][102];
    int ping_pong_lvl01g_screen_w = 100, ping_pong_lvl01g_screen_h = 30;
    int ping_pong_game_difficulty=0;

void ping_pong_initializeScreen(void)
{
    for (int i = 0; i < ping_pong_lvl01g_screen_h + 2; i++)
    {
        for (int j = 0; j < ping_pong_lvl01g_screen_w + 2; j++)
        {
            if (i == 0 || i == ping_pong_lvl01g_screen_h + 1 || j == 0 || j == ping_pong_lvl01g_screen_w + 1)
                ping_pong_lvl01g_screen[i][j] = 'X';
            else
                ping_pong_lvl01g_screen[i][j] = ' ';
        }
    }
}

void ping_pong_setGameView(void)
{
    for(int i = 1; i < ping_pong_lvl01g_screen_h + 1; i++)
    {
        for(int j = 1; j < ping_pong_lvl01g_screen_w + 1; j++)
        {
            main_screen[8 + i][24 + j] = ping_pong_lvl01g_screen[i][j];
        }
    }
}

int  ping_pong_moveHBar(int j)
{
    if ((GetAsyncKeyState(VK_RIGHT) & 0X8000) || (GetAsyncKeyState(0x44) & 0X8000))
    {
        if (j < ping_pong_lvl01g_screen_w - 1 && ping_pong_lvl01g_screen[1][j+1] == ' ' && ping_pong_lvl01g_screen[ping_pong_lvl01g_screen_h][j+1] == ' ')
        {
            ping_pong_lvl01g_screen[1][j - 14] = 32;
            ping_pong_lvl01g_screen[ping_pong_lvl01g_screen_h][j - 14] = 32;
            ping_pong_lvl01g_screen[1][j - 13] = 32;
            ping_pong_lvl01g_screen[ping_pong_lvl01g_screen_h][j - 13] = 32;

            for(int k = 0; k < 15; k++)
            {
                ping_pong_lvl01g_screen[1][j - 12 + k] = 219;
                ping_pong_lvl01g_screen[ping_pong_lvl01g_screen_h][j - 12 + k] = 219;
            }

            j = j + 2;
        }
    }
    else if ((GetAsyncKeyState(VK_LEFT) & 0X8000) || (GetAsyncKeyState(0x41) & 0X8000))
    {
        if (j > 2 && ping_pong_lvl01g_screen[ping_pong_lvl01g_screen_h][j - 15] == ' ' && ping_pong_lvl01g_screen[1][j - 15] == ' ')
        {
            ping_pong_lvl01g_screen[ping_pong_lvl01g_screen_h][j] = 32;
            ping_pong_lvl01g_screen[1][j] = 32;
            ping_pong_lvl01g_screen[1][j - 1] = 32;
            ping_pong_lvl01g_screen[ping_pong_lvl01g_screen_h][j - 1] = 32;

            for(int k = 0; k < 15; k++)
            {
                ping_pong_lvl01g_screen[1][j - 2 - k] = 219;
                ping_pong_lvl01g_screen[ping_pong_lvl01g_screen_h][j - 2 - k] = 219;
            }

            j = j - 2;
        }
    }
    else if(GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        int feedback = ingame_menu_screen();
        if(feedback == 1) return -1;
    }

    return j;
}

int ping_pong_moveVBar(int i)
{
    if((GetAsyncKeyState(VK_UP) & 0X8000) || (GetAsyncKeyState(0x57) & 0X8000))
    {
        if(i > 2 && ping_pong_lvl01g_screen[i-6][2] == ' ' && ping_pong_lvl01g_screen[i-6][ping_pong_lvl01g_screen_w - 1] == ' ')
        {
            ping_pong_lvl01g_screen[i][1] = 32;
            ping_pong_lvl01g_screen[i][ping_pong_lvl01g_screen_w] = 32;
            ping_pong_lvl01g_screen[i-1][1] = 32;
            ping_pong_lvl01g_screen[i-1][ping_pong_lvl01g_screen_w] = 32;

            for(int k = 0; k < 6; k++)
            {
                ping_pong_lvl01g_screen[i - 2 - k][1] = 219;
                ping_pong_lvl01g_screen[i - 2 - k][ping_pong_lvl01g_screen_w] = 219;
            }

            ping_pong_lvl01g_screen[i][2] = 32;
            ping_pong_lvl01g_screen[i][ping_pong_lvl01g_screen_w - 1] = 32;
            ping_pong_lvl01g_screen[i-1][2] = 32;
            ping_pong_lvl01g_screen[i-1][ping_pong_lvl01g_screen_w - 1] = 32;

            for(int k = 0; k < 6; k++)
            {
                ping_pong_lvl01g_screen[i - 2 - k][2] = 219;
                ping_pong_lvl01g_screen[i - 2 - k][ping_pong_lvl01g_screen_w - 1] = 219;
            }

            i = i - 2;
        }
    }
    else if((GetAsyncKeyState(VK_DOWN) & 0X8000) || (GetAsyncKeyState(0x53) & 0X8000))
    {
        if(i < ping_pong_lvl01g_screen_h - 1 && ping_pong_lvl01g_screen[i+1][2] == ' ' && ping_pong_lvl01g_screen[i+1][ping_pong_lvl01g_screen_w - 1] == ' ')
        {
            ping_pong_lvl01g_screen[i-5][1] = 32;
            ping_pong_lvl01g_screen[i-5][ping_pong_lvl01g_screen_w] = 32;
            ping_pong_lvl01g_screen[i-4][1] = 32;
            ping_pong_lvl01g_screen[i-4][ping_pong_lvl01g_screen_w] = 32;

            for(int k = 0; k < 6; k++)
            {
                ping_pong_lvl01g_screen[i - 3 + k][1] = 219;
                ping_pong_lvl01g_screen[i - 3 + k][ping_pong_lvl01g_screen_w] = 219;
            }

            ping_pong_lvl01g_screen[i-5][2] = 32;
            ping_pong_lvl01g_screen[i-5][ping_pong_lvl01g_screen_w - 1] = 32;
            ping_pong_lvl01g_screen[i-4][2] = 32;
            ping_pong_lvl01g_screen[i-4][ping_pong_lvl01g_screen_w - 1] = 32;

            for(int k = 0; k < 6; k++)
            {
                ping_pong_lvl01g_screen[i - 3 + k][2] = 219;
                ping_pong_lvl01g_screen[i - 3 + k][ping_pong_lvl01g_screen_w - 1] = 219;
            }

            i = i + 2;
        }
    }
    else if(GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        int feedback = ingame_menu_screen();
        if(feedback == 1) return -1;
    }

    return i;
}

int ping_pong_checkNextDirection(void)
{
    switch (ping_pong_ball.current_direction)
    {
    case 1:
        if ((ping_pong_lvl01g_screen[ping_pong_ball.y - 1][ping_pong_ball.x] != ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x - 1] != ' ') || (ping_pong_lvl01g_screen[ping_pong_ball.y - 1][ping_pong_ball.x] == ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x - 1] == ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y - 1][ping_pong_ball.x - 1] != ' '))
            return 4;
        else if (ping_pong_lvl01g_screen[ping_pong_ball.y - 1][ping_pong_ball.x] != ' ')
            return 3;
        else if (ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x - 1] != ' ')
            return 2;
        break;
    case 2:
        if ((ping_pong_lvl01g_screen[ping_pong_ball.y - 1][ping_pong_ball.x] != ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x + 1] != ' ') || (ping_pong_lvl01g_screen[ping_pong_ball.y - 1][ping_pong_ball.x] == ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x + 1] == ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y - 1][ping_pong_ball.x + 1] != ' '))
            return 3;
        else if (ping_pong_lvl01g_screen[ping_pong_ball.y - 1][ping_pong_ball.x] != ' ')
            return 4;
        else if (ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x + 1] != ' ')
            return 1;
        break;
    case 3:
        if ((ping_pong_lvl01g_screen[ping_pong_ball.y + 1][ping_pong_ball.x] != ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x - 1] != ' ') || (ping_pong_lvl01g_screen[ping_pong_ball.y + 1][ping_pong_ball.x] == ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x - 1] == ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y + 1][ping_pong_ball.x - 1] != ' '))
            return 2;
        else if (ping_pong_lvl01g_screen[ping_pong_ball.y + 1][ping_pong_ball.x] != ' ')
            return 1;
        else if (ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x - 1] != ' ')
            return 4;
        break;
    case 4:
        if ((ping_pong_lvl01g_screen[ping_pong_ball.y + 1][ping_pong_ball.x] != ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x + 1] != ' ') || (ping_pong_lvl01g_screen[ping_pong_ball.y + 1][ping_pong_ball.x] == ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x + 1] == ' ' && ping_pong_lvl01g_screen[ping_pong_ball.y + 1][ping_pong_ball.x + 1] != ' '))
            return 1;
        else if (ping_pong_lvl01g_screen[ping_pong_ball.y + 1][ping_pong_ball.x] != ' ')
            return 2;
        else if (ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x + 1] != ' ')
            return 3;
        break;
    }

    return ping_pong_ball.current_direction;
}

void ping_pong_moveBall(int direction)
{
    ping_pong_ball.current_direction = direction;

    switch (direction)
    {
    case 1:
        ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x] = ' ';
        ping_pong_setBallPosition(ping_pong_ball.x - 1, ping_pong_ball.y - 1);
        break;
    case 2:
        ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x] = ' ';
        ping_pong_setBallPosition(ping_pong_ball.x + 1, ping_pong_ball.y - 1);
        break;
    case 3:
        ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x] = ' ';
        ping_pong_setBallPosition(ping_pong_ball.x - 1, ping_pong_ball.y + 1);
        break;
    case 4:
        ping_pong_lvl01g_screen[ping_pong_ball.y][ping_pong_ball.x] = ' ';
        ping_pong_setBallPosition(ping_pong_ball.x + 1, ping_pong_ball.y + 1);
        break;
    }
}

void ping_pong_setBallPosition(int x, int y)
{
    ping_pong_ball.x = x;
    ping_pong_ball.y = y;

    ping_pong_lvl01g_screen[y][x] = 'O';
}

int play_ping_pong(void)
{
    //setting game screen
    initialize_main_screen();
    setGameViewport(22, 6, 100, 32);

    for(int k = 1; k < 99; k++)
    {
        main_screen[39][25 + k] = 196;
    }

    main_screen[40][25] = 'P';
    main_screen[40][26] = 'r';
    main_screen[40][27] = 'o';
    main_screen[40][28] = 'g';
    main_screen[40][29] = 'r';
    main_screen[40][30] = 'e';
    main_screen[40][31] = 's';
    main_screen[40][32] = 's';
    main_screen[40][33] = ':';

    ping_pong_initializeScreen();

    ping_pong_setBallPosition(50, 15);

    srand(time(0));
    ping_pong_ball.current_direction = (rand() % 4) + 1;

    int i, j;
    int gameover=0;

    for (j = 42; j < 57; j++)
    {
        ping_pong_lvl01g_screen[1][j] = 219;
        ping_pong_lvl01g_screen[ping_pong_lvl01g_screen_h][j] = 219;
    }

    j--;

    for (i = 13; i < 19; i++)
    {
        ping_pong_lvl01g_screen[i][2] = 219;
        ping_pong_lvl01g_screen[i][ping_pong_lvl01g_screen_w - 1] = 219;

        ping_pong_lvl01g_screen[i][1] = 219;
        ping_pong_lvl01g_screen[i][ping_pong_lvl01g_screen_w] = 219;
    }

    i--;

    int f_count = 0;

    int target;

    if(ping_pong_game_difficulty == 1)
    {
        target = 1199;
    }
    else target = 850;

    int gameloop=0;

    while (1)
    {
        if(ping_pong_game_difficulty == 0)
        {
            if(gameloop<250)
                delay(377777777);
            else if(gameloop<600)
                delay(355555555);
            else if(gameloop<850)
                delay(244444444);
            
            else break;

        }
        else if(ping_pong_game_difficulty == 1)
        {
            if(gameloop<150)
                delay(266666666);
            else if(gameloop<400)
                delay(255555555);
            else if(gameloop<700)
                delay(244444444);
            else if(gameloop<1050)
                delay(193333333);
            else if(gameloop<1200)
                delay(133333333);

            else break;
        }

        //setting game screen
        ping_pong_setGameView();

        //setting progress bar
        for(int k = 0; k < (90 * gameloop) / target; k++)
        {
            main_screen[40][35 + k] = 219;
        }

        for(int k = (90 * gameloop) / target ; k < 90; k++)
        {
            main_screen[40][35 + k] = ' ';
        }

        //showing screen
        show_main_screen();

        i = ping_pong_moveVBar(i);

        if(i == -1) return -1;

        j = ping_pong_moveHBar(j);

        if(i == -1) return -1;

        //collision detection
        gameover = 0;

        for(int k=0; k <3; k++)
        {
            for(int l = 0; l < 3; l++)
            {
                if(ping_pong_lvl01g_screen[ping_pong_ball.y - 1 + k][ping_pong_ball.x - 1 + l] == 'X')
                {
                    gameover = 1;
                }
            }
        }

        if(gameover == 1) return 0;

        ping_pong_moveBall(ping_pong_checkNextDirection());

        if(f_count == 20)
        {
            f_count = 0;

            for(int p = 6; p < 26; p++)
            {
                for (int q = 11; q < 91; q++)
                {
                    if (ping_pong_lvl01g_screen[p][q] != 'O')
                    {
                        ping_pong_lvl01g_screen[p][q] = ' ';
                    }
                }
            }

            //block generation
            for(int t = 0, x = 11, y = 6; t < 4; t++)
            {
                for(int k = 0; k < 2;)
                {
                    int m = y + (rand() % 10);
                    int n = x + (rand() % 39);

                    if(ping_pong_lvl01g_screen[m][n] == ' ' && ping_pong_lvl01g_screen[m][n+1] == ' ')
                    {
                        ping_pong_lvl01g_screen[m][n] = 219;
                        ping_pong_lvl01g_screen[m][n + 1] = 219;

                        k++;
                    }
                }

                switch(t)
                {
                case 0:
                    x += 40;
                    break;
                case 1:
                    y += 10;
                    break;
                case 2:
                    x -= 40;
                    break;
                }
            }
        }
        else f_count++;

        gameloop++;
    }

    return 1;
}
