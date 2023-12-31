#ifndef PLAYER_MOVEMENT_H
#define PLAYER_MOVEMENT_H

enum Player_State
{
    left_no_gun, right_no_gun, left_gun, right_gun
};

enum Action
{
    move_left, move_right, not_moving
};


struct coordinate
{
    int x;
     int y;
};

class Player_Movement
{
        protected:
          Player_State player_state;
           coordinate player_pos;
    public:
        Player_Movement();
        int get_player_pos_x();
        int get_player_pos_y();
        void change_player_position(Action player_action, Player_State changed_state);
        virtual void player_movement(Action player_action, Player_State changed_state)=0;




};

#endif // PLAYER_MOVEMENT_H
