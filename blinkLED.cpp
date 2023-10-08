////////////////////////////////////////
//	blinkLED.c
//      Blinks the USR3 LED.
//	Wiring:	None
//	Setup:	
//	See:	https://github.com/beagleboard/cloud9-examples/blob/v2020.01/BeagleBone/Black/blinkLED.c
////////////////////////////////////////
#include <stdio.h>
#include <unistd.h>

int main() {
	FILE * trigger = fopen("/sys/class/leds/beaglebone:green:usr3/trigger", "w");
	FILE * brightness = fopen("/sys/class/leds/beaglebone:green:usr3/brightness", "w");
	int on = 0;
	
	fprintf(trigger, "none\n");
    
	while(1) {
		fprintf(brightness, "%d\n", on);
		fflush(brightness);
		if(!on) 
			on = 1;
		else 
			on = 0;
		usleep(500000);
	}
}