#include "LED_Task.h" // Ensure this includes the LED_Task class definition
#include <vector>
#include <queue>
#include <iostream>
#include<unistd.h> // for sleep
struct Process {
    int id;
    int burstTime;
    int remainingTime;
    LED_Task ledTask;
    Process(int id, int burstTime, int pin) : id(id), burstTime(burstTime), remainingTime(burstTime), ledTask(pin) {}
};

void roundRobinScheduling(std::vector<Process*>& processes, int timeQuantum) {
    std::queue<Process*> queue;
    for (auto& process : processes) {
        queue.push(process);
    }

    int currentTime = 0;
    while (!queue.empty()) {
        Process* currentProcess = queue.front();
        queue.pop();

        int time = std::min(currentProcess->remainingTime, timeQuantum);
        currentProcess->remainingTime -= time;
        currentTime += time;

        // Turn on the LED for this process
        currentProcess->ledTask.LED_open();
        std::cout << "Process " << currentProcess->id << " is running (LED ON) from time " << currentTime - time << " to " << currentTime << std::endl;
        usleep(time * 1000000); // Assuming time is in seconds

        // Turn off the LED after its time slice
        currentProcess->ledTask.LED_close();
        std::cout << "Process " << currentProcess->id << " finished (LED OFF) at time " << currentTime << std::endl;

        if (currentProcess->remainingTime > 0) {
            queue.push(currentProcess);
        }
    }
}
int main() {
    std::vector<Process*> processes;

    // Manually adding processes
    
    Process* task1= new Process(1, 10, 60);
    Process* task2= new Process(2, 10, 31);
    processes.emplace_back(task1);
    processes.emplace_back(task2);

    int timeQuantum = 3;
    roundRobinScheduling(processes, timeQuantum);

    return 0;
}

