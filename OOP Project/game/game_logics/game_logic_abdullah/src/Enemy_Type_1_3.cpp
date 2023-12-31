#include "include/Enemy_Type_1_3.h"

Enemy_Type_1_3::Enemy_Type_1_3()
{


    enemy_pos_x=51;
    enemy_pos_y=56;
    enemy_hp=40;
    enemy_height=5;
    enemy_width=3;
    enemy_state=left_moving3;
    shoot_delay=3;

    change_enemy_state(enemy_state);
    bullet_power=3;



}
void Enemy_Type_1_3::move_enemy(const Environment3& e)
{

    if(enemy_state==left_moving3)
    {
        if(e.get_environment1(enemy_pos_y, enemy_pos_x-1)==':')
            enemy_state=right_moving3;
        else
            enemy_pos_x--;
    }
    else if(enemy_state==right_moving3)
    {
        if(e.get_environment1(enemy_pos_y, enemy_pos_x+enemy_width)==':')
            enemy_state=left_moving3;
        else
            enemy_pos_x++;
    }

if(enemy_hp<=0)
        enemy_state= enemy1_destroyed3;

    change_enemy_state(enemy_state);

}


void Enemy_Type_1_3::change_enemy_state(enemy_state_type_1_3 next_state)
{

    for(int i=0; i<60; i++)
        for(int j=0; j<150; j++)
            enemy[i][j]=32;

    int height=enemy_height;

    if(next_state==left_moving3)
    {
        char temp[5][4]=
        {
            "444",
            "320",
            "320",
            "000",
            "5 6"
        };

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
    else if(next_state==right_moving3)
    {
        char temp[5][4]=
        {
            "444",
            "027",
            "027",
            "000",
            "5 6"
        };

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

enemy_state_type_1_3 Enemy_Type_1_3:: get_enemy_state() const
{
    return enemy_state;
}


void Enemy_Type_1_3:: convert_enemy (int i, int j)
{

    int height=enemy_height;

    if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='0')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=219;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='1')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=223;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='2')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=254;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='3')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=198;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='4')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=220;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='5')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=222;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='6')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=221;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='7')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=181;

}

void Enemy_Type_1_3::shoot_enemy_bullet(const Environment3& e)
{
    if(enemy_state==left_moving3 && current_delay==0 )
    {

        if(e.get_environment1(enemy_pos_y-2, enemy_pos_x-1) !=':')
            enemy_bullet[enemy_pos_y-2][enemy_pos_x-1]='L';

        if(e.get_environment1(enemy_pos_y-3, enemy_pos_x-1) !=':')
            enemy_bullet[enemy_pos_y-3][enemy_pos_x-1]='L';

        increment_current_delay();
    }
    else if (enemy_state==right_moving3 && current_delay==0)

    {

         if(e.get_environment1(enemy_pos_y-2, enemy_pos_x+enemy_width) !=':')
        enemy_bullet[enemy_pos_y-2][enemy_pos_x+enemy_width]='R';

        if(e.get_environment1(enemy_pos_y-3, enemy_pos_x+enemy_width) !=':')
        enemy_bullet[enemy_pos_y-3][enemy_pos_x+enemy_width]='R';

        increment_current_delay();

    }

    else


        increment_current_delay();



  move_enemy_bullet(e);
}

void Enemy_Type_1_3::set_enemy_pos(int y, int x)
{
    enemy_pos_x=x;
    enemy_pos_y=y;
}
