#ifndef LIGHT_H
#define LIGHT_H

#include "Types.h"
#include "Effect.h"

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
		Effect *effect;
	
		Light(int analogPin, int channel, Effect effect);
		void On();
		void Off();
		bool IsOn();
		void SetBrightness(int r, int g, int b);
    void Update();
};

#endif
