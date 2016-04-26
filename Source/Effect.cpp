#include <Arduino.h>
#include "Effect.h"

void EffectBlink(Light *light)
{
    unsigned long delay = 1000;

    if(millis() - light->lastUpdateTime < delay)
    {
      return;
    }

    if(light->IsOn())
    {
      light->Off();
    }
    else
    {
      light->On();
    }

    light->lastUpdateTime = millis();
}

void EffectOnOff(Light *light)
{
   int sensorValue = analogRead(light->pin);
   unsigned long curTime = millis();
   unsigned long onLength = 100;
   unsigned long sensorThreashold = 100;
   
   if(sensorValue > sensorThreashold)
   {
      light->SetBrightness(255, 255, 255);
      light->lastUpdateTime = curTime;
   }
   else if(curTime > light->lastUpdateTime + onLength)
   {
      light->SetBrightness(0, 0, 0);
   }
}


void EffectBrightness(Light *light)
{
  int sensorValue = analogRead(light->pin);
  unsigned long curTime = millis();
  float percentage = sensorValue / 1024.0;
  int brightness = percentage * 255.0;
  unsigned long sensorThreashold = 60;
  
  if(sensorValue > sensorThreashold)
  {
    Serial.println(sensorValue);
    light->SetBrightness(brightness, brightness, brightness);
    light->lastUpdateTime = curTime;
  }
  else
  {
    light->SetBrightness(0, 0, 0);
  }
}

