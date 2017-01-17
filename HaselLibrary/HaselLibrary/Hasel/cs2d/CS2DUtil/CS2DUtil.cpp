#include"CS2DUtil.h"

#include"../Hasel/Shape/ShapeInc.h"

using namespace hasel;

bool hasel::cs2d::IsIntersectShape(shape::ShapeBase * shapeA, shape::ShapeBase * shapeB, const math::Vector2 & posA, const math::Vector2 & posB, math::Vector2* inter)
{
	//if (!shapeA->aabb.GetCollideShape(shapeB->aabb))
	//	return false;

	auto circleA = dynamic_cast<shape::Circle*>(shapeA);
	auto circleB = dynamic_cast<shape::Circle*>(shapeB);

	if (circleA&&circleB)
		return IsIntersectCircle(circleA, circleB, posA, posB,inter);

	auto segmentA = dynamic_cast<shape::Segment*>(shapeA);
	auto segmentB = dynamic_cast<shape::Segment*>(shapeB);

	if (circleA&&segmentB)
		return IsIntersectCicrleSegment(circleA, segmentB, posA, posB,inter);
	if (segmentA&&circleB)
		return IsIntersectCicrleSegment(circleB, segmentA, posB, posA,inter);

	return false;
}

bool hasel::cs2d::IsIntersectCircle(shape::Circle * circleA, shape::Circle * circleB, const math::Vector2 & posA, const math::Vector2 & posB, math::Vector2* inter)
{
	float x = posA.x - posB.x;
	float y = posA.y - posB.y;
	float r = circleA->radius + circleB->radius;
	return x*x + y*y <= r*r;
}

bool hasel::cs2d::IsIntersectCicrleSegment(shape::Circle * circle, shape::Segment * segment, const math::Vector2 & posA, const math::Vector2 & posB, math::Vector2* inter)
{
	auto r  = circle->radius;
	auto s1 = segment->offset + posB;
	auto s2 = s1 + segment->vector;
	auto s = segment->vector;
	auto p  = circle->offset + posA;
	auto a  = p - s1;
	auto b  = p - s2;
	auto d  = fabs(s.Cross(a)) / s.GetLength();
	if (d > r)
		return false;
	auto dotA = a.Dot(s);
	auto dotB = b.Dot(s);
	return dotA*dotB <= 0 ||
		r > a.GetLength() || r > b.GetLength();
}
