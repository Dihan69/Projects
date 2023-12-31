#pragma once

#include <iostream>
#include <windows.h>

class ConsoleUtil
{
    private:

        static short custMaxScrDim, custMinScrDim, custScrDim;

        static void get_screen_dimension(int screen_width, int screen_height)
        {
            //getting computer monitor screen size
            const HWND deskHandle = GetDesktopWindow();

            RECT deskRect;
            GetWindowRect(deskHandle, &deskRect);

            //calculating corresponding font size
            COORD curFontsize;
            curFontsize.X = (deskRect.right / screen_width);
            curFontsize.Y = (deskRect.bottom / screen_height);

            custMaxScrDim = std::max(curFontsize.X, curFontsize.Y);
            custMinScrDim = std::min(curFontsize.X, curFontsize.Y);

            if(custMaxScrDim < 3) custMaxScrDim = 3;
            if(custMinScrDim < 3) custMinScrDim = 3;

            custScrDim = (custMaxScrDim + custMinScrDim) / 2;
        }

        static void modify_screen_dimension(short dimMod)
        {
            if(custScrDim + dimMod > custMaxScrDim) custScrDim = custMaxScrDim;
            else if(custScrDim + dimMod < custMinScrDim) custScrDim = custMinScrDim;
            else custScrDim += dimMod;
        }

    public:

        static void fullscreen()
        {
            keybd_event(VK_MENU, 0x38, 0, 0);
            keybd_event(VK_RETURN, 0x1c, 0, 0);
            keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
        }

        static void user_screen_setup(short screen_width, short screen_height, short dimMod = 0)
        {
            if(custScrDim == -1) get_screen_dimension(screen_width, screen_height);
            if(dimMod != 0) modify_screen_dimension(dimMod);

            //changing font size
            CONSOLE_FONT_INFOEX curConFontInfo;

            curConFontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
            curConFontInfo.nFont = 0;
            curConFontInfo.dwFontSize.X = custScrDim;
            curConFontInfo.dwFontSize.Y = custScrDim;
            curConFontInfo.FontFamily = 0;
            curConFontInfo.FontWeight = FW_NORMAL;
            wcscpy(curConFontInfo.FaceName, L"Consolas");

            SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &curConFontInfo);

            keep_fixed_size(screen_width, screen_height);
        }

        static void custom_screen_setup(short screen_width, short screen_height, short scrDimX, short scrDimY)
        {
            //changing font size
            CONSOLE_FONT_INFOEX curConFontInfo;

            curConFontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
            curConFontInfo.nFont = 0;
            curConFontInfo.dwFontSize.X = scrDimX;
            curConFontInfo.dwFontSize.Y = scrDimY;
            curConFontInfo.FontFamily = 0;
            curConFontInfo.FontWeight = FW_NORMAL;
            wcscpy(curConFontInfo.FaceName, L"Consolas");

            SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &curConFontInfo);

            keep_fixed_size(screen_width, screen_height);
        }

        static void keep_fixed_size(short screen_width, short screen_height)
        {
            //changing screen buffer size
            COORD curBuffSize;

            curBuffSize.X = screen_width + 1;
            curBuffSize.Y = screen_height + 1;

            SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), curBuffSize);

            //changing window size
            SMALL_RECT curWinSize;

            curWinSize.Top = 0;
            curWinSize.Left = 0;
            curWinSize.Bottom = screen_height;
            curWinSize.Right = screen_width;

            SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &curWinSize);
        }

        static void reset_cursor_position()
        {
            COORD cursorPosition;

            cursorPosition.X = 0;
            cursorPosition.Y = 0;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        }

        static void enable_mouse_input()
        {
            SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);
        }
};

short ConsoleUtil::custMaxScrDim = -1;
short ConsoleUtil::custMinScrDim = -1;
short ConsoleUtil::custScrDim = -1;
