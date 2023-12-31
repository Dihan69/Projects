#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    protected:
        char enemy[60][150];
        int enemy_pos_y;
        int enemy_pos_x;
        int enemy_hp;
        int enemy_height;
        int enemy_width;



    public:
        Enemy();
        char get_enemy_array(int i, int j)const;
        int get_enemy_pos_y()const;
        int get_enemy_pos_x()const;
        int get_enemy_hp()const;
        int get_enemy_height()const;
        int get_enemy_width()const;
        void set_enemy_attribute(int y, int x, int hp, int h, int w);
        void set_enemy_hp(int h);




};

#endif // ENEMY_H
