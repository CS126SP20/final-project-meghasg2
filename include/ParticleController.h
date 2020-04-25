//
// Created by Megha Ganesh on 4/24/20.
//

#ifndef FINALPROJECT_PARTICLECONTROLLER_H
#define FINALPROJECT_PARTICLECONTROLLER_H

#include "Particle.h"
#include <Box2D/Box2D.h>
#include <list>

namespace particles {
class ParticleController {
 public:
  ParticleController();
  // pass the physics world from the main app by reference
  void setup(b2World &w);
  void update();
  void draw();
  void addParticle(const cinder::ivec2 &mousePos);
  void removeAll();

 private:
  // store a pointer to the physics world from the main app
  b2World *world;
  std::list<Particle> particles;
};
}
#endif  // FINALPROJECT_PARTICLECONTROLLER_H
