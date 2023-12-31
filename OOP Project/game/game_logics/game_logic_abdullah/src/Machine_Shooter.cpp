#include "include/Machine_Shooter.h"

Machine_Shooter::Machine_Shooter()
{


    length=0;
    pos_x=0;
    pos_y=0;
    shoot_delay=30;
    shoot_direction=up_to_down;
    bullet_power=10;
}

void Machine_Shooter::set_machine_shooter(int l, int y, int x, int s, Shoot_Direction d)
{
    length=l;
    pos_x=x;
    pos_y=y;
    shoot_delay=s;
    shoot_direction=d;
}






int Machine_Shooter::get_length()const
{
    return length;
}
int Machine_Shooter::get_pos_x()const
{
    return pos_x;
}
int Machine_Shooter::get_pos_y()const
{
    return pos_y;
}
Shoot_Direction Machine_Shooter:: get_shoot_direction()const
{
    return shoot_direction;
}

int Machine_Shooter::get_shoot_delay() const
{
return shoot_delay;
}

int Machine_Shooter::get_current_delay() const
{
return current_delay;
}
void Machine_Shooter::increment_current_delay()
{
    current_delay++;
    current_delay= current_delay%shoot_delay;
}
