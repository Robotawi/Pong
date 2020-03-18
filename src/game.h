#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "player.h"
#include "ball.h"

class Game {
 public:
  Game(std::size_t screen_width, std::size_t screen_height, std::size_t grid_width, std::size_t grid_height);

  ~Game();
  void run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);

  void chkWallCollision();
  void chkBallPlayerCollision();
  std::string getScore();
  void update();

 private:
  Player* rplayer;
  Player* lplayer;
  Ball* ball;
  bool newturn;

  int scrnwidth;
  int scrnheight;
  int grdwidth;
  int grdnheight;
  int rscore{0};
  int lscore{0};


};

#endif