#ifndef ALGOS_H
#define ALGOS_H

#include <algorithm>
#include <stdexcept>
#include <utility>
#include <vector>


class Task {
public:
    Task() : times(0, 0) {}
    Task(double startIn, double endIn) : times(startIn, endIn) {
        checkIfValid();
    }

    std::pair<double, double> getTimes() const {
        return times;
    }

    void setTime(std::pair<double, double> timeIn) {
        times = timeIn;
        checkIfValid();
    }

    bool overlap(const Task &other) const {
        const auto &otherTimes = other.getTimes();
        return !((otherTimes.first > times.first && otherTimes.first > times.second && otherTimes.second > times.first && otherTimes.second > times.second)
              || (otherTimes.first < times.first && otherTimes.first < times.second && otherTimes.second < times.first && otherTimes.second < times.second));
    }

private:
    std::pair<double, double> times;

    void checkIfValid() const {
        if (times.first > times.second) {
            throw std::invalid_argument("Task length cannot be negative");
        }
    }
};

struct TaskCompFinish {
    bool operator()(const Task &a, const Task &b) {
        return a.getTimes().second < b.getTimes().second;
    }
};

std::vector<Task> schedule_tasks(std::vector<Task> tasks);

#endif
