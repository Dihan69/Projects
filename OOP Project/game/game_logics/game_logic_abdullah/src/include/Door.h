#ifndef DOOR_H
#define DOOR_H


class Door
{
     protected:
         int pos_x;
         int pos_y;
         int length;
         int height;
    public:
        Door();
         int get_door_pos_x() const;
         int get_door_pos_y() const;
         int get_door_length() const;
         int get_door_height() const;
         void set_door_height(int h);
         void set_door_length(int l);
         void set_door_pos_y(int y);
         void set_door_pos_x(int x);




};

#endif // DOOR_H
