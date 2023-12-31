#ifndef PLAYER_FLYING2_H
#define PLAYER_FLYING2_H

#include "Environment2.h"
enum Flying2
{
    fly_up2, fly_forward2, not_flying2
};

enum Jetpack_Animation2
{
    one_dot2, two_dot2, no_dot2
};


class Player_Flying2
{
protected:
    Flying2 player_flying;
    int fuel_capacity;
    int current_fuel;
    Jetpack_Animation2 anime;

public:
    Player_Flying2();
    Flying2 get_flying();
    void set_flying(Flying2 no);
    int get_fuel();
    int get_capacity();
    void change_fuel();
    void set_fuel_capacity(int c);
    virtual int float_player(const Environment2& e) = 0;


};

#endif // PLAYER_FLYING2_H
