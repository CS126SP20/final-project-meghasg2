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
  float width_;
  float height_;
  bool mouse_pressed_;
  cinder::vec2 mouse_pos_;
  cinder::vec2 mouse_vel_;

  b2Vec2 gravity_;
  b2World* world_;
  particles::ParticleController particle_controller_;
  Platform platform_;
  cinder::app::KeyEvent key;

};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
