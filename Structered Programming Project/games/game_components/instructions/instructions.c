#pragma once

#include "instructions.h"
#include "text_screen_utility.c"

int instruction_index = 0;

void auto_instruction_view(void)
{
    switch(instruction_index)
    {
        case 0:
            instruction_pingpong();
            break;

        case 1:
            instruction_collect_and_escape_part_01();
            break;

        case 2:
            instruction_collect_and_escape_part_02();
            break;

        case 3:
            instruction_collect_and_escape_part_03();
            break;

        case 4:
            instruction_collect_and_escape_part_04();
            break;

        case 5:
            instruction_tower_defence();
            break;

        case 6:
            instruction_maze();
            break;

        case 7:
            instruction_mixmatch();
            break;

        case 8:
            instruction_fps();
            break;

        case 9:
            instruction_run();
            break;

        case 10:
            instruction_spacewar();
            break;

        case 11:
            instruction_snake_spinoff();
            break;
    }
}

void instruction_pingpong(void)
{
    initialize_main_screen();

    char instruction[11][90];

    FILE *fp = fopen("text_components/game_instructions/instruction_pingpong.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 11; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            main_screen[18 + i][28 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_collect_and_escape_part_01(void)
{
    initialize_main_screen();

    char instruction[90];

    FILE *fp = fopen("text_components/game_instructions/instruction_collect_and_escape_part_01.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int j = 0; j < 90; j++)
    {
        fscanf(fp, "%c", &instruction[j]);
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int j = 0; j < 90; j++)
    {
        main_screen[23][32 + j] = instruction[j];

        if(skip == 0)
        {
            show_main_screen();
            delay(19999999);
        }

        if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_collect_and_escape_part_02(void)
{
    initialize_main_screen();

    char instruction[3][90];

    FILE *fp = fopen("text_components/game_instructions/instruction_collect_and_escape_part_02.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            main_screen[22 + i][28 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_collect_and_escape_part_03(void)
{
    initialize_main_screen();

    char instruction[10][90];

    FILE *fp = fopen("text_components/game_instructions/instruction_collect_and_escape_part_03.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            main_screen[19 + i][28 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_collect_and_escape_part_04(void)
{
    initialize_main_screen();

    char instruction[8][90];

    FILE *fp = fopen("text_components/game_instructions/instruction_collect_and_escape_part_04.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            main_screen[19 + i][28 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_tower_defence(void)
{
    initialize_main_screen();

    char instruction[8][90];

    FILE *fp = fopen("text_components/game_instructions/instruction_tower_defence.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            main_screen[18 + i][28 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_mixmatch(void)
{
    initialize_main_screen();

    char instruction[25][90];

    FILE *fp = fopen("text_components/game_instructions/instruction_mixmatch.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 90; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            main_screen[11 + i][28 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_spacewar(void)
{
    initialize_main_screen();

    char instruction[13][90];

    FILE *fp = fopen("text_components/game_instructions/instruction_spacewar.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 90; j++)
        {
            main_screen[18 + i][28 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_maze(void)
{
    initialize_main_screen();

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    char sprite[4][3][29] =
    {
        {
            "                    |?  ?|  ",
            " |?!!?|  |?$**$?|  |?!++!?| ",
            " ddIObb  %%-S1-%%  %%-MO-%% "
        },
        {
            "                            ",
            "  []   ()   ;:;:  ;;;;   K  ",
            "                            "
        },
        {
            "                            ",
            "  /\\   t  p   x   C  c   ###",
            "                  O:;O      "
        },
        {
            "            #               ",
            "   ##<>##   ^     ##G1##    ",
            "            #               "
        }
    };

    for(int k = 0; k < 4; k++)
    {
        int start_y;

        if(k == 0) start_y = 4;
        else if(k == 1) start_y = 11;
        else if(k == 2) start_y = 18;
        else if(k == 3) start_y = 25;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 28; j++)
            {
                        if(sprite[k][i][j] == '#')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 219;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 219;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 177;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 177;
                        }
                        else if(sprite[k][i][j] == '<')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 205;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 187;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 197;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 182;
                        }
                        else if(sprite[k][i][j] == '>')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 201;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 205;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 199;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 197;
                        }
                        else if(sprite[k][i][j] == '^')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 198;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 181;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 200;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 188;
                        }
                        else if(sprite[k][i][j] == 'G')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 205;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 203;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 191;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 215;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 205;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 187;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 218;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 186;
                        }
                        else if(sprite[k][i][j] == '[')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = ']';
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 220;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 222;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 187;
                        }
                        else if(sprite[k][i][j] == ']')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 220;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = '[';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 201;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 221;
                        }
                        else if(sprite[k][i][j] == '(')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 218;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 220;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 222;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 200;
                        }
                        else if(sprite[k][i][j] == ')')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 220;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 191;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 187;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 221;
                        }
                        else if(sprite[k][i][j] == '/')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 219;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 219;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 219;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = '>';
                        }
                        else if(sprite[k][i][j] == '\\')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 219;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 219;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = '<';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 219;
                        }
                        else if(sprite[k][i][j] == 't')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 219;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 220;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 219;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 223;
                        }
                        else if(sprite[k][i][j] == 'p')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 220;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 219;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 223;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 219;
                        }
                        else if(sprite[k][i][j] == 'x')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 219;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 219;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 221;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 222;
                        }
                        else if(sprite[k][i][j] == 'K')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 219;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 223;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 219;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 222;
                        }
                        else if(sprite[k][i][j] == 'C')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 220;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = ' ';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = sprite[k][i + 1][j];
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 219;

                                i++;

                                main_screen[start_y + (2 * i)][47 + (2 * j)] = 219;
                                main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 219;
                                main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 177;
                                main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 221;

                                i--;
                        }
                        else if(sprite[k][i][j] == 'c')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = ' ';
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 220;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 219;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = sprite[k][i + 1][j];

                                i++;

                                main_screen[start_y + (2 * i)][47 + (2 * j)] = 219;
                                main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 219;
                                main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 222;
                                main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 177;

                                i--;
                        }
                        else if(sprite[k][i][j] == '|')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = '.';
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 196;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 221;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 178;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 196;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = '.';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 178;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 179;
                        }
                        else if(sprite[k][i][j] == '!')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 205;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 205;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 178;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 178;
                        }
                        else if(sprite[k][i][j] == '?')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = '.';
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 196;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 179;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 178;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 196;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = '.';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 178;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 222;
                        }
                        else if(sprite[k][i][j] == '+')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = '.';
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = ' ';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 186;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 191;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = ' ';
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = '.';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 218;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 186;
                        }
                        else if(sprite[k][i][j] == '$')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 218;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 196;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 191;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 218;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 191;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = ' ';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 218;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 196;
                        }
                        else if(sprite[k][i][j] == '*')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = ' ';
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 218;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 218;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 196;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 196;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 191;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 191;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 218;
                        }
                        else if(sprite[k][i][j] == 'd')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 211;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 191;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 222;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 220;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 191;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 213;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = '/';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 223;
                        }
                        else if(sprite[k][i][j] == 'b')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 184;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 218;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 223;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = '\\';

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 218;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 189;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 220;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 221;
                        }
                        else if(sprite[k][i][j] == '%')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 198;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 220;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 221;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 220;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 220;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 181;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 220;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 222;
                        }
                        else if(sprite[k][i][j] == '-')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 220;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 220;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 196;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 196;
                        }
                        else if(sprite[k][i][j] == 'M')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 213;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 196;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = '\\';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 176;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 196;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 184;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 176;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = '/';
                        }
                        else if(sprite[k][i][j] == 'S')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = '/';
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 176;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 222;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 220;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 176;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = '\\';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 220;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 221;
                        }
                        else if(sprite[k][i][j] == 'I')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 191;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 205;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = '\\';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 176;

                            j++;

                            main_screen[start_y + (2 * i)][47 + (2 * j)] = 205;
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = 218;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 176;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = '/';
                        }
                        else if(sprite[k][i][j] == ';')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = ' ';
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = ' ';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 176;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 176;
                        }
                        else if(sprite[k][i][j] == ':')
                        {
                            main_screen[start_y + (2 * i)][47 + (2 * j)] = ' ';
                            main_screen[start_y + (2 * i)][47 + (2 * j) + 1] = ' ';
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j)] = 178;
                            main_screen[start_y + (2 * i) + 1][47 + (2 * j) + 1] = 178;
                        }
            }
        }
    }

    char sprite_name[4][57] =
    {
        "   database pc     security room pc    control room pc  ",
        "   player    enemy   detector line  enemy view  gatepass",
        "  detector  built-in-wall detector   cameras       wall ",
        "         normal doors            database room doors    "
    };

    for(int k = 0; k < 56; k++)
    {
        main_screen[10][47 + k] = sprite_name[0][k];
        main_screen[17][47 + k] = sprite_name[1][k];
        main_screen[24][47 + k] = sprite_name[2][k];
        main_screen[31][47 + k] = sprite_name[3][k];
    }

    char instruction[11][93];

    FILE *fp = fopen("text_components/game_instructions/instruction_maze.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 93; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 93; j++)
        {
            main_screen[33 + i][29 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_fps(void)
{
    initialize_main_screen();

    char instruction[18][84];

    FILE *fp = fopen("text_components/game_instructions/instruction_fps.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 18; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 18; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            main_screen[14 + i][35 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_run(void)
{
    initialize_main_screen();

    char instruction[5][86];

    FILE *fp = fopen("text_components/game_instructions/instruction_run.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 86; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 86; j++)
        {
            main_screen[21 + i][34 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}

void instruction_snake_spinoff(void)
{
    initialize_main_screen();

    char instruction[12][86];

    FILE *fp = fopen("text_components/game_instructions/instruction_snake_spinoff.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 86; j++)
        {
            fscanf(fp, "%c", &instruction[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    text_screen_opening_sequence(0);

    for(int k = 0; k < 16; k++)
    {
        main_screen[3][66 + k] = "[ INSTRUCTIONS ]"[k];
    }

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 86; j++)
        {
            main_screen[18 + i][34 + j] = instruction[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(GetAsyncKeyState(VK_SPACE) & 0x8000) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(0);
}
