#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running, Player *pr, Player *pl) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          pr->moveUp();
          break;

        case SDLK_DOWN:
            pr->moveDown();
          break;

        case SDLK_w:
            pl->moveUp();
          break;

        case SDLK_s:
            pl->moveDown();
          break;
      }
    }
  }
}