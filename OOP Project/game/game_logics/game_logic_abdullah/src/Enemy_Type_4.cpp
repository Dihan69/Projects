#include "include/Enemy_Type_4.h"

Enemy_Type_4::Enemy_Type_4()
{


    enemy_pos_x=51;
    enemy_pos_y=56;
    enemy_hp=100;
    enemy_height=6;
    enemy_width=5;
    enemy_state=up_moving4;
    shoot_delay=5;
    pause=0;
    change_enemy_state(enemy_state);
    bullet_power=5;

    char temp [6][6]=
    {
        "  210",
        " <310",
        "<4310",
        "<4310",
        " <310",
        "  210"
    };

}
void Enemy_Type_4::move_enemy(const Environment3& e)
{

    if(enemy_state==up_moving4)
    {
        if(e.get_environment1(enemy_pos_y-enemy_height, enemy_pos_x)==':')
            enemy_state=down_moving4;
        else
            enemy_pos_y--;
    }
    else if(enemy_state==down_moving4)
    {
        if(e.get_environment1(enemy_pos_y+1, enemy_pos_x)==':')
            enemy_state=up_moving4;
        else
            enemy_pos_y++;
    }

    if(enemy_hp<=0)
        enemy_state= enemy4_destroyed;

    change_enemy_state(enemy_state);

}


void Enemy_Type_4::change_enemy_state(enemy_state_type_4 next_state)
{

    for(int i=0; i<60; i++)
        for(int j=0; j<150; j++)
            enemy[i][j]=32;

    if(enemy_state!=enemy4_destroyed)
    {
        int height=enemy_height;


        char temp [6][6]=
        {
            "  210",
            " <310",
            "<5310",
            "<5310",
            " <310",
            "  410"
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

enemy_state_type_4 Enemy_Type_4:: get_enemy_state() const
{
    return enemy_state;
}


void Enemy_Type_4:: convert_enemy (int i, int j)
{

    int height=enemy_height;

    if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='0')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=219;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='1')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=254;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='2')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=213;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='3')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=179;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='4')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=212;
    else if(enemy[enemy_pos_y-height+i][enemy_pos_x+j]=='5')
        enemy[enemy_pos_y-height+i][enemy_pos_x+j]=198;


}

void Enemy_Type_4::shoot_enemy_bullet(const Environment3& e)
{
    if( current_delay==0 )
    {

        enemy_bullet[enemy_pos_y-2][enemy_pos_x-1]='L';

        enemy_bullet[enemy_pos_y-3][enemy_pos_x-1]='L';

        increment_current_delay();
    }
    else
        increment_current_delay();

    if( pause==10 )
    {

        enemy_bullet[enemy_pos_y-1][enemy_pos_x]='L';

        enemy_bullet[enemy_pos_y-4][enemy_pos_x]='L';

        increment_current_delay();
        pause=0;
    }
    else
        pause++;




    move_enemy_bullet(e);
}

void Enemy_Type_4::set_enemy_pos(int y, int x)
{
    enemy_pos_x=x;
    enemy_pos_y=y;
}
