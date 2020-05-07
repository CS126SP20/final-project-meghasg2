// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <Conversions.h>
#include <Particle.h>
#include <ParticleController.h>
#include <cinder/Rand.h>
#include <cinder/app/AppBase.h>
#include <mylibrary/example.h>
#include <Globals.h>

#include <catch2/catch.hpp>

TEST_CASE("Random sanity test", "[random]") {
  const float random = cinder::randFloat();
  REQUIRE(0. <= random);
  REQUIRE(random <= 1.);
}

TEST_CASE("Test Particle's setup method", "[Particle][setup]") {
  // Setup returns global::COLOR_SCHEME; make sure this is incremented every
  // time RemoveAll() is called
  cinder::vec2 size = cinder::vec2(5.0f, 5.0f);
  particles::ParticleController particle_controller;
  particles::Particle particle;
  REQUIRE(particle.setup(size) == 0);
  particle_controller.RemoveAll();
  REQUIRE(particle.setup(size) == 1);
  particle_controller.RemoveAll();
  REQUIRE(particle.setup(size) == 2);
  particle_controller.RemoveAll();
  REQUIRE(particle.setup(size) == 0);
}
TEST_CASE("Test Particle's resize method", "[Particle][resize]") {
  particles::Particle particle;
  cinder::vec2 size = cinder::vec2(5.0f, 5.0f);
  REQUIRE(particle.resize(cinder::vec2(5.0f, 5.0f)) == size);
}
TEST_CASE("Test ParticleController's setup method", "[ParticleController][setup]") {
  particles::ParticleController particle_controller;
  auto* world_ = new b2World(b2Vec2(0.0f, 10.0f));
  REQUIRE(particle_controller.setup(*world_) == world_);
}
TEST_CASE("Test ParticleController's IncreaseBodySize method", "[ParticleController]") {
  particles::ParticleController particle_controller;
  cinder::vec2 size = cinder::vec2(8.0f, 8.0f);
  REQUIRE(particle_controller.IncreaseBodySize() == size);
}
TEST_CASE("Test ParticleController's DecreaseBodySize method", "[ParticleController]") {
  particles::ParticleController particle_controller;
  cinder::vec2 size = cinder::vec2(2.0f, 2.0f);
  REQUIRE(particle_controller.DecreaseBodySize() == size);
}
TEST_CASE("Test ParticleController's SwitchBodyType method", "[ParticleController]") {
  auto* world = new b2World(b2Vec2(0.0f, 10.0f));
  particles::ParticleController particle_controller;
  particle_controller.setup(*world);
  particle_controller.AddParticle(cinder::vec2(2.0f, 2.0f));
  // Need at least one particle in ParticleController's list of Particles
  auto* particle = new particles::Particle();
  b2BodyDef body_def;
  particle->body_ = world->CreateBody(&body_def);
  b2PolygonShape dynamic_box;
  dynamic_box.SetAsBox(Conversions::ToPhysics(global::BOX_SIZE_X + 3),
                       Conversions::ToPhysics(global::BOX_SIZE_Y + 3));
  b2FixtureDef fixture_def;
  fixture_def.shape = &dynamic_box;
  fixture_def.density = 1.0f;
  fixture_def.friction = 0.3f;
  fixture_def.restitution = 0.5f;  // bounce
  particle->body_->CreateFixture(&fixture_def);
  particle->body_->SetType(b2_dynamicBody);
  REQUIRE(particle->body_->GetType() == particle_controller.SwitchBodyType());
}

