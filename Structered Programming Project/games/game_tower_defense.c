#pragma once

#include "game_components/game_utility.c"

int tower_defense_game_difficulty = 0;

int play_tower_defense(void)
{
    //setting the game screen-------------
    initialize_main_screen();
    setGameViewport(24, 5, 96, 33);
    //------------------------------------

    char tower_defense_map[2][30][97] =
    {
        {
            "                                                                                                ",
            "                                                                                                ",
            "                                                                                                ",
            "                                                                                                ",
            "                                    11  22  3333333333333333332222222222222211111111111100000000",
            "                                              33                                                ",
            "                                    22  743   22                                                ",
            "                                        7743  11                                                ",
            "                                    33        00                                                ",
            "                                    333322110000                                                ",
            "                                    33                    33332211000033333333222222211111110000",
            "                                    33                    33        00                          ",
            "                                    33                    33  4473                              ",
            "                                    33                    33  743   22                          ",
            "                          11  22  3333        A BB        33                                    ",
            "                                    33        CC D        3333  22  11                          ",
            "                          22   374  33                    33                                    ",
            "                              3477  33                    33                                    ",
            "                          00        33                    33                                    ",
            "00001111111222222233333333000011223333                    33                                    ",
            "                                                000011223333                                    ",
            "                                                00        33                                    ",
            "                                                11  3744                                        ",
            "                                                22   374  22                                    ",
            "                                                33                                              ",
            "0000000011111111111122222222222222333333333333333333  22  11                                    ",
            "                                                                                                ",
            "                                                                                                ",
            "                                                                                                ",
            "                                                                                                "
        },
        {
            "                                              00          00                                    ",
            "                                              00          11                                    ",
            "                                              11          22                                    ",
            "                                              22          33                                    ",
            "                                    11  22  3333          33332222222222222211111111111100000000",
            "                                              33                                                ",
            "                                    22  473   22                                                ",
            "                                        7743  11                                                ",
            "                                    33        00                                                ",
            "                                    333322110000                                                ",
            "                                    33                    33332211000033333333222222211111110000",
            "                                    33                    33        00                          ",
            "                                    33                    33  4473                              ",
            "                                    33                    33  473   22                          ",
            "                          11  22  3333        A BB        33                                    ",
            "                                    33        CC D        3333  22  11                          ",
            "                          22   347  33                    33                                    ",
            "                              3477  33                    33                                    ",
            "                          00        33                    33                                    ",
            "00001111111222222233333333000011223333                    33                                    ",
            "                                                000011223333                                    ",
            "                                                00        33                                    ",
            "                                                11  3744                                        ",
            "                                                22   347  22                                    ",
            "                                                33                                              ",
            "00000000111111111111222222222222223333          3333  22  11                                    ",
            "                                    33          22                                              ",
            "                                    22          11                                              ",
            "                                    11          00                                              ",
            "                                    00          00                                              "
        }
    };

    char breach_layer[30][96];
    char pulse_layer[30][96];
    char background[30][96];

    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 96; j++)
        {
            breach_layer[i][j] = ' ';
            pulse_layer[i][j] = ' ';
            background[i][j] = ' ';
        }
    }

    int breach_per_wave = 1;

    int breachGenerationDelay = 0;
    int breachDelay = 0;
    int pulseDelay = 0;
    int gameloop=0;

    int max_health;

    if(tower_defense_game_difficulty==0)
        max_health=50;
    else
        max_health=40;
    int hitpoints = max_health;

    int target;

    if (tower_defense_game_difficulty==0)
        target=45000;
    else
        target=55000;

    int game_running = 1;

    int generation_time=1500;
    int enter_delay=150;

    //initial
    for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 96; j++)
            {
                if(tower_defense_map[tower_defense_game_difficulty][i][j] == '3' || tower_defense_map[tower_defense_game_difficulty][i][j] == 'A' || tower_defense_map[tower_defense_game_difficulty][i][j] == 'D') background[i][j] = 219;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '2') background[i][j] = 178;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '1') background[i][j] = 177;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '0') background[i][j] = 176;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '4' || tower_defense_map[tower_defense_game_difficulty][i][j] == 'C') background[i][j] = 220;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '5') background[i][j] = 221;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '6') background[i][j] = 222;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '7' || tower_defense_map[tower_defense_game_difficulty][i][j] == 'B') background[i][j] = 223;
                else background[i][j] = tower_defense_map[tower_defense_game_difficulty][i][j];
            }
        }

    for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 96; j++)
            {
                main_screen[i + 8][j + 27] = background[i][j];
            }
        }
      main_screen[38][27] = 'C';
    main_screen[38][28] = 'o';
    main_screen[38][29] = 'n';
    main_screen[38][30] = 'd';
    main_screen[38][31] = 'i';
    main_screen[38][32] = 't';
    main_screen[38][33] = 'i';
    main_screen[38][34] = 'o';
    main_screen[38][35] = 'n';
    main_screen[38][36] = ':';

        for(int k = 0; k < 85; k++)
        {
            main_screen[38][37 + k] = ' ';
        }

        for(int k = 0; k < (hitpoints*85)/max_health; k++)
        {
            main_screen[38][37 + k] = 219;
        }

          main_screen[40][27] = 'P';
    main_screen[40][28] = 'r';
    main_screen[40][29] = 'o';
    main_screen[40][30] = 'g';
    main_screen[40][31] = 'r';
    main_screen[40][32] = 'e';
    main_screen[40][33] = 's';
    main_screen[40][34] = 's';
    main_screen[40][35] = ' ';
    main_screen[40][36] = ':';


    for(int k=0; (k< (85*gameloop)/target) && k<85 ; k++)
        main_screen[40][37 + k] = 219;

    for(int k=(85*gameloop)/target ; k<85; k++)
        main_screen[40][37 + k] = ' ';

    show_main_screen();

    while(game_running)
    {
        //gameflow
        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 96; j++)
            {
                if(tower_defense_map[tower_defense_game_difficulty][i][j] == '3' || tower_defense_map[tower_defense_game_difficulty][i][j] == 'A' || tower_defense_map[tower_defense_game_difficulty][i][j] == 'D') background[i][j] = 219;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '2') background[i][j] = 178;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '1') background[i][j] = 177;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '0') background[i][j] = 176;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '4' || tower_defense_map[tower_defense_game_difficulty][i][j] == 'C') background[i][j] = 220;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '5') background[i][j] = 221;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '6') background[i][j] = 222;
                else if(tower_defense_map[tower_defense_game_difficulty][i][j] == '7' || tower_defense_map[tower_defense_game_difficulty][i][j] == 'B') background[i][j] = 223;
                else background[i][j] = tower_defense_map[tower_defense_game_difficulty][i][j];
            }
        }

        if(breachGenerationDelay == generation_time)
        {
            switch(tower_defense_game_difficulty)
            {
            case 1:
                for(int k = 0; k < breach_per_wave; k++)
                {
                    if(rand() % 3 && breach_layer[0][52 + k] == ' ' && breach_layer[0][53 + k] == ' ')
                    {
                        breach_layer[0][52 + k] = '[';
                        breach_layer[0][53 + k] = ']';
                    }

                    if(rand() % 3 && breach_layer[29][42 + k] == ' ' && breach_layer[29][43 + k] == ' ')
                    {
                        breach_layer[29][42 + k] = '[';
                        breach_layer[29][43 + k] = ']';
                    }
                }

            case 0:
                for(int k = 0; k < breach_per_wave; k++)
                {
                    if(rand() % 4 && breach_layer[6 + k][94] == ' ' && breach_layer[6 + k][95] == ' ')
                    {
                        breach_layer[6 + k][94] = '[';
                        breach_layer[6 + k][95] = ']';
                    }

                    if(rand() % 4 && breach_layer[21 + k][0] == ' ' && breach_layer[21 + k][1] == ' ')
                    {
                        breach_layer[21 + k][0] = '[';
                        breach_layer[21 + k][1] = ']';
                    }
                }
                break;
            }

            breachGenerationDelay = 0;
        }
        else breachGenerationDelay++;

        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 96; j++)
            {
                if(breach_layer[i][j] == '[')
                {
                    int core_found = 0;

                    for(int l = -1; l < 2; l++)
                    {
                        for(int k = -1; k < 3; k++)
                        {
                            if(l == 0 && k == 0) k += 2;

                            if(tower_defense_map[tower_defense_game_difficulty][i + l][j + k] == 'B' || tower_defense_map[tower_defense_game_difficulty][i + l][j + k] == 'C')
                            {
                                breach_layer[i][j] = ' ';
                                breach_layer[i][j + 1] = ' ';

                                hitpoints--;

                                core_found = 1;
                                break;
                            }
                        }

                        if(core_found) break;
                    }
                }
            }
        }

        if(breachDelay == enter_delay)
        {
            for(int i = 0; i < 15; i++)
            {
                for(int j = 48; j < 96; j++)
                {
                    if(breach_layer[i][j] == '[')
                    {
                        if(j > 48 && breach_layer[i][j - 1] == ' ' && tower_defense_map[tower_defense_game_difficulty][i][j - 1] == ' ')
                        {
                            breach_layer[i][j + 1] = ' ';

                            breach_layer[i][j - 1] = '[';
                            breach_layer[i][j] = ']';
                        }
                    }
                }
            }

            for(int i = 14; i >= 0; i--)
            {
                for(int j = 48; j < 96; j++)
                {
                    if(breach_layer[i][j] == '[')
                    {
                        if(i < 14 && breach_layer[i + 1][j] == ' ' && breach_layer[i + 1][j + 1] == ' ' && tower_defense_map[tower_defense_game_difficulty][i + 1][j] == ' ' && tower_defense_map[tower_defense_game_difficulty][i + 1][j + 1] == ' ')
                        {
                            breach_layer[i][j] = ' ';
                            breach_layer[i][j + 1] = ' ';

                            breach_layer[i + 1][j] = '[';
                            breach_layer[i + 1][j + 1] = ']';
                        }
                    }
                }
            }

            for(int i = 15; i < 30; i++)
            {
                for(int j = 47; j >= 0; j--)
                {
                    if(breach_layer[i][j] == '[')
                    {
                        if(j < 47 && breach_layer[i][j + 2] == ' ' && tower_defense_map[tower_defense_game_difficulty][i][j + 2] == ' ')
                        {
                            breach_layer[i][j] = ' ';

                            breach_layer[i][j + 1] = '[';
                            breach_layer[i][j + 2] = ']';
                        }
                    }
                }
            }

            for(int i = 15; i < 30; i++)
            {
                for(int j = 0; j < 48; j++)
                {
                    if(breach_layer[i][j] == '[')
                    {
                        if(i > 15 && breach_layer[i - 1][j] == ' ' && breach_layer[i - 1][j + 1] == ' ' && tower_defense_map[tower_defense_game_difficulty][i - 1][j] == ' ' && tower_defense_map[tower_defense_game_difficulty][i - 1][j + 1] == ' ')
                        {
                            breach_layer[i][j] = ' ';
                            breach_layer[i][j + 1] = ' ';

                            breach_layer[i - 1][j] = '[';
                            breach_layer[i - 1][j + 1] = ']';
                        }
                    }
                }
            }

            breachDelay = 0;
        }
        else breachDelay++;

        if(pulseDelay == 50)
        {
            for(int i = 0; i < 30; i++)
            {
                for(int j = 0; j < 96; j++)
                {
                    if(pulse_layer[i][j] == 'S')
                    {
                        if(i - 1 < 0 || j - 2 < 0)
                        {
                            pulse_layer[i][j] = ' ';
                            pulse_layer[i][j + 1] = ' ';
                        }
                        else if(pulse_layer[i - 1][j - 2] == ' ' && pulse_layer[i - 1][j - 1] == ' ')
                        {
                            pulse_layer[i][j] = ' ';
                            pulse_layer[i][j + 1] = ' ';

                            pulse_layer[i - 1][j - 2] = 'S';
                            pulse_layer[i - 1][j - 1] = 'S';
                        }
                    }
                    else if(pulse_layer[i][j] == 'D')
                    {
                        if(i - 1 < 0 || j + 2 > 95)
                        {
                            pulse_layer[i][j] = ' ';
                        }
                        else if(pulse_layer[i - 1][j + 2] == ' ')
                        {
                            pulse_layer[i][j] = ' ';

                            pulse_layer[i - 1][j + 2] = 'D';
                        }
                    }
                }
            }

            for(int i = 29; i >= 0; i--)
            {
                for(int j = 95; j >= 0; j--)
                {
                    if(pulse_layer[i][j] == 'W')
                    {
                        if(i + 1 > 29 || j + 2 > 95)
                        {
                            pulse_layer[i][j - 1] = ' ';
                            pulse_layer[i][j] = ' ';
                        }
                        else if(pulse_layer[i + 1][j + 1] == ' ' && pulse_layer[i + 1][j + 2] == ' ')
                        {
                            pulse_layer[i][j - 1] = ' ';
                            pulse_layer[i][j] = ' ';

                            pulse_layer[i + 1][j + 1] = 'W';
                            pulse_layer[i + 1][j + 2] = 'W';
                        }
                    }
                    else if(pulse_layer[i][j] == 'A')
                    {
                        if(i + 1 > 29 || j - 2 < 0)
                        {
                            pulse_layer[i][j] = ' ';
                        }
                        else if(pulse_layer[i + 1][j - 2] == ' ')
                        {
                            pulse_layer[i][j] = ' ';

                            pulse_layer[i + 1][j - 2] = 'A';
                        }
                    }
                }
            }

            pulseDelay = 0;
        }
        else pulseDelay++;

        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 96; j++)
            {
                if(pulse_layer[i][j] == 'W' || pulse_layer[i][j] == 'S')
                {
                    if(breach_layer[i][j] == '[' || breach_layer[i][j + 1] == ']')
                    {
                        breach_layer[i][j] = ' ';
                        breach_layer[i][j + 1] = ' ';

                        pulse_layer[i][j] = ' ';
                        pulse_layer[i][j + 1] = ' ';
                    }
                    else if(breach_layer[i][j] == ']')
                    {
                        breach_layer[i][j - 1] = ' ';
                        breach_layer[i][j] = ' ';

                        pulse_layer[i][j] = ' ';
                        pulse_layer[i][j + 1] = ' ';
                    }
                    else if(breach_layer[i][j + 1] == '[')
                    {
                        breach_layer[i][j + 1] = ' ';
                        breach_layer[i][j + 2] = ' ';

                        pulse_layer[i][j] = ' ';
                        pulse_layer[i][j + 1] = ' ';
                    }

                    j++;
                }
                else if(pulse_layer[i][j] == 'A' || pulse_layer[i][j] == 'D')
                {
                    if(breach_layer[i][j] == '[')
                    {
                        breach_layer[i][j] = ' ';
                        breach_layer[i][j + 1] = ' ';

                        pulse_layer[i][j] = ' ';
                    }
                    else if(breach_layer[i][j] == ']')
                    {
                        breach_layer[i][j - 1] = ' ';
                        breach_layer[i][j] = ' ';

                        pulse_layer[i][j] = ' ';
                    }
                }
            }
        }

        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 96; j++)
            {
                if(breach_layer[i][j] != ' ')
                {
                    background[i][j] = breach_layer[i][j];
                }
            }
        }

        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 96; j++)
            {
                if(pulse_layer[i][j] == 'S' || pulse_layer[i][j] == 'W')
                {
                    background[i][j] = '<';
                    background[i][j + 1] = '>';

                    j++;
                }
                else if(pulse_layer[i][j] == 'A' || pulse_layer[i][j] == 'D')
                {
                    background[i][j] = 'o';
                }
            }
        }

        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 96; j++)
            {
                main_screen[i + 8][j + 27] = background[i][j];
            }
        }

        for(int k = 0; k < 85; k++)
        {
            main_screen[38][37 + k] = ' ';
        }

        for(int k = 0; k < (hitpoints*85)/max_health; k++)
        {
            main_screen[38][37 + k] = 219;
        }

        for(int k=0; (k< (85*gameloop)/target) && k<85 ; k++)
            main_screen[40][37 + k] = 219;

        for(int k=(85*gameloop)/target ; k<85; k++)
            main_screen[40][37 + k] = ' ';

        show_main_screen();

        if(hitpoints <= 0) return 0;

        //navigation
        if(GetAsyncKeyState((unsigned short)'W') & 0x8000)
        {
            if(pulse_layer[8][44] == ' ' && pulse_layer[8][45] == ' ')
            {
                pulse_layer[8][44] = 'W';
                pulse_layer[8][45] = 'W';
            }
        }
        else if(GetAsyncKeyState((unsigned short)'S') & 0x8000)
        {
            if(pulse_layer[21][50] == ' ' && pulse_layer[21][51] == ' ')
            {
                pulse_layer[21][50] = 'S';
                pulse_layer[21][51] = 'S';
            }
        }
        else if(GetAsyncKeyState((unsigned short)'A') & 0x8000)
        {
            if(pulse_layer[18][29] == ' ')
            {
                pulse_layer[18][29] = 'A';
            }
        }
        else if(GetAsyncKeyState((unsigned short)'D') & 0x8000)
        {
            if(pulse_layer[11][66] == ' ')
            {
                pulse_layer[11][66] = 'D';
            }
        }
        else if(GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            int feedback = ingame_menu_screen();

            if(feedback == 1) return -1;
        }

        gameloop++;

        if(gameloop==3000)

            breach_per_wave=2;

        else if(gameloop==12000)
            breach_per_wave=3;

        if(tower_defense_game_difficulty==0 && gameloop>=target-7000)
        breach_per_wave=0;
            else if(tower_defense_game_difficulty==1 && gameloop>=target-7000)
             breach_per_wave=0;

        if(tower_defense_game_difficulty==0 && gameloop>target)
            return 1;
        else if(tower_defense_game_difficulty==1 && gameloop>=target)
            return 1;

            if(gameloop>=25000)
            {
                generation_time=1000;
                enter_delay=120;
            }
    }
}

