#pragma once

#include <iostream>
#include <conio.h>
#include <ctime>

#include "draw_utility.hpp"

struct BackgroundBlock
{
    float px, py;
    float vcx, vcy;
    float r;

    int v;
    float oa_pair[6][2];
};

class Background
{
    private:

        static int block_cnt;

        static BackgroundBlock* blocks;
        static Screen* background_screen;

        static int randomNumber_Int(int minNum, int maxNum)
        {
            return (minNum + (rand() % (maxNum - minNum + 1)));
        }

        static float randomNumber_Float(float minNum, float maxNum)
        {
            return (minNum + (maxNum - minNum) * ((float)rand() / RAND_MAX));
        }

        static float randomSequentialNumber_Float(int part, int div, float minNum, float maxNum)
        {
            return (minNum + ((maxNum - minNum) / div) * (part + ((float)rand() / RAND_MAX)));
        }

        static void createBlock(BackgroundBlock& any)
        {
            any.px = randomNumber_Float(0, background_screen->get_width());
            any.py = randomNumber_Float(0, background_screen->get_height());

            any.vcx = randomNumber_Float(-5, 5);
            any.vcy = randomNumber_Float(-5, 5);

            any.r = randomNumber_Float(10, 25);

            any.v = randomNumber_Int(5, 6);

            for(int i = 0; i < any.v; i++)
            {
                any.oa_pair[i][0] = randomNumber_Float(-2, 2);
                any.oa_pair[i][1] = randomSequentialNumber_Float(i, any.v, 0, 359);
            }
        }

        static void drawBlock(BackgroundBlock& any)
        {
            float x1, y1, x2, y2;

            for(int i = 0, j = 1; i < any.v; i++, j = (j + 1) % any.v)
            {
                x1 = any.px + (any.r + any.oa_pair[i][0]) * cos(any.oa_pair[i][1] * DrawUtil::thetaToRadConst);
                y1 = any.py + (any.r + any.oa_pair[i][0]) * sin(any.oa_pair[i][1] * DrawUtil::thetaToRadConst);

                x2 = any.px + (any.r + any.oa_pair[j][0]) * cos(any.oa_pair[j][1] * DrawUtil::thetaToRadConst);
                y2 = any.py + (any.r + any.oa_pair[j][0]) * sin(any.oa_pair[j][1] * DrawUtil::thetaToRadConst);

                DrawUtil::drawLine_2P(*background_screen, x1, y1, x2, y2, 176);
            }
        }

        static void updateBlock(BackgroundBlock& any)
        {
            any.px += any.vcx;
            any.py += any.vcy;

            if(any.px < -any.r)
            {
                any.px = background_screen->get_width() + any.r;
            }
            else if(any.px > background_screen->get_width() + any.r)
            {
                any.px = -any.r;
            }

            if(any.py < -any.r)
            {
                any.py = background_screen->get_height() + any.r;
            }
            else if(any.py > background_screen->get_height() + any.r)
            {
                any.py = -any.r;
            }
        }

    public:

        static void setup()
        {
            srand(time(0));

            blocks = new BackgroundBlock[block_cnt];
            background_screen = new Screen(150, 53);

            for(int i = 0; i < block_cnt; i++)
            {
                createBlock(blocks[i]);
            }
        }

        static void update()
        {
            background_screen->clean();

            for(int i = 0; i < block_cnt; i++)
            {
                drawBlock(blocks[i]);
                DrawUtil::shapeFill(*background_screen, blocks[i].px, blocks[i].py, 177, 176);
                updateBlock(blocks[i]);
            }
        }

        static void attach(Screen& main_screen)
        {
            for(int i = 0; i < main_screen.get_height(); i++)
            {
                for(int j = 0; j < main_screen.get_width(); j++)
                {
                    main_screen.set_pixel(j, i, background_screen->get_pixel(j, i));
                }
            }
        }

        static void dump()
        {
            delete[] blocks;
            delete background_screen;
        }
};

int Background::block_cnt = 5;

BackgroundBlock* Background::blocks = NULL;
Screen* Background::background_screen = NULL;
