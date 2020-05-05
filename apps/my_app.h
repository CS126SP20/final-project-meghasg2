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
  void PrintText(const std::string& text, const cinder::Color& color, const cinder::ivec2& size,
                     const cinder::vec2& loc);


 private:
  float width_;
  float height_;
  bool mouse_pressed_;
  cinder::vec2 mouse_pos_;
  cinder::vec2 mouse_vel_;
  std::string text = "Key: \n Press the spacebar to clear the screen and "
                     "change the color of the particles \n Press the 'e' key to "
                     "increase the size of the particles \n Press the 's' key to "
                     "change the gravity of the particles and have them fall";
  b2Vec2 gravity_;
  b2World* world_;
  particles::ParticleController particle_controller_;
  Platform platform_;
  cinder::app::KeyEvent key;

};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
