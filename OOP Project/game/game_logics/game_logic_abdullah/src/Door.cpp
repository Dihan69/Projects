#include "include/Door.h"

Door:: Door()
{
    pos_x=0;
    pos_y=0;
    height=0;
    length=0;
}
int Door::get_door_pos_x() const
{
    return pos_x;
}
int Door::get_door_pos_y() const
{
    return pos_y;
}
int Door::get_door_length() const
{
    return length;
}
int Door::get_door_height() const
{
    return height;
}

void Door::set_door_height(int h)
{
    height=h;
}
void Door::set_door_pos_y(int y)
{
    pos_y=y;
}
void Door::set_door_pos_x(int x)
{
    pos_x=x;
}

 void Door::set_door_length(int l)
 {
     length=l;
 }
