#ifndef ENVIRONMENT2_H
#define ENVIRONMENT2_H

#include "Machine_Shooter.h"
#include "Door.h"
#include "Movable_box.h"

class Environment2
{

protected:

    char environment2[60][150];
    Machine_Shooter machine_shooter[9];
    char shooter[60][150];
     char move_box_arr[60][150];
    Door door[2];
    Movable_box movable_box;

public:
    Environment2();
    char get_environment1(int i, int j) const;
    void set_trap_view();
    void shoot_machine();
    char get_machine_shooter_array( int i, int j );
    void destroy_bullet(int i, int j);
    void destroy_collectible(int i, int j);
    void set_door_view();
    void open_door(int i);
    void destroy_machine_shooter_bullet(int i, int j);
    void set_move_view();
    void change_move_box_state();
    char get_move_box_array(int i, int j);




};

#endif // ENVIRONMENT2_H
