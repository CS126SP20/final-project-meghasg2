//
// Created by Megha Ganesh on 4/21/20.
//

#include "Direction.h"

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

namespace myapp {
class Engine {
 public:
  void SetDirection(Direction);
  Direction getDirection();
  Engine();
 private:
  Direction direction_;
};
}

#endif  // FINALPROJECT_ENGINE_H
