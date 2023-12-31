#ifndef ENEMY_TYPE_4_H
#define ENEMY_TYPE_4_H

#include "Enemy3.h"
#include "Environment3.h"
#include "Enemy_bullet3.h"

enum enemy_state_type_4
{
    up_moving4, down_moving4, enemy4_destroyed
};

class Enemy_Type_4 : public Enemy3, public Enemy_bullet3
{
    private:
    enemy_state_type_4 enemy_state;
    int pause;

    public:
        Enemy_Type_4();
        void change_enemy_state(enemy_state_type_4 next_state);
        void convert_enemy(int i, int j);
        enemy_state_type_4 get_enemy_state() const;
        void move_enemy(const Environment3& e);
        void shoot_enemy_bullet(const Environment3& e);
        void set_enemy_pos(int y, int x);
};

#endif // ENEMY_TYPE_4_H
