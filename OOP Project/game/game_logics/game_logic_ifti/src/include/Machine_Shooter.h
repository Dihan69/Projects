#ifndef MACHINE_SHOOTER_H
#define MACHINE_SHOOTER_H


enum Shoot_Direction
{
    up_to_down, down_to_up, left_to_right, right_to_left
};

class Machine_Shooter
{
    protected:

        int length;
        int pos_x;
        int pos_y;
        Shoot_Direction shoot_direction;
        int shoot_delay;
        int current_delay;
        int bullet_power;

    public:
        Machine_Shooter();
        void set_machine_shooter(int l, int x, int y, int s, Shoot_Direction d);
        int get_length()const;
        int get_pos_x()const;
        int get_pos_y()const;
        int get_shoot_delay() const;
        int get_current_delay() const;
        void increment_current_delay();
        Shoot_Direction get_shoot_direction()const;
        char get_shooter(int i, int j) const;
        int get_bullet_power() const;







    private:
};

#endif // MACHINE_SHOOTER_H
