
/** DmxSimple is available from: http://code.google.com/p/tinkerit/
** Help and support: http://groups.google.com/group/dmxsimple       */

#include <DmxSimple.h>
#include "Light.h"
#include "Effect.h"

Light lights[1] = {
  Light(0, 2, Blink)
};

int lightCount = 1;

void setup() {

  Serial.begin(9600);
  
  /* The most common pin for DMX output is pin 3, which DmxSimple
  ** uses by default. If you need to change that, do it here. */
  DmxSimple.usePin(3);
  pinMode(13, OUTPUT);

  /* DMX devices typically need to receive a complete set of channels
  ** even if you only need to adjust the first channel. You can
  ** easily change the number of channels sent here. If you don't
  ** do this, DmxSimple will set the maximum channel number to the
  ** highest channel you DmxSimple.write() to. */
  /*DmxSimple.maxChannel(4);*/
}

void loop() {
  
  for(int i = 0; i < lightCount;i++) {

    switch(lights[i].effectType) {
      case Blink:
        EffectBlink(&lights[i]);
        break;
      case OnOff:
        EffectOnOff(&lights[i]);
        break;
      case Brightness:
        EffectBrightness(&lights[i]);
        break;
    }
    
  }
  
}

