#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include "Environment1.h"

enum player_Shooting_State
{
    shooting, not_shooting
};

class Player_Bullet
{
protected:
    char player_bullet[60][150];
    int gun_power;
    int total_charge;
    int current_charge;
    int cool_down;
    int per_bullet_charge_consumption;

public:
    Player_Bullet();
    char get_player_bullet_array(int i, int j);
    int get_gun_power()const;
    int get_total_charge() const;
    int get_current_charge() const;
    int get_cooldown()  const;
    void set_total_charge(int c);
    void set_gun_power(int p);
    void destroy_player_bullet(int i, int j);
    void move_player_bullet(const Environment1& e);
    virtual void shoot_player_bullet(const Environment1 & e)=0;




};

#endif // PLAYER_BULLET_H
