#ifndef PLAYER_BULLET2_H
#define PLAYER_BULLET2_H


#include <iostream>
#include "Environment2.h"
#include "Player_Flying2.h"
#include "Player_Movement2.h"
#include "Player_Bullet2.h"

#include "Environment2.h"

enum player_Shooting_State2
{
    shooting2, not_shooting2
};

class Player_Bullet2
{
protected:
    char player_bullet[60][150];
    int gun_power;
    int total_charge;
    int current_charge;
    int cool_down;
    int per_bullet_charge_consumption;

public:
    Player_Bullet2();
    char get_player_bullet_array(int i, int j);
    int get_gun_power()const;
    int get_total_charge() const;
    int get_current_charge() const;
    int get_cooldown()  const;
    void set_total_charge(int c);
    void set_gun_power(int p);
    void destroy_player_bullet(int i, int j);
    void move_player_bullet(const Environment2& e);
virtual void shoot_player_bullet(const Environment2 & e)=0;



};

#endif // PLAYER_BULLET2_H
