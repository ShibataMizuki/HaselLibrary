#include "TimerManager.h"
#include"TimerBase.h"

using namespace hasel;

void hasel::time::TimerManager::Add(const sptr<time::TimerBase>& timer)
{
	timers.push_back(timer);
}

void hasel::time::TimerManager::Remove(time::TimerBase * timer)
{
	timers.remove_if([&](const sptr<time::TimerBase>& v) {return v.get() == timer; });
}

void hasel::time::TimerManager::Update(float dt)
{
	for (auto& timer : timers)
	{
		if (!timer->IsActive())
			continue;

		timer->Step(dt);
		timer->Update();
	}
}

void hasel::time::TimerManager::RemoveAll()
{
	timers.clear();
}
