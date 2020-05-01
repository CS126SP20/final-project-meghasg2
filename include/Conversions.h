//
// Created by Megha Ganesh on 4/24/20.
//

#ifndef FINALPROJECT_CONVERSIONS_H
#define FINALPROJECT_CONVERSIONS_H

#include "cinder/Vector.h"
#include "Box2D/Box2D.h"

struct Conversions {

  static float GetScaling() {
    static float scaling = 50.0f; return scaling;
  }

  static cinder::vec2 ToScreen(b2Vec2 fin) {
    return cinder::vec2(fin.x, fin.y) * GetScaling();
  }

  static b2Vec2 ToPhysics(cinder::vec2 fin) {
    return b2Vec2( fin.x/ GetScaling(), fin.y/ GetScaling() );
  }

  static float ToPhysics(float fin) {
    return fin / GetScaling();
  }

  static float ToScreen(float fin) {
    return fin * GetScaling();
  }

  static float RadianstoDegrees(float rad) {
    return rad * 180.0f/M_PI;
  }
};


#endif  // FINALPROJECT_CONVERSIONS_H
