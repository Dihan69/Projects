#include "include/Enemy_bullet3.h"

Enemy_bullet3:: Enemy_bullet3()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
            enemy_bullet[i][j]=' ';
    }

    bullet_power=0;
    shoot_delay=0;
    current_delay=0;
}
void Enemy_bullet3::set_power(int p)
{
    bullet_power=p;
}
void Enemy_bullet3::set_delay(int d)
{
    shoot_delay=d;
}

void Enemy_bullet3:: increment_current_delay()
{
    current_delay++;
    current_delay=current_delay%shoot_delay;
}
int Enemy_bullet3::get_power()const
{


    return bullet_power;
}

char Enemy_bullet3::get_enemy_bullet_array(int i, int j) const
{
    return enemy_bullet[i][j];
}

int Enemy_bullet3::get_bullet_power() const
{
    return bullet_power;
}

void Enemy_bullet3::destroy_enemy_bullet_array(int i, int j)
{
    enemy_bullet[i][j]=' ';
}



void Enemy_bullet3:: move_enemy_bullet(const Environment3& e)
{
    for(int t=0; t<2; t++)
    {
        for(int y=0; y<60; y++)
            for(int x=0; x<149; x++)
            {
                if(enemy_bullet[y][x+1]=='L')
                {
                    enemy_bullet[y][x]='L';
                    enemy_bullet[y][x+1]=32;
                }



            }

        for(int y=0; y<60; y++)
            for(int x=149; x>0; x--)

            {
                if(enemy_bullet[y][x-1]=='R')
                {
                    enemy_bullet[y][x]='R';
                    enemy_bullet[y][x-1]=32;
                }


            }

        for(int y=0; y<60; y++)
            for(int x=0; x<150; x++)

            {
                if(enemy_bullet[y+1][x]=='U')
                {
                    enemy_bullet[y][x]='U';
                    enemy_bullet[y+1][x]=32;
                }


            }

            for(int y=59; y>0; y--)
            for(int x=0; x<150; x++)

            {
                if(enemy_bullet[y-1][x]=='D')
                {
                    enemy_bullet[y][x]='D';
                    enemy_bullet[y-1][x]=32;
                }


            }





        //destroy bullet if hit by wall
        for(int y=0; y<60; y++)
        {
            for(int x=0; x<150; x++)
            {
                if(e.get_environment1(y, x) !='.')
                    enemy_bullet[y][x]=32;
            }
        }

    }
}

