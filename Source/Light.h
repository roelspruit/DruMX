#ifndef LIGHT_H
#define LIGHT_H

#include "Types.h"

class Effect;

class Light
{
	private:
		int startChannel;
		int r;
		int g;
		int b;
	
    public:
		int pin;
		unsigned long lastUpdateTime;
		EffectType effectType;
	
		Light(int analogPin, int channel, EffectType effectType);
		void On();
		void Off();
		bool IsOn();
		void SetBrightness(int r, int g, int b);
};

#endif