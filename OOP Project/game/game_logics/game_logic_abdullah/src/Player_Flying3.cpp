#include "include/Player_Flying3.h"


Player_Flying3::Player_Flying3()
{
    player_flying=not_flying3;
    fuel_capacity=70;
    current_fuel=fuel_capacity;
    anime= no_dot3;
}

void Player_Flying3:: set_flying(Flying3 no)
{
    player_flying= no;

}

void Player_Flying3::change_fuel()
{
    if(player_flying==not_flying3 && current_fuel<fuel_capacity)
        current_fuel++;
    else if((player_flying==fly_up3 || player_flying==fly_forward3) && current_fuel>1)
    {
        current_fuel-=1;

    }

}

Flying3 Player_Flying3::get_flying()
{
    return player_flying;
}

int Player_Flying3::get_fuel()
{
    return current_fuel;
}

int Player_Flying3::get_capacity()
{
    return fuel_capacity;
}

void Player_Flying3::set_fuel_capacity(int c)
{
    fuel_capacity=c;
}
