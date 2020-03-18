//
// Created by zozo on 3/16/20.
//

#ifndef SDL2TEST_MOVINGOBJECT_H
#define SDL2TEST_MOVINGOBJECT_H

class MovingObject{
public:
    virtual  void reset() = 0;
    virtual  int getY() = 0;
    void move();
    int getX();


protected:
    int init_x, init_y;
    int curr_x, curr_y;
    int speed;
};
#endif //SDL2TEST_MOVINGOBJECT_H
