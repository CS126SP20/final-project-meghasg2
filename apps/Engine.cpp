//
// Created by Megha Ganesh on 4/21/20.
//

#include "Engine.h"
namespace myapp {

void Engine::SetDirection(const myapp::Direction direction) {
  direction_ = direction;
}

myapp::Direction Engine::getDirection() { return direction_; }

Engine::Engine() {

}

}
