//
// Created by Megha Ganesh on 4/24/20.
//

#include "ParticleController.h"
#include "Conversions.h"
#include "Globals.h"
#include "cinder/Vector.h"

namespace particles {
ParticleController::ParticleController() {}

b2World* ParticleController::setup(b2World &w) {
  world_ = &w;
  return world_;
}

void ParticleController::draw() {
  for (auto & particle : particles_) {
    particle.draw();
  }
}

void ParticleController::update() {
  for (auto & particle : particles_) {
    particle.update();
  }
}

void ParticleController::AddParticle(const cinder::ivec2 &mouse_pos) {
  Particle p = Particle();
  // Define a body
  b2BodyDef body_def;
  body_def.type = b2_staticBody;
  // Set the position to that of the mouse
  body_def.position.Set(Conversions::ToPhysics(mouse_pos.x),
                        Conversions::ToPhysics(mouse_pos.y));
  // b2Body will be referenced to its corresponding particle instead of just
  // creating a new body
  body_def.userData = &p;
  // Use the world to create the body
  p.body_ = world_->CreateBody(&body_def);
  // Define the fixture
  b2PolygonShape static_box;
  // Box is 0.5f x 0.5f
  static_box.SetAsBox(Conversions::ToPhysics(global::BOX_SIZE_X),
                         Conversions::ToPhysics(global::BOX_SIZE_Y));
  b2FixtureDef fixture_def;
  fixture_def.shape = &static_box;
  fixture_def.density = global::DENSITY;
  fixture_def.friction = global::FRICTION;
  // Restitution = bounce
  fixture_def.restitution = global::RESTITUTION;
  // Create the fixture with density, friction, and bounce
  p.body_->CreateFixture(&fixture_def);
  // Particle can do the rest of the initialization on its own
  p.setup(cinder::vec2(global::BOX_SIZE_X, global::BOX_SIZE_Y));
  // Add Particle to list of Particles
  particles_.push_back(p);
}

void ParticleController::RemoveAll() {
  for (auto & particle : particles_) {
    world_->DestroyBody(particle.body_);
  }
  particles_.clear();
  // Change color of particles
  if (global::COLOR_SCHEME == 0 || global::COLOR_SCHEME == 1) {
    global::COLOR_SCHEME++;
  } else if (global::COLOR_SCHEME == 2) {
    global::COLOR_SCHEME = 0;
  }
}

b2BodyType ParticleController::SwitchBodyType() {
  for (auto & particle : particles_) {
    // Set body type to dynamic instead of static
    particle.body_->SetType(b2_dynamicBody);
    b2PolygonShape dynamic_box;
    // +3 is to account for the body size increasing/decreasing
    dynamic_box.SetAsBox(
        Conversions::ToPhysics(global::BOX_SIZE_X + kSizeDifference),
        Conversions::ToPhysics(global::BOX_SIZE_Y + kSizeDifference));
    b2FixtureDef fixture_def;
    fixture_def.shape = &dynamic_box;
    fixture_def.density = global::DENSITY;
    fixture_def.friction = global::FRICTION;
    // Restitution = bounce
    fixture_def.restitution = global::RESTITUTION;
    // Create the fixture with density, friction, and bounce
    particle.body_->CreateFixture(&fixture_def);
  }
  return particles_.begin()->body_->GetType();
}

cinder::vec2 ParticleController::IncreaseBodySize() {
  cinder::vec2 size = cinder::vec2(global::BOX_SIZE_X + kSizeDifference,
      global::BOX_SIZE_X + kSizeDifference);
  for (auto & particle : particles_) {
    particle.resize(size);
  }
  return size;
}

cinder::vec2 ParticleController::DecreaseBodySize() {
  cinder::vec2 size = cinder::vec2(global::BOX_SIZE_X - kSizeDifference,
      global::BOX_SIZE_X - kSizeDifference);
  for (auto & particle : particles_) {
    particle.resize(size);
  }
  return size;
}
}
