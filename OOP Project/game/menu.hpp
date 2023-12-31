#pragma once

#include <iostream>

#include "utility/device_utility.hpp"
#include "utility/screen_utility.hpp"
#include "utility/background_utility.hpp"

#include "game_logics/game_logic_ifti/src/include/GameLogic2.h"
#include "game_logics/game_logic_dihan/src/include/GameLogic.h"
#include "game_logics/game_logic_abdullah/src/include/GameLogic3.h"

class ChapterMenu
{
    private:

        static Keyboard* keyboard;
        static int cm_button_cnt;

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

        static void set_buttons(Screen& chapter_menu_screen)
        {
            int button_h, button_w, pos_x, pos_y;

            //5x32
            button_h = 5;
            button_w = 32;

            char button1[button_h][button_w + 1] =
            {
                "###0#0#0###0###0###0###0###00##0",
                "#000#0#0#0#0#0#00#00#000#0#000#0",
                "#000###0###0###00#00##00##0000#0",
                "#000#0#0#0#0#0000#00#000#0#000#0",
                "###0#0#0#0#0#0000#00###0#0#000#0"
            };

            pos_x = 11;
            pos_y = 9;

            for(int i = 0; i < button_h; i++)
            {
                for(int j = 0; j < button_w; j++)
                {
                    if(button1[i][j] != '0') chapter_menu_screen.set_pixel(pos_x + j, pos_y + i, set_character(button1[i][j]));
                }
            }

            char button2[button_h][button_w + 1] =
            {
                "###0#0#0###0###0###0###0###00###",
                "#000#0#0#0#0#0#00#00#000#0#0000#",
                "#000###0###0###00#00##00##000###",
                "#000#0#0#0#0#0000#00#000#0#00#00",
                "###0#0#0#0#0#0000#00###0#0#00###"
            };

            pos_x = 11;
            pos_y = 19;

            for(int i = 0; i < button_h; i++)
            {
                for(int j = 0; j < button_w; j++)
                {
                    if(button2[i][j] != '0') chapter_menu_screen.set_pixel(pos_x + j, pos_y + i, set_character(button2[i][j]));
                }
            }

            char button3[button_h][button_w + 1] =
            {
                "###0#0#0###0###0###0###0###00###",
                "#000#0#0#0#0#0#00#00#000#0#0000#",
                "#000###0###0###00#00##00##0000##",
                "#000#0#0#0#0#0000#00#000#0#0000#",
                "###0#0#0#0#0#0000#00###0#0#00###"
            };

            pos_x = 11;
            pos_y = 29;

            for(int i = 0; i < button_h; i++)
            {
                for(int j = 0; j < button_w; j++)
                {
                    if(button3[i][j] != '0') chapter_menu_screen.set_pixel(pos_x + j, pos_y + i, set_character(button3[i][j]));
                }
            }

            //5x15
            button_h = 5;
            button_w = 15;

            char button4[button_h][button_w + 1] =
            {
                "###0###0###0#0#",
                "#0#0#0#0#000#0#",
                "##00###0#000##0",
                "#0#0#0#0#000#0#",
                "###0#0#0###0#0#"
            };

            pos_x = 11;
            pos_y = 39;

            for(int i = 0; i < button_h; i++)
            {
                for(int j = 0; j < button_w; j++)
                {
                    if(button4[i][j] != '0') chapter_menu_screen.set_pixel(pos_x + j, pos_y + i, set_character(button4[i][j]));
                }
            }
        }

        static void set_highlighter(Screen& chapter_menu_screen, int hl_idx)
        {
            if(hl_idx != 3) chapter_menu_screen.set_tab_style02(9, 7 + (hl_idx * 10), 32, 5);
            else chapter_menu_screen.set_tab_style02(9, 37, 15, 5);
        }

        static void set_screen(Screen& chapter_menu_screen, int hl_idx)
        {
            chapter_menu_screen.set_tab_style00(0, 0, 148, 51);

            set_buttons(chapter_menu_screen);

            set_highlighter(chapter_menu_screen, hl_idx);
        }

        static bool navigation(int& hl_idx)
        {
            //system("pause>nul");

            keyboard->checkKeyState();

            if(keyboard->getKey(Keyboard::UP_ARROW).isPressed())
            {
                hl_idx--;
                if(hl_idx == -1) hl_idx += cm_button_cnt;
            }
            else if(keyboard->getKey(Keyboard::DOWN_ARROW).isPressed())
            {
                hl_idx++;
                if(hl_idx == cm_button_cnt) hl_idx -= cm_button_cnt;
            }
            else if(keyboard->getKey(Keyboard::ENTER).isPressed())
            {
                system("cls");

                if(hl_idx == 0)
                {
                    Game_logic2 level;
                    level.show_rules();
                    level.game_flow();
                }
                else if(hl_idx == 1)
                {
                    Game_logic level;
                    level.show_rules();
                    level.game_flow();
                }
                else if(hl_idx == 2)
                {
                    Game_logic3 level;
                    level.show_rules();
                    level.game_flow();
                }
                else return false;
            }

            return true;
        }

    public:

        static void run()
        {
            setup();

            int hl_idx = 0;
            Screen chapter_menu_screen(150, 53);

            Background::update();
            Background::attach(chapter_menu_screen);
            set_screen(chapter_menu_screen, hl_idx);

            bool is_running = true;

            while(is_running)
            {
                chapter_menu_screen.show();
                is_running = navigation(hl_idx);

                chapter_menu_screen.clean();
                Background::update();
                Background::attach(chapter_menu_screen);
                set_screen(chapter_menu_screen, hl_idx);
            }

            dump();
        }
};

Keyboard* ChapterMenu::keyboard = NULL;
int ChapterMenu::cm_button_cnt = 4;

class MainMenu
{
    private:

        static Keyboard* keyboard;
        static int mm_button_cnt;

        static void setup()
        {
            keyboard = new Keyboard();
            Background::setup();
        }

        static void dump()
        {
            Background::dump();
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

        static void set_title(Screen& main_menu_screen)
        {
            //17x56
            int title_h = 17;
            int title_w = 56;

            char title[title_h][title_w + 1] =
            {
                "00000000a00000000000000000000000000000000000000000000000",
                "0\\0000/bpb\\0000/0000000000000000000000000000000000000000",
                "0000/bcccccb\\0000000000000000000000000000000000000000000",
                "000i\\ebdmdbf/j000000000000000000000000000000000000000000",
                "00/\\e0000000f/\\00000000000000000000000000000000000000000",
                "00ae0\\f###e/##a0#0##00#00####0####000###000###00#####000",
                "0/da0g##00#h##d\\#0##00#0##0##0##0##0##$$$0##0##0##0##000",
                "0adc00##00#0##da#0###0#0###000##00#*#%$$$0##0000##000000",
                "bpdn00##0000##dp#0###0#00###00###0#*##%%%0##0000####0000",
                "0adc00##0##0##da#0##0##000###0####0*#####0##0000##000000",
                "0\\da0e##00#f##d/#0##0##0##0##0##0000#####0##0##0##0##000",
                "00ag0/h###g\\0###00##00#0####00##0000$#0$#00###00#####000",
                "00\\/g0000000h\\/000bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
                "000k/gbdodbh\\l0000000000bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0",
                "0000\\bcccccb/0000000000000000000000000000000000000000000",
                "0/0000\\bpb/0000\\0000000000000000000000000000000000000000",
                "00000000a00000000000000000000000000000000000000000000000"
            };

            int pos_x = 78;
            int pos_y = 6;

            for(int i = 0; i < title_h; i++)
            {
                for(int j = 0; j < title_w; j++)
                {
                    if(title[i][j] != '0') main_menu_screen.set_pixel(pos_x + j, pos_y + i, set_character(title[i][j]));
                }
            }
        }

        static void set_buttons(Screen& main_menu_screen)
        {
            int button_h, button_w, pos_x, pos_y;

            //5x15
            button_h = 5;
            button_w = 15;

            char button1[button_h][button_w + 1] =
            {
                "###0#000###0#0#",
                "#0#0#000#0#0#0#",
                "###0#000###00#0",
                "#000#000#0#00#0",
                "#000###0#0#00#0"
            };

            pos_x = 11;
            pos_y = 29;

            for(int i = 0; i < button_h; i++)
            {
                for(int j = 0; j < button_w; j++)
                {
                    if(button1[i][j] != '0') main_menu_screen.set_pixel(pos_x + j, pos_y + i, set_character(button1[i][j]));
                }
            }

            //5x15

            char button2[button_h][button_w + 1] =
            {
                "###0#0#0###0###",
                "#000#0#00#000#0",
                "##000#000#000#0",
                "#000#0#00#000#0",
                "###0#0#0###00#0"
            };

            pos_x = 11;
            pos_y = 39;

            for(int i = 0; i < button_h; i++)
            {
                for(int j = 0; j < button_w; j++)
                {
                    if(button2[i][j] != '0') main_menu_screen.set_pixel(pos_x + j, pos_y + i, set_character(button2[i][j]));
                }
            }
        }

        static void set_highlighter(Screen& main_menu_screen, int hl_idx)
        {
            main_menu_screen.set_tab_style02(9, 27 + (hl_idx * 10), 15, 5);
        }

        static void set_screen(Screen& main_menu_screen, int hl_idx)
        {
            main_menu_screen.set_tab_style00(0, 0, 148, 51);

            set_title(main_menu_screen);
            set_buttons(main_menu_screen);

            set_highlighter(main_menu_screen, hl_idx);
        }

        static bool navigation(int& hl_idx)
        {
            //system("pause>nul");

            keyboard->checkKeyState();

            if(keyboard->getKey(Keyboard::UP_ARROW).isPressed())
            {
                hl_idx--;
                if(hl_idx == -1) hl_idx += mm_button_cnt;
            }
            else if(keyboard->getKey(Keyboard::DOWN_ARROW).isPressed())
            {
                hl_idx++;
                if(hl_idx == mm_button_cnt) hl_idx -= mm_button_cnt;
            }
            else if(keyboard->getKey(Keyboard::ENTER).isPressed())
            {
                switch(hl_idx)
                {
                    case 0:
                        ChapterMenu::run();
                        break;

                    case 1:
                        return false;
                        break;
                }
            }

            return true;
        }

    public:

        static void run()
        {
            setup();

            int hl_idx = 0;
            Screen main_menu_screen(150, 53);

            Background::update();
            Background::attach(main_menu_screen);
            set_screen(main_menu_screen, hl_idx);

            bool is_running = true;

            while(is_running)
            {
                main_menu_screen.show();
                is_running = navigation(hl_idx);

                main_menu_screen.clean();
                Background::update();
                Background::attach(main_menu_screen);
                set_screen(main_menu_screen, hl_idx);
            }

            dump();
        }
};

Keyboard* MainMenu::keyboard = NULL;
int MainMenu::mm_button_cnt = 2;
