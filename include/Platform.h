//
// Created by Megha Ganesh on 4/27/20.
//

#ifndef FINALPROJECT_PLATFORM_H
#define FINALPROJECT_PLATFORM_H

#include <Box2D/Box2D.h>
#include <cinder/Rand.h>

#include "Particle.h"

class Platform {
 public:
  Platform();
  void setup(b2World &w);
  void update();
  void draw();
  void Mouse(const cinder::ivec2 mouse);
 private:
  b2World *world_;
  b2BodyDef body_def;
  b2Body*body_;
  particles::Particle particle_;
  cinder::Color color_ = ci::ColorA(
      ci::Rand::randFloat(0,.2), 0, 1, 1);
  cinder::ivec2 mouse_pos;
  float WORLD_TO_BOX_;
  float BOX_TO_WORLD_;
};

#endif  // FINALPROJECT_PLATFORM_H
