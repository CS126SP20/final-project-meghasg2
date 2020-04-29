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

void Particle::setup(cinder::vec2 boxSize) {
  size = boxSize;
  if (global::COLOR_SCHEME == 0) {
    color = ci::ColorA(1, ci::Rand::randFloat(0,.8), 0, 1);  // red to yellow)
  } else {
    color = ci::ColorA(ci::Rand::randFloat(0,.8), 0, 1, 1);  // blue to violet
  }
}

void Particle::update() {

}

void Particle::draw() {
  cinder::gl::color(color);
  cinder::vec2 pos = Conversions::toScreen(body->GetPosition());
  float t = Conversions::radiansToDegrees(body->GetAngle());
  cinder::gl::pushMatrices();
  cinder::gl::translate(pos);
  cinder::gl::rotate(t);

  cinder::Rectf rect(-size.x, -size.y, size.x, size.y);
  cinder::gl::drawSolidRect(rect);
  cinder::gl::popMatrices();

}

}
