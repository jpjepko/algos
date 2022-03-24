#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#include "algos.h"

using namespace std;

std::vector<Task> schedule_tasks(std::vector<Task> tasks) {
	// No possible scheduling if no tasks exist
	if (tasks.empty()) {
		return tasks;
	}
	
	// Sort tasks by finish time
	TaskCompFinish cmpFinish;
	sort(tasks.begin(), tasks.end(), cmpFinish);

	vector<Task> res;
	
	// Add earliest-ending task to result
	res.push_back(tasks.front());

	// Add earliest-ending non-overlapping task
	for (size_t i = 1; i < tasks.size(); ++i) {
		const auto task = tasks[i];
		if (!task.overlap(res.back())) {
			res.push_back(task);
		}
	}

	return res;
}
