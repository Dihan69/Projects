#include "include/Player_Movement2.h"

Player_Movement2::Player_Movement2()
{
   player_pos.x=2;
    player_pos.y=56;
    player_state=right_no_gun2;
}

int Player_Movement2::get_player_pos_x()
{
    return player_pos.x;
}

int Player_Movement2::get_player_pos_y()
{
    return player_pos.y;
}


void Player_Movement2::change_player_position(Action2 player_action, Player_State2 changed_state)
{
    if(player_action==move_left2)
        (player_pos.x)--;
    else if(player_action==move_right2)
        (player_pos.x)++;
    else

        //next if else part is for gun out or holster stance animation
        if(player_state==right_no_gun2 && changed_state==right_gun2)
            (player_pos.x)--;
        else if(player_state==right_gun2 && changed_state==right_no_gun2)
            (player_pos.x)++;
        else if(player_state==left_no_gun2 && changed_state==left_gun2)
            (player_pos.x)-=3;
        else if(player_state==left_gun2 && changed_state==left_no_gun2)
            (player_pos.x)+=3;
}
