#include "include/Player3.h"

Player3::Player3()
{
    height=6;
    change_player_state(player_state);
    max_hp=50;
    player_hp=max_hp;
}




void Player3::change_player_state(Player_State3 state)
{

    for(int i=0; i<60; i++)
        for(int j=0; j<150; j++)
            player[i][j]=32;

    if(state==right_no_gun3)
    {
        char temp[height][6+1]=
        {
            "  555 ",
            " 00111",
            "402111",
            "400222",
            " 00000",
            " 10 10"
        };

        for(int i=0; i<height; i++)
        {
            for(int j=0; j<6; j++)
            {
                player[player_pos.y-height+1+i][player_pos.x+j]=temp[i][j];

                //instead of doing height+1 in the function everytime in the function, by passing i+1, we are reducing writing
                convert_player(i+1, j);
                ///this will convert to ascii character
            }
        }
    }
    else if(state==left_no_gun3)
    {
        char temp[height][6+1]=
        {
            " 555  ",
            "11100 ",
            "111206",
            "222006",
            "00000 ",
            "10 10 "
        };

        for(int i=0; i<height; i++)
        {
            for(int j=0; j<6; j++)
            {
                player[player_pos.y-height+1+i][player_pos.x+j]=temp[i][j];
                convert_player(i+1, j);
                ///this will convert to ascii character
            }
        }
    }
    else if(state==right_gun3)
    {
        char temp[height][10+1]=
        {
            "  555     ",
            " 00111    ",
            "402111777=",
            "400222554 ",
            " 00000    ",
            " 10 10    "
        };



        for(int i=0; i<7-1; i++)
        {
            for(int j=0; j<10; j++)
            {
                player[player_pos.y-height+1+i][player_pos.x+j]=temp[i][j];
                convert_player(i+1, j);
            }
        }
    }

    else if(state==left_gun3)
    {
        char temp[height][10+1]=
        {
            "     555  ",
            "    11100 ",
            "=777111206",
            " 655222006",
            "    00000 ",
            "    10 10 "
        };



        for(int i=0; i<height; i++)
        {
            for(int j=0; j<10; j++)
            {
                player[player_pos.y-height+1+i][player_pos.x+j]=temp[i][j];
                convert_player(i+1, j);
                ///this will convert to ascii character
            }
        }
    }

    flying_animation(state);
}

void Player3::flying_animation(Player_State3 current_state)
{
    if(player_flying==fly_forward3 || player_flying==fly_up3)
    {
        int factor;

        if(current_state==right_gun3|| current_state== right_no_gun3)
            factor=0;
        else if(current_state==left_no_gun3)
            factor=5;
        else if (current_state==left_gun3)
            factor=9;


        if( anime==two_dot3 )
        {
            player[(player_pos.y)][(player_pos.x)+factor]=' ';
            player[(player_pos.y)-1][(player_pos.x)+factor]=' ';

            anime=no_dot3;
        }
        else if(anime==one_dot3)
        {
            player[(player_pos.y)][(player_pos.x)+factor]='.';
            player[(player_pos.y)-1][(player_pos.x)+factor]='.';

            anime=two_dot3;
        }
        else if(anime=no_dot3)
        {
            player[(player_pos.y)][(player_pos.x)+factor]='.';

            anime=one_dot3;
        }
    }


}

void Player3:: convert_player(int i, int j)
{
    if(player[player_pos.y-height+i][player_pos.x+j]=='0')
        player[player_pos.y-height+i][player_pos.x+j]=178;
    else if(player[player_pos.y-height+i][player_pos.x+j]=='1')
        player[player_pos.y-height+i][player_pos.x+j]=177;
    else if(player[player_pos.y-height+i][player_pos.x+j]=='2')
        player[player_pos.y-height+i][player_pos.x+j]=176;
    else if(player[player_pos.y-height+i][player_pos.x+j]=='4')
        player[player_pos.y-height+i][player_pos.x+j]=221;
    else if(player[player_pos.y-height+i][player_pos.x+j]=='5')
        player[player_pos.y-height+i][player_pos.x+j]=220;
    else if(player[player_pos.y-height+i][player_pos.x+j]=='6')
        player[player_pos.y-height+i][player_pos.x+j]=222;
    else if(player[player_pos.y-height+i][player_pos.x+j]=='=')
        player[player_pos.y-height+i][player_pos.x+j]=205;
    else if(player[player_pos.y-height+i][player_pos.x+j]=='7')
        player[player_pos.y-height+i][player_pos.x+j]=254;
    else if(player[player_pos.y-height+i][player_pos.x+j]=='8')
        player[player_pos.y-height+i][player_pos.x+j]=181;

}

char Player3::get_player(int i, int j) const
{
    return player[i][j];
}


void Player3::show_player()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
            cout<<player[i][j];

        cout<<endl;
    }
}

int Player3:: float_player(const Environment3& e)
{
    if(player_flying==fly_up3)
    {



        (player_pos.y)--;

    }
    else if(player_flying== not_flying3 )
    {
        int correction;

        if(player_state==left_gun3)
            correction=4;
        else correction=0;

        //when player has left gun, the position starts to count from gun tip, for example
        //GGGGPPPPPP
        //Here first G is player position mathemactically. but all the calculation are done based on leg
        //this is not a problem for right gun as PPPPPPGGGG, first P is position


        for(int k=0; k<2; k++)
        {
            int allowed=1;

            for(int i=correction; i<6+correction; i++)
            {
                if(e.get_environment1((player_pos.y)+1,(player_pos.x)+i)==':' )
                {
                    allowed=0;
                    break;
                }


            }


            if(allowed)
                (player_pos.y)++;

        }
    }

    change_player_state(player_state);

}





void Player3:: player_movement(Action3 player_action, Player_State3 changed_state)
{
    change_player_position(player_action, changed_state);


    player_state=changed_state;

    change_player_state(player_state);
}

void Player3::shoot_player_bullet(const Environment3 & e)
{
    if(current_charge>per_bullet_charge_consumption && cool_down==0)
    {
        if(player_state==right_gun3 && (e.get_environment1(player_pos.y-3, player_pos.x+10) =='.'))
        {

            player_bullet[player_pos.y-3][player_pos.x+10]='R';
            current_charge-=per_bullet_charge_consumption;

        }
        else if(player_state==left_gun3 && (e.get_environment1(player_pos.y-3, player_pos.x-1) =='.'))
        {

            player_bullet[player_pos.y-3][player_pos.x-1]='L';
            current_charge-=per_bullet_charge_consumption;

        }
    }
    else //if(current_charge==0)
        cool_down=6;


}

void Player3::set_player_hp(int h)
{
    if(h>0)
    player_hp=h;
else
    player_hp=0;
}
int Player3:: get_player_hp() const
{
    return player_hp;

}

void Player3::set_player_max_hp(int h)
{
    max_hp=h;

}
int Player3:: get_player_max_hp() const
{
    return max_hp;

}
