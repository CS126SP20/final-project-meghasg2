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
  world = &w;










  bodyDef.type = b2_kinematicBody;
  bodyDef.position.Set(6, 13);
  bodyDef.angle = 0;
  body = world->CreateBody(&bodyDef);

  b2PolygonShape* bodyShape = new b2PolygonShape;

  float boxSizeX =
      cinder::Rand::randFloat(global::BOX_X_MIN, global::BOX_X_MAX);
  float boxSizeY =
      cinder::Rand::randFloat(global::BOX_Y_MIN, global::BOX_Y_MAX);

  size = cinder::vec2(boxSizeX, boxSizeY);

  // bodyShape->SetAsBox(Conversions::toPhysics(cinder::app::getWindowWidth()/2),
  //                     Conversions::toPhysics(1.0f));


  bodyShape->SetAsBox(40.0f, 1.0f);

  b2FixtureDef fixtureDef;
  fixtureDef.density = 1.0f;
  fixtureDef.restitution = 1.0f;  // bounce
  fixtureDef.shape = bodyShape;
  body->CreateFixture(&fixtureDef);

  WORLD_TO_BOX = 0.01f;
  BOX_TO_WORLD = 100.0f;

  b2Vec2 vel = body->GetLinearVelocity();
  int time = 2.0f;

  vel.x = (0-280)* WORLD_TO_BOX / (time);
  //vel.y = (100-180)* WORLD_TO_BOX/(time);
  body->SetLinearVelocity(vel);



}

void Platform::update() {
}

void Platform::draw() {

  cinder::gl::color(color);
  cinder::vec2 pos = Conversions::toScreen(body->GetPosition());
  float t = Conversions::radiansToDegrees(body->GetAngle());
  cinder::gl::pushMatrices();
  cinder::gl::translate(pos);
  cinder::gl::rotate(t);

  cinder::Rectf rect(-size.x, -size.y, size.x, size.y);

  cinder::gl::drawSolidRect(rect);
  cinder::gl::popMatrices();

  // cinder::gl::clear();
  // cinder::gl::drawSolidCircle( cinder::app::getWindowCenter(), 200 );



}


void Platform::mouse(const cinder::ivec2 mousePosition) {
  mousepos = mousePosition;
}