#ifndef PLAYER_FLYING3_H
#define PLAYER_FLYING3_H

#include "Environment3.h"

enum Flying3
{
    fly_up3, fly_forward3, not_flying3
};

enum Jetpack_Animation3
{
    one_dot3, two_dot3, no_dot3
};


class Player_Flying3
{
protected:
    Flying3 player_flying;
    int fuel_capacity;
    int current_fuel;
    Jetpack_Animation3 anime;

public:
    Player_Flying3();
    Flying3 get_flying();
    void set_flying(Flying3 no);
    int get_fuel();
    int get_capacity();
    void change_fuel();
    void set_fuel_capacity(int c);
    virtual int float_player(const Environment3& e) = 0;


};

#endif // PLAYER_FLYING3_H
