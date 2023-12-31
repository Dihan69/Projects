#ifndef ENEMY_TYPE_0_H
#define ENEMY_TYPE_0_H

#include "Environment2.h"

#include <time.h>
#include <iostream>

using namespace std;

class Enemy_type_0
{
  private:
      int pos_x;
      int pos_y;
      int destruct_power;
      bool is_destroyed;
      char enemy[60][150];
  public:
    Enemy_type_0();
    void set_enemy_type_0(int x, int y);
    void destroy_enemy_type_0();
    void move_enemy(const Environment2& e);
    int get_destruct_power();
    bool get_is_destroyed();
    char get_enemy_array(int i, int j);
};

#endif // ENEMY_TYPE_0_H
