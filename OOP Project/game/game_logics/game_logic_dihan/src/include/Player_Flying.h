#ifndef PLAYER_FLYING_H
#define PLAYER_FLYING_H

#include "Environment1.h"

enum Flying
{
    fly_up, fly_forward, not_flying
};

enum Jetpack_Animation
{
    one_dot, two_dot, no_dot
};


class Player_Flying
{
protected:
    Flying player_flying;
    int fuel_capacity;
    int current_fuel;
    Jetpack_Animation anime;

public:
    Player_Flying();
    Flying get_flying();
    void set_flying(Flying no);
    int get_fuel();
    int get_capacity();
    void change_fuel();
    void set_fuel_capacity(int c);
    virtual int float_player(const Environment1& e) = 0;


};

#endif // PLAYER_FLYING_H
