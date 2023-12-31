#include "include/Player2.h"

Player2::Player2()
{
    height=6;
    change_player_state(player_state);
    max_hp=50;
    player_hp=max_hp;
}




void Player2::change_player_state(Player_State2 state)
{

    for(int i=0; i<60; i++)
        for(int j=0; j<150; j++)
            player[i][j]=32;

    if(state==right_no_gun2)
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
    else if(state==left_no_gun2)
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
    else if(state==right_gun2)
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

    else if(state==left_gun2)
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

void Player2::flying_animation(Player_State2 current_state)
{
    if(player_flying==fly_forward2 || player_flying==fly_up2)
    {
        int factor;

        if(current_state==right_gun2|| current_state== right_no_gun2)
            factor=0;
        else if(current_state==left_no_gun2)
            factor=5;
        else if (current_state==left_gun2)
            factor=9;


        if( anime==two_dot2 )
        {
            player[(player_pos.y)][(player_pos.x)+factor]=' ';
            player[(player_pos.y)-1][(player_pos.x)+factor]=' ';

            anime=no_dot2;
        }
        else if(anime==one_dot2)
        {
            player[(player_pos.y)][(player_pos.x)+factor]='.';
            player[(player_pos.y)-1][(player_pos.x)+factor]='.';

            anime=two_dot2;
        }
        else if(anime==no_dot2)
        {
            player[(player_pos.y)][(player_pos.x)+factor]='.';

            anime=one_dot2;
        }
    }


}

void Player2:: convert_player(int i, int j)
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

char Player2::get_player(int i, int j) const
{
    return player[i][j];
}


void Player2::show_player()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
            cout<<player[i][j];

        cout<<endl;
    }
}

int Player2:: float_player(const Environment2& e)
{
    if(player_flying==fly_up2)
    {



        (player_pos.y)--;

    }
    else if(player_flying== not_flying2 )
    {
        int correction;

        if(player_state==left_gun2)
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





void Player2:: player_movement(Action2 player_action, Player_State2 changed_state)
{
    change_player_position(player_action, changed_state);


    player_state=changed_state;

    change_player_state(player_state);
}

void Player2::shoot_player_bullet(const Environment2 & e)
{
    if(current_charge>per_bullet_charge_consumption && cool_down==0)
    {
        if(player_state==right_gun2 && (e.get_environment1(player_pos.y-3, player_pos.x+10) =='.'))
        {

            player_bullet[player_pos.y-3][player_pos.x+10]='R';
            current_charge-=per_bullet_charge_consumption;

        }
        else if(player_state==left_gun2 && (e.get_environment1(player_pos.y-3, player_pos.x-1) =='.'))
        {

            player_bullet[player_pos.y-3][player_pos.x-1]='L';
            current_charge-=per_bullet_charge_consumption;

        }
    }
    else //if(current_charge==0)
        cool_down=6;


}

void Player2::set_player_hp(int h)
{
    if(h>0)
    player_hp=h;
else
    player_hp=0;
}
int Player2:: get_player_hp() const
{
    return player_hp;

}

void Player2::set_player_max_hp(int h)
{
    max_hp=h;

}
int Player2:: get_player_max_hp() const
{
    return max_hp;

}
