/*
 * TaskQueue.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: deth
 */

#include "TaskQueue.h"

namespace utility
{


bool TaskQueue::try_put(task_t&& task)
{
	{
		lock_t lock(m_mut, std::try_to_lock);
		if(!lock)
			return false;
		m_q.emplace_back(std::forward<task_t>(task));
	}
	m_ready.notify_one();
	return true;
}

bool TaskQueue::try_fetch(task_t& task)
{
	lock_t lock(m_mut, std::try_to_lock);
	if(!lock || m_q.empty())
		return false;
	task = std::move(m_q.front());
	m_q.pop_front();
	return true;
}

void TaskQueue::put(task_t&& task)
{
	{
		lock_t lock(m_mut);
		m_q.emplace_back(std::forward<task_t>(task));
	}
	m_ready.notify_one();
}

bool TaskQueue::fetch(task_t& task)
{
	lock_t lock(m_mut);
	m_ready.wait(lock, [this]{ return !m_q.empty() || m_done; });
	if(m_q.empty())
		return false;
	task = std::move(m_q.front());
	m_q.pop_front();
	return true;
}

void TaskQueue::done()
{
	{
		lock_t lock(m_mut);
		m_done = true;
	}
	m_ready.notify_all();
}

} /* namespace utility */
