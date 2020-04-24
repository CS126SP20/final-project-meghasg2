// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <Box2D/Box2D.h>
#include "Engine.h"


namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  ~MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

 private:
  Engine engine;
  b2World* world;
  b2Vec2 gravity;
  //ground body
  b2BodyDef groundBodyDef;
  b2Body* groundBody;
  b2PolygonShape groundBox;
  //dynamic body
  b2BodyDef bodyDef;
  b2Body* body;
  b2PolygonShape dynamicBox;
  b2FixtureDef fixtureDef;
  //simulating the world
  float timeStep;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;

  int count = 0;




};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
