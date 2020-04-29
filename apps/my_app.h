// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include <Box2D/Box2D.h>
#include "Conversions.h"
#include "ParticleController.h"
#include "Platform.h"

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  ~MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void mouseMove(cinder::app::MouseEvent event) override;
  void mouseDown(cinder::app::MouseEvent event) override;
  void mouseUp(cinder::app::MouseEvent event) override;
  void mouseDrag(cinder::app::MouseEvent event) override;

 private:
  float width;
  float height;
  bool mousePressed;
  cinder::vec2 mousePos;
  cinder::vec2 mouseVel;

  b2Vec2 gravity;
  b2World* world;
  b2World* platform_world;
  b2Vec2 platform_gravity;
  particles::ParticleController particleController;
  Platform platform;

};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
