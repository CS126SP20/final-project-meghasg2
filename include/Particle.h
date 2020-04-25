//
// Created by Megha Ganesh on 4/24/20.
//

#ifndef FINALPROJECT_PARTICLE_H
#define FINALPROJECT_PARTICLE_H

#include "cinder/Color.h"
#include <Box2D/Box2D.h>
#include "cinder/gl/gl.h"

namespace particles {
class Particle {
 public:
  Particle();
  ~Particle();
  // pass in a pointer to the particle
  void setup(cinder::vec2 boxSize);
  void update();
  void draw();

  b2Body* body;
  cinder::Color color;
  cinder::vec2 size;
};

}


#endif  // FINALPROJECT_PARTICLE_H
