#include <DmxSimple.h>
#include <Arduino.h>
#include "Light.h"
#include "Effect.h"

Light::Light(int analogPin, int channel, Effect effect)
{
  this->pin = analogPin;
  this->startChannel = channel;
  this->lastUpdateTime = 0;
  this->effect = &effect;
}

void Light::Update()
{
  this->effect->ApplyToLight(this);
}

void Light::On()
{
	this->SetBrightness(255, 255, 255);
}

void Light::Off()
{
	this->SetBrightness(0, 0, 0);
}

bool Light::IsOn()
{
	return r > 0 || g < 0 || b < 0;
}

void Light::SetBrightness(int r, int g, int b)
{
this->r = r;
this->g = g;
this->b = b;

  DmxSimple.write(startChannel, r);
  DmxSimple.write(startChannel + 1, g);
  DmxSimple.write(startChannel + 2, b);
}
