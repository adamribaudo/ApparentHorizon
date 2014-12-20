#include "Shape.h"

Shape::Shape(ofVec3f position, float horizon) {
  mOpenTime = ofGetElapsedTimef();
  mColor.setHsb(128, 255, 255, 255);
  mInitialColor.setHsb(128, 255, 255, 255);
  mRotation = 0;
  mPosition = position;
  mInitialPositionZ = mPosition[2];
  mHorizon = horizon;
  mDepth = 1.0;
  mWidth = 1.0;
  mHeight = 1.0;
  mTimeToHorizon = 10.0;
}

Shape::~Shape() {
}

void Shape::update(double time) {
  mElapsedTime = ofGetElapsedTimef() - mOpenTime;
  mPosition[2] = ofMap(mElapsedTime, 0.0, mTimeToHorizon, mInitialPositionZ, -mHorizon);
  mColor.setBrightness(ofMap(mPosition[2], mInitialPositionZ, -mHorizon, mInitialColor[2], 10.0));
}

void Shape::draw() {
  ofPushMatrix();
  ofPushStyle();
  ofRotateZ(mRotation);
  ofFill();
  ofColor(mColor);
  ofSetLineWidth(ofMap(mPosition[2], -mInitialPositionZ, -mHorizon, 3.0, 0.0));
  ofTranslate(mPosition[0], mPosition[1], mPosition[2]);  
  ofLine(-mWidth, -mHeight,  mWidth, -mHeight);  
  ofLine( mWidth, -mHeight,  mWidth,  mHeight);  
  ofLine( mWidth,  mHeight, -mWidth,  mHeight);  
  ofLine(-mWidth,  mHeight, -mWidth, -mHeight);
  ofPopStyle();
  ofPopMatrix();
}

double Shape::getElapsedTime() {
  return mElapsedTime;
}

ofVec3f Shape::getPosition() {
  return mPosition;
}

void Shape::setColor(float hue, float saturation, float brightness) {
  mColor.setHsb(hue, saturation, brightness);
}

void Shape::setHue(float hue) {
  mColor.setHue(hue);
}

void Shape::setSaturation(float sat) {
  mColor.setSaturation(sat);
}

void Shape::setRotation(float rotation) {
  mRotation = rotation;
}
