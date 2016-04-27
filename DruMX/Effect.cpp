#include <Arduino.h>
#include "Effect.h"
#include "Light.h"

Effect::Effect(EffectType effectType)
{
  this->effectType = effectType;
}

void Effect::ApplyToLight(Light *light)
{
  switch(this->effectType) {
    case Blink:
      EffectBlink(light);
      break;
    case OnOff:
      EffectOnOff(light);
      break;
    case Brightness:
      EffectBrightness(light);
      break;
  }
}

void Effect::EffectBlink(Light *light)
{
    unsigned long delay = 1000;

    if(millis() - light->lastUpdateTime < delay) {
      return;
    }

    if(light->IsOn()) {
      light->Off();
    } else {
      light->On();
    }

    light->lastUpdateTime = millis();
}

void Effect::EffectOnOff(Light *light)
{
   int sensorValue = analogRead(light->pin);
   unsigned long curTime = millis();
   unsigned long onLength = 100;
   
   if(sensorValue > sensorThreashold) {
      light->SetBrightness(255, 255, 255);
      light->lastUpdateTime = curTime;
   } else if(curTime > light->lastUpdateTime + onLength) {
      light->SetBrightness(0, 0, 0);
   }
}

void Effect::EffectBrightness(Light *light)
{
  int sensorValue = analogRead(light->pin);
  unsigned long curTime = millis();
  float percentage = sensorValue / 1024.0;
  int brightness = percentage * 255.0;
  
  if(sensorValue > sensorThreashold) {
    Serial.println(sensorValue);
    light->SetBrightness(brightness, brightness, brightness);
    light->lastUpdateTime = curTime;
  } else {
    light->SetBrightness(0, 0, 0);
  }
}


