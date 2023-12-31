#ifndef ENEMY_TYPE_1_3_H
#define ENEMY_TYPE_1_3_H


#include "Enemy3.h"
#include "Environment3.h"
#include "Enemy_bullet3.h"


enum enemy_state_type_1_3
{
    left_moving3, right_moving3, enemy1_destroyed3
};
class Enemy_Type_1_3: public Enemy3, public Enemy_bullet3


{

    private:
    enemy_state_type_1_3 enemy_state;

    public:
        Enemy_Type_1_3();
        void change_enemy_state(enemy_state_type_1_3 next_state);
        void convert_enemy(int i, int j);
        enemy_state_type_1_3 get_enemy_state() const;
        void move_enemy(const Environment3& e);
        void shoot_enemy_bullet(const Environment3& e);
        void set_enemy1_pos(int y, int x);
void set_enemy_pos(int y, int x);


};

#endif // ENEMY_TYPE_1_3_H
