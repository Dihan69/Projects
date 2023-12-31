#include "include/Trap.h"

Trap:: Trap()
{
    height=0;
    length=0;
    trap_pos_y=0;
    trap_pos_x=0;
    direction=down;
}
void Trap::set_trap(int h, int l, Trap_Direction d, int x, int y)
{
    height=h;
    length=l;
    direction= d;
    trap_pos_x=x;
    trap_pos_y=y;

}
int Trap::get_height() const
{
    return height;
}
int Trap::get_length() const
{
    return length;
}
int Trap::get_trap_y()
{
    return trap_pos_y;
}
int Trap::get_trap_x()
{
    return trap_pos_x;
}

int Trap::get_direction() const
{
    return direction;
}
