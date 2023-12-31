#ifndef PLAYER_MOVEMENT2_H
#define PLAYER_MOVEMENT2_H


enum Player_State2
{
    left_no_gun2, right_no_gun2, left_gun2, right_gun2
};

enum Action2
{
    move_left2, move_right2, not_moving2
};


struct coordinate2
{
    int x;
     int y;
};

class Player_Movement2
{
        protected:
          Player_State2 player_state;
           coordinate2 player_pos;
    public:
        Player_Movement2();
        int get_player_pos_x();
        int get_player_pos_y();
        void change_player_position(Action2 player_action, Player_State2 changed_state);
        virtual void player_movement(Action2 player_action, Player_State2 changed_state)=0;




};

#endif // PLAYER_MOVEMENT2_H
