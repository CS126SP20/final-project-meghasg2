//
// Created by Megha Ganesh on 4/24/20.
//

#include "ParticleController.h"

#include <list>

#include "Conversions.h"
#include "cinder/Rand.h"
#include "Globals.h"
#include "cinder/Vector.h"

namespace particles {
ParticleController::ParticleController() {}

b2World* ParticleController::setup(b2World &w) {
  world_ = &w;
  return world_;
}

void ParticleController::draw() {
  for (std::list<Particle>::iterator p = particles_.begin();
       p != particles_.end(); p++) {
    p->draw();
  }
}

void ParticleController::update() {
  for (std::list<Particle>::iterator p = particles_.begin();
       p != particles_.end(); p++) {
    p->update();
  }
}

void ParticleController::AddParticle(const cinder::ivec2 &mouse_pos) {
  Particle p = Particle();
  b2BodyDef body_def;
  body_def.type = b2_staticBody;
  body_def.position.Set(Conversions::ToPhysics(mouse_pos.x),
                        Conversions::ToPhysics(mouse_pos.y));
  body_def.userData = &p;
  p.body_ = world_->CreateBody(&body_def);
  b2PolygonShape dynamic_box;
  dynamic_box.SetAsBox(Conversions::ToPhysics(global::BOX_SIZE_X),
                         Conversions::ToPhysics(global::BOX_SIZE_Y));
  b2FixtureDef fixture_def;
  fixture_def.shape = &dynamic_box;
  fixture_def.density = 1.0f;
  fixture_def.friction = 0.3f;
  fixture_def.restitution = 0.5f;  // bounce
  p.body_->CreateFixture(&fixture_def);
  p.setup(cinder::vec2(global::BOX_SIZE_X, global::BOX_SIZE_Y));
  particles_.push_back(p);
}

void ParticleController::RemoveAll() {
  for (std::list<Particle>::iterator p = particles_.begin();
       p != particles_.end(); p++) {
    world_->DestroyBody(p->body_);
  }

  particles_.clear();

  if (global::COLOR_SCHEME == 0) {
    global::COLOR_SCHEME++;
  } else if (global::COLOR_SCHEME == 1) {
    global::COLOR_SCHEME++;
  } else if (global::COLOR_SCHEME == 2) {
    global::COLOR_SCHEME = 0;
  }
}

b2BodyType ParticleController::SwitchBodyType() {
  for (std::list<Particle>::iterator p = particles_.begin();
       p != particles_.end(); p++) {
    p->body_->SetType(b2_dynamicBody);
    b2PolygonShape dynamic_box;
    dynamic_box.SetAsBox(Conversions::ToPhysics(global::BOX_SIZE_X + 3),
                         Conversions::ToPhysics(global::BOX_SIZE_Y + 3));
    b2FixtureDef fixture_def;
    fixture_def.shape = &dynamic_box;
    fixture_def.density = 1.0f;
    fixture_def.friction = 0.3f;
    fixture_def.restitution = 0.5f;  // bounce
    p->body_->CreateFixture(&fixture_def);
  }
  return particles_.begin()->body_->GetType();
}


cinder::vec2 ParticleController::IncreaseBodySize() {
  cinder::vec2 size = cinder::vec2(8.0f, 8.0f);
  for (std::list<Particle>::iterator p = particles_.begin();
       p != particles_.end(); p++) {
    p->resize(size);
  }
  return size;
}

cinder::vec2 ParticleController::DecreaseBodySize() {
  cinder::vec2 size = cinder::vec2(2.0f, 2.0f);
  for (std::list<Particle>::iterator p = particles_.begin();
       p != particles_.end(); p++) {
    p->resize(size);
  }
  return size;
}
}
