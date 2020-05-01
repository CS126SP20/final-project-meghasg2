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

void ParticleController::setup(b2World &w) { world_ = &w; }

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

void ParticleController::AddParticle(const cinder::ivec2 &mouse_pos, cinder::app::KeyEvent key) {
  Particle p = Particle();
  b2BodyDef body_def;
  body_def.type = b2_staticBody;
  body_def.position.Set(Conversions::ToPhysics(mouse_pos.x),
                        Conversions::ToPhysics(mouse_pos.y));

  // instead of just creating body...
  // b2Body* body = world->CreateBody(&bodyDef);
  // do the following to create it with a circular reference to it's corresponding particle
  body_def.userData = &p;
  p.body_ = world_->CreateBody(&body_def);
  /***if (key.getChar() == 'c') {
    b2CircleShape circle_shape;
    circle_shape.m_p.Set(Conversions::ToPhysics(5.0f),
                         Conversions::ToPhysics(5.0f));
    circle_shape.m_radius = 1;
    b2FixtureDef fixture_def;
    fixture_def.shape = &circle_shape;
    fixture_def.density = 1.0f;
    fixture_def.friction = 0.3f;
    fixture_def.restitution = 0.5f;  // bounce

    p.body_->CreateFixture(&fixture_def);
    // rest of initialization particle can do for itself
    p.setup(cinder::vec2(5.0f, 5.0f));
    particles_.push_back(p);
  } else {***/
    b2PolygonShape dynamic_box;

    dynamic_box.SetAsBox(Conversions::ToPhysics(5.0f),
                         Conversions::ToPhysics(5.0f));

    b2FixtureDef fixture_def;
    fixture_def.shape = &dynamic_box;
    fixture_def.density = 1.0f;
    fixture_def.friction = 0.3f;
    fixture_def.restitution = 0.5f;  // bounce

    p.body_->CreateFixture(&fixture_def);

    // rest of initialization particle can do for itself
    p.setup(cinder::vec2(5.0f, 5.0f));
    particles_.push_back(p);

}

void ParticleController::RemoveAll() {
  for (std::list<Particle>::iterator p = particles_.begin();
       p != particles_.end(); p++) {
    world_->DestroyBody(p->body_);
  }

  particles_.clear();

  if (global::COLOR_SCHEME == 0) {
    global::COLOR_SCHEME = 1;
  } else if (global::COLOR_SCHEME == 1) {
    global::COLOR_SCHEME = 2;
  } else if (global::COLOR_SCHEME == 2) {
    global::COLOR_SCHEME = 0;
  }
}

void ParticleController::SwitchBodyType() {
  for (std::list<Particle>::iterator p = particles_.begin();
       p != particles_.end(); p++) {
    p->body_->SetType(b2_dynamicBody);


    b2PolygonShape dynamic_box;

    dynamic_box.SetAsBox(Conversions::ToPhysics(10.0f),
                         Conversions::ToPhysics(10.0f));

    b2FixtureDef fixture_def;
    fixture_def.shape = &dynamic_box;
    fixture_def.density = 1.0f;
    fixture_def.friction = 0.3f;
    fixture_def.restitution = 0.5f;  // bounce

    p->body_->CreateFixture(&fixture_def);
  }

}


void ParticleController::SwitchBodySize() {
  for (std::list<Particle>::iterator p = particles_.begin();
       p != particles_.end(); p++) {
    p->resize(cinder::vec2(10.0f, 10.0f));
  }
}
}
