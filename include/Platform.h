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
  void mouse(const cinder::ivec2 mouse);
 private:
  b2World *world;
  b2BodyDef bodyDef;
  b2Body* body;
  particles::Particle p;
  cinder::Color color = ci::ColorA(ci::Rand::randFloat(0,.8), 0, 1, 1);
  cinder::ivec2 mousepos;
  float WORLD_TO_BOX;
  float BOX_TO_WORLD;

  cinder::vec2 size;

};

#endif  // FINALPROJECT_PLATFORM_H
