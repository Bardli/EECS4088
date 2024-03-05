#include <iostream>
#include "GPIO.h"
#include<unistd.h>
using namespace exploringBB;


// Define states
enum State {
    DIM,
    RED,
    WHITE,
    BOTH_LED,
    END,
    STOPPED
};

// Current state
State currentState = DIM;
GPIO RED_LED(50);
GPIO WHITE_LED(31);

// Function to transition to the next state
void transition(State nextState) {
    currentState = nextState;
}

void nonestate() {
    std::cout << "Initializing...\n";
    RED_LED.setDirection(OUTPUT);
    WHITE_LED.setDirection(OUTPUT);
    RED_LED.setValue(LOW);
    WHITE_LED.setValue(LOW);
    transition(RED);
}

void redState() {
    int time = 1 ;
    std::cout << "Red on\n";
    RED_LED.setValue(HIGH);
    usleep(time * 1000000); 
    std::cout << "Red off\n";
    RED_LED.setValue(LOW);
    usleep(time * 1000000 * 0.5);
    transition(WHITE);
}

void whiteState() {
    int time = 1 ;
    std::cout << "White on\n";
    WHITE_LED.setValue(HIGH);
    usleep(time * 1000000); // Assuming time is in seconds
    std::cout << "White off\n";
    WHITE_LED.setValue(LOW);
    usleep(time * 1000000* 0.5);
    transition(BOTH_LED);
}
void bothState() {
    int time = 1 ;
    std::cout << "Both on\n";
    RED_LED.setValue(HIGH);
    WHITE_LED.setValue(HIGH);
    // Example condition to transition to another state
    usleep(time * 1000000); // Assuming time is in seconds
    std::cout << "Both off\n";
    RED_LED.setValue(LOW);
    WHITE_LED.setValue(LOW);
    usleep(time * 1000000* 0.5);
    transition(STOPPED);
}

void stoppedState() {
    std::cout << "Stopped.\n";
    std::cout << "Press r to show again.\n";
    char input;
    std::cin>>input;
    if (input=='r'){
        transition(DIM);
    }

}

// Main scheduler loop
int main() {
    while (currentState != STOPPED) {
        switch (currentState) {
            case DIM:
                nonestate();
                break;
            case RED:
                redState();
                break;
            case WHITE:
                whiteState();
                break;
            case BOTH_LED:
                bothState();
                break;
            default:
                stoppedState();
                return 0;
        }
    }
    return 0;
}
