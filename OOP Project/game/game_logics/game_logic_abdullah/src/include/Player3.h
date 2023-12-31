#ifndef PLAYER3_H
#define PLAYER3_H

#include "Environment3.h"
#include "Player_Flying3.h"
#include "Player_Movement3.h"
#include "Player_Bullet3.h"

using namespace std;

class Player3: public Player_Flying3, public Player_Movement3, public Player_Bullet3
{
protected:
    char player[60][150];
    int height;
    int player_hp;
    int max_hp;

public:
    Player3();
    void change_player_state(Player_State3 state);
    void show_player();
    void convert_player(int i, int j);
    char get_player(int i, int j) const;
    int float_player(const Environment3& e);
    void flying_animation(Player_State3 current_state);
    void player_movement(Action3 player_action, Player_State3 changed_state);
    void shoot_player_bullet(const Environment3 & e);
    void set_player_hp(int h);
    int get_player_hp() const;
    void set_player_max_hp(int h);
    int get_player_max_hp() const;





};

#endif // PLAYER3_H
