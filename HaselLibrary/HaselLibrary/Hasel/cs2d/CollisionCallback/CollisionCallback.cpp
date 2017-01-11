#include "CollisionCallback.h"

#include"../Hasel/Hasel.h"

using namespace std;
using namespace hasel;
using namespace hasel::cs2d;

unsigned long long Callback::ConstructionCount = 0;

hasel::cs2d::Callback::Callback(int attributeA, int attributeB,const std::function<void(const wptr<RigidBody>&, const wptr<RigidBody>&)>& callback):
	attributeA(attributeA),attributeB(attributeB),
	callback(callback),uniqueNum(ConstructionCount++)
{
}

int hasel::cs2d::Callback::GetAttributeA() const
{
	return attributeA;
}

int hasel::cs2d::Callback::GetAttributeB() const
{
	return attributeB;
}

void hasel::cs2d::Callback::operator()(const wptr<RigidBody>& bodyA, const wptr<RigidBody>& bodyB)const
{
	callback(bodyA, bodyB);
}

bool hasel::cs2d::Callback::operator==(const Callback & rhs) const
{
	return uniqueNum == rhs.uniqueNum;
}
