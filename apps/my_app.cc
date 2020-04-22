// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Log.h"



#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <Box2D/Box2D.h>
#include "Direction.h"

namespace myapp {

using cinder::app::KeyEvent;
using cinder::Color;

MyApp::MyApp()   {}

void MyApp::setup() {
    cinder::gl::enableDepthWrite();
    cinder::gl::enableDepthRead();
}

void MyApp::update() {
}

void MyApp::draw() {
  // cinder::gl::enableAlphaBlending();
  cinder::gl::clear();
  // reset the matrices
  cinder::gl::setMatricesWindow(getWindowSize());

    cinder::gl::translate(getWindowCenter().x, 100);
    cinder::gl::color(Color(1, 0, 0));
    cinder::gl::drawSolidCircle(cinder::vec2(0), 70);



  if (engine.getDirection() == Direction::kDown) {
    cinder::gl::translate(0, 200);
    cinder::gl::color(Color(1, 0, 0));
    cinder::gl::drawSolidCircle(cinder::vec2(0), 70);

  }

  cinder::gl::translate(0, 400);
  cinder::gl::color(Color(1, 1, 0));
  cinder::gl::drawSolidCircle(cinder::vec2(0), 70);


}

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_UP:
    case KeyEvent::KEY_k:
    case KeyEvent::KEY_w: {
      engine.SetDirection(Direction::kUp);
      break;
    }
    case KeyEvent::KEY_DOWN:
    case KeyEvent::KEY_j:
    case KeyEvent::KEY_s: {
      // move down 150 pixels
      /*cinder::gl::translate(0, 200);
      cinder::gl::color(Color(1, 1, 0));
      cinder::gl::drawSolidCircle(cinder::vec2(0), 70);*/

      engine.SetDirection(Direction::kDown);
      break;
    }
    case KeyEvent::KEY_LEFT:
    case KeyEvent::KEY_h:
    case KeyEvent::KEY_a: {
      engine.SetDirection(Direction::kLeft);
      break;
    }
    case KeyEvent::KEY_RIGHT:
    case KeyEvent::KEY_l:
    case KeyEvent::KEY_d: {
      engine.SetDirection(Direction::kRight);
      break;
    }
  }
}
}

 // namespace myapp
