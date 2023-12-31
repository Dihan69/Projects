#include "include/Movable_box.h"

Movable_box::Movable_box()
{
    speed=0;
    pos_x=0;
    pos_y=0;
    length=0;
    move_dir=left_right;

}
void Movable_box::set_movable_box(int s, int x, int y, int l, box_move_direction dir)
{
    speed=s;
    pos_x=x;
    pos_y=y;
    length=l;
    move_dir=dir;
}

void Movable_box::change_box_pos(int x, int y, box_move_direction dir)
{
    pos_x=x;
    pos_y=y;
    move_dir=dir;
}
int Movable_box::get_pos_x()
{
    return pos_x;
}
int Movable_box::get_pos_y()
{
    return pos_y;
}
int Movable_box::get_length()
{
    return length;
}
box_move_direction Movable_box::get_direction()
{
    return move_dir;
}




