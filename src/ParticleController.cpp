//
// Created by Megha Ganesh on 4/24/20.
//

#include "ParticleController.h"

#include <list>

#include "Conversions.h"
#include "Globals.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"

namespace particles {
ParticleController::ParticleController() {
}

void ParticleController::setup(b2World &w) {
  world = &w;
}

void ParticleController::draw() {
  for( std::list<Particle>::iterator p = particles.begin(); p != particles.end(); p++ ){
    p->draw();
  }
}

void ParticleController::update() {
  for (std::list<Particle>::iterator p = particles.begin(); p != particles.end(); p++) {
    p->update();
  }
}

void ParticleController::addParticle(const cinder::ivec2 &mousePos) {
  Particle p = Particle();
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(Conversions::toPhysics(mousePos.x), Conversions::toPhysics(mousePos.y));

  // instead of just creating body...
  // b2Body* body = world->CreateBody(&bodyDef);
  // do the following to create it with a circular reference to it's corresponding particle
  bodyDef.userData = &p;
  p.body = world->CreateBody(&bodyDef);

  b2PolygonShape dynamicBox;
  float boxSizeX = cinder::Rand::randFloat(global::BOX_X_MIN, global::BOX_X_MAX);
  float boxSizeY = cinder::Rand::randFloat(global::BOX_Y_MIN, global::BOX_Y_MAX);

  dynamicBox.SetAsBox(Conversions::toPhysics(boxSizeX), Conversions::toPhysics(boxSizeY));

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  fixtureDef.restitution = 0.5f; // bounce

  p.body->CreateFixture(&fixtureDef);

  // rest of initialization particle can do for itself
  p.setup(cinder::vec2(boxSizeX, boxSizeY));
  particles.push_back(p);
}

void ParticleController::removeAll() {
  for( std::list<Particle>::iterator p = particles.begin(); p != particles.end(); p++) {
    world->DestroyBody(p->body);
  }

  particles.clear();

  if (global::COLOR_SCHEME == 0)
    global::COLOR_SCHEME++;
  else
    global::COLOR_SCHEME--;

}

}



