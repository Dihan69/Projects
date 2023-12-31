#include "include/Player_Movement3.h"

Player_Movement3::Player_Movement3()
{
   player_pos.x=2;
    player_pos.y=56;
    player_state=right_no_gun3;
}

int Player_Movement3::get_player_pos_x()
{
    return player_pos.x;
}

int Player_Movement3::get_player_pos_y()
{
    return player_pos.y;
}

void Player_Movement3::set_player_pos_x(int x)
{
    player_pos.x=x;
}


void Player_Movement3::change_player_position(Action3 player_action, Player_State3 changed_state)
{
    if(player_action==move_left3)
        (player_pos.x)--;
    else if(player_action==move_right3)
        (player_pos.x)++;
    else

        //next if else part is for gun out or holster stance animation
        if(player_state==right_no_gun3 && changed_state==right_gun3)
            (player_pos.x)--;
        else if(player_state==right_gun3 && changed_state==right_no_gun3)
            (player_pos.x)++;
        else if(player_state==left_no_gun3 && changed_state==left_gun3)
            (player_pos.x)-=3;
        else if(player_state==left_gun3 && changed_state==left_no_gun3)
            (player_pos.x)+=3;
}
