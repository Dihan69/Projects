#include "include/Player_Movement.h"

Player_Movement::Player_Movement()
{
   player_pos.x=2;
    player_pos.y=56;
    player_state=right_no_gun;
}

int Player_Movement::get_player_pos_x()
{
    return player_pos.x;
}

int Player_Movement::get_player_pos_y()
{
    return player_pos.y;
}


void Player_Movement::change_player_position(Action player_action, Player_State changed_state)
{
    if(player_action==move_left)
        (player_pos.x)--;
    else if(player_action==move_right)
        (player_pos.x)++;
    else

        //next if else part is for gun out or holster stance animation
        if(player_state==right_no_gun && changed_state==right_gun)
            (player_pos.x)--;
        else if(player_state==right_gun && changed_state==right_no_gun)
            (player_pos.x)++;
        else if(player_state==left_no_gun && changed_state==left_gun)
            (player_pos.x)-=3;
        else if(player_state==left_gun && changed_state==left_no_gun)
            (player_pos.x)+=3;
}

