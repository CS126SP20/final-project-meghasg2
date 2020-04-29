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

MyApp::MyApp() : gravity(0.0f, 0.0f), platform_gravity(-20.0f, 0.0f) {
  world = new b2World(gravity);
  platform_world = new b2World(platform_gravity);
}

MyApp::~MyApp() {
  delete world;
}

void MyApp::setup() {
  mousePressed = false;
  // first define a ground box (no mass)
  // 1. define a body
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(Conversions::toPhysics(
      cinder::app::getWindowWidth()/2),
          Conversions::toPhysics(cinder::app::getWindowHeight())); // pos of ground
  // 2. use world to create body
  b2Body* groundBody = world->CreateBody(&groundBodyDef);
  // 3. define fixture
  b2PolygonShape groundBox;
  groundBox.SetAsBox(
      Conversions::toPhysics(cinder::app::getWindowWidth()/2),
      Conversions::toPhysics(1.0f)); // size the ground
  // 4. create fixture on body
  groundBody->CreateFixture(&groundBox, 0.0f);

  //pass world to ParticleController
  particleController.setup(*world);

  b2BodyDef platGroundBodyDef;
  platGroundBodyDef.position.Set(Conversions::toPhysics(
      cinder::app::getWindowWidth()/4),
                                 Conversions::toPhysics(cinder::app::getWindowHeight()/2)); // pos of ground
  // 2. use world to create body
  b2Body* platformGroundBody = world->CreateBody(&platGroundBodyDef);
  // 3. define fixture
  b2PolygonShape platformGroundBox;
  platformGroundBox.SetAsBox(
      Conversions::toPhysics(cinder::app::getWindowWidth()/4),
      Conversions::toPhysics(3.0f)); // size the ground
  // 4. create fixture on body
  platformGroundBody->CreateFixture(&platformGroundBox, 0.0f);





  //pass world to Platform
  /***
    b2BodyDef platGroundBodyDef;
    platGroundBodyDef.position.Set(Conversions::toPhysics(
            cinder::app::getWindowWidth()/2),
                               Conversions::toPhysics(cinder::app::getWindowHeight())); // pos of ground
    // 2. use world to create body
    b2Body* platformGroundBody = platform_world->CreateBody(&platGroundBodyDef);
    // 3. define fixture
    b2PolygonShape platformGroundBox;
    platformGroundBox.SetAsBox(
            Conversions::toPhysics(cinder::app::getWindowWidth()/2),
            Conversions::toPhysics(1.0f)); // size the ground
    // 4. create fixture on body
    platformGroundBody->CreateFixture(&platformGroundBox, 0.0f);
    ***/

  platform.setup(*world);

}

void MyApp::mouseDown(cinder::app::MouseEvent event) {
  mousePressed = true;
}

void MyApp::mouseUp(cinder::app::MouseEvent event) {
  mousePressed = false;
}

void MyApp::mouseMove(cinder::app::MouseEvent event) {
  // mouseVel = (event.getPos() - mousePos);
  mousePos = event.getPos();
}

void MyApp::mouseDrag(cinder::app::MouseEvent event) {
  mouseMove(event);
}

void MyApp::keyDown(KeyEvent event) {
  switch(event.getChar()) {
    case ' ': particleController.removeAll(); break;
  }
}

void MyApp::update() {
  if (mousePressed) {
    particleController.addParticle(mousePos);
  }
  platform.mouse(mousePos);
  particleController.update();
  // step physics world
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;
  world->Step(timeStep, velocityIterations, positionIterations);
  platform_world->Step(timeStep, velocityIterations, positionIterations);
}

void MyApp::draw() {
    cinder::gl::clear(Color(0, 0, 0));
    cinder::gl::enableAlphaBlending();
    particleController.draw();
    platform.draw();
}
}


 // namespace myapp
