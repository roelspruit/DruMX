# DruMX

DruMX is an arduino program that takes input from a vibration sensor and converts it (via effects) to a DMX signal.

##Effects

###Blink
Simple automatic blink effect that does not rely on trigger input. This just blinks a light for 1 second on and off.

###OnOff
If the trigger input reaches a certain threshold the light is turned up to full brightness. If the input is lower than the threshold for 100 milliseconds, the light is turned off again.

###Brightness
If the trigger input reaches a certain threshold the light is turned up to a brightness that is proportional to the input value.