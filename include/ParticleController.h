//
// Created by Megha Ganesh on 4/24/20.
//

#ifndef FINALPROJECT_PARTICLECONTROLLER_H
#define FINALPROJECT_PARTICLECONTROLLER_H

#include <Box2D/Box2D.h>
#include <cinder/app/KeyEvent.h>

#include <list>

#include "Particle.h"

namespace particles {
class ParticleController {
 public:
  ParticleController();
  // pass the physics world from the main app by reference
  void setup(b2World &w);
  void update();
  void draw();
  void AddParticle(const cinder::ivec2 &mouse_pos, cinder::app::KeyEvent key);
  void RemoveAll();
  void SwitchBodyType();
  void SwitchBodySize();

  bool switch_;

 private:
  // store a pointer to the physics world from the main app
  b2World *world_;
  std::list<Particle> particles_;
  int count_ = 0;
};
}
#endif  // FINALPROJECT_PARTICLECONTROLLER_H
