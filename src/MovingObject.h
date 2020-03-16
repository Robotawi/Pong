//
// Created by zozo on 3/16/20.
//

#ifndef SDL2TEST_MOVINGOBJECT_H
#define SDL2TEST_MOVINGOBJECT_H

class MovingObject{
public:
    virtual  void move() = 0;
    virtual  void reset() = 0;
    virtual  int getX() = 0;
    virtual  int getY() = 0;

protected:
    int init_x, init_y;
    int curr_x, curr_y;
};
#endif //SDL2TEST_MOVINGOBJECT_H
