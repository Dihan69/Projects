#pragma once

#include <iostream>
#include <fstream>

#include "screen_utility.hpp"
#include "file_utility.hpp"
#include "time_utility.hpp"

class StartUp
{
    private:

        static void preface()
        {
            Screen main_screen(150, 53);

            main_screen.show();
            TimeUtil::delay(0.5f);

            char text[3][27] = {"a Computer Science project",
                                "  written in C++ language ",
                                "    made by Team A.I.D.   "};

            for(int l = 0; l < 3; l++)
            {
                for(int k = 0; k < 26; k++)
                {
                    main_screen.set_pixel(62 + k, 26, text[l][k]);
                }

                main_screen.show();
                TimeUtil::delay(0.65f);

                for(int k = 25; k >= 0; k--)
                {
                    main_screen.set_pixel(62 + k, 26, ' ');
                }

                main_screen.show();
                TimeUtil::delay(0.5f);
            }
        }

        static char set_character(const char ch)
        {
            if(ch == '0') return ' ';
            else if(ch == '#') return 219;
            else if(ch == '&') return 178;
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

        static void move_animation_background(char anim_bg[], int anim_bg_h, int anim_bg_w)
        {
            int speed = 3;

            for(int i = 0; i < anim_bg_h; i++)
            {
                for(int j = 0; j < anim_bg_w - speed; j++)
                {
                    int k = j + speed;
                    if(k >= anim_bg_w) k -= anim_bg_w;

                    std::swap(anim_bg[i * anim_bg_w + j], anim_bg[i * anim_bg_w + k]);
                }
            }
        }

        static void attach_animation_background(Screen& main_screen, char anim_bg[], int anim_bg_h, int anim_bg_w)
        {
            for(int i = 0; i < anim_bg_h; i++)
            {
                for(int j = 0; j < anim_bg_w; j++)
                {
                    main_screen.set_pixel(j, i + 1, set_character(anim_bg[i * anim_bg_w + j]));
                }
            }
        }

        static void attach_title_sequence(Screen& main_screen, char title[][57], int seq_no)
        {
            for(int i = 0; i < 17; i++)
            {
                for(int j = 0; j < 4 * seq_no; j++)
                {
                    if(title[i][j] != '0') main_screen.set_pixel(j + 47, i + 17, set_character(title[i][j]));
                }
            }
        }

        static void animation()
        {
            ///loading animation
            int anim_bg_h = 51, anim_bg_w = 150;

            char animation_background[anim_bg_h * anim_bg_w];
            FileUtil::load_sprite(animation_background, 150, 51, "animation_background.txt");

            char title[17][57] =
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

            ///playing animation
            Screen main_screen(150, 53);

            for(int i = 0; i < 60; i++)
            {
                attach_animation_background(main_screen, animation_background, anim_bg_h, anim_bg_w);
                main_screen.set_tab_style00(0, 0, 148, 51);

                if(i >= 25 && i < 40) attach_title_sequence(main_screen, title, i - 25);
                else if( i >= 40) attach_title_sequence(main_screen, title, 14);

                main_screen.show();

                move_animation_background(animation_background, anim_bg_h, anim_bg_w);
                main_screen.clean();
            }

            main_screen.set_tab_style00(0, 0, 148, 51);
            main_screen.show();
            TimeUtil::delay(0.25f);
        }

    public:

        static void run()
        {
            preface();
            animation();
        }
};
