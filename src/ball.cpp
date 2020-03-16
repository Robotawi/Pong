//
// Created by Mohamed raessa on 3/16/20.
//

#include "ball.h"
#include <iostream>
using namespace std;

Ball::Ball(int & screen_width, int & screen_height) {
    init_x = screen_width/2;
    init_y = screen_height/2;
    curr_x = init_x;
    curr_y = init_y;
}
void Ball::reset() {
    curr_x = init_x;
    curr_y = init_y;
}

void Ball::move() {
    switch(direction){
        case STOP:
            break;
        case LEFT:
            curr_x--;
            break;
        case ULEFT:
            curr_x--;
            curr_y--;
            break;
        case DLEFT:
            curr_x--;
            curr_y++;
            break;
        case RIGHT:
            curr_x++;
            break;
        case URIGHT:
            curr_x++;
            curr_y--;
            break;
        case DRIGHT:
            curr_x++;
            curr_y++;
            break;
    }
}

int Ball::getX() {
    return curr_x;
}

int Ball::getY() {
    return curr_y;
}

void Ball::randDirect() {
    std::mt19937 genseed(rd());
    std::uniform_int_distribution<int> dist(1, 6);
    direction = (Bdirec)dist(genseed);
}
// for trial
int Ball::getDirection(){
    // returns the index of the direction element in the enum
    return direction;
}


int main(){
    int width = 300;
    int height = 200;

    Ball myball(width, height);
    myball.randDirect();
    int newdirec = myball.getDirection();
    cout << newdirec << endl;
    cout << myball.getX() << ", " << myball.getY() << endl;
    myball.move();
    cout << myball.getX() << ", " << myball.getY() << endl;
    myball.move();
    cout << myball.getX() << ", " << myball.getY() << endl;
}