#include "LED_Task.h"
#include <iostream>
#include <unistd.h> // for usleep

// Constructor
LED_Task::LED_Task(int pin) : ledGPIO(pin), state(OFF) {
    ledGPIO.setDirection(OUTPUT);
}

void LED_Task::LED_open() {
    state = ON;
    ledGPIO.setValue(HIGH);
    std::cout << "LED on pin " << ledGPIO.getNumber() << " is ON." << std::endl;
}

void LED_Task::LED_close() {
    state = OFF;
    ledGPIO.setValue(LOW);
    std::cout << "LED on pin " << ledGPIO.getNumber() << " is OFF." << std::endl;
}


void LED_Task::toggle_LED() {
    if (state == ON) {
        LED_close();
    } else {
        LED_open();
    }
}
