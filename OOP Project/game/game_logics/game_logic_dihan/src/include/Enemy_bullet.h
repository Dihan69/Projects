#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H

#include "Environment1.h"

class Enemy_bullet
{
protected:
    char enemy_bullet[60][150];

    int bullet_power;
    int current_delay;
    int shoot_delay;



public:
    Enemy_bullet();
    void set_power(int p);
    void set_delay(int d);
    int get_power()const;
    char get_enemy_bullet_array(int i, int j) const;
    void destroy_enemy_bullet_array(int i, int j);
void  increment_current_delay();
void move_enemy_bullet(const Environment1& e);
int get_bullet_power() const;


};

#endif // ENEMY_BULLET_H
