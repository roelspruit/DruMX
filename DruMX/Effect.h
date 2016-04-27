#ifndef EFFECT_H
#define EFFECT_H

#include "Types.h"

class Light;

class Effect
{
  private:
    EffectType effectType;
    void EffectBlink(Light *light);
    void EffectOnOff(Light *light);
    void EffectBrightness(Light *light);
   
  public:
    Effect(EffectType effectType);
    void ApplyToLight(Light *light);
    unsigned long sensorThreashold = 100;
};

#endif
