#include "game.h"
#include <iostream>
#include <thread>
#include "SDL.h"

Game::Game(std::size_t screen_width, std::size_t screen_height, std::size_t grid_width, std::size_t grid_height){
    newturn = true;

    scrnwidth = static_cast<int>(screen_width);
    scrnheight = static_cast<int>(screen_height);
    grdwidth = static_cast<int>(grid_width);
    grdnheight = static_cast<int>(grid_height);

    ball = new Ball(scrnwidth, scrnheight, grdwidth, grdnheight);
    ball->reset();

    rplayer = new Player(scrnwidth, scrnheight, grdwidth, grdnheight, std::move("right"));
    lplayer = new Player(scrnwidth, scrnheight, grdwidth, grdnheight, std::move("left"));
}
Game::~Game() {
    delete(ball);
    delete(rplayer);
    delete(lplayer);
}
void Game::run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;


  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, rplayer, lplayer);
    update(); // next step
    renderer.Render(rplayer, lplayer, ball);
    if (newturn){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        newturn = false;
    }
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(lscore, rscore, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::update() {
  ball->move();
  chkWallCollision();
  chkBallPlayerCollision();
}

void Game::chkWallCollision() {
//    std::cout << ball->getDirection() << std::endl;
    if (ball->getY() == 0){
        switch(ball->getDirection()){
            case 1:
                ball->redirect(2);
                break;
            case 3:
                ball->redirect(4);
                break;
        }
    }
    else if (ball->getY() == scrnheight - ball->getRadius()){
        switch(ball->getDirection()){
            case 2:
                ball->redirect(1);
                break;
            case 4:
                ball->redirect(3);
                break;
        }
    }
}

void Game::chkBallPlayerCollision()  {
    //if the ball on the left
    if (ball->getX() == ball->getRadius()){ // check if ball y is within the player y, if in, collision. if not, score and reset
//        std::cout << " Ball at the left edge, ball x is " << ball->getX() << ". Ball y is "<< ball->getY() << std::endl;
//        std::cout << " Player y is" << ->getX() << ". Ball y is "<< ball->getY() << std::endl;
        if (ball->getY() >= lplayer->getY() && ball->getY() <= lplayer->getY() + lplayer->getHeight()){
            //bounce
            switch(ball->getDirection()){
                case 1:
                    ball->redirect(3);
                    break;
                case 2:
                    ball->redirect(4);
                    break;
            }
        }
        else{
            rscore ++;
            ball->reset();
            rplayer->reset();
            lplayer->reset();

        }
    }
    //if the ball on the right
    else if (ball->getX() == scrnwidth - 2 * ball->getRadius()){
        if (ball->getY() >= rplayer->getY() && ball->getY() <= rplayer->getY() + lplayer->getHeight()){
            switch(ball->getDirection()){
                case 3:
                    ball->redirect(1);
                    break;
                case 4:
                    ball->redirect(2);
                    break;
            }
        }
        else{
            lscore ++;
            ball->reset();
            rplayer->reset();
            lplayer->reset();

        }
    }
}

std::string Game::getScore() { return "Left player ("+std::to_string(lscore)+") - Right player ("+std::to_string(rscore)+")"; }
