#pragma once

#include <iostream>
#include <windows.h>

#include "console_utility.hpp"

class Screen
{
    private:

        char* pixel;
        int height, width;

    public:

        ///constructor
        Screen(int w, int h) : height(h), width(w)
        {
            pixel = new char[w * h];
            clean();
        }

        ///getter functions
        int get_height() const
        {
            return height;
        }

        int get_width() const
        {
            return width;
        }

        char get_pixel(int x, int y) const
        {
            if(x >= 0 && x < width && y >= 0 && y < height)
            {
                return pixel[y * width + x];
            }
            else return '\0';
        }

        ///setter functions
        void set_pixel(int x, int y, char c)
        {
            if(x >= 0 && x < width && y >= 0 && y < height)
            {
                pixel[y * width + x] = c;
            }
        }

        ///associated utility functions
        void clean()
        {
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    set_pixel(j, i, ' ');
                }
            }
        }

        void clean(int x1, int y1, int x2, int y2)
        {
            for(int i = y1; i <= y2; i++)
            {
                for(int j = x1; j <= x2; j++)
                {
                    set_pixel(j, i, ' ');
                }
            }
        }

        void show()
        {
            ConsoleUtil::reset_cursor_position();

            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    std::cout << get_pixel(j, i);
                }

                std::cout << "\n";
            }
        }

        void show(int x1, int y1, int x2, int y2)
        {
            ConsoleUtil::reset_cursor_position();

            for(int i = y1; i <= y2; i++)
            {
                for(int j = x1; j <= x2; j++)
                {
                    std::cout << get_pixel(j, i);
                }

                std::cout << "\n";
            }
        }

        void show_error_message(std::string em) const
        {
            std::cout << "\nERROR:[ " << em << " ]\n";
        }

        ///message boxes/tabs
        void set_tab_style00(int x, int y, int w, int h)
        {
            //main layer
            set_pixel(x, y, 218);
            set_pixel(x + w + 1, y, 191);
            set_pixel(x, y + h + 1, 192);
            set_pixel(x + w + 1, y + h + 1, 192);

            for(int i = y + 1; i < y + h + 1; i++)
            {
                set_pixel(x, i, 179);
                set_pixel(x + w + 1, i, 179);
            }

            for(int j = x + 1; j < x + w + 1; j++)
            {
                set_pixel(j, y, 196);
                set_pixel(j, y + h + 1, 196);
            }
        }

        void set_tab_style01(int x, int y, int w, int h)
        {
            //outer layer
            set_pixel(x, y, 218);
            set_pixel(x, y + ((h + 6) / 4) - 1, 192);
            set_pixel(x + ((w + 6) / 4) - 1, y, 191);

            set_pixel(x + w + 5, y + h + 5, 217);
            set_pixel(x + w + 5, y + h - ((h + 6) / 4) + 6, 191);
            set_pixel(x + w - ((w + 6) / 4) + 6, y + h + 5, 192);

            for(int j = 1; j < ((w + 6) / 4) - 1; j++)
            {
                set_pixel(x + j, y, 196);
                set_pixel(x + w - ((w + 6) / 4) + 6 + j, y + h, 196);
            }

            for(int i = 1; i < ((h + 6) / 4) - 1; i++)
            {
                set_pixel(x, y + i, 179);
                set_pixel(x + w + 5, y + h - ((h + 6) / 4) + 6 + i, 179);
            }

            set_pixel(x, y + h + 5, 178);
            set_pixel(x, y + h - ((h + 6) / 3) + 6, '/');
            set_pixel(x + ((w + 6) / 3) - 1, y + h + 5, '/');

            set_pixel(x + w + 5, y, 178);
            set_pixel(x + w + 5, y + ((h + 6) / 3) - 1, '/');
            set_pixel(x + w - ((w + 6) / 3) + 6, y, '/');

            for(int j = 1; j < ((w + 6) / 3) - 1; j++)
            {
                set_pixel(x + w - ((w + 6) / 3) + 6 + j, y, 223);
                set_pixel(x + j, y + h + 5, 220);
            }

            for(int i = 1; i < ((h + 6) / 3) - 1; i++)
            {
                set_pixel(x + w + 5, y + i, 222);
                set_pixel(x, y + h - ((h + 6) / 3) + 6 + i, 221);
            }

            //mid layer
            set_pixel(x + 1, y + 1, 201);
            set_pixel(x + w + 4, y + 1, 191);
            set_pixel(x + 1, y + h + 4, 192);
            set_pixel(x + w + 4, y + h + 4, 188);

            for(int i = y + 2; i < y + h + 4; i++)
            {
                set_pixel(x + 1, i, 178);
                set_pixel(x + w + 4, i, 178);
            }

            for(int j = x + 2; j < x + w + 4; j++)
            {
                set_pixel(j, y + 1, 177);
                set_pixel(j, y + h + 4, 177);
            }

            //inner layer
            set_pixel(x + 2, y + 2, 201);
            set_pixel(x + w + 3, y + 2, 187);
            set_pixel(x + 2, y + h + 3, 200);
            set_pixel(x + w + 3, y + h + 3, 188);

            for(int i = y + 3; i < y + h + 3; i++)
            {
                set_pixel(x + 2, i, 186);
                set_pixel(x + w + 3, i, 186);
            }

            for(int j = x + 3; j < x + w + 3; j++)
            {
                set_pixel(j, y + 2, 205);
                set_pixel(j, y + h + 3, 205);
            }
        }

        void set_tab_style02(int x, int y, int w, int h)
        {
            //outer layer
            set_pixel(x, y, 177);
            set_pixel(x + w + 3, y, 191);
            set_pixel(x, y + h + 3, 192);
            set_pixel(x + w + 3, y + h + 3, 177);

            for(int i = 1; i < h + 3; i++)
            {
                if(i <((h + 4) / 3))
                {
                    set_pixel(x, y + i, 177);
                    set_pixel(x + w + 3, y + i, 221);
                }
                else if(i > (h + 4) - ((h + 4) / 3) - 1)
                {
                    set_pixel(x, y + i, 221);
                    set_pixel(x + w + 3, y + i, 177);
                }
                else
                {
                    set_pixel(x, y + i, 221);
                    set_pixel(x + w + 3, y + i, 221);
                }
            }

            for(int j = 1; j < w + 3; j++)
            {
                if(j <((w + 4) / 3))
                {
                    set_pixel(x + j, y, 177);
                    set_pixel(x + j, y + h + 3, 220);
                }
                else if(j > (w + 4) - ((w + 4) / 3) - 1)
                {
                    set_pixel(x + j, y, 220);
                    set_pixel(x + j, y + h + 3, 177);
                }
                else
                {
                    set_pixel(x + j, y, 220);
                    set_pixel(x + j, y + h + 3, 220);
                }
            }

            //inner layer
            set_pixel(x + 1, y + 1, 218);
            set_pixel(x + w + 2, y + 1, 191);
            set_pixel(x + 1, y + h + 2, 192);
            set_pixel(x + w + 2, y + h + 2, 217);

            for(int i = y + 2; i < y + h + 2; i++)
            {
                set_pixel(x + 1, i, 179);
                set_pixel(x + w + 2, i, 179);
            }

            for(int j = x + 2; j < x + w + 2; j++)
            {
                set_pixel(j, y + 1, 196);
                set_pixel(j, y + h + 2, 196);
            }
        }

        ///destructor
        virtual ~Screen()
        {
            delete[] pixel;
        }
};
