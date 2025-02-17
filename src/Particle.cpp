//
// Created by Megha Ganesh on 4/24/20.
//

#include "Particle.h"

#include <Box2D/Box2D.h>

#include "Conversions.h"
#include "Globals.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

namespace particles {
Particle::Particle() {
}

Particle::~Particle() {
}

int Particle::setup(cinder::vec2 box_size) {
  size_ = box_size;
  if (global::COLOR_SCHEME == 0) {
    // Color of particles changes from red to yellow
    color_ = ci::ColorA(
        1, ci::Rand::randFloat(0,.8), 0, 1);
  } else if (global::COLOR_SCHEME == 1) {
    // Color of particles changes from blue to violet
    color_ = ci::ColorA(ci::Rand::randFloat(
        0,.8), 0, 1, 1);
  } else if (global::COLOR_SCHEME == 2) {
    // Color of particles change from white to cyan
    color_ = ci::ColorA(ci::Rand::randFloat(
        0,.8), 1, 1, 1);
  }
  return global::COLOR_SCHEME;
}

cinder::vec2 Particle::resize(const cinder::vec2& box_size) {
  size_ = box_size;
  return size_;
}

void Particle::update() {
}

void Particle::draw() {
  cinder::gl::color(color_);
  // Get position and angle from body and use that to draw to GUI (using OpenGL)
  cinder::vec2 pos = Conversions::ToScreen(body_->GetPosition());
  float t = Conversions::RadianstoDegrees(body_->GetAngle());
  // Tells OpenGL to store the current state we are in and sets where to start
  // the current object transformations
  cinder::gl::pushMatrices();
  cinder::gl::translate(pos);
  cinder::gl::rotate(t);
  cinder::Rectf rect(-size_.x, -size_.y, size_.x, size_.y);
  cinder::gl::drawSolidRect(rect);
  // Tells OpenGL to go back to our previous state and ends the current object
  // transformations
  cinder::gl::popMatrices();
}
}
