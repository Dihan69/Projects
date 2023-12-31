#include "include/Environment1.h"

#include <iostream>
#include <fstream>


Environment1::Environment1()
{
    ifstream inFile;
    inFile.open("Demo.txt");

    int row=60, collum=150;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<collum; j++)
            inFile >> environment1[i][j];
    }

    trap[0].set_trap(3,23, down, 14,3);
    trap[1].set_trap(2,2, up,36,14);
    trap[2].set_trap( 2, 4, up, 4,33);
    trap[3].set_trap( 3, 3, up, 25,46);
    trap[4].set_trap( 2, 6,  up, 41,40);
    trap[5].set_trap(3, 9, up, 71, 44);
    trap[6].set_trap(8, 10, up, 88, 56);

    set_trap_view();

    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
            shooter[i][j]=' ';
    }

    machine_shooter[0].set_machine_shooter(3, 3, 57, 18, up_to_down);
    machine_shooter[1].set_machine_shooter(3, 3, 71, 24, up_to_down);

    door[0].set_door_height(16);
    door[0].set_door_pos_x(98);
    door[0].set_door_pos_y(3);
    door[0].set_door_length(2);
    door[1].set_door_height(21);
    door[1].set_door_pos_x(148);
    door[1].set_door_pos_y(36);
    door[1].set_door_length(2);

    set_door_view();

}

void Environment1::shoot_machine()
{
    for(int i=0; i<2; i++)
    {
        if(machine_shooter[i].get_current_delay()==5)
        {
            for(int x=0; x<machine_shooter[i].get_length(); x++)
            {

                if(machine_shooter[i].get_shoot_direction()==up_to_down)

                    shooter[machine_shooter[i].get_pos_y()+1][machine_shooter[i].get_pos_x()+x]='D';
            }

            machine_shooter[i].increment_current_delay();

        }
        else
            machine_shooter[i].increment_current_delay();

        for(int y=59; y>0; y--)
            for(int x=machine_shooter[i].get_pos_x( ); x<machine_shooter[i].get_pos_x( )+machine_shooter[i].get_length() ; x++)
                //{
            {
                if(shooter[y-1][x]=='D')
                    shooter[y][x]=shooter[y-1][x];
                else
                    shooter[y][x]=32;

            }

        //destroy bullet if hit by wall
        for(int y=0; y<60; y++)
        {
            for(int x=0; x<150; x++)
            {
                if(environment1[y][x]==':')
                    shooter[y][x]=32;
            }
        }

    }
}

char Environment1::get_environment1(int i, int j) const
{
    return environment1[i][j];
}

void Environment1::destroy_bullet(int i, int j)
{
    shooter[i][j]=32;
}
void Environment1::destroy_collectible(int i, int j)
{
    environment1[i][j]='.';
}



void Environment1:: set_trap_view()
{
    for(int i=0; i<7; i++)
    {
        for(int x= trap[i].get_trap_x() ; x< trap[i].get_trap_x()+ trap[i].get_length(); x++  )
            environment1[trap[i].get_trap_y()][x]=177;

        if(trap[i].get_direction()== up )

            for(int y=trap[i].get_trap_y()-1; y>trap[i].get_trap_y()-trap[i].get_height(); y--)
            {
                for(int x= trap[i].get_trap_x() ; x< trap[i].get_trap_x()+ trap[i].get_length(); x++  )
                    environment1[y][x]=216;
            }

        if(trap[i].get_direction()== down )
        {
            for(int y=trap[i].get_trap_y()+1; y<trap[i].get_trap_y()+trap[i].get_height(); y++)
            {
                for(int x= trap[i].get_trap_x() ; x< trap[i].get_trap_x()+ trap[i].get_length(); x++  )
                    environment1[y][x]=216;
            }
        }

        if(trap[i].get_direction()== up )


        {
            for(int x= trap[i].get_trap_x() ; x< trap[i].get_trap_x()+ trap[i].get_length(); x++  )
                environment1[trap[i].get_trap_y()-trap[i].get_height()+1][x]=179;
        }

        if(trap[i].get_direction()== down )
        {

            for(int x= trap[i].get_trap_x() ; x< trap[i].get_trap_x()+ trap[i].get_length(); x++  )
                environment1[trap[i].get_trap_y()+trap[i].get_height()-1][x]=179;
        }

    }



}

void Environment1::set_door_view()
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<door[i].get_door_height(); j++)
        {
            for(int k=0; k<door[i].get_door_length(); k++)
                environment1[door[i].get_door_pos_y()+j][door[i].get_door_pos_x()+k]='|';
        }
    }
}

void Environment1::open_door(int i)
{

    for(int j=0; j<door[i].get_door_height(); j++)
    {
        for(int k=0; k<door[i].get_door_length(); k++)
            environment1[door[i].get_door_pos_y()+j][door[i].get_door_pos_x()+k]='.';
    }
}


char Environment1::get_machine_shooter_array( int i, int j )
{
    return shooter[i][j];
}

void Environment1::destroy_machine_shooter_bullet(int i, int j)
{
    shooter[i][j]=' ';
}

