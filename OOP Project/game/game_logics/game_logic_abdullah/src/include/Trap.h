#ifndef TRAP_H
#define TRAP_H


#include <iostream>

enum Trap_Direction
{
    up, down
};




class Trap
{
     protected:
         int height;
         int length;
         Trap_Direction direction;
         int trap_pos_x;
         int trap_pos_y;


    public:
        Trap();
        void set_trap(int h, int l, Trap_Direction d, int x, int y);
        int get_height() const;
        int get_length() const;
        int get_trap_y() ;
        int get_direction() const;
        int get_trap_x() ;





};

#endif // TRAP_H
