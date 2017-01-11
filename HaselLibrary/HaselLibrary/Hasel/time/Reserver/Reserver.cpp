#include "Reserver.h"
#include"time/TimerManager.h"

using namespace std;
using namespace hasel;

hasel::time::Reserver::~Reserver()
{
	time::TimerManager::GetInstance()->Remove(this);
}

sptr<time::Reserver> hasel::time::Reserver::Create(float waitTime, const std::function<void()>& function)
{
	auto reserver = make_shared<Reserver>();
	reserver->waitTime = waitTime;
	reserver->function = function;

	time::TimerManager::GetInstance()->Add(reserver);

	return reserver;
}

void hasel::time::Reserver::Update()
{
	if (Get() >= waitTime)
	{
		function();
		time::TimerManager::GetInstance()->Remove(this);
	}
}
