#pragma once

#include <iostream>
#include <fstream>

#include "device_utility.hpp"
#include "screen_utility.hpp"

class InGameMenu
{
    private:

        static Keyboard* keyboard;
        static int button_cnt;

        static void setup()
        {
            keyboard = new Keyboard();
        }

        static void dump()
        {
            delete keyboard;
            system("cls");
        }

        static char set_character(const char ch)
        {
            if(ch == '0') return ' ';
            else if(ch == '#') return 219;
            else if(ch == '$') return 177;
            else if(ch == '%') return 176;
            else if(ch == '*') return 222;
            else if(ch == '*') return 222;
            else if(ch == 'a') return 179;
            else if(ch == 'b') return 196;
            else if(ch == 'c') return 186;
            else if(ch == 'd') return 205;
            else if(ch == 'e') return 218;
            else if(ch == 'f') return 191;
            else if(ch == 'g') return 192;
            else if(ch == 'h') return 217;
            else if(ch == 'i') return 201;
            else if(ch == 'j') return 187;
            else if(ch == 'k') return 200;
            else if(ch == 'l') return 188;
            else if(ch == 'm') return 202;
            else if(ch == 'n') return 185;
            else if(ch == 'o') return 203;
            else if(ch == 'p') return 197;
            else return ch;
        }

        static void set_buttons(Screen& ingame_menu_screen)
        {
            int button_h, button_w, pos_x, pos_y;

            //5x23
            button_h = 5;
            button_w = 23;

            char button1[button_h][button_w + 1] =
            {
                "###0###0###0#0#0#0#0###",
                "#0#0#000#000#0#0###0#00",
                "##00##000#00#0#0#0#0##0",
                "#0#0#00000#0#0#0#0#0#00",
                "#0#0###0###0###0#0#0###"
            };

            pos_x = 11;
            pos_y = 29;

            for(int i = 0; i < button_h; i++)
            {
                for(int j = 0; j < button_w; j++)
                {
                    ingame_menu_screen.set_pixel(pos_x + j, pos_y + i, set_character(button1[i][j]));
                }
            }

            //5x32
            button_h = 5;
            button_w = 32;

            char button2[button_h][button_w + 1] =
            {
                "#0#0###0###0###00#0#0###0###0#0#",
                "###0#0#00#00#0#00###0#000#0#0#0#",
                "#0#0###00#00#0#00#0#0##00#0#0#0#",
                "#0#0#0#00#00#0#00#0#0#000#0#0#0#",
                "#0#0#0#0###0#0#00#0#0###0#0#0###"
            };

            pos_x = 11;
            pos_y = 39;

            for(int i = 0; i < button_h; i++)
            {
                for(int j = 0; j < button_w; j++)
                {
                    ingame_menu_screen.set_pixel(pos_x + j, pos_y + i, set_character(button2[i][j]));
                }
            }
        }

        static void set_highlighter(Screen& ingame_menu_screen, int hl_idx)
        {
            if(hl_idx == 0) ingame_menu_screen.set_tab_style02(9, 27, 23, 5);
            else ingame_menu_screen.set_tab_style02(9, 37, 32, 5);
        }

        static void set_screen(Screen& ingame_menu_screen, int hl_idx)
        {
            ingame_menu_screen.clean();

            ingame_menu_screen.set_tab_style00(0, 0, 148, 51);

            set_buttons(ingame_menu_screen);

            set_highlighter(ingame_menu_screen, hl_idx);
        }

        static bool navigation(Screen& ingame_menu_screen, int& hl_idx)
        {
            system("pause>nul");

            keyboard->checkKeyState();

            if(keyboard->getKey(Keyboard::UP_ARROW).isPressed())
            {
                hl_idx = (button_cnt - (hl_idx - 1)) % button_cnt;

                set_screen(ingame_menu_screen, hl_idx);
            }
            else if(keyboard->getKey(Keyboard::DOWN_ARROW).isPressed())
            {
                hl_idx = (hl_idx + 1) % button_cnt;

                set_screen(ingame_menu_screen, hl_idx);
            }
            else if(keyboard->getKey(Keyboard::ENTER).isPressed())
            {
                return false;
            }

            return true;
        }

    public:

        static bool run()
        {
            setup();

            int hl_idx = 0;
            Screen ingame_menu_screen(150, 53);
            set_screen(ingame_menu_screen, hl_idx);

            bool is_running = true;

            while(is_running)
            {
                ingame_menu_screen.show();
                is_running = navigation(ingame_menu_screen, hl_idx);
            }

            dump();

            if(hl_idx == 0) return true;
            else return false;
        }
};

Keyboard* InGameMenu::keyboard = NULL;
int InGameMenu::button_cnt = 2;
