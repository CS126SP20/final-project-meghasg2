//
// Created by Megha Ganesh on 4/24/20.
//

#ifndef FINALPROJECT_CONVERSIONS_H
#define FINALPROJECT_CONVERSIONS_H

#include "cinder/Vector.h"
#include "Box2D/Box2D.h"

struct Conversions {

  static float getScaling(){ static float scaling = 50.0f; return scaling; }

  static cinder::vec2 toScreen( b2Vec2 fin )
  {
    return cinder::vec2(fin.x, fin.y) * getScaling();
  }

  static b2Vec2 toPhysics( cinder::vec2 fin )
  {
    return b2Vec2( fin.x/getScaling(), fin.y/getScaling() );
  }

  static float toPhysics( float fin )
  {
    return fin / getScaling();
  }

  static float toScreen( float fin )
  {
    return fin * getScaling();
  }

  static float radiansToDegrees( float rad )
  {
    return rad * 180.0f/M_PI;
  }
};


#endif  // FINALPROJECT_CONVERSIONS_H
