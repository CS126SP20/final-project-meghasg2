//
// Created by Megha Ganesh on 4/27/20.
//

#include "Platform.h"
#include <Box2D/Box2D.h>
#include "Conversions.h"
#include <cinder/app/App.h>
#include "cinder/Rand.h"
#include "Globals.h"


Platform::Platform() {
}


void Platform::setup(b2World &w) {
  // Pass world by reference from my_app
  world_ = &w;
  // Define a kinematic body
  body_def.type = b2_kinematicBody;
  body_def.position.Set(12, 13);
  body_def.angle = 0;
  // Use the world to create the body
  body_ = world_->CreateBody(&body_def);

  b2PolygonShape* body_shape = new b2PolygonShape;
  float box_size_X =
      cinder::Rand::randFloat(global::BOX_X_MIN, global::BOX_X_MAX);
  float box_size_Y =
      cinder::Rand::randFloat(global::BOX_Y_MIN, global::BOX_Y_MAX);

  body_shape->SetAsBox(Conversions::ToPhysics(box_size_X),
                       Conversions::ToPhysics(box_size_Y));



  // Define the fixture
  b2FixtureDef fixture_def;
  fixture_def.density = 1.0f;
  fixture_def.shape = body_shape;
  // Create the fixture on the body
  body_->CreateFixture(&fixture_def);

  WORLD_TO_BOX_ = 0.01f;

  b2Vec2 vel = body_->GetLinearVelocity();
  int time = 2.0f;
  vel.x = (0 - 280) * WORLD_TO_BOX_ / (time);
  // Set the velocity of the platform
  body_->SetLinearVelocity(vel);

}

void Platform::update() {
}

void Platform::draw() {

  cinder::gl::color(color_);
  cinder::vec2 pos = Conversions::ToScreen(body_->GetPosition());
  float t = Conversions::RadianstoDegrees(body_->GetAngle());
  cinder::gl::pushMatrices();
  cinder::gl::translate(pos);
  cinder::gl::rotate(t);

  cinder::Rectf rect(-300, -20, 20, 50);

  cinder::gl::drawSolidRect(rect);
  cinder::gl::popMatrices();
}


void Platform::Mouse(const cinder::ivec2 mouse) {
  mouse_pos = mouse;
}