#include "include/Enemy_Type_2.h"

Enemy_Type_2:: Enemy_Type_2()
{
    enemy_hp=20;
    enemy_height=5;
    enemy_width=5;

    enemy_pos_x=50;
    enemy_pos_y=25;
    change_enemy_state(moving_down);
    current_delay=0;
    shoot_delay=20;

    bullet_power=2;


}

void Enemy_Type_2::set_enemy_pos(int i, int j)
{
    enemy_pos_y=i;
    enemy_pos_x=j;
}
void Enemy_Type_2::set_enemy_state(enemy_state_type_2 next_state)
{
    enemy_state= next_state;
}
void Enemy_Type_2::change_enemy_state(enemy_state_type_2 next_state)
{
    for(int i=0; i<60; i++)
        for(int j=0; j<150; j++)
            enemy[i][j]=32;

    if(enemy_hp>0)
    {
        char temp [5][6]=
        {
            "  ^  ",
            "  2  ",
            "<314>",
            "  5  ",
            "  v  "
        };




        int height=enemy_height;


        for(int i=0; i<height; i++)
        {
            for(int j=0; j<enemy_width; j++)
            {
                enemy[enemy_pos_y-height+1+i][enemy_pos_x+j]=temp[i][j];

                //instead of doing height+1 in the function everytime in the function, by passing i+1, we are reducing writing
                convert_enemy(i+1, j);
                ///this will convert to ascii character
            }
        }
    }

}


void Enemy_Type_2::convert_enemy(int i, int j)
{
    int height=enemy_height;


    if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='0')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=219;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='1')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=206;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='2')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=220;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='3')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=222;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='4')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=221;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='5')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=223;




}
enemy_state_type_2 Enemy_Type_2::get_enemy_state() const
{
    return enemy_state;
}

void Enemy_Type_2::move_enemy(const Environment1& e)
{
    if(enemy_hp>0)
    {
        if(enemy_state==moving_up)
        {
            if(e.get_environment1(enemy_pos_y-enemy_height, enemy_pos_x)==':')
                enemy_state=moving_down;
            else
                enemy_pos_y--;
        }
        else //if(enemy_state==moving_down)
        {
            if(e.get_environment1(enemy_pos_y+1, enemy_pos_x)==':')
                enemy_state=moving_up;
            else
                enemy_pos_y++;
        }
    }


    change_enemy_state(enemy_state);
}
void Enemy_Type_2::shoot_enemy_bullet(const Environment1& e)
{
    if(enemy_hp>0)
    {
        int height=enemy_height;

        if(current_delay % 4 == 0 )
        {

            if(e.get_environment1(enemy_pos_y-height, enemy_pos_x+2) !=':')
                enemy_bullet[enemy_pos_y-height][enemy_pos_x+2]='U';


        }

        if(current_delay % 8 == 0)
        {
            if(e.get_environment1(enemy_pos_y-2, enemy_pos_x-1) !=':')
                enemy_bullet[enemy_pos_y-2][enemy_pos_x-1]='L';
        }
        if(current_delay % 6 == 0)
        {
            if(e.get_environment1(enemy_pos_y-1, enemy_pos_x+2) !=':')
                enemy_bullet[enemy_pos_y-1][enemy_pos_x+2]='D';
        }
        if(current_delay % 10 == 0)
        {
            if(e.get_environment1(enemy_pos_y-2, enemy_pos_x+enemy_width) !=':')
                enemy_bullet[enemy_pos_y-2][enemy_pos_x+enemy_width]='R';
        }


        increment_current_delay();

        move_enemy_bullet(e);
    }
    else
    {
        for(int i=0; i<60; i++)
        {
            for(int j=0; j<150; j++)
                enemy_bullet[i][j]=32;
        }
    }

}
