#include "Circle.h"
using namespace std;
using namespace hasel::shape;
using namespace hasel;
using namespace hasel::math;

hasel::shape::Circle::Circle(float radius) :
	radius(radius)
{
	aabb.width  = radius*2.f;
	aabb.height = radius*2.f;
}

hasel::shape::Circle::Circle(const math::Vector2 & offset, float radius) :
	ShapeBase(offset),radius(radius)
{
	aabb.width  = radius*2.f;
	aabb.height = radius*2.f;
}

sptr<ShapeBase> hasel::shape::Circle::CloneShared()
{
	return move(make_shared<Circle>(offset, radius));
}
