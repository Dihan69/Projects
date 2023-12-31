#pragma once

#include <iostream>
#include <cmath>

#include "screen_utility.hpp"

class DrawUtil
{
    public:

        static const double thetaToRadConst;

        static void fix_angle(float& theta)
        {
            if(theta < 0) theta = 360 - (abs(theta) - (((int)abs(theta) / 360) * 360));
            if(theta > 360) theta = theta - (((int)theta / 360) * 360);
        }

        static void drawPoint_C(Screen& canvas, float x, float y, char border)
        {
            canvas.set_pixel((int)x, (int)y, border);
        }

        static void drawPoint_DA(Screen& canvas, float r, float theta, char border)
        {
            fix_angle(theta);

            float x = r * cos(theta * thetaToRadConst);
            float y = r * sin(theta * thetaToRadConst);

            drawPoint_C(canvas, x, y, border);
        }

        static void drawLine_2P(Screen& canvas, float x1, float y1, float x2, float y2, char border)
        {
            float xUnit = (x2 - x1) * 0.001;
            float yUnit = (y2 - y1) * 0.001;

            for(float dy = 0, dx = 0, cnt = 0; cnt <= 1001; dy += yUnit, dx += xUnit, cnt++)
            {
                drawPoint_C(canvas, x1 + dx, y1 + dy, border);
            }
        }

        static void drawLine_PDA(Screen& canvas, float x, float y, float d, float theta, char border)
        {
            fix_angle(theta);

            float xUnit = d * cos(theta * thetaToRadConst) * 0.001;
            float yUnit = d * sin(theta * thetaToRadConst) * 0.001;

            for(float dy = 0, dx = 0, cnt = 0; cnt <= 1001; dy += yUnit, dx += xUnit, cnt++)
            {
                drawPoint_C(canvas, x + dx, y + dy, border);
            }
        }

        static void drawLine_2DA(Screen& canvas, float d1, float theta1, float d2, float theta2, char border)
        {
            fix_angle(theta1);
            fix_angle(theta2);

            float x = d1 * cos(theta1 * thetaToRadConst);
            float y = d1 * sin(theta1 * thetaToRadConst);

            float xUnit = d2 * cos(theta2 * thetaToRadConst) * 0.001;
            float yUnit = d2 * sin(theta2 * thetaToRadConst) * 0.001;

            for(float dy = 0, dx = 0, cnt = 0; cnt <= 1001; dy += yUnit, dx += xUnit, cnt++)
            {
                drawPoint_C(canvas, x + dx, y + dy, border);
            }
        }

        static void customFloodFill(Screen& canvas, int x, int y, char fill_type, char border_type)
        {
            if(x < 0 || x >= canvas.get_width() || y < 0 || y >= canvas.get_height() || canvas.get_pixel(x, y) == border_type || canvas.get_pixel(x, y) == fill_type) return;

            canvas.set_pixel(x, y, fill_type);

            customFloodFill(canvas, x + 1, y, fill_type, border_type);
            customFloodFill(canvas, x - 1, y, fill_type, border_type);
            customFloodFill(canvas, x, y + 1, fill_type, border_type);
            customFloodFill(canvas, x, y - 1, fill_type, border_type);
        }

        static void shapeFill(Screen& canvas, float x, float y, char shape_fill_type, char shape_border_type)
        {
            customFloodFill(canvas, x, y, shape_fill_type, shape_border_type);
        }
};

const double DrawUtil::thetaToRadConst = (3.1416 / 180);
