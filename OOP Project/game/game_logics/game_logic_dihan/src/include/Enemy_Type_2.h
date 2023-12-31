#ifndef ENEMY_TYPE_2_H
#define ENEMY_TYPE_2_H

#include "Enemy.h"
#include "Environment1.h"
#include "Enemy_bullet.h"

enum enemy_state_type_2
{
    moving_up, moving_down, standing_still, enemy2_destroyed
};

class Enemy_Type_2: public Enemy, public Enemy_bullet
{
 private:
    enemy_state_type_2 enemy_state;


    public:
        Enemy_Type_2();
        void change_enemy_state(enemy_state_type_2 next_state);
        void convert_enemy(int i, int j);
        void set_enemy_pos(int i, int j);
        void set_enemy_state(enemy_state_type_2 next_state);
        enemy_state_type_2 get_enemy_state() const;
        void move_enemy(const Environment1& e);
        void shoot_enemy_bullet(const Environment1& e);

};

#endif // ENEMY_TYPE_2_H
