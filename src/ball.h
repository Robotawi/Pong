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
//    enum Bdirec {STOP = 0, LEFT = 1, ULEFT = 2, DLEFT = 3, RIGHT = 4, URIGHT = 5, DRIGHT = 6};
    enum Bdirec {STOP = 0, ULEFT = 1, DLEFT = 2, URIGHT = 3, DRIGHT = 4};

    //TODO: think about the ball radius
    Ball(int &screen_width, int &screen_height, int &grid_width, int &grid_height);
    void reset();
    int getX();
    int getY();
    // for trial
    int getDirection();
    int getRadius();
    void move();
    void redirect(int &&d);
    void randDirect();

private:
    Bdirec direction;
    std::random_device rd;
    int radius;
    int speed;
};
#endif //SDL2TEST_BALL_H
