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
  b2World* setup(b2World &w);
  void update();
  void draw();
  void AddParticle(const cinder::ivec2 &mouse_pos);
  void RemoveAll();
  b2BodyType SwitchBodyType();
  cinder::vec2 IncreaseBodySize();
  cinder::vec2 DecreaseBodySize();

 private:
  b2World *world_;
  std::list<Particle> particles_;
  const float kSizeDifference = 3.0f;

};
}
#endif  // FINALPROJECT_PARTICLECONTROLLER_H
