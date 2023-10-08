#include <iostream>
#include <queue>
#include <vector>

struct Process {
    int id;
    int burstTime;
    int remainingTime;
};

void roundRobinScheduling(std::vector<Process>& processes, int timeQuantum) {
    std::queue<Process> queue;
    for (auto& process : processes) {
        queue.push(process);
    }

    int currentTime = 0;
    while (!queue.empty()) {
        Process currentProcess = queue.front();
        queue.pop();

        int time = std::min(currentProcess.remainingTime, timeQuantum);
        currentProcess.remainingTime -= time;
        currentTime += time;

        std::cout << "Process " << currentProcess.id << " is running from time " << currentTime - time << " to " << currentTime << std::endl;

        if (currentProcess.remainingTime > 0) {
            queue.push(currentProcess);
        }
    }
}

int main() {
    // id brust_time ramiain_time
    std::vector<Process> processes = {
        {1, 10, 10},
        {2, 5, 5},
        {3, 8, 8}
    };

    int timeQuantum = 3;
    roundRobinScheduling(processes, timeQuantum);

    return 0;
}
