#ifndef ENEMY_TYPE_1_H
#define ENEMY_TYPE_1_H

#include "Enemy.h"
#include "Environment1.h"
#include "Enemy_bullet.h"


enum enemy_state_type_1
{
    left_moving, right_moving, enemy1_destroyed
};
class Enemy_Type_1: public Enemy, public Enemy_bullet


{

    private:
    enemy_state_type_1 enemy_state;

    public:
        Enemy_Type_1();
        void change_enemy_state(enemy_state_type_1 next_state);
        void convert_enemy(int i, int j);
        enemy_state_type_1 get_enemy_state() const;
        void move_enemy(const Environment1& e);
        void shoot_enemy_bullet(const Environment1& e);



};

#endif // ENEMY_TYPE_1_H
