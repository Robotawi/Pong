//
// Created by Mohamed Raessa on 3/17/20.
//

#ifndef SDL2TEST_PLAYER_H
#define SDL2TEST_PLAYER_H

#include "MovingObject.h"
#include <string>
class Player:public MovingObject{
public:
    Player(int &screen_width, int &screen_height, int &grid_width, int &grid_height, std::string &&id);
    void reset();
    int getY();
    int getX();
    int getHeight();
    void moveUp();
    void moveDown();
private:
    int thickness;
    int height;
    int scrnheight;
};
#endif //SDL2TEST_PLAYER_H
