//
// Created by Mohamed Raessa on 3/16/20.
//

#ifndef SDL2TEST_BALL_H
#define SDL2TEST_BALL_H

#include "MovingObject.h"
#include <random>
//move, reset, getx, gety

class Ball:public MovingObject{
public:
    enum Bdirec {STOP = 0, LEFT = 1, ULEFT = 2, DLEFT = 3, RIGHT = 4, URIGHT = 5, DRIGHT = 6};
    Ball(int & screen_width, int & screen_height);
    void reset();
    int getX();
    int getY();
    // for trial
    int getDirection();
    void move();
    void redirect(Bdirec d);
    void randDirect();

private:
    Bdirec direction;
    std::random_device rd;
};
#endif //SDL2TEST_BALL_H
