#include "include/Environment3.h"

Environment3::Environment3()
{
    ifstream inFile;
    inFile.open("last_level.txt");

    int row=60, collum=150;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<collum; j++)
            inFile >> environment3[i][j];
    }

    trap[0].set_trap(3,2, up, 10,38);
    trap[1].set_trap(2,62, up,18,14);
    trap[2].set_trap( 3, 78, down, 68,2);
    trap[3].set_trap( 2, 30, up, 105,14);

    trap[4].set_trap( 4, 38,  up, 21,56);
    trap[5].set_trap(2, 37, up, 59, 56);
    trap[6].set_trap(5, 10, up, 96, 56);
    trap[7].set_trap(3, 25, up, 106, 56);

    trap[8].set_trap(3, 22, down, 66, 45);
    trap[9].set_trap(2, 13, down, 118, 45);
    // (int h, int l, Trap_Direction d, int x, int y)

    set_trap_view();

    for(int i=0; i<60; i++)
    {
        for(int j=0; j<150; j++)
            shooter[i][j]=' ';
    }

    machine_shooter[0].set_machine_shooter(2, 5, 2, 20, left_to_right);
    machine_shooter[1].set_machine_shooter(2, 8, 145, 110, right_to_left);

//(int l, int y, int x, int s, Shoot_Direction d)

    door.set_door_height(12);
    door.set_door_pos_x(146);
    door.set_door_pos_y(45);
    door.set_door_length(4);


    set_door_view();



}



char Environment3::get_environment1(int i, int j) const
{
    return environment3[i][j];
}


void Environment3::destroy_collectible(int i, int j)
{
    environment3[i][j]='.';
}



void Environment3:: set_trap_view()
{
    for(int i=0; i<10; i++)
    {
        for(int x= trap[i].get_trap_x() ; x< trap[i].get_trap_x()+ trap[i].get_length(); x++  )
            environment3[trap[i].get_trap_y()][x]=177;

        if(trap[i].get_direction()== up )

            for(int y=trap[i].get_trap_y()-1; y>trap[i].get_trap_y()-trap[i].get_height(); y--)
            {
                for(int x= trap[i].get_trap_x() ; x< trap[i].get_trap_x()+ trap[i].get_length(); x++  )
                    environment3[y][x]=216;
            }

        if(trap[i].get_direction()== down )
        {
            for(int y=trap[i].get_trap_y()+1; y<trap[i].get_trap_y()+trap[i].get_height(); y++)
            {
                for(int x= trap[i].get_trap_x() ; x< trap[i].get_trap_x()+ trap[i].get_length(); x++  )
                    environment3[y][x]=216;
            }
        }

        if(trap[i].get_direction()== up )


        {
            for(int x= trap[i].get_trap_x() ; x< trap[i].get_trap_x()+ trap[i].get_length(); x++  )
                environment3[trap[i].get_trap_y()-trap[i].get_height()+1][x]=179;
        }

        if(trap[i].get_direction()== down )
        {

            for(int x= trap[i].get_trap_x() ; x< trap[i].get_trap_x()+ trap[i].get_length(); x++  )
                environment3[trap[i].get_trap_y()+trap[i].get_height()-1][x]=179;
        }

    }



}

void Environment3::set_door_view()
{
    for(int j=0; j<door.get_door_height(); j++)
    {
        for(int k=0; k<door.get_door_length(); k++)
            environment3[door.get_door_pos_y()+j][door.get_door_pos_x()+k]='|';
    }

}

void Environment3::open_door(int i)
{

    for(int j=0; j<door.get_door_height(); j++)
    {
        for(int k=0; k<door.get_door_length(); k++)
            environment3[door.get_door_pos_y()+j][door.get_door_pos_x()+k]='.';
    }
}


void Environment3::shoot_machine()
{
    for(int i=0; i<2; i++)
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
                if(environment3[y][x]==':')
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
                if(environment3[y][x]==':')
                    shooter[y][x]=32;
            }
        }

    }
}

char Environment3::get_machine_shooter_array( int i, int j )
{
    return shooter[i][j];
}

void Environment3::destroy_machine_shooter_bullet(int i, int j)
{
    shooter[i][j]=' ';
}





