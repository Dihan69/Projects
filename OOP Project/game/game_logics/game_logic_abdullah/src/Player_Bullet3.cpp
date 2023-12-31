#include "include/Player_Bullet3.h"

Player_Bullet3:: Player_Bullet3()
{

    for(int i=0; i<60; i++)
        for(int j=0; j<150; j++)
            player_bullet[i][j]=32;

    total_charge=48;
    current_charge=total_charge;
    gun_power=5;
    cool_down=0;
    per_bullet_charge_consumption=6;
}

void Player_Bullet3::destroy_player_bullet(int i, int j)
{
    player_bullet[i][j]=' ';
}

char Player_Bullet3::get_player_bullet_array(int i, int j)
{
    return player_bullet[i][j];
}

int Player_Bullet3::get_gun_power()const
{
    return gun_power;
}
int Player_Bullet3::get_total_charge() const
{
    return total_charge;
}
int Player_Bullet3::get_current_charge() const
{
    return current_charge;
}
void Player_Bullet3::set_total_charge(int c)
{
    total_charge=c;
}

void Player_Bullet3::set_gun_power(int p)
{
    gun_power=p;
}

void Player_Bullet3::move_player_bullet(const Environment3& e)
{
    for(int t=0; t<2; t++)
    {
        for(int y=0; y<60; y++)
            for(int x=0; x<149; x++)
            {
                if(player_bullet[y][x+1]=='L')
                {
                    player_bullet[y][x]='L';
                    player_bullet[y][x+1]=32;
                }



            }

        for(int y=0; y<60; y++)
            for(int x=149; x>0; x--)

            {
                if(player_bullet[y][x-1]=='R')
                {
                    player_bullet[y][x]='R';
                    player_bullet[y][x-1]=32;
                }


            }


            //destroy bullet if hit by wall
    for(int y=0; y<60; y++)
        {
            for(int x=0; x<150; x++)
            {
                if(e.get_environment1(y, x) !='.')
                    player_bullet[y][x]=32;
            }
        }

    }

    if(current_charge<=total_charge && cool_down==0)
        current_charge++;

     if(cool_down>0)
            cool_down--;
}

int Player_Bullet3:: get_cooldown()  const
{
    return cool_down;
}
