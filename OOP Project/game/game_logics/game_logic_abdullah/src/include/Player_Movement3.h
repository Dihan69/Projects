#ifndef PLAYER_MOVEMENT3_H
#define PLAYER_MOVEMENT3_H


enum Player_State3
{
    left_no_gun3, right_no_gun3, left_gun3, right_gun3
};

enum Action3
{
    move_left3, move_right3, not_moving3
};


struct coordinate3
{
    int x;
     int y;
};

class Player_Movement3
{
        protected:
          Player_State3 player_state;
           coordinate3 player_pos;
    public:
        Player_Movement3();
        int get_player_pos_x();
        int get_player_pos_y();
        void change_player_position(Action3 player_action, Player_State3 changed_state);
        void set_player_pos_x(int x);
        virtual void player_movement(Action3 player_action, Player_State3 changed_state)=0;




};

#endif // PLAYER_MOVEMENT3_H
