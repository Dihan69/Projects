#include "include/Enemy_type_0.h"

Enemy_type_0::Enemy_type_0()
{
    destruct_power=20;
    is_destroyed=false;
    pos_x=0;
    pos_y=0;

    for(int i=0; i<60; i++)
        for(int j=0; j<150; j++)
            enemy[i][j]=32;
}
void Enemy_type_0::set_enemy_type_0(int y, int x)
{
    pos_x=x;
    pos_y=y;
}
void Enemy_type_0::move_enemy(const Environment2& e)
{
    for(int i=0; i<60; i++)
        for(int j=0; j<150; j++)
            enemy[i][j]=32;

    if(is_destroyed==false)
    {
       // srand(time(0));

        int num;
        int count;

        num=rand()%5;
        count=rand()%2;

        for(int i=0; i<=count; i++)
        if(num==0)
        {
            //do nothing
        }
        else if(num==1)
        {
            //do down
            if(e.get_environment1(pos_y+1, pos_x)=='.' && e.get_environment1(pos_y+1, pos_x+1)=='.' && e.get_environment1(pos_y+1, pos_x+2)=='.')
                pos_y++;
        }
        else if(num==2)
        {
            //go up
            if(e.get_environment1(pos_y-1, pos_x)=='.' && e.get_environment1(pos_y-1, pos_x+1)=='.' && e.get_environment1(pos_y-1, pos_x+2)=='.')
                pos_y--;
        }

        else if(num==3 && pos_x>75) //makes sure the enemies dont move left of original door pos
        {
            //go left
            if(e.get_environment1(pos_y, pos_x-1)=='.')
                pos_x--;
        }
        else if(num==4)
        {
            //go right
            if(e.get_environment1(pos_y, pos_x+3)=='.')
                pos_x++;
        }

        enemy[pos_y][pos_x]='[';
        enemy[pos_y][pos_x+1]=':';
        enemy[pos_y][pos_x+2]=']';




    }
}
int Enemy_type_0::get_destruct_power()
{
    return destruct_power;
}
void Enemy_type_0::destroy_enemy_type_0()
{
    is_destroyed=true;
}

char Enemy_type_0::get_enemy_array(int i, int j)
{
    return enemy[i][j];
}

bool Enemy_type_0::get_is_destroyed()
{
    return is_destroyed;
}
