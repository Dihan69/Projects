#include "include/Enemy.h"

Enemy::Enemy()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
            enemy[i][j]=32;
    }

    enemy_pos_y=0;
    enemy_pos_x=0;
    enemy_hp=0;
    enemy_height=0;
    enemy_width=0;

}
char Enemy::get_enemy_array(int i, int j) const
{
    return enemy[i][j];
}

int Enemy::get_enemy_pos_y() const
{
    return enemy_pos_y;
}
int Enemy::get_enemy_pos_x() const
{
    return enemy_pos_x;
}
int Enemy::get_enemy_hp()const
{
    return enemy_hp;
}
int Enemy::get_enemy_height()const
{
    return enemy_height;
}
int Enemy::get_enemy_width()const
{
    return enemy_width;
}
void Enemy::set_enemy_attribute(int y, int x, int hp, int h, int w)
{
    enemy_pos_y=y;
    enemy_pos_x=x;
    enemy_hp=hp;
    enemy_height=h;
    enemy_width=w;
}

void Enemy::set_enemy_hp(int h)
{
    enemy_hp=h;
}
