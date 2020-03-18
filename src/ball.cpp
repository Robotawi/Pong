//
// Created by Mohamed raessa on 3/16/20.
//

#include "ball.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

Ball::Ball(int &screen_width, int &screen_height, int &grid_width, int &grid_height) {
    radius = screen_height/grid_height;

    init_x = screen_width/2;
    init_y = screen_height/2;
    curr_x = init_x;
    curr_y = init_y;

    speed = 2;
}
void Ball::reset() {
    curr_x = init_x;
    curr_y = init_y;
    this->randDirect();
}

void Ball::move() {
    switch(direction){
        case STOP:
            break;
        case ULEFT:
            curr_x-=speed;
            curr_y-=speed;
            break;
        case DLEFT:
            curr_x-=speed;
            curr_y+=speed;
            break;
        case URIGHT:
            curr_x+=speed;
            curr_y-=speed;
            break;
        case DRIGHT:
            curr_x+=speed;
            curr_y+=speed;
            break;
    }
}
/*
void Ball::move() {
    switch(direction){
        case STOP:
            break;
        case LEFT:
            curr_x-=speed;
            break;
        case ULEFT:
            curr_x-=speed;
            curr_y-=speed;
            break;
        case DLEFT:
            curr_x-=speed;
            curr_y+=speed;
            break;
        case RIGHT:
            curr_x+=speed;
            break;
        case URIGHT:
            curr_x+=speed;
            curr_y-=speed;
            break;
        case DRIGHT:
            curr_x+=speed;
            curr_y+=speed;
            break;
    }
}
*/
int Ball::getX() {
    return curr_x;
}

int Ball::getY() {
    return curr_y;
}

void Ball::randDirect() {
    std::mt19937 genseed(rd());
    std::uniform_int_distribution<int> dist(1, 4);

    direction = (Bdirec)dist(genseed);
}
// for trial
int Ball::getDirection(){
    // returns the index of the direction element in the enum
    return direction;
}

int Ball::getRadius() {
    return radius;
}
void Ball::redirect(int &&d) {
    direction = (Bdirec)d;
}
//int main(){
//    int width = 300;
//    int height = 200;
//
//    Ball myball(width, height);
//    myball.randDirect();
//    int newdirec = myball.getDirection();
//    cout << newdirec << endl;
//    cout << myball.getX() << ", " << myball.getY() << endl;
//    myball.move();
//    cout << myball.getX() << ", " << myball.getY() << endl;
//    myball.move();
//    cout << myball.getX() << ", " << myball.getY() << endl;
//}