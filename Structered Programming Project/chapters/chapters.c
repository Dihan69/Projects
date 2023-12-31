#pragma once

#include "chapters.h"
#include "text_screen_utility.c"

void story_chapter_name_view(int chapter_index)
{
    initialize_main_screen();

    setGameInstructionTab(71, 22, 4, 1);
    show_main_screen();
    delay(400000000);

    clear_main_screen(65, 21, 20, 8);
    setGameInstructionTab(65, 21, 16, 4);
    show_main_screen();
    delay(400000000);

    clear_main_screen(50, 17, 52, 16);
    setGameInstructionTab(50, 17, 48, 12);
    show_main_screen();
    delay(400000000);

    char text1[28];
    sprintf(text1, "   -  -  CHAPTER %02d  -  -  ", chapter_index);

    for(int k = 0; k < 27; k++)
    {
        main_screen[23][63 + k] = text1[k];
    }

    switch(chapter_index)
    {
        case 0:
            for(int k = 0; k < 27; k++)
            {
                main_screen[26][63 + k] = "     ... THE CAUSE ...     "[k];
            }
            break;

        case 1:
            for(int k = 0; k < 27; k++)
            {
                main_screen[26][63 + k] = "      ... THE TEST ...     "[k];
            }
            break;

        case 2:
            for(int k = 0; k < 27; k++)
            {
                main_screen[26][63 + k] = "      ... THE TRAP ...     "[k];
            }
            break;

        case 3:
            for(int k = 0; k < 27; k++)
            {
                main_screen[26][63 + k] = "     ... THE BREACH ...    "[k];
            }
            break;

        case 4:
            for(int k = 0; k < 27; k++)
            {
                main_screen[26][63 + k] = "     ... THE SEARCH ...    "[k];
            }
            break;

        case 5:
            for(int k = 0; k < 27; k++)
            {
                main_screen[26][63 + k] = "      ... THE RAID ...     "[k];
            }
            break;

        case 6:
            for(int k = 0; k < 27; k++)
            {
                main_screen[26][63 + k] = "     ... THE ESCAPE ...    "[k];
            }
            break;

        case 7:
            for(int k = 0; k < 27; k++)
            {
                main_screen[26][63 + k] = "     ... THE FLIGHT ...    "[k];
            }
            break;

        case 8:
            for(int k = 0; k < 27; k++)
            {
                main_screen[26][63 + k] = "     ... THE DREAM ...     "[k];
            }
            break;
    }

    show_main_screen();
    delay(4111111111);
    delay(4111111111);

    clear_main_screen(50, 17, 52, 16);
    setGameInstructionTab(65, 21, 16, 4);
    show_main_screen();
    delay(400000000);

    clear_main_screen(65, 21, 20, 8);
    setGameInstructionTab(71, 22, 4, 1);
    show_main_screen();
    delay(400000000);
}

void story_chapter_00(int key_input)
{
    if(key_input == 1) story_chapter_name_view(0);

    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_00.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 38; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    if(key_input == 1) show_pause_screen();

    text_screen_opening_sequence(1);

    if(key_input == 1)
    {
        for(int k = 0; k < 23; k++)
        {
            main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
        }
    }

    for(int i = 0; i < 38; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            main_screen[5 + i][33 + j] = dialogue[i][j];

            if(skip == 0)
            {
                show_main_screen();
                delay(19999999);
            }

            if(key_input == 1 && (GetAsyncKeyState(VK_SPACE) & 0x8000)) skip = 1;
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(1);
}

void story_chapter_01_part_01(void)
{
    story_chapter_name_view(1);

    initialize_main_screen();

    char dialogue[40][94];

    //A
    FILE *fp = fopen("text_components/chapters/story_chapter_01_part_01_A.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            main_screen[6 + i][33 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //B
    fp = fopen("text_components/chapters/story_chapter_01_part_01_B.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 27; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 27; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[11 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //C
    fp = fopen("text_components/chapters/story_chapter_01_part_01_C.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 34; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 34; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[4 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_01_part_02(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_01_part_02.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 35; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 35; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[6 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_02_part_01(void)
{
    story_chapter_name_view(2);

    initialize_main_screen();

    char dialogue[40][94];

    //A
    FILE *fp = fopen("text_components/chapters/story_chapter_02_part_01_A.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 38; i++)
    {
        for(int j = 0; j < 88; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 38; i++)
    {
        for(int j = 0; j < 88; j++)
        {
            main_screen[5 + i][31 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //B
    fp = fopen("text_components/chapters/story_chapter_02_part_01_B.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 38; i++)
    {
        for(int j = 0; j < 86; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 38; i++)
    {
        for(int j = 0; j < 86; j++)
        {
            main_screen[5 + i][32 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //C
    fp = fopen("text_components/chapters/story_chapter_02_part_01_C.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 34; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 34; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[7 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_02_part_02(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_02_part_02.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 37; i++)
    {
        for(int j = 0; j < 82; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 37; i++)
    {
        for(int j = 0; j < 82; j++)
        {
            main_screen[5 + i][34 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_02_part_03(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    //A
    FILE *fp = fopen("text_components/chapters/story_chapter_02_part_03_A.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[6 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //B
    fp = fopen("text_components/chapters/story_chapter_02_part_03_B.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 35; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 35; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[6 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_02_part_04(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_02_part_04.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 38; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 38; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            main_screen[5 + i][33 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_02_part_05(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_02_part_05.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 21; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 21; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[13 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_03_part_01(void)
{
    story_chapter_name_view(3);

    initialize_main_screen();

    char dialogue[40][94];

    //A
    FILE *fp = fopen("text_components/chapters/story_chapter_03_part_01_A.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 23; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 23; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[12 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //B
    fp = fopen("text_components/chapters/story_chapter_03_part_01_B.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[8 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_03_part_02(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_03_part_02.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 21; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 21; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            main_screen[13 + i][33 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_04_part_01(void)
{
    story_chapter_name_view(4);

    initialize_main_screen();

    char dialogue[40][94];

    //A
    FILE *fp = fopen("text_components/chapters/story_chapter_04_part_01_A.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 35; i++)
    {
        for(int j = 0; j < 78; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 35; i++)
    {
        for(int j = 0; j < 78; j++)
        {
            main_screen[6 + i][36 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //B
    fp = fopen("text_components/chapters/story_chapter_04_part_01_B.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 34; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 34; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            main_screen[7 + i][33 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_04_part_02(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    //A
    FILE *fp = fopen("text_components/chapters/story_chapter_04_part_02_A.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < 86; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < 86; j++)
        {
            main_screen[6 + i][32 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //B
    fp = fopen("text_components/chapters/story_chapter_04_part_02_B.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 38; i++)
    {
        for(int j = 0; j < 86; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 38; i++)
    {
        for(int j = 0; j < 86; j++)
        {
            main_screen[5 + i][33 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_05_part_01(void)
{
    story_chapter_name_view(5);

    initialize_main_screen();

    char dialogue[40][94];

    //A
    FILE *fp = fopen("text_components/chapters/story_chapter_05_part_01_A.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[16 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //B
    fp = fopen("text_components/chapters/story_chapter_05_part_01_B.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 37; i++)
    {
        for(int j = 0; j < 56; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 37; i++)
    {
        for(int j = 0; j < 56; j++)
        {
            main_screen[5 + i][47 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_05_part_02(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_05_part_02.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[17 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_06_part_01(void)
{
    story_chapter_name_view(6);

    initialize_main_screen();

    char dialogue[40][94];

    //A
    FILE *fp = fopen("text_components/chapters/story_chapter_06_part_01_A.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 37; i++)
    {
        for(int j = 0; j < 82; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 37; i++)
    {
        for(int j = 0; j < 82; j++)
        {
            main_screen[5 + i][34 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //B
    fp = fopen("text_components/chapters/story_chapter_06_part_01_B.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[8 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //C
    fp = fopen("text_components/chapters/story_chapter_06_part_01_C.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[6 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_06_part_02(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_06_part_02.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            main_screen[17 + i][33 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_07_part_01(void)
{
    story_chapter_name_view(7);

    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_07_part_01.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 27; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 27; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[10 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_07_part_02(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    //A
    FILE *fp = fopen("text_components/chapters/story_chapter_07_part_02_A.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    int skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[7 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    //B
    fp = fopen("text_components/chapters/story_chapter_07_part_02_B.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    skip = 0;

    show_pause_screen();
    text_screen_opening_sequence(1);

    for(int k = 0; k < 23; k++)
    {
        main_screen[44][62 + k] = "[ press SPACE to skip ]"[k];
    }

    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            main_screen[17 + i][35 + j] = dialogue[i][j];

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

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_08_part_01(void)
{
    srand(time(0));

    initialize_main_screen();
    transition();
    system("cls");

    initialize_main_screen();
    transition();
    system("cls");

    initialize_main_screen();
    transition();
    system("cls");

    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_08_part_01.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    text_screen_opening_sequence(1);

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < 84; j++)
        {
            main_screen[6 + i][33 + j] = dialogue[i][j];

            show_main_screen();
            delay(19999999);
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(1);

    show_pause_screen();
}

void story_chapter_08_part_02(void)
{
    initialize_main_screen();

    char dialogue[40][94];

    FILE *fp = fopen("text_components/chapters/story_chapter_08_part_02.txt", "r");

    if(fp == NULL) show_error_screen();

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 66; j++)
        {
            fscanf(fp, "%c", &dialogue[i][j]);
        }

        fscanf(fp, "%*c");
    }

    fclose(fp);

    text_screen_opening_sequence(1);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 66; j++)
        {
            main_screen[21 + i][44 + j] = dialogue[i][j];

            show_main_screen();
            delay(19999999);
        }
    }

    for(int k = 0; k < 27; k++)
    {
        main_screen[44][60 + k] = "[ press ENTER to continue ]"[k];
    }

    show_main_screen();
    pressEnterToContinue();

    text_screen_closing_sequence(1);

    show_pause_screen();

    story_chapter_name_view(8);

    initialize_main_screen();
    transition();
    system("cls");

    initialize_main_screen();
    transition();
    system("cls");
}
