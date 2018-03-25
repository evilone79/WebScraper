/*
 * TaskRunner.h
 *
 *  Created on: Mar 22, 2018
 *      Author: deth
 */

#ifndef TASKRUNNER_H_
#define TASKRUNNER_H_

#include "TaskQueue.h"
#include <vector>
#include <thread>
#include <atomic>

namespace utility
{

class TaskRunner
{
public:
	TaskRunner();
	virtual ~TaskRunner();

	/**
	 * Submits the task for execution in task pool
	 * @param task
	 */
	void submit(task_t&& task);
	void teardown();

private:
	void run(uint8_t n);

	uint8_t m_count = 0;
	std::vector<std::thread> m_runners;
	std::vector<TaskQueue> m_queues	{ m_count };
	std::atomic_uint8_t m_index;
};

} /* namespace utility */

#endif /* TASKRUNNER_H_ */
