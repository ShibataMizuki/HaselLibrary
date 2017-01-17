#include"AABB.h"
#include<iostream>
#include<algorithm>
using namespace std;
using namespace hasel::shape;
using namespace hasel::math;

void hasel::shape::AABB::SetSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

Vector2 AABB::GetUpper() const
{
	Vector2 upper;
	upper.x = centerPos.x + width / 2.f;
	upper.y = centerPos.y + height / 2.f;
	return move(upper);
}

Vector2 AABB::GetLower() const
{
	Vector2 lower;
	lower.x = centerPos.x - width / 2.f;
	lower.y = centerPos.y - height / 2.f;
	return move(lower);
}


AABB::AABB(const Vector2 & centerPos, float width, float height) :
	centerPos(centerPos),width(width), height(height)
{
}

AABB::AABB(const Vector2 & lower, const Vector2 & upper)
{
	centerPos.x = (upper.x + lower.x) / 2.f;
	centerPos.y = (upper.y + lower.y) / 2.f;
	width = upper.x - lower.x;
	height = upper.y - lower.y;
}

bool AABB::IsIntersect(const AABB & aabb) const
{
	Vector2 thisUpper = GetUpper();
	Vector2 thisLower = GetLower();
	Vector2 targetUpper = aabb.GetUpper();
	Vector2 targetLower = aabb.GetLower();

	return thisUpper.x > targetLower.x&&
		thisLower.x < targetUpper.x&&
		thisUpper.y>targetLower.y&&
		thisLower.y < targetUpper.y;
}


AABB AABB::Merge(const AABB& aabb1, const AABB& aabb2)
{
	Vector2 retLower, retUpper;
	retLower.x = min(aabb1.GetLower().x, aabb2.GetLower().x);
	retLower.y = min(aabb1.GetLower().y, aabb2.GetLower().y);
	retUpper.x = max(aabb1.GetUpper().x, aabb2.GetUpper().x);
	retUpper.y = max(aabb1.GetUpper().y, aabb2.GetUpper().y);
	return AABB(retLower, retUpper);
}

void AABB::Dump() const
{
	cout << "[Center]" << centerPos.Dump() << endl;
	cout << "[Upper]" << GetUpper().Dump() << endl;
	cout << "[Lower]" << GetLower().Dump() << endl;
}