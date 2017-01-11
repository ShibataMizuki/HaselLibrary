#include "TimerManager.h"
#include"TimerBase.h"

using namespace hasel;

void hasel::time::TimerManager::Add(const wptr<time::TimerBase>& timer)
{
	timers.push_back(timer);
}

void hasel::time::TimerManager::Remove(time::TimerBase * timer)
{
	timers.remove_if([&](const wptr<time::TimerBase>& v) {return v.lock().get() == timer; });
}

void hasel::time::TimerManager::Update(float dt)
{
	for (auto& timer : timers)
	{
		if (timer.expired())
			continue;

		if (!timer.lock()->IsActive())
			continue;

		timer.lock()->Step(dt);
		timer.lock()->Update();
	}
}
