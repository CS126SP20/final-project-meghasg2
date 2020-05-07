// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <Box2D/Box2D.h>
#include <cinder/audio/Voice.h>

#include "Conversions.h"
#include "ParticleController.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

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
  void PrintText(const std::string& text, const cinder::Color& color,
      const cinder::ivec2& size, const cinder::vec2& loc);
  cinder::audio::VoiceRef mVoice;

 private:
  bool mouse_pressed_;
  cinder::vec2 mouse_pos_;
  const std::string text_ = "Welcome to Etch a Sketch!"
                     "\n Press the spacebar to clear the screen and change the"
                     " color of the particles"
                     "\n Press the 'i' key to increase the size of the particles"
                     "\n Press the 'd' key to decrease the size of the particles"
                     "\n Press the 's' key to watch the particles fall";
  b2Vec2 gravity_;
  b2World* world_;
  particles::ParticleController particle_controller_;
  const float32 kTimeStep = 1.0f / 60.0f;
  const int32 kVelocityIterations = 6;
  const int32 kPositionIterations = 2;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
