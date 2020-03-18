//
// Created by Mohamed Raessa on 3/17/20.
//

#include "player.h"
#include <iostream>

//TODO: think about the player thickness
Player::Player(int &screen_width, int &screen_height, int &grid_width, int &grid_height, std::string &&id) {
    speed = 16;
    thickness = screen_width/grid_width;
    height = thickness * 4;
    scrnheight = screen_height;

    if (id == "right"){
        init_x = screen_width - thickness;
        init_y = screen_height/2 - height/2;

        curr_x = init_x;
        curr_y = init_y;
    }
    else if (id == "left"){
        init_x = 0;
        init_y = screen_height/2 - height/2;
        curr_x = init_x;
        curr_y = init_y;
    }


}

void Player::moveUp() {
    curr_y -= speed;
    if(curr_y <= 0) curr_y = 0;
}

void Player::moveDown() {
    curr_y += speed ;
    if(curr_y >=  scrnheight - height) curr_y = scrnheight - height;
}

void Player::reset() {
    curr_x = init_x;
    curr_y = init_y;
}

int Player::getY() {
    return curr_y;
}

int Player::getX() {
    return curr_x;
}

int Player::getHeight() {
    return height;
}
//int main(){
//    int width = 300;
//    int height = 200;
//    std::string idright = "right";
//    Player myplayer(width, height, idright);
//    std::cout << myplayer.getY() << std::endl;
//    myplayer.moveUp();
//    myplayer.moveUp();
//    myplayer.moveUp();
//    std::cout << myplayer.getY() << std::endl;
//    myplayer.moveDown();
//    myplayer.moveDown();
//    std::cout << myplayer.getY() << std::endl;
//
//}