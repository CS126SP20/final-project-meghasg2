// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <Box2D/Box2D.h>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>

#include "Conversions.h"
#include "cinder/Rand.h"
#include <cinder/Text.h>
#include <cinder/ImageIo.h>


namespace myapp {

using cinder::app::KeyEvent;
using cinder::Color;
using cinder::ColorA;
using cinder::audio::Voice;
using cinder::gl::Texture;

MyApp::MyApp() : gravity_(0.0f, 10.0f), mouse_pressed_{false} {
  world_ = new b2World(gravity_);
}

MyApp::~MyApp() {
  delete world_;
}

void MyApp::setup() {
  // These three lines must be commented out if I'm running the app and have
  // headphones on
  cinder::audio::SourceFileRef sourceFile = cinder::audio::load(
      cinder::app::loadAsset(
          "Invasion-of-the-Giant-Disco-Ants_Looping.mp3"));
  mVoice = cinder::audio::Voice::create( sourceFile );
  mVoice->start();

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
  ground_box.SetAsBox(
      Conversions::ToPhysics(cinder::app::getWindowWidth() / 2),
      Conversions::ToPhysics(1.0f));
  // Create the fixture on the body
  ground_body->CreateFixture(&ground_box, 0.0f);
  // Pass the world to the ParticleController class
  particle_controller_.setup(*world_);
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
  switch(event.getChar()) {
    case ' ': {
      particle_controller_.RemoveAll();
      break;
    }
    case 's': {
      particle_controller_.SwitchBodyType();
      break;
    }
    case 'i': {
      particle_controller_.IncreaseBodySize();
      break;
    }
    case 'd': {
      particle_controller_.DecreaseBodySize();
      break;
    }
  }
}

// Sourced from snake app
void MyApp::PrintText(const std::string& text, const Color& color,
    const cinder::ivec2& size, const cinder::vec2& loc) {
  cinder::gl::color(color);
  const char kNormalFont[] = "Arial";
  auto box = ci::TextBox()
      .alignment(ci::TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 20))
      .size(size)
      .color(color)
      .backgroundColor(ci::ColorA(0, 0, 0, 0))
      .text(text);
  const auto box_size = box.getSize();
  const cinder::vec2 locp = {
      loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void MyApp::update() {
  // This must be commented out if I'm running the app and have headphones on
  if (!mVoice->isPlaying()) { mVoice->start(); }
  if (mouse_pressed_) {
    particle_controller_.AddParticle(mouse_pos_);
  }
  particle_controller_.update();
  // Step physics world
  world_->Step(kTimeStep, kVelocityIterations, kPositionIterations);
}

void MyApp::draw() {
  cinder::gl::clear(Color(0, 0, 0));
  cinder::gl::enableAlphaBlending();
  particle_controller_.draw();
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 500};
  const Color color = Color(1, 1, 1);
  PrintText(text_, color, size, center);
}
}


 // namespace myapp
