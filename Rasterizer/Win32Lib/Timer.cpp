#include "Timer.h"
#include <Windows.h>

//构造函数，初始化各个变量为默认值
Timer::Timer()
	:	m_deltaTime(0.f),
		m_baseTime(0),
		m_stopTime(0),
		m_pausedTime(0),
		m_currTime(0),
		m_prevTime(0),
		m_stopped(false)
{
	__int64 frequency;
	//收集系统信息，初始化计数器之间的时间差
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&frequency));
	m_secsPerCount = 1.f/frequency;
}

float Timer::totalTime() const
{
	//如果是暂停状态，如下图所示：
	//	开始时刻T0			暂停起始时刻S	当前时刻T
	//		|---------------------|------------|
	//总的时间为:S - T0 - 暂停的累计时间
	//注意把计数转换为秒
	if(m_stopped)
	{
		return (m_stopTime-m_baseTime-m_pausedTime)*m_secsPerCount;
	}
	//如果是正常状态
	//	开始时刻T0							当前时刻T
	//		|----------------------------------|
	//总的时间为：T - T0 - 暂停的累计时间
	//注意把计数转换为秒
	else
	{
		return (m_currTime-m_baseTime-m_pausedTime)*m_secsPerCount;
	}
}

float Timer::deltaTime() const
{
	//返回离上次计时中间的时间差
	return m_deltaTime;
}

void Timer::start()
{
	//暂停恢复
	//如果本来非暂停状态，则不操作
	//如果为暂停状态
	if(m_stopped)
	{
		//先获取开始时刻
		__int64 startTime;
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&startTime));

		//把本次暂停时间累计到总暂停时间中
		m_pausedTime += (startTime-m_stopTime);
		m_prevTime = startTime;
		m_stopTime = 0;
		m_stopped = false;
	}
}

void Timer::stop()
{
	if(!m_stopped)
	{
		__int64 curr;
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&curr));
		m_stopTime = curr;
		m_stopped = true;
	}
}

void Timer::reset()
{
	//重置定时器，进入工作状态
	__int64 curr;
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&curr));
	//确定起始时间
	m_baseTime = curr;
	m_currTime = curr;
	m_prevTime = curr;
	m_deltaTime = 0.f;

	m_stopTime = 0;
	//暂停累计清零
	m_pausedTime = 0;
	m_stopped = false;
}

void Timer::tick()
{
	//每帧调用的计时函数
	//用于更新定时器状态

	//如果为暂停状态，则不操作
	if(m_stopped)
	{
		m_deltaTime = 0.f;
		return;
	}

	//先获取当前时间
	__int64 curr;
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&curr));
	m_currTime = curr;
	//计算距离上一次计时的时间差
	m_deltaTime = (m_currTime-m_prevTime)*m_secsPerCount;
	//确保为正数(其实一般情况下不可能为负)
	m_deltaTime = m_deltaTime<0? 0.f : m_deltaTime;

	//把上次时间更新为本次时间，供下次Tick用
	m_prevTime = m_currTime;
}