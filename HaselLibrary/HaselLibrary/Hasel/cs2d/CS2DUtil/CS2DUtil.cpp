#include"CS2DUtil.h"

#include"../Hasel/Shape/ShapeInc.h"

using namespace hasel;

bool hasel::cs2d::IsIntersectShape(shape::ShapeBase * shapeA, shape::ShapeBase * shapeB, const math::Vector2 & posA, const math::Vector2 & posB)
{
	if (!shapeA->aabb.IsIntersect(shapeB->aabb))
		return false;

	bool result = false;

	auto circleA = dynamic_cast<shape::Circle*>(shapeA);
	auto circleB = dynamic_cast<shape::Circle*>(shapeB);

	if (circleA&&circleB)
		result = IsIntersectCircle(circleA, circleB, posA, posB);

	return result;
}

bool hasel::cs2d::IsIntersectCircle(shape::Circle * circleA, shape::Circle * circleB, const math::Vector2 & posA, const math::Vector2 & posB)
{
	float x = posA.x - posB.x;
	float y = posA.y - posB.y;
	float r = circleA->radius + circleB->radius;
	return x*x + y*y <= r*r;
}
