#include "include/Player_Flying.h"


Player_Flying::Player_Flying()
{
    player_flying=not_flying;
    fuel_capacity=50;
    current_fuel=fuel_capacity;
    anime= no_dot;
}

void Player_Flying:: set_flying(Flying no)
{
    player_flying= no;

}

void Player_Flying::change_fuel()
{
    if(player_flying==not_flying && current_fuel<fuel_capacity)
        current_fuel++;
    else if((player_flying==fly_up || player_flying==fly_forward) && current_fuel>1)
    {
        current_fuel-=2;

    }

}

Flying Player_Flying::get_flying()
{
    return player_flying;
}

int Player_Flying::get_fuel()
{
    return current_fuel;
}

int Player_Flying::get_capacity()
{
    return fuel_capacity;
}

void Player_Flying::set_fuel_capacity(int c)
{
    fuel_capacity=c;
}
