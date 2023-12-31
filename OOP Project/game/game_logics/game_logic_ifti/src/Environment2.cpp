#include "include/Environment2.h"


#include <iostream>
#include <fstream>

using namespace std;

Environment2::Environment2()
{
    ifstream inFile;
    inFile.open("Level0.txt");

    int row=60, collum=150;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<collum; j++)
            inFile >> environment2[i][j];
    }

    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
            shooter[i][j]=' ';
    }

    machine_shooter[0].set_machine_shooter(4, 6, 2, 30, left_to_right);
    machine_shooter[1].set_machine_shooter(4, 10, 32, 35, right_to_left);
    machine_shooter[2].set_machine_shooter(9, 7, 70, 15, right_to_left);
    machine_shooter[3].set_machine_shooter(5, 4, 44, 20, up_to_down);
    machine_shooter[4].set_machine_shooter(3, 50, 71, 25, right_to_left);
    machine_shooter[5].set_machine_shooter(3, 54, 71, 20, right_to_left);
    machine_shooter[6].set_machine_shooter(3, 16, 34, 12, up_to_down);
    machine_shooter[7].set_machine_shooter(3, 16, 39, 20, up_to_down);
    machine_shooter[8].set_machine_shooter(3,16, 44, 30, up_to_down);



    //(int l, int y, int x, int s, Shoot_Direction d)

    door[0].set_door_height(16);
    door[0].set_door_pos_x(75);
    door[0].set_door_pos_y(28);
    door[0].set_door_length(2);
    door[1].set_door_height(13);
    door[1].set_door_pos_x(146);
    door[1].set_door_pos_y(44);
    door[1].set_door_length(4);

    set_door_view();

    movable_box.set_movable_box(1, 62,5,10, up_down);

}



void Environment2::shoot_machine()
{
    for(int i=0; i<9; i++)
    {
        if(machine_shooter[i].get_current_delay()==5)
        {
            for(int x=0; x<machine_shooter[i].get_length(); x++)
            {

                if(machine_shooter[i].get_shoot_direction()==up_to_down)

                    shooter[machine_shooter[i].get_pos_y()+1][machine_shooter[i].get_pos_x()+x]='D';
                else if(machine_shooter[i].get_shoot_direction()==left_to_right)

                    shooter[machine_shooter[i].get_pos_y()+x][machine_shooter[i].get_pos_x()+1]='R';
                else if(machine_shooter[i].get_shoot_direction()==right_to_left)

                    shooter[machine_shooter[i].get_pos_y()+x][machine_shooter[i].get_pos_x()-1]='L';
            }

            machine_shooter[i].increment_current_delay();

        }
        else
            machine_shooter[i].increment_current_delay();






        //destroy bullet if hit by wall
        for(int y=0; y<60; y++)
        {
            for(int x=0; x<150; x++)
            {
                if(environment2[y][x]==':')
                    shooter[y][x]=32;
            }
        }

    }



    for(int t=0; t<2; t++)
    {

        for(int y=59; y>0; y--)
            for(int x=0; x<150; x++)
                //{
            {
                if(shooter[y-1][x]=='D')
                {
                    shooter[y][x]='D';
                    shooter[y-1][x]=32;
                }

            }

        for(int y=0; y<60; y++)
            for(int x=0; x<149; x++)
            {
                if(shooter[y][x+1]=='L')
                {
                    shooter[y][x]='L';
                    shooter[y][x+1]=32;
                }



            }

        for(int y=0; y<60; y++)
            for(int x=149; x>0; x--)

            {
                if(shooter[y][x-1]=='R')
                {
                    shooter[y][x]='R';
                    shooter[y][x-1]=32;
                }


            }


        //destroy bullet if hit by wall
        for(int y=0; y<60; y++)
        {
            for(int x=0; x<150; x++)
            {
                if(environment2[y][x]==':'||move_box_arr[y][x]=='M')
                    shooter[y][x]=32;
            }
        }

    }
}

char Environment2::get_environment1(int i, int j) const
{
    return environment2[i][j];
}

void Environment2::destroy_bullet(int i, int j)
{
    shooter[i][j]=32;
}
void Environment2::destroy_collectible(int i, int j)
{
    environment2[i][j]='.';
}





void Environment2::set_door_view()
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<door[i].get_door_height(); j++)
        {
            for(int k=0; k<door[i].get_door_length(); k++)
                environment2[door[i].get_door_pos_y()+j][door[i].get_door_pos_x()+k]='|';
        }
    }
}

void Environment2::open_door(int i)
{

    for(int j=0; j<door[i].get_door_height(); j++)
    {
        for(int k=0; k<door[i].get_door_length(); k++)
            environment2[door[i].get_door_pos_y()+j][door[i].get_door_pos_x()+k]='.';
    }
}

void Environment2::set_move_view()
{
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
            move_box_arr[i][j]=32;
    }

    for(int i=movable_box.get_pos_y(); i<movable_box.get_length()+movable_box.get_pos_y(); i++)
    {
        for(int j=movable_box.get_pos_x(); j<2+movable_box.get_pos_x(); j++)
            move_box_arr[i][j]='M';
    }
}

void Environment2::change_move_box_state()
{
    if(movable_box.get_direction()==up_down)
    {
        if(environment2[movable_box.get_pos_y()+movable_box.get_length()][movable_box.get_pos_x()] ==':' )
        movable_box.change_box_pos(movable_box.get_pos_x(),movable_box.get_pos_y(), down_up);
        else
            movable_box.change_box_pos(movable_box.get_pos_x(), movable_box.get_pos_y()+1, up_down);
    }
    else if(movable_box.get_direction()==down_up)
    {
        if(environment2[movable_box.get_pos_y()-1][movable_box.get_pos_x()] ==':' )
        movable_box.change_box_pos(movable_box.get_pos_x(),movable_box.get_pos_y(), up_down);
        else
            movable_box.change_box_pos(movable_box.get_pos_x(), movable_box.get_pos_y()-1, down_up);
    }

    set_move_view();


}


char Environment2::get_machine_shooter_array( int i, int j )
{
    return shooter[i][j];
}

void Environment2::destroy_machine_shooter_bullet(int i, int j)
{
    shooter[i][j]=' ';
}

char Environment2::get_move_box_array(int i, int j)
{
    return move_box_arr[i][j];
}
