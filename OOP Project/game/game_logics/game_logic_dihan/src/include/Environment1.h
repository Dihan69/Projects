#ifndef ENVIRONMENT1_H
#define ENVIRONMENT1_H

#include <iostream>
#include "Trap.h"
#include "Machine_Shooter.h"
#include "Door.h"

using namespace std;

class Environment1
{

protected:

    char environment1[60][150];

    Trap trap[7];
    Machine_Shooter machine_shooter[2];
    char shooter[60][150];
    Door door[2];

public:
    Environment1();
    char get_environment1(int i, int j) const;
    void set_trap_view();
    void shoot_machine();
    char get_machine_shooter_array( int i, int j );
    void destroy_bullet(int i, int j);
    void destroy_collectible(int i, int j);
    void set_door_view();
    void open_door(int i);
    void destroy_machine_shooter_bullet(int i, int j);



};

#endif // ENVIRONMENT1_H
