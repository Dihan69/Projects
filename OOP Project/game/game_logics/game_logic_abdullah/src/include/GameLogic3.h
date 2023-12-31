#pragma once

#include <iostream>

#include "Environment3.h"
#include "Player3.h"
#include "Enemy_Type_4.h"
#include "Enemy_Type_1_3.h"

#include "utility/screen_utility.hpp"
#include "utility/device_utility.hpp"
#include "utility/menu_utility.hpp"

using namespace std;

enum Key_Press3
{
    up_key3, down_key3, left_key3, right_key3, enter_key3, space_key3, no_key3
};

enum Movement_Result3
{
    can_move3, cannot_move3, got_trapped3
};

enum Game_State3
{
    failed3, running3, passed3
};

class Game_logic3
{

private:
    bool will_resume;

    Action3 player_action;
    Player_State3 player_state;
    Environment3 e;
    Player3 p;
    Enemy_Type_1_3 enemy1[3];
    Enemy_Type_4 enemy4;
    int enemy1_count;
    int factor;
    Movement_Result3 movement_result;
    Key_Press3 key;
    Game_State3 game_state;

    ///utility
    Keyboard keyboard;
    Screen* main_screen;

    void screen_setup();
    void screen_dump();

public:
    Game_logic3();
    void show_rules();
    void game_flow();
    Movement_Result3 is_movement_allowed(Player3 temp_player, Environment3 temp_env, Player_State3 temp_state, Action3 temp_action) const;
    void set_main_screen();
    Game_State3 end_game_check();
    void keyboard_press_action();
    void collision_check_P_EB1( );
    void collision_check_PB_E1 ();
    void collision_check_P_E1 ();
    void collision_check_P_E4 ();
    void collision_check_PB_EB1 ();
    void collision_check_PB_EB4 ();
    void collision_check_PB_E4();
    void collision_check_P_EB4();
    void collision_check_P_MS();
    void collectable_check();
    void show_hud();

};

void Game_logic3::screen_setup()
{
    main_screen = new Screen(150, 50);
}

void Game_logic3::screen_dump()
{
    delete main_screen;
}

void Game_logic3::show_rules()
{

    cout<<"----------"<<endl;
    cout<<"Basic keys"<<endl;
    cout<<"----------"<<endl;
    cout<<"Left : Move Left"<<endl;
    cout<<"Right: Move Right"<<endl;
    cout<<"Up   : Fly up"<<endl;
    cout<<"Down : Stop flying"<<endl;
    cout<<"Enter: Gun in or Gun out"<<endl;
    cout<<"Space: Shoot"<<endl<<endl;
    cout<<endl;

    cout<<"-----"<<endl;
    cout<<"Rules"<<endl;
    cout<<"-----"<<endl;
    cout<<"> Enemy will die after getting hit by player bullet for a few time"<<endl;
    cout<<"> Each enemy has different health point and bullet power"<<endl;
    cout<<"> Getting hit by bullet will decrease player health"<<endl;
    cout<<"> Getting direct contact with enemy will kill player"<<endl;
    cout<<"> Running into traps from any direction will kill player"<<endl;
    cout<<"> You cannot put gun out too close to wall and near trap"<<endl;
    cout<<endl;

    cout<<"------------"<<endl;
    cout<<"Collectables"<<endl;
    cout<<"------------"<<endl;
    cout<<"H: Restores Health"<<endl;
    cout<<"F: Increases Max Fuel Capacity"<<endl;
    cout<<"K: Unlocks certain door"<<endl;
    cout<<"C: Increases Max Bullet Charge"<<endl;

cout<<endl;

    cout<<"------------"<<endl;
    cout<<"Tips"<<endl;
    cout<<"------------"<<endl;
    cout<<"> Last part of the level is extremely difficult"<<endl;
    cout<<"> However, it is possible to finish with quick work of hand"<<endl;

    cout<<endl;

    cout<<"PRESS SPACEBAR TO CONTINUE...."<<endl;

    while(1)
    {
        keyboard.checkKeyState();
        if(keyboard.getKey(Keyboard::SPACEBAR).isPressed()) break;
    }
}




///FUNCTIONS FOR GAME LOGIC CLASS///

Game_logic3:: Game_logic3()
{
    player_state= right_no_gun3;
    player_action=not_moving3;

    factor=10;

    enemy1_count=3;

    movement_result=can_move3;
    game_state=running3;


    enemy4.set_enemy_pos(25, 117);

    enemy1[0].set_enemy_pos(42, 120);
    enemy1[1].set_enemy_pos(42, 95);
    enemy1[2].set_enemy_pos(42, 60);

    will_resume = true;
}


void Game_logic3:: game_flow()
{
    screen_setup();

    while(1)
    {

        collectable_check();

        set_main_screen();

        main_screen->show();
        show_hud();



        game_state= end_game_check();

        if(game_state!=running3)
            break;






        keyboard.checkKeyState();
        keyboard_press_action();
        if(will_resume == false) break;

        p.change_fuel();
        p.move_player_bullet(e);

        if(p.get_fuel()<2)
            p.set_flying(not_flying3);


        e.shoot_machine();



        enemy4.move_enemy(e);
        enemy4.shoot_enemy_bullet(e);

        for(int n=0; n<enemy1_count; n++)
        {
            enemy1[n].move_enemy(e);
            enemy1[n].shoot_enemy_bullet(e);
        }


        collision_check_P_MS();
        collision_check_PB_EB1 ();
        collision_check_PB_EB4 ();
        collision_check_P_EB1();
        collision_check_P_E1 ();
        collision_check_P_E4 ();
        collision_check_PB_E1 ();
        collision_check_P_EB4();
        collision_check_PB_E4();



        if(p.get_player_pos_x()>=142 && p.get_player_pos_y()>=45)
            game_state=passed3;


        if(movement_result==got_trapped3)
            p.set_player_hp(0);

    }

    screen_dump();
}

Game_State3 Game_logic3::end_game_check()
{
    if(movement_result==got_trapped3 || p.get_player_hp()<=0)
    {
        main_screen->set_pixel(p.get_player_pos_x()-2, p.get_player_pos_y()-factor-3, 'G');
        main_screen->set_pixel(p.get_player_pos_x()-1, p.get_player_pos_y()-factor-3, 'A');
        main_screen->set_pixel(p.get_player_pos_x(), p.get_player_pos_y()-factor-3, 'M');
        main_screen->set_pixel(p.get_player_pos_x()+1, p.get_player_pos_y()-factor-3, 'E');
        main_screen->set_pixel(p.get_player_pos_x()+2, p.get_player_pos_y()-factor-3, ' ');
        main_screen->set_pixel(p.get_player_pos_x()+3, p.get_player_pos_y()-factor-3, 'O');
        main_screen->set_pixel(p.get_player_pos_x()+4, p.get_player_pos_y()-factor-3, 'V');
        main_screen->set_pixel(p.get_player_pos_x()+5, p.get_player_pos_y()-factor-3, 'E');
        main_screen->set_pixel(p.get_player_pos_x()+6, p.get_player_pos_y()-factor-3, 'R');

        main_screen->show();
        show_hud();

        while(1)
        {
            keyboard.checkKeyState();
            if(keyboard.getKey(Keyboard::ENTER).isDown()) break;
        }

        return failed3;
    }
    else if(game_state==passed3)
    {
        char temp[]= "CONGRATULATION ON PASSING LEVEL 2";

        for(int i=0; i<strlen(temp); i++)
            main_screen->set_pixel(i+65, 30-factor, temp[i]);

        char temp2[]="    !!press enter to proceed!!   ";

        for(int i=0; i<strlen(temp); i++)
            main_screen->set_pixel(i+65, 31-factor, temp2[i]);

        main_screen->show();
        show_hud();


        while(1)
        {
            keyboard.checkKeyState();
            if(keyboard.getKey(Keyboard::ENTER).isDown()) break;
        }

        return passed3;


    }
    else
        return running3;

}

void Game_logic3::show_hud()
{
    //for(int i=0; i<150; i++)
    //  cout<<" ";
    //cout<<endl;

    cout<<"HEALTH: ";

    for(int i= 0; i<p.get_player_hp(); i++)
        cout<< (char) 254;

    for(int i=p.get_player_hp(); i<150-10; i++)
    {
        if(i==p.get_player_max_hp())
            cout<<'|';
        else
            cout<<" ";
    }
    cout<<endl;

    cout<<"FUEL  : ";

    for(int i= 0; i<p.get_fuel(); i++)
        cout<< (char) 254;

    for(int i=p.get_fuel(); i<150-10; i++)
    {
        if(i==p.get_capacity())
            cout<<'|';
        else
            cout<<" ";

    }
    cout<<endl;

    cout<<"CHARGE: ";

    for(int i= 0; i<p.get_current_charge(); i++)
        cout<< (char) 254;

    for(int i=p.get_current_charge(); i<150-10; i++)
    {
        if(i==p.get_total_charge()+1)
            cout<<'|';
        else
            cout<<" ";
    }
    cout<<endl;



}

void Game_logic3:: set_main_screen()
{
    for(int i=0; i<60-factor; i++)
    {
        for(int j=0; j<150; j++)
        {


            if(p.get_player(i+factor, j)!=32)
                main_screen->set_pixel(j, i, p.get_player(i+factor, j));

            if(e.get_environment1(i+factor, j)==':')
                main_screen->set_pixel(j, i, 219);
            else  if(e.get_environment1(i+factor, j)=='.' && p.get_player(i+factor, j)==32  )
                main_screen->set_pixel(j, i, 32);
            else if(e.get_environment1(i+factor, j)!='.')
                main_screen->set_pixel(j, i, e.get_environment1(i+factor, j));



            if(e.get_machine_shooter_array(i+factor, j)!=32) //&& e.get_environment1(i+factor, j)!=':' )
            {
                if(e.get_machine_shooter_array(i+factor, j)=='D')
                    main_screen->set_pixel(j, i, '|');
                else
                    main_screen->set_pixel(j, i, '-');

            }
//
            if((enemy4.get_enemy_array(i+factor, j))!=32 )
                main_screen->set_pixel(j, i, enemy4.get_enemy_array(i+factor, j));

            if((enemy4.get_enemy_bullet_array(i+factor, j))!=32 )
                main_screen->set_pixel(j, i, '*');
//
            for(int n=0; n<enemy1_count; n++)
            {
                if((enemy1[n].get_enemy_array(i+factor, j))!=32 )
                    main_screen->set_pixel(j, i, enemy1[n].get_enemy_array(i+factor, j));

                if((enemy1[n].get_enemy_bullet_array(i+factor, j))!=32 )
                    main_screen->set_pixel(j, i, '*');

            }
//
            if((p.get_player_bullet_array(i+factor, j))!=32 )
                main_screen->set_pixel(j, i, 'o');

        }
    }
}

void Game_logic3::collision_check_P_EB4( )
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
        {
            if(p.get_player(i,j)!=32 && enemy4.get_enemy_bullet_array(i,j) !=32 )
            {
                p.set_player_hp(p.get_player_hp()-enemy4.get_bullet_power());
                enemy4.destroy_enemy_bullet_array(i, j);
            }
        }
    }
}

void Game_logic3:: collision_check_P_EB1()
{
    for(int k=0; k<enemy1_count; k++)
    {
        for(int i=0; i<60; i++)
        {
            for(int j=0; j<150; j++)
            {
                if(p.get_player(i,j)!=32 && enemy1[k].get_enemy_bullet_array(i,j) !=32 )
                {
                    p.set_player_hp(p.get_player_hp()-enemy1[k].get_bullet_power());
                    enemy1[k].destroy_enemy_bullet_array(i, j);
                }
            }
        }
    }
}
//
void Game_logic3::collision_check_P_MS()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
        {
            if(p.get_player(i,j)!=32 && e.get_machine_shooter_array(i,j) !=32 )
            {
                p.set_player_hp(p.get_player_hp()-10);
                e.destroy_machine_shooter_bullet(i, j);
            }
        }
    }
}

void Game_logic3::collision_check_PB_E4 ()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
        {
            if(p.get_player_bullet_array(i,j)!=32 && enemy4.get_enemy_array(i,j) !=32 )
            {
                enemy4.set_enemy_hp(enemy4.get_enemy_hp()-p.get_gun_power());
                p.destroy_player_bullet(i, j);
            }
        }
    }
}

void Game_logic3::collision_check_P_E4 ()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
        {
            if(p.get_player(i,j)!=32 && enemy4.get_enemy_array(i,j) !=32 )
            {
                p.set_player_hp(0);
            }
        }
    }
}

void Game_logic3::collision_check_P_E1 ()
{
    for(int k=0; k<enemy1_count; k++)
    {
        for(int i=0; i<60; i++)
        {
            for(int j=0; j<150; j++)
            {
                if(p.get_player(i,j)!=32 && enemy1[k].get_enemy_array(i,j) !=32 )
                {
                    p.set_player_hp(0);
                }
            }
        }
    }

}


void Game_logic3::collision_check_PB_EB4 ()
{

    for(int i=0; i<60; i++)
    {
        for(int j=0; j<149; j++)
        {
            if( (p.get_player_bullet_array(i,j)!=32 && enemy4.get_enemy_bullet_array(i,j) !=32) || (p.get_player_bullet_array(i,j+1)!=32 && enemy4.get_enemy_bullet_array(i,j) !=32) ||
                    (p.get_player_bullet_array(i,j)!=32 && enemy4.get_enemy_bullet_array(i,j+1) !=32) || (p.get_player_bullet_array(i,j+1)!=32 && enemy4.get_enemy_bullet_array(i,j+1) !=32) )

            {
                p.destroy_player_bullet(i, j);
                enemy4.destroy_enemy_bullet_array(i, j);
                p.destroy_player_bullet(i, j+1);
                enemy4.destroy_enemy_bullet_array(i, j+1);
            }
        }
    }
}

void Game_logic3::collision_check_PB_EB1 ()
{
    for(int k=0; k<enemy1_count; k++)
    {
        for(int i=0; i<60; i++)
        {
            for(int j=0; j<149; j++)
            {
                if( (p.get_player_bullet_array(i,j)!=32 && enemy1[k].get_enemy_bullet_array(i,j) !=32) || (p.get_player_bullet_array(i,j+1)!=32 && enemy1[k].get_enemy_bullet_array(i,j) !=32) ||
                        (p.get_player_bullet_array(i,j)!=32 && enemy1[k].get_enemy_bullet_array(i,j+1) !=32) || (p.get_player_bullet_array(i,j+1)!=32 && enemy1[k].get_enemy_bullet_array(i,j+1) !=32) )

                {
                    p.destroy_player_bullet(i, j);
                    enemy1[k].destroy_enemy_bullet_array(i, j);
                    p.destroy_player_bullet(i, j+1);
                    enemy1[k].destroy_enemy_bullet_array(i, j+1);
                }
            }
        }
    }
}

void Game_logic3::collision_check_PB_E1()
{
    for(int k=0; k<enemy1_count; k++)
    {
        for(int i=0; i<60; i++)
        {
            for(int j=0; j<150; j++)
            {
                if(p.get_player_bullet_array(i,j)!=32 && enemy1[k].get_enemy_array(i,j) !=32 )
                {
                    enemy1[k].set_enemy_hp(enemy1[k].get_enemy_hp()-p.get_gun_power());
                    p.destroy_player_bullet(i, j);
                }
            }
        }
    }
}

void Game_logic3::collectable_check()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<149; j++)
        {
            if(p.get_player(i,j)!=32 && e.get_environment1(i,j)=='F')
            {
                p.set_fuel_capacity(p.get_capacity()+34);
                e.destroy_collectible(i,j);
            }

            if(p.get_player(i,j)!=32 && e.get_environment1(i,j)=='H')
            {

                p.set_player_hp(p.get_player_max_hp());
                e.destroy_collectible(i,j);
            }

            if(p.get_player(i,j)!=32 && e.get_environment1(i,j)=='C')
            {
                p.set_total_charge(p.get_total_charge()+14);

                e.destroy_collectible(i,j);
            }

            if(p.get_player(i,j)!=32 && e.get_environment1(i,j)=='K')
            {

                e.open_door(0);
                e.destroy_collectible(i,j);
            }



        }
    }
}

void Game_logic3::keyboard_press_action()
{
    if(keyboard.getKey(Keyboard::UP_ARROW).isDown())
    {


        key=up_key3;

        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move3)
        {
            if(p.get_fuel()>4)
                p.set_flying(fly_up3);


            p.float_player(e);

            p.set_flying(fly_forward3);

        }
        else if(movement_result==cannot_move3)
        {
            if(p.get_fuel()>4)
                p.set_flying(fly_forward3);


            p.float_player(e);
        }
    }
    else if(keyboard.getKey(Keyboard::DOWN_ARROW).isDown())
    {
        if(p.get_player_pos_y()>25 && factor!=10)
            factor++;

        key=down_key3;

        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move3)
        {
            p.set_flying(not_flying3);
            p.float_player(e);

        }
    }
    else if(keyboard.getKey(Keyboard::RIGHT_ARROW).isDown())
    {
        key=right_key3;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move3)
        {
            if(player_state==right_no_gun3 || player_state==right_gun3)
                player_action=move_right3;
            else
            {
                player_action=not_moving3;

                if(player_state==left_no_gun3)
                    player_state=right_no_gun3;
                else if(player_state==left_gun3)
                    player_state=right_gun3;

            }

            p.float_player(e);
            p.player_movement(player_action, player_state);
        }
    }
    else if(keyboard.getKey(Keyboard::LEFT_ARROW).isDown())
    {

        key=left_key3;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move3)
        {
            if(player_state==left_no_gun3 || player_state==left_gun3)
                player_action=move_left3;
            else
            {
                player_action=not_moving3;

                if(player_state==right_no_gun3)
                    player_state=left_no_gun3;
                else if(player_state==right_gun3)
                    player_state=left_gun3;

            }

            p.float_player(e);
            p.player_movement(player_action, player_state);
        }
    }
    else if(keyboard.getKey(Keyboard::ENTER).isDown() && p.get_flying()!=fly_up3 )
    {
        key=enter_key3;


        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move3)
        {
            if(player_state==right_no_gun3)
                player_state=right_gun3;
            else if(player_state==right_gun3)
                player_state=right_no_gun3;
            else if(player_state==left_no_gun3)
                player_state=left_gun3;
            else if(player_state==left_gun3)
                player_state=left_no_gun3;

            player_action=not_moving3;

            p.float_player(e);
            p.player_movement(player_action, player_state);
        }

    }
    else if(keyboard.getKey(Keyboard::SPACEBAR).isDown())
    {

        p.shoot_player_bullet(e);

        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move3)
        {
            player_action=not_moving3;

            p.float_player(e);
            p.player_movement(player_action, player_state);

        }
    }
    else if(keyboard.getKey(Keyboard::ESCAPE).isPressed())
    {
        system("cls");
        will_resume = InGameMenu::run();
    }
    else
    {




        key=no_key3;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move3)
        {
            p.float_player(e);
            p.player_movement(not_moving3, player_state);
        }

    }

    if(movement_result==cannot_move3)
    {

        key=no_key3;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result==can_move3)
        {
            p.float_player(e);
            p.player_movement(not_moving3, player_state);
        }
    }



    if(p.get_player_pos_y()<35 && factor!=0)
        factor--;
    else if(p.get_player_pos_y()>35 && factor!=10)
        factor++;

}

Movement_Result3 Game_logic3::is_movement_allowed(Player3 temp_player, Environment3 temp_env, Player_State3 temp_state, Action3 temp_action) const
{
    Movement_Result3 result=can_move3;

    //the following portion imitate the action on a temporary world to see if it breaks the rule
    if(key==up_key3)
    {
        if(temp_player.get_fuel()>4)
            temp_player.set_flying(fly_up3);


        temp_player.float_player(temp_env);

        temp_player.set_flying(fly_forward3);
    }
    else if(key==down_key3)
    {



        temp_player.set_flying(not_flying3);
        temp_player.float_player(e);

    }
    else if(key==right_key3)
    {
        if(temp_state==right_no_gun3 || temp_state==right_gun3)
            temp_action=move_right3;
        else
        {
            temp_action=not_moving3;

            if(temp_state==left_no_gun3)
                temp_state=right_no_gun3;
            else if(temp_state==left_gun3)
                temp_state=right_gun3;

        }

        temp_player.float_player(temp_env);
        temp_player.player_movement(temp_action, temp_state);
    }
    else if(key==left_key3)
    {
        if(temp_state==left_no_gun3 || temp_state==left_gun3)
            temp_action=move_left3;
        else
        {
            temp_action=not_moving3;

            if(temp_state==right_no_gun3)
                temp_state=left_no_gun3;
            else if(temp_state==right_gun3)
                temp_state=left_gun3;

        }

        temp_player.float_player(temp_env);
        temp_player.player_movement(temp_action, temp_state);
    }
    else if(key==enter_key3)
    {
        if(temp_state==right_no_gun3)
            temp_state=right_gun3;
        else if(temp_state==right_gun3)
            temp_state=right_no_gun3;
        else if(temp_state==left_no_gun3)
            temp_state=left_gun3;
        else if(temp_state==left_gun3)
            temp_state=left_no_gun3;

        temp_action=not_moving3;

        temp_player.float_player(e);
        temp_player.player_movement(temp_action, temp_state);
    }
    else if(key==no_key3)
    {
        temp_player.float_player(temp_env);
        temp_player.player_movement(not_moving3, temp_state);
    }

    for(int i=0; i<60; i++)
    {
        for(int j=0; j< 150; j++)
        {

            if(temp_player.get_player(i, j)!=32 && (temp_env.get_environment1(i, j) ==(char) 216 || temp_env.get_environment1(i, j) ==(char) 179 ))
                result=got_trapped3;
            else if(temp_player.get_player(i, j)!=32 &&  (temp_env.get_environment1(i, j) !='.' && (temp_env.get_environment1(i,j) <'A' || temp_env.get_environment1(i,j) >'Z') ) )
                result=cannot_move3;
        }
        if(result!=can_move3)
            break;
    }

    return result;


}
