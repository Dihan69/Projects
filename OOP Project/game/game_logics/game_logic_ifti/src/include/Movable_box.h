#ifndef MOVABLE_BOX_H
#define MOVABLE_BOX_H


enum box_move_direction
{
    up_down, down_up, left_right, right_left
};

class Movable_box
{


private:
    int speed;
    int pos_x;
    int pos_y;
    int length;
    box_move_direction move_dir;


public:
    Movable_box();
    void set_movable_box(int s, int x, int y, int l, box_move_direction dir);
    void change_box_pos(int x, int y, box_move_direction dir);
    int get_pos_x();
    int get_pos_y();
    int get_length();
    box_move_direction get_direction();
    void set_move_view();
};
#endif // MOVABLE_BOX_H
