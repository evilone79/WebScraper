/*
 * TaskQueue.h
 *
 *  Created on: Mar 22, 2018
 *      Author: deth
 */

#ifndef TASKQUEUE_H_
#define TASKQUEUE_H_

#include <mutex>
#include <deque>
#include <functional>
#include <condition_variable>

namespace utility
{

using lock_t = std::unique_lock<std::mutex>;
using task_t = std::function<void()>;
class TaskQueue
{
public:

	bool try_put(task_t&& task);
	bool try_fetch(task_t& task);

	void put(task_t&& task);
	bool fetch(task_t& task);

	void done();

private:
	std::mutex m_mut;
	std::deque<task_t> m_q;
	std::condition_variable m_ready;
	bool m_done = false;
};

} /* namespace utility */

#endif /* TASKQUEUE_H_ */
