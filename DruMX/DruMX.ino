
/** DmxSimple is available from: http://code.google.com/p/tinkerit/
** Help and support: http://groups.google.com/group/dmxsimple       */

#include <DmxSimple.h>
#include "Light.h"
#include "Effect.h"

Light lights[1] = {
  Light(0, 2, Effect(Blink))
};

int lightCount = 1;

void setup() {

  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
  
  setupDMX();
  
}

void setupDMX() {
  /* Set this to the maximum DMX channel that will be used */
  DmxSimple.maxChannel(4);
  DmxSimple.usePin(3);
}

void loop() {
  
  for(int i = 0; i < lightCount;i++) {
    lights[i].Update();
  }
  
}


