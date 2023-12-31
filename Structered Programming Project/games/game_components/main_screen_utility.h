#pragma once

#include <stdio.h>
#include <time.h>
#include <windows.h>

#define MAIN_SCREEN_WIDTH 150
#define MAIN_SCREEN_HEIGHT 50

#define MAIN_SCREEN_BORDER 177
#define EMPTY_SPACE 32

void window_fullscreen(void);

char main_screen[MAIN_SCREEN_HEIGHT][MAIN_SCREEN_WIDTH + 1];

void initialize_main_screen(void);
void clear_main_screen(int x, int y, int w, int h);

void setGameViewport(int x, int y, int w, int h);
void setGameInstructionTab(int x, int y, int w, int h);
void setGameAccessoryTab(int x, int y, int w, int h);

void setMessageBox(int x, int y, int w, int h);

void show_main_screen(void);
void show_error_screen(void);

void resetCursorPosition(void);

void delay(int delay_length);

void pressEnterToContinue(void);

void transition(void);
