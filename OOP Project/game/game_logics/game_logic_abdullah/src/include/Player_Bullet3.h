#ifndef PLAYER_BULLET3_H
#define PLAYER_BULLET3_H


#include "Environment3.h"

enum player_Shooting_State3
{
    shooting3, not_shooting3
};

class Player_Bullet3
{
protected:
    char player_bullet[60][150];
    int gun_power;
    int total_charge;
    int current_charge;
    int cool_down;
    int per_bullet_charge_consumption;

public:
    Player_Bullet3();
    char get_player_bullet_array(int i, int j);
    int get_gun_power()const;
    int get_total_charge() const;
    int get_current_charge() const;
    int get_cooldown()  const;
    void set_total_charge(int c);
    void set_gun_power(int p);
    void destroy_player_bullet(int i, int j);
    void move_player_bullet(const Environment3& e);
    virtual void shoot_player_bullet(const Environment3 & e)=0;




};

#endif // PLAYER_BULLET3_H
