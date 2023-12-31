#include <iostream>
#include <conio.h>

#include "Environment2.h"
#include "Player2.h"
#include "Enemy_type_0.h"

#include "utility/console_utility.hpp"
#include "utility/device_utility.hpp"
#include "utility/screen_utility.hpp"
#include "utility/menu_utility.hpp"

using namespace std;

 enum Key_Press2
{
    up_key2, down_key2, left_key2, right_key2, enter_key2, space_key2, no_key2
};

 enum Movement_Result2
{
    can_move2, cannot_move2, got_trapped2
};

 enum Game_State2
{
    failed2, running2, passed2
};



class Game_logic2
{

private:
    bool will_resume;

    Action2 player_action;
    Player_State2 player_state;
    Environment2 e;
    Player2 p;
    Enemy_type_0 e0[10];
    int enemy0_count;
    int destroyed_e0_count;
    int move_box_delay;
    int factor;
    Movement_Result2 movement_result;
    Key_Press2 key;
    int key_collected;
    Game_State2 game_state;

    ///utility
    Keyboard keyboard;
    Screen* main_screen;

    void screen_setup();
    void screen_dump();

public:
    Game_logic2();
    void show_rules();
    void game_flow();
    Movement_Result2 is_movement_allowed(Player2 temp_player, Environment2 temp_env, Player_State2 temp_state, Action2 temp_action) const;
    void set_main_screen();
    Game_State2 end_game_check();
    void keyboard_press_action();
    void collision_check_P_E0 ();
    void collision_check_PB_E0();

    void collision_check_P_MS();
    void collectable_check();
    void show_hud();

};

void Game_logic2::screen_setup()
{
    main_screen = new Screen(150, 50);
}

void Game_logic2::screen_dump()
{
    delete main_screen;
}


void Game_logic2::show_rules()
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
    cout<<"> Enemy will die after getting hit by player bullet for one or more time"<<endl;
    cout<<"> Getting hit by bullet will decrease player health"<<endl;
    cout<<"> Getting direct contact with enemy will destroy enemy and deplete health"<<endl;
    cout<<"> Collect all keys to unlock first door"<<endl;
    cout<<"> Destroy all enemies to unlock second door"<<endl;
    cout<<"> You cannot put gun out too close to wall and near trap"<<endl;
    cout<<endl;

    cout<<"------------"<<endl;
    cout<<"Collectables"<<endl;
    cout<<"------------"<<endl;
    cout<<"H: Restores Health"<<endl;
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

Game_logic2:: Game_logic2()
{
    player_state= right_no_gun2;
    player_action=not_moving2;

    factor=10;

    move_box_delay=0;
    destroyed_e0_count=0;
    key_collected=0;

    movement_result=can_move2;
    game_state=running2;

    enemy0_count=10;

    e0[0].set_enemy_type_0(7, 100);
    e0[1].set_enemy_type_0(10, 125);
    e0[2].set_enemy_type_0(25, 115);
    e0[3].set_enemy_type_0(40, 95);
    e0[4].set_enemy_type_0(55, 140);
    e0[5].set_enemy_type_0(52, 130);
    e0[6].set_enemy_type_0(30, 140);
    e0[7].set_enemy_type_0(26, 125);
    e0[8].set_enemy_type_0(20, 110);
    e0[9].set_enemy_type_0(15, 125);

    will_resume = true;
}


void Game_logic2:: game_flow()
{
    screen_setup();

    while(1)
    {

        collectable_check();

        set_main_screen();
        main_screen->show();
        show_hud();

//
//
//
        game_state= end_game_check();
//
        if(game_state!=running2)
            break;
//

//
//
//
        keyboard.checkKeyState();
//
//
        keyboard_press_action();
        if(will_resume == false) break;
//
        p.change_fuel();
        p.move_player_bullet(e);
        e.shoot_machine();

        if(move_box_delay==2)
        {
            e.change_move_box_state();
            move_box_delay=0;
        }
        else
            move_box_delay++;

        for(int n=0; n<enemy0_count; n++)
        {
            e0[n].move_enemy(e);

        }

        if(p.get_fuel()<2)
            p.set_flying(not_flying2);

        collision_check_P_E0 ();
        collision_check_PB_E0();
//
        collision_check_P_MS();

//
//

        destroyed_e0_count=0;
        for(int i=0; i<enemy0_count; i++)
            if(e0[i].get_is_destroyed()==true)
                destroyed_e0_count++;

        if(key_collected==3)
            e.open_door(0);

        if(destroyed_e0_count==enemy0_count)
        {
            e.open_door(1);
            if(p.get_player_pos_x()>=140)
                game_state=passed2;
        }

        for(int i=0; i<60; i++)
            for(int j=0; j<150; j++)
            {
                if(e.get_move_box_array(i,j)=='M' && p.get_player(i,j)!=32)
                    movement_result=got_trapped2;
            }
        if(movement_result==got_trapped2)
            p.set_player_hp(0);

    }

    screen_dump();
}



Game_State2 Game_logic2::end_game_check()
{
    if(movement_result==got_trapped2 || p.get_player_hp()<=0)
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

        return failed2;
    }
    else if(game_state==passed2)
    {
        char temp[]= "CONGRATULATION ON PASSING LEVEL 1";

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

        return passed2;


    }
    else
        return running2;

}

void Game_logic2::show_hud()
{
    for(int i=0; i<150; i++)
        cout<<" ";
    cout<<endl;

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

void Game_logic2:: set_main_screen()
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

            if(e.get_move_box_array(i+factor, j)=='M')
                main_screen->set_pixel(j, i, 232);

            if(e.get_machine_shooter_array(i+factor, j)!=32)
            {
                if(e.get_machine_shooter_array(i+factor, j)=='D')
                    main_screen->set_pixel(j, i, '|');
                else
                    main_screen->set_pixel(j, i, '-');

            }

            for(int n=0; n<enemy0_count; n++)
            {
                if((e0[n].get_enemy_array(i+factor, j))!=32 )
                    main_screen->set_pixel(j, i, e0[n].get_enemy_array(i+factor, j));



            }
//
            if((p.get_player_bullet_array(i+factor, j))!=32 )
                main_screen->set_pixel(j, i, 'o');

        }
    }
}





void Game_logic2::collision_check_P_MS()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
        {
            if(p.get_player(i,j)!=32 && e.get_machine_shooter_array(i,j) !=32 )
            {
                p.set_player_hp(p.get_player_hp()-5);
                e.destroy_machine_shooter_bullet(i, j);
            }
        }
    }
}


//
//
//
void Game_logic2::collision_check_P_E0 ()
{
    for(int k=0; k<enemy0_count; k++)
    {
        for(int i=0; i<60; i++)
        {
            for(int j=0; j<150; j++)
            {
                if(p.get_player(i,j)!=32 && e0[k].get_enemy_array(i,j) !=32 )
                {
                    p.set_player_hp(p.get_player_hp()-e0[k].get_destruct_power());
                    e0[k].destroy_enemy_type_0();


                }
            }
        }
    }

}

void Game_logic2::collision_check_PB_E0()
{
    for(int k=0; k<enemy0_count; k++)
    {
        for(int i=0; i<60; i++)
        {
            for(int j=0; j<150; j++)
            {
                if(p.get_player_bullet_array(i,j)!=32 && e0[k].get_enemy_array(i,j) !=32 )
                {
                    e0[k].destroy_enemy_type_0();

                    p.destroy_player_bullet(i, j);
                }
            }
        }
    }
}








void Game_logic2::collectable_check()
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

                key_collected++;
                e.destroy_collectible(i,j);
            }



        }
    }
}

void Game_logic2::keyboard_press_action()
{
    if(keyboard.getKey(Keyboard::UP_ARROW).isDown())
    {


        key=up_key2;

        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move2)
        {
            if(p.get_fuel()>4)
                p.set_flying(fly_up2);


            p.float_player(e);

            p.set_flying(fly_forward2);

        }
        else if(movement_result==cannot_move2)
        {
            if(p.get_fuel()>4)
                p.set_flying(fly_forward2);


            p.float_player(e);
        }
    }
    else if(keyboard.getKey(Keyboard::DOWN_ARROW).isDown())
    {
        if(p.get_player_pos_y()>25 && factor!=10)
            factor++;

        key=down_key2;

        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move2)
        {
            p.set_flying(not_flying2);
            p.float_player(e);

        }
    }
    else if(keyboard.getKey(Keyboard::RIGHT_ARROW).isDown())
    {
        key=right_key2;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move2)
        {
            if(player_state==right_no_gun2 || player_state==right_gun2)
                player_action=move_right2;
            else
            {
                player_action=not_moving2;

                if(player_state==left_no_gun2)
                    player_state=right_no_gun2;
                else if(player_state==left_gun2)
                    player_state=right_gun2;

            }

            p.float_player(e);
            p.player_movement(player_action, player_state);
        }
    }
    else if(keyboard.getKey(Keyboard::LEFT_ARROW).isDown())
    {

        key=left_key2;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move2)
        {
            if(player_state==left_no_gun2 || player_state==left_gun2)
                player_action=move_left2;
            else
            {
                player_action=not_moving2;

                if(player_state==right_no_gun2)
                    player_state=left_no_gun2;
                else if(player_state==right_gun2)
                    player_state=left_gun2;

            }

            p.float_player(e);
            p.player_movement(player_action, player_state);
        }
    }
    else if(keyboard.getKey(Keyboard::ENTER).isDown() && p.get_flying()!=fly_up2 )
    {
        key=enter_key2;


        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move2)
        {
            if(player_state==right_no_gun2)
                player_state=right_gun2;
            else if(player_state==right_gun2)
                player_state=right_no_gun2;
            else if(player_state==left_no_gun2)
                player_state=left_gun2;
            else if(player_state==left_gun2)
                player_state=left_no_gun2;

            player_action=not_moving2;

            p.float_player(e);
            p.player_movement(player_action, player_state);
        }

    }
    else if(keyboard.getKey(Keyboard::SPACEBAR).isDown())
    {

        p.shoot_player_bullet(e);

        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move2)
        {
            player_action=not_moving2;

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




        key=no_key2;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result!=cannot_move2)
        {
            p.float_player(e);
            p.player_movement(not_moving2, player_state);
        }

    }

    if(movement_result==cannot_move2)
    {

        key=no_key2;



        movement_result= is_movement_allowed(p, e, player_state, player_action);

        if( movement_result==can_move2)
        {
            p.float_player(e);
            p.player_movement(not_moving2, player_state);
        }
    }



    if(p.get_player_pos_y()<35 && factor!=0)
        factor--;
    else if(p.get_player_pos_y()>35 && factor!=10)
        factor++;

}

Movement_Result2 Game_logic2::is_movement_allowed(Player2 temp_player, Environment2 temp_env, Player_State2 temp_state, Action2 temp_action) const
{
    Movement_Result2 result=can_move2;

    //the following portion imitate the action on a temporary world to see if it breaks the rule
    if(key==up_key2)
    {
        if(temp_player.get_fuel()>4)
            temp_player.set_flying(fly_up2);


        temp_player.float_player(temp_env);

        temp_player.set_flying(fly_forward2);
    }
    else if(key==down_key2)
    {
        temp_player.set_flying(not_flying2);
        temp_player.float_player(e);
    }
    else if(key==right_key2)
    {
        if(temp_state==right_no_gun2 || temp_state==right_gun2)
            temp_action=move_right2;
        else
        {
            temp_action=not_moving2;

            if(temp_state==left_no_gun2)
                temp_state=right_no_gun2;
            else if(temp_state==left_gun2)
                temp_state=right_gun2;

        }

        temp_player.float_player(temp_env);
        temp_player.player_movement(temp_action, temp_state);
    }
    else if(key==left_key2)
    {
        if(temp_state==left_no_gun2 || temp_state==left_gun2)
            temp_action=move_left2;
        else
        {
            temp_action=not_moving2;

            if(temp_state==right_no_gun2)
                temp_state=left_no_gun2;
            else if(temp_state==right_gun2)
                temp_state=left_gun2;

        }

        temp_player.float_player(temp_env);
        temp_player.player_movement(temp_action, temp_state);
    }
    else if(key==enter_key2)
    {
        if(temp_state==right_no_gun2)
            temp_state=right_gun2;
        else if(temp_state==right_gun2)
            temp_state=right_no_gun2;
        else if(temp_state==left_no_gun2)
            temp_state=left_gun2;
        else if(temp_state==left_gun2)
            temp_state=left_no_gun2;

        temp_action=not_moving2;

        temp_player.float_player(e);
        temp_player.player_movement(temp_action, temp_state);
    }
    else if(key==no_key2)
    {
        temp_player.float_player(temp_env);
        temp_player.player_movement(not_moving2, temp_state);
    }

    for(int i=0; i<60; i++)
    {
        for(int j=0; j< 150; j++)
        {

            if(temp_player.get_player(i, j)!=32 && ( temp_env.get_move_box_array(i, j) =='M' || (temp_env.get_environment1(i, j) !='.' && (temp_env.get_environment1(i,j) <'A' || temp_env.get_environment1(i,j) >'Z') ) ) )
                result=cannot_move2;
        }
        if(result!=can_move2)
            break;
    }

    return result;


}


