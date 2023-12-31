#include "include/Player_Flying2.h"

Player_Flying2::Player_Flying2()
{
    player_flying=not_flying2;
    fuel_capacity=50;
    current_fuel=fuel_capacity;
    anime= no_dot2;
}

void Player_Flying2:: set_flying(Flying2 no)
{
    player_flying= no;

}

void Player_Flying2::change_fuel()
{
    if(player_flying==not_flying2 && current_fuel<fuel_capacity)
        current_fuel++;
    else if((player_flying==fly_up2 || player_flying==fly_forward2) && current_fuel>1)
    {
        current_fuel-=2;

    }

}

Flying2 Player_Flying2::get_flying()
{
    return player_flying;
}

int Player_Flying2::get_fuel()
{
    return current_fuel;
}

int Player_Flying2::get_capacity()
{
    return fuel_capacity;
}

void Player_Flying2::set_fuel_capacity(int c)
{
    fuel_capacity=c;
}
