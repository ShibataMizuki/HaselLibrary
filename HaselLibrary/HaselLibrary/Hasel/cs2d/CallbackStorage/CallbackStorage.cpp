#include "CallbackStorage.h"
#include"cs2d/CollisionCallback/CollisionCallback.h"

using namespace std;
using namespace hasel;
using namespace cs2d;

void hasel::cs2d::CallbackStorage::AddCallback(const Callback & callback)
{
	callbacks[{callback.GetAttributeA(), callback.GetAttributeB()}].push_back(callback);
}

void hasel::cs2d::CallbackStorage::RemoveCallback(const Callback & callback)
{
	callbacks[{callback.GetAttributeA(), callback.GetAttributeB()}].remove(callback);
}

const std::list<Callback>& hasel::cs2d::CallbackStorage::GetCallbacks(int attributeA, int attributeB)const
{
	return callbacks.at({ attributeA,attributeB });
}

std::list<Callback> hasel::cs2d::CallbackStorage::GetAllCallbacks() const
{
	list<Callback> result;
	for (auto& list : callbacks)
		result.insert(result.end(), list.second.begin(), list.second.end());

	return move(result);
}

void hasel::cs2d::CallbackStorage::RemoveAll()
{
	callbacks.clear();
}