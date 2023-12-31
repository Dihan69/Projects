#ifndef ENVIRONMENT3_H
#define ENVIRONMENT3_H

#include "Machine_Shooter.h"
#include <iostream>
#include <fstream>
#include "Trap.h"

#include "Door.h"

using namespace std;

class Environment3
{

protected:

    char environment3[60][150];

    Trap trap[10];

Machine_Shooter machine_shooter[2];
    char shooter[60][150];


    Door door;

public:
    Environment3();
    char get_environment1(int i, int j) const;
    void set_trap_view();
   void destroy_machine_shooter_bullet(int i, int j);
    void destroy_bullet(int i, int j);
    void destroy_collectible(int i, int j);
    void set_door_view();
    void open_door(int i);
    void shoot_machine();
char get_machine_shooter_array( int i, int j );




};

#endif // ENVIRONMENT3_H
