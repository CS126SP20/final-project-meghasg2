// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <Box2D/Box2D.h>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>

#include "Conversions.h"
#include "cinder/Log.h"
#include "cinder/Rand.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace myapp {

using cinder::app::KeyEvent;
using cinder::Color;

MyApp::MyApp() : gravity_(0.0f, 10.0f) {
  world_ = new b2World(gravity_);
  particle_controller_.switch_ = false;
}

MyApp::~MyApp() {
  delete world_;
}

void MyApp::setup() {
  mouse_pressed_ = false;
  // Define a ground box with no mass
  // Define a body
  b2BodyDef ground_body_def;
  // Set the position to that of the ground
  ground_body_def.position.Set(
      Conversions::ToPhysics(cinder::app::getWindowWidth() / 2),
      Conversions::ToPhysics(cinder::app::getWindowHeight()));
  // Use the world to create the body
  b2Body* ground_body = world_->CreateBody(&ground_body_def);
  // Define the fixture
  b2PolygonShape ground_box;
  // Box is the size of the ground
  ground_box.SetAsBox(Conversions::ToPhysics(cinder::app::getWindowWidth() / 2),
                     Conversions::ToPhysics(1.0f));
  // Create the fixture on the body
  ground_body->CreateFixture(&ground_box, 0.0f);
  // Pass the world to the ParticleController class
  particle_controller_.setup(*world_);


/***
  // Define a platform with no mass
  // Define a body
  b2BodyDef platform_ground_body_def;
  // Set the position to be slightly higher than that of the ground
  platform_ground_body_def.position.Set(
      Conversions::ToPhysics(cinder::app::getWindowWidth() / 2),
      Conversions::ToPhysics(cinder::app::getWindowHeight() /
                             2));
  // Use the world to create the body
  b2Body* platform_ground_body = world_->CreateBody(&platform_ground_body_def);
  // Define the fixture
  b2PolygonShape platform_ground_box;
  platform_ground_box.SetAsBox(
      Conversions::ToPhysics(cinder::app::getWindowWidth() / 2),
      Conversions::ToPhysics(1.0f)); // size the ground
  // Create the fixture on the body
  platform_ground_body->CreateFixture(&platform_ground_box, 0.0f);
  platform_.setup(*world_);
  ***/

}

void MyApp::mouseDown(cinder::app::MouseEvent event) {
  mouse_pressed_ = true;
}

void MyApp::mouseUp(cinder::app::MouseEvent event) {
  mouse_pressed_ = false;
}

void MyApp::mouseMove(cinder::app::MouseEvent event) {
  mouse_pos_ = event.getPos();
}

void MyApp::mouseDrag(cinder::app::MouseEvent event) {
  mouseMove(event);
}

void MyApp::keyDown(KeyEvent event) {
  key = event;
  switch(event.getChar()) {
    case ' ': {
      particle_controller_.RemoveAll();
      break;
    }
    case 's': {
      particle_controller_.switch_ = true;
      particle_controller_.SwitchBodyType();
    }
    case 'e': {
      particle_controller_.switch_ = true;
      particle_controller_.SwitchBodySize();
    }
  }
}

void MyApp::update() {
  if (mouse_pressed_) {
    particle_controller_.AddParticle(mouse_pos_, key);
  }
  platform_.Mouse(mouse_pos_);
  particle_controller_.update();
  // Step physics world
  float32 time_step = 1.0f / 60.0f;
  int32 velocity_iterations = 6;
  int32 position_iterations = 2;
  world_->Step(time_step, velocity_iterations, position_iterations);
}

void MyApp::draw() {
    cinder::gl::clear(Color(0, 0, 0));
    cinder::gl::enableAlphaBlending();
    particle_controller_.draw();
    //platform_.draw();
}
}


 // namespace myapp
