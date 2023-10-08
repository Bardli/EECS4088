// Task.cpp
#include "Task.h"

void Task::set_total(long long new_time) {
    task_total_time = new_time;
}

long long Task::get_total() {
    return task_total_time;
}

void Task::set_remain(long long new_time) {
    task_remain_time = new_time;
}

long long Task::get_remain() {
    return task_remain_time;
}

std::string Task::get_name() {
    return taskname;
}

void Task::set_name(std::string new_name) {
    taskname = new_name;
}

