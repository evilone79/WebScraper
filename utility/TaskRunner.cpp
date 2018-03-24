/*
 * TaskRunner.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: deth
 */

#include "TaskRunner.h"

namespace utility
{

TaskRunner::TaskRunner() :
		m_count(std::thread::hardware_concurrency()),
		m_index {0}
{
	for (auto i = 0; i < m_count; ++i)
	{
		m_runners.emplace_back([this, i](){	run(i); });
	}
}

TaskRunner::~TaskRunner()
{
	teardown();
}

void TaskRunner::submit(task_t&& task)
{
	auto cur = m_index++;
	for(auto i = 0; i < m_count; ++i)
	{
		auto& q = m_queues[(cur + i) % m_count];
		if(q.try_put(std::forward<task_t>(task)))
			return;
	}
	m_queues[cur].put(std::forward<task_t>(task));
}

void TaskRunner::teardown()
{
	for(auto& q : m_queues) q.done();
	for(auto& r : m_runners) r.join();
}

void TaskRunner::run(uint8_t n)
{
	while(true)
	{
		task_t task;
		for(uint32_t i = 0; i < m_count * 32; ++i)
		{
			auto& q = m_queues[(n + i) % m_count];
			if(q.try_fetch(task)) break;
		}
		if(!task && !m_queues[n].fetch(task))
			break;
		try
		{
			task();
		}catch(...) {}
	}
}

} /* namespace utility */


