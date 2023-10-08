#ifndef LED_TASK_H
#define LED_TASK_H

#include "Task.h"
#include "GPIO.h"
using namespace exploringBB;

class LED_Task : public Task {
    enum LED_state {
        OFF = 0,
        ON = 1
    };

protected:
    GPIO ledGPIO;
    LED_state state;

public:
    LED_Task(int pin); // Constructor
    void LED_open();
    void LED_close();
    void toggle_LED();
};

#endif // LED_TASK_H
