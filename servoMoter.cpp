#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <csignal>
#include <cmath> 

using namespace std;

const string pwmPeriod = "20000000"; // Period in ns, (20 ms)
const string pwm = "1"; // pwm to use
const string channel = "b"; // channel to use
const string PWMPATH = "/dev/bone/pwm/" + pwm + "/" + channel;
const double low = 0.8; // Smallest angle (in ms)
const double hi = 2.4; // Largest angle (in ms)
const int ms = 250; // How often to change position, in ms
double pos = 1.5; // Current position, about middle ms)
double step = 0.1; // Step size to next position

void signal_handler(int signum) {
    cout << "Got SIGINT, turning motor off" << endl;
    ofstream f(PWMPATH + "/enable");
    if (f.is_open()) {
        f << "0";
        f.close();
    }
    exit(signum);
}

int main() {
    // Register signal SIGINT and signal handler
    signal(SIGINT, signal_handler);
    cout << "Hit ^C to stop" << endl;

    ofstream f_period(PWMPATH + "/period");
    if (f_period.is_open()) {
        f_period << pwmPeriod;
        f_period.close();
    }

    ofstream f_enable(PWMPATH + "/enable");
    if (f_enable.is_open()) {
        f_enable << "1";
        f_enable.close();
    }

    ofstream f_duty_cycle(PWMPATH + "/duty_cycle");
    if (!f_duty_cycle.is_open()) {
        cerr << "Failed to open duty_cycle" << endl;
        return -1;
    }

    while (true) {
        pos += step; // Take a step
        if (pos > hi || pos < low) {
            step *= -1;
        }
        string duty_cycle = to_string(static_cast<int>(round(pos * 1000000))); // Convert ms to ns

        // Uncomment next line for debugging
        // cout << "pos = " << pos << " duty_cycle = " << duty_cycle << endl;

        f_duty_cycle.seekp(0);
        f_duty_cycle << duty_cycle;
        usleep(ms * 1000);
    }

    return 0;
}