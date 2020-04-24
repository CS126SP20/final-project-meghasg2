// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "my_app.h"


using cinder::app::App;
using cinder::app::RendererGl;


namespace myapp {

const int kSamples = 8;
const int kWidth = 800;
const int kHeight = 800;

void SetUp(App::Settings* settings) {
  settings->setWindowSize(kWidth, kHeight);
  settings->setTitle("My CS 126 Application");


  b2Vec2 gravity(0.0f, -10.0f);
  b2World world(gravity);


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

  groundBodyDef.position.Set(0.0f, -10.0f);
  groundBody = world.CreateBody(&groundBodyDef);
  groundBox.SetAsBox(50.0f, 10.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);

  //create dynamic body
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(0.0f, 4.0f);
  body = world.CreateBody(&bodyDef);
  dynamicBox.SetAsBox(1.0f, 1.0f);
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  body->CreateFixture(&fixtureDef);

  //simulating the world
  timeStep = 1.0f / 60.0f;


  for (int32 i = 0; i < 60; ++i) {
    world.Step(timeStep, velocityIterations, positionIterations);
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    printf("RUN: %4.2f %4.2f %4.2f\n", position.x, position.y, angle);
  }



}

}  // namespace myapp


// This is a macro that runs the application.
CINDER_APP(myapp::MyApp,
           RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
           myapp::SetUp)
