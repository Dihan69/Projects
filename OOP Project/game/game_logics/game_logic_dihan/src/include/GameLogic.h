#pragma once

#include <iostream>
#include <string.h>

#include "Player.h"
#include "Environment1.h"
#include "Enemy_Type_1.h"
#include "Enemy_Type_2.h"

#include "utility/screen_utility.hpp"
#include "utility/device_utility.hpp"
#include "utility/menu_utility.hpp"

using namespace std;

enum Key_Press
{
    up_key, down_key, left_key, right_key, enter_key, space_key, no_key
};

enum Movement_Result
{
    can_move, cannot_move, got_trapped
};

enum Game_State
{
    failed, running, passed
};

class Game_logic
{

private:
    bool will_resume;

    Action player_action;
    Player_State player_state;
    Environment1 e;
    Player p;
    Enemy_Type_1 enemy1;
    Enemy_Type_2 enemy2[4];
    int enemy2_count;
    int factor;
    Movement_Result movement_result;
    Key_Press key;
    Game_State game_state;

    ///utility
    Keyboard keyboard;
    Screen* main_screen;

    void screen_setup();
    void screen_dump();

public:
    Game_logic();
    void show_rules();
    void game_flow();
    Movement_Result is_movement_allowed(Player temp_player, Environment1 temp_env, Player_State temp_state, Action temp_action) const;
    void set_main_screen();
    Game_State end_game_check();
    void keyboard_press_action();
    void collision_check_P_EB1( );
    void collision_check_PB_E1 ();
    void collision_check_P_E1 ();
    void collision_check_P_E2 ();
    void collision_check_PB_EB1 ();
    void collision_check_PB_EB2 ();
    void collision_check_PB_E2();
    void collision_check_P_EB2();
    void collision_check_P_MS();
    void collectable_check();
    void show_hud();

};

void Game_logic::screen_setup()
{
    main_screen = new Screen(150, 50);
}

void Game_logic::screen_dump()
{
    delete main_screen;
}

void Game_logic::show_rules()
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

    cout<<endl;

    cout<<"PRESS SPACEBAR TO CONTINUE...."<<endl;

    while(1)
    {
        keyboard.checkKeyState();
        if(keyboard.getKey(Keyboard::SPACEBAR).isPressed()) break;
    }
}




///FUNCTIONS FOR GAME LOGIC CLASS///

Game_logic:: Game_logic()
{
    player_state= right_no_gun;
    player_action=not_moving;

    factor=10;

    enemy2_count=4;

    movement_result=can_move;
    game_state=running;


    enemy2[0].set_enemy_pos(17, 125);
    enemy2[1].set_enemy_pos(50, 136);
    enemy2[2].set_enemy_pos(56, 116);
    enemy2[3].set_enemy_pos(37, 126);
    enemy2[3].change_enemy_state(moving_down);

    will_resume = true;
}


void Game_logic:: game_flow()
{
    screen_setup();

    while(1)
    {


        set_main_screen();
        main_screen->show();
        show_hud();



         game_state= end_game_check();

        if(game_state!=running)
            break;

        collectable_check();



        keyboard.checkKeyState();


        keyboard_press_action();
        if(will_resume == false) break;

        p.change_fuel();
        p.move_player_bullet(e);
        e.shoot_machine();
        enemy1.move_enemy(e);
        enemy1.shoot_enemy_bullet(e);

        for(int n=0; n<enemy2_count; n++)
        {
            enemy2[n].move_enemy(e);
            enemy2[n].shoot_enemy_bullet(e);
        }

        if(p.get_fuel()<2)
            p.set_flying(not_flying);

        collision_check_P_MS();
        collision_check_PB_EB2 ();
        collision_check_PB_EB1 ();
        collision_check_P_EB1();
        collision_check_P_E1 ();
        collision_check_P_E2 ();
        collision_check_PB_E1 ();
        collision_check_P_EB2();
        collision_check_PB_E2();


        if(enemy2[0].get_enemy_hp()<=0 && enemy2[1].get_enemy_hp()<=0 && enemy2[2].get_enemy_hp()<=0 && enemy2[3].get_enemy_hp()<=0)
            {
                e.open_door(1);
                if(p.get_player_pos_x()>=140)
                        game_state=passed;
            }
        if(movement_result==got_trapped)
            p.set_player_hp(0);

    }

    screen_dump();
}

Game_State Game_logic::end_game_check()
{
    if(movement_result==got_trapped || p.get_player_hp()<=0)
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

        return failed;
    }
    else if(game_state==passed)
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

         return passed;


    }
    else
        return running;

}

void Game_logic::show_hud()
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

void Game_logic:: set_main_screen()
{
    for(int i=0; i<60-factor; i++)
    {
        for(int j=0; j<150; j++)
        {


            if(p.get_player(i+factor, j)!=32)
                main_screen->set_pixel(j, i, p.get_player(i+factor, j));

            if(e.get_environment1(i+factor, j)==':')
                main_screen->set_pixel(j, i, 219);
            else  if(e.get_environment1(i+factor, j)=='.' && p.get_player(i+factor, j)==32 )
                main_screen->set_pixel(j, i, 32);
            else if(e.get_environment1(i+factor, j)!='.')
                main_screen->set_pixel(j, i, e.get_environment1(i+factor, j));


            if(e.get_machine_shooter_array(i+factor, j)!=32)
                main_screen->set_pixel(j, i, '|');

            if((enemy1.get_enemy_array(i+factor, j))!=32 )
                main_screen->set_pixel(j, i, enemy1.get_enemy_array(i+factor, j));

            if((enemy1.get_enemy_bullet_array(i+factor, j))!=32 )
                main_screen->set_pixel(j, i, '*');

            for(int n=0; n<enemy2_count; n++)
            {
                if((enemy2[n].get_enemy_array(i+factor, j))!=32 )
                    main_screen->set_pixel(j, i, enemy2[n].get_enemy_array(i+factor, j));

                if((enemy2[n].get_enemy_bullet_array(i+factor, j))!=32 )
                    main_screen->set_pixel(j, i, '*');

            }

            if((p.get_player_bullet_array(i+factor, j))!=32 )
                main_screen->set_pixel(j, i, 'o');

        }
    }
}

void Game_logic::collision_check_P_EB1( )
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
        {
            if(p.get_player(i,j)!=32 && enemy1.get_enemy_bullet_array(i,j) !=32 )
            {
                p.set_player_hp(p.get_player_hp()-enemy1.get_bullet_power());
                enemy1.destroy_enemy_bullet_array(i, j);
            }
        }
    }
}

void Game_logic:: collision_check_P_EB2()
{
    for(int k=0; k<enemy2_count; k++)
    {
        for(int i=0; i<60; i++)
        {
            for(int j=0; j<150; j++)
            {
                if(p.get_player(i,j)!=32 && enemy2[k].get_enemy_bullet_array(i,j) !=32 )
                {
                    p.set_player_hp(p.get_player_hp()-enemy2[k].get_bullet_power());
                    enemy2[k].destroy_enemy_bullet_array(i, j);
                }
            }
        }
    }
}

void Game_logic::collision_check_P_MS()
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

void Game_logic::collision_check_PB_E1 ()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
        {
            if(p.get_player_bullet_array(i,j)!=32 && enemy1.get_enemy_array(i,j) !=32 )
            {
                enemy1.set_enemy_hp(enemy1.get_enemy_hp()-p.get_gun_power());
                p.destroy_player_bullet(i, j);
            }
        }
    }
}

void Game_logic::collision_check_P_E1 ()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
        {
            if(p.get_player(i,j)!=32 && enemy1.get_enemy_array(i,j) !=32 )
            {
                p.set_player_hp(0);
            }
        }
    }
}

void Game_logic::collision_check_P_E2 ()
{
      for(int k=0; k<enemy2_count; k++)
    {
        for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
        {
            if(p.get_player(i,j)!=32 && enemy2[k].get_enemy_array(i,j) !=32 )
            {
                p.set_player_hp(0);
            }
        }
    }
    }

    }


void Game_logic::collision_check_PB_EB1 ()
{

    for(int i=0; i<60; i++)
    {
        for(int j=0; j<149; j++)
        {
            if( (p.get_player_bullet_array(i,j)!=32 && enemy1.get_enemy_bullet_array(i,j) !=32) || (p.get_player_bullet_array(i,j+1)!=32 && enemy1.get_enemy_bullet_array(i,j) !=32) ||
                    (p.get_player_bullet_array(i,j)!=32 && enemy1.get_enemy_bullet_array(i,j+1) !=32) || (p.get_player_bullet_array(i,j+1)!=32 && enemy1.get_enemy_bullet_array(i,j+1) !=32) )

            {
                p.destroy_player_bullet(i, j);
                enemy1.destroy_enemy_bullet_array(i, j);
                p.destroy_player_bullet(i, j+1);
                enemy1.destroy_enemy_bullet_array(i, j+1);
            }
        }
    }
}

void Game_logic::collision_check_PB_EB2 ()
{
    for(int k=0; k<enemy2_count; k++)
    {
        for(int i=0; i<60; i++)
        {
            for(int j=0; j<149; j++)
            {
                if( (p.get_player_bullet_array(i,j)!=32 && enemy2[k].get_enemy_bullet_array(i,j) !=32) || (p.get_player_bullet_array(i,j+1)!=32 && enemy2[k].get_enemy_bullet_array(i,j) !=32) ||
                        (p.get_player_bullet_array(i,j)!=32 && enemy2[k].get_enemy_bullet_array(i,j+1) !=32) || (p.get_player_bullet_array(i,j+1)!=32 && enemy2[k].get_enemy_bullet_array(i,j+1) !=32) )

                {
                    p.destroy_player_bullet(i, j);
                    enemy2[k].destroy_enemy_bullet_array(i, j);
                    p.destroy_player_bullet(i, j+1);
                    enemy2[k].destroy_enemy_bullet_array(i, j+1);
                }
            }
        }
    }
}

void Game_logic::collision_check_PB_E2()
{
    for(int k=0; k<4; k++)
    {
        for(int i=0; i<60; i++)
        {
            for(int j=0; j<150; j++)
            {
                if(p.get_player_bullet_array(i,j)!=32 && enemy2[k].get_enemy_array(i,j) !=32 )
                {
                    enemy2[k].set_enemy_hp(enemy2[k].get_enemy_hp()-p.get_gun_power());
                    p.destroy_player_bullet(i, j);
                }
            }
        }
    }
}

void Game_logic::collectable_check()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<149; j++)
        {
            if(p.get_player(i,j)!=32 && e.get_environment1(i,j)=='F')
            {
                p.set_fuel_capacity(p.get_capacity()+20);
                e.destroy_collectible(i,j);
            }

            if(p.get_player(i,j)!=32 && e.get_environment1(i,j)=='H')
            {
                p.set_player_hp(p.get_player_max_hp());
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

void Game_logic::keyboard_press_action()
{
    if(keyboard.getKey(Keyboard::UP_ARROW).isDown())
    {


        key=up_key;

        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move)
        {
            if(p.get_fuel()>4)
                p.set_flying(fly_up);


            p.float_player(e);

            p.set_flying(fly_forward);

        }
        else if(movement_result==cannot_move)
        {
            if(p.get_fuel()>4)
                p.set_flying(fly_forward);


            p.float_player(e);
        }
    }
    else if(keyboard.getKey(Keyboard::DOWN_ARROW).isDown())
    {
        if(p.get_player_pos_y()>25 && factor!=10)
            factor++;

        key=down_key;

        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move)
        {
            p.set_flying(not_flying);
            p.float_player(e);

        }
    }
    else if(keyboard.getKey(Keyboard::RIGHT_ARROW).isDown())
    {
        key=right_key;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move)
        {
            if(player_state==right_no_gun || player_state==right_gun)
                player_action=move_right;
            else
            {
                player_action=not_moving;

                if(player_state==left_no_gun)
                    player_state=right_no_gun;
                else if(player_state==left_gun)
                    player_state=right_gun;

            }

            p.float_player(e);
            p.player_movement(player_action, player_state);
        }
    }
    else if(keyboard.getKey(Keyboard::LEFT_ARROW).isDown())
    {

        key=left_key;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move)
        {
            if(player_state==left_no_gun || player_state==left_gun)
                player_action=move_left;
            else
            {
                player_action=not_moving;

                if(player_state==right_no_gun)
                    player_state=left_no_gun;
                else if(player_state==right_gun)
                    player_state=left_gun;

            }

            p.float_player(e);
            p.player_movement(player_action, player_state);
        }
    }
    else if(keyboard.getKey(Keyboard::ENTER).isDown() && p.get_flying()!=fly_up )
    {
        key=enter_key;


        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move)
        {
            if(player_state==right_no_gun)
                player_state=right_gun;
            else if(player_state==right_gun)
                player_state=right_no_gun;
            else if(player_state==left_no_gun)
                player_state=left_gun;
            else if(player_state==left_gun)
                player_state=left_no_gun;

            player_action=not_moving;

            p.float_player(e);
            p.player_movement(player_action, player_state);
        }

    }
    else if(keyboard.getKey(Keyboard::SPACEBAR).isDown())
    {

        p.shoot_player_bullet(e);

        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move)
        {
            player_action=not_moving;

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




        key=no_key;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move)
        {
            p.float_player(e);
            p.player_movement(not_moving, player_state);
        }

    }

    if(movement_result==cannot_move)
    {

        key=no_key;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result==can_move)
        {
            p.float_player(e);
            p.player_movement(not_moving, player_state);
        }
    }



    if(p.get_player_pos_y()<35 && factor!=0)
        factor--;
    else if(p.get_player_pos_y()>35 && factor!=10)
        factor++;

}

Movement_Result Game_logic::is_movement_allowed(Player temp_player, Environment1 temp_env, Player_State temp_state, Action temp_action) const
{
    Movement_Result result=can_move;

    //the following portion imitate the action on a temporary world to see if it breaks the rule
    if(key==up_key)
    {
        if(temp_player.get_fuel()>4)
            temp_player.set_flying(fly_up);


        temp_player.float_player(temp_env);

        temp_player.set_flying(fly_forward);
    }
    else if(key==down_key)
    {
        temp_player.set_flying(not_flying);
        temp_player.float_player(e);
    }
    else if(key==right_key)
    {
        if(temp_state==right_no_gun || temp_state==right_gun)
            temp_action=move_right;
        else
        {
            temp_action=not_moving;

            if(temp_state==left_no_gun)
                temp_state=right_no_gun;
            else if(temp_state==left_gun)
                temp_state=right_gun;

        }

        temp_player.float_player(temp_env);
        temp_player.player_movement(temp_action, temp_state);
    }
    else if(key==left_key)
    {
        if(temp_state==left_no_gun || temp_state==left_gun)
            temp_action=move_left;
        else
        {
            temp_action=not_moving;

            if(temp_state==right_no_gun)
                temp_state=left_no_gun;
            else if(temp_state==right_gun)
                temp_state=left_gun;

        }

        temp_player.float_player(temp_env);
        temp_player.player_movement(temp_action, temp_state);
    }
    else if(key==enter_key)
    {
        if(temp_state==right_no_gun)
            temp_state=right_gun;
        else if(temp_state==right_gun)
            temp_state=right_no_gun;
        else if(temp_state==left_no_gun)
            temp_state=left_gun;
        else if(temp_state==left_gun)
            temp_state=left_no_gun;

        temp_action=not_moving;

        temp_player.float_player(e);
        temp_player.player_movement(temp_action, temp_state);
    }
    else if(key==no_key)
    {
        temp_player.float_player(temp_env);
        temp_player.player_movement(not_moving, temp_state);
    }

    for(int i=0; i<60; i++)
    {
        for(int j=0; j< 150; j++)
        {

            if(temp_player.get_player(i, j)!=32 && (temp_env.get_environment1(i, j) ==(char) 216 || temp_env.get_environment1(i, j) ==(char) 179 ))
                result=got_trapped;
            else if(temp_player.get_player(i, j)!=32 && (temp_env.get_environment1(i, j) !='.' && (temp_env.get_environment1(i,j) <'A' || temp_env.get_environment1(i,j) >'Z') ) )
                result=cannot_move;
        }
        if(result!=can_move)
            break;
    }

    return result;


}
