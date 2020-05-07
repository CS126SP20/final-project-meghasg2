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
  int setup(cinder::vec2 box_size);
  void update();
  void draw();
  cinder::vec2 resize(const cinder::vec2& box_size);
  b2Body* body_;
  cinder::Color color_;
  cinder::vec2 size_;
};
}


#endif  // FINALPROJECT_PARTICLE_H
