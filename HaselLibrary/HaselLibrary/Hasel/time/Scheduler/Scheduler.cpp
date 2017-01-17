#include "Scheduler.h"
#include"time/TimerManager.h"

using namespace std;
using namespace hasel;

sptr<time::Scheduler> hasel::time::Scheduler::Create(float interval, const std::function<void()>& function)
{
	auto scheduler = make_shared<Scheduler>();
	scheduler->interval = interval;
	scheduler->function = function;

	return scheduler;
}

hasel::time::Scheduler::~Scheduler()
{
	time::TimerManager::GetInstance()->Remove(this);
}

void hasel::time::Scheduler::Update()
{
	if (Get() >= interval)
	{
		function();
		Reset();
	}
}
