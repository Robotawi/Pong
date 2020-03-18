#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"
class Controller {
 public:
  void HandleInput(bool &running, Player *pr, Player *pl) const;

};

#endif