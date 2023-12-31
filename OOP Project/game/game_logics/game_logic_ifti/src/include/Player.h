#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Environment2.h"
#include "Player_Flying.h"
#include "Player_Movement.h"
#include "Player_Bullet.h"

using namespace std;

class Player: public Player_Flying, public Player_Movement, public Player_Bullet
{
protected:
    char player[60][150];
    int height;
    int player_hp;
    int max_hp;

public:
    Player();
    void change_player_state(Player_State state);
    void show_player();
    void convert_player(int i, int j);
    char get_player(int i, int j) const;
    int float_player(const Environment2& e);
    void flying_animation(Player_State current_state);
    void player_movement(Action player_action, Player_State changed_state);
    void shoot_player_bullet(const Environment2 & e);
    void set_player_hp(int h);
    int get_player_hp() const;
    void set_player_max_hp(int h);
    int get_player_max_hp() const;





};

#endif // PLAYER_H
