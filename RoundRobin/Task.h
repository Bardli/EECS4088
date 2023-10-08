// Task.h
#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
protected:
    std::string taskname;
    long long task_total_time;
    long long task_remain_time;

public:
    void set_total(long long new_time);
    long long get_total();
    void set_remain(long long new_time);
    long long get_remain();
    std::string get_name();
    void set_name(std::string new_name);
};

#endif // TASK_H
