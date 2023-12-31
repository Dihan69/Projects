#pragma once

#include "text_screen_utility.h"
#include "main_screen_utility.c"

void show_pause_screen(void)
{
    initialize_main_screen();

    setGameInstructionTab(65, 19, 14, 5);

    show_main_screen();
    delay(1555555555);

    main_screen[23][70] = 219;
    main_screen[23][71] = 219;
    show_main_screen();
    delay(1555555555);

    main_screen[23][73] = 219;
    main_screen[23][74] = 219;
    show_main_screen();
    delay(1555555555);

    main_screen[23][76] = 219;
    main_screen[23][77] = 219;
    show_main_screen();
    delay(1555555555);
}

void text_screen_opening_sequence(int type)
{
    initialize_main_screen();

    if(type == 0) setMessageBox(65, 19, 14, 5);
    else if(type == 1) setGameInstructionTab(65, 19, 14, 5);

    show_main_screen();
    delay(400000000);

    initialize_main_screen();

    if(type == 0) setMessageBox(55, 14, 34, 15);
    else if(type == 1) setGameInstructionTab(55, 14, 34, 15);

    show_main_screen();
    delay(400000000);

    initialize_main_screen();

    if(type == 0) setMessageBox(45, 9, 54, 25);
    else if(type == 1) setGameInstructionTab(45, 9, 54, 25);

    show_main_screen();
    delay(400000000);

    initialize_main_screen();

    if(type == 0) setMessageBox(26, 2, 94, 40);
    else if(type == 1) setGameInstructionTab(26, 2, 94, 40);

    show_main_screen();
    delay(400000000);
}

void text_screen_closing_sequence(int type)
{
    initialize_main_screen();

    if(type == 0) setMessageBox(26, 2, 94, 40);
    else if(type == 1) setGameInstructionTab(26, 2, 94, 40);

    show_main_screen();
    delay(400000000);

    initialize_main_screen();

    if(type == 0) setMessageBox(45, 9, 54, 25);
    else if(type == 1) setGameInstructionTab(45, 9, 54, 25);

    show_main_screen();
    delay(400000000);

    initialize_main_screen();

    if(type == 0) setMessageBox(55, 14, 34, 15);
    else if(type == 1) setGameInstructionTab(55, 14, 34, 15);

    show_main_screen();
    delay(400000000);

    initialize_main_screen();

    if(type == 0) setMessageBox(65, 19, 14, 5);
    else if(type == 1) setGameInstructionTab(65, 19, 14, 5);

    show_main_screen();
    delay(400000000);
}
