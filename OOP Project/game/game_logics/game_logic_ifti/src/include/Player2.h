#ifndef PLAYER2_H
#define PLAYER2_H


#include <iostream>
#include "Environment2.h"
#include "Player_Flying2.h"
#include "Player_Movement2.h"
#include "Player_Bullet2.h"

using namespace std;

class Player2: public Player_Flying2, public Player_Movement2, public Player_Bullet2
{
protected:
    char player[60][150];
    int height;
    int player_hp;
    int max_hp;

public:
    Player2();
    void change_player_state(Player_State2 state);
    void show_player();
    void convert_player(int i, int j);
    char get_player(int i, int j) const;
    int float_player(const Environment2& e);
    void flying_animation(Player_State2 current_state);
    void player_movement(Action2 player_action, Player_State2 changed_state);
    void shoot_player_bullet(const Environment2 & e);
    void set_player_hp(int h);
    int get_player_hp() const;
    void set_player_max_hp(int h);
    int get_player_max_hp() const;





};

#endif // PLAYER2_H
