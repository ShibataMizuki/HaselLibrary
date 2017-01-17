#include "ShapeUtil.h"
#include"shape/ShapeInc.h"

using namespace std;
using namespace hasel;

shape::Shape hasel::shape::MakeCircle()
{
	Shape shape(make_shared<shape::Circle>());
	return move(shape);
}

shape::Shape hasel::shape::MakeCircle(float radius)
{
	Shape shape(make_shared<shape::Circle>(radius));
	return move(shape);
}

shape::Shape hasel::shape::MakeCircle(const math::Vector2 & offset, float radius)
{
	Shape shape(make_shared<shape::Circle>(offset,radius));
	return move(shape);
}

shape::Shape hasel::shape::MakeSegment(const math::Vector2 & start, const math::Vector2 & end)
{
	Shape shape(make_shared<shape::Segment>(start, end));
	return move(shape);
}

float hasel::shape::GetDistance(const math::Vector2 & point, const shape::Segment * segment,const math::Vector2& segmentPos)
{
	auto s1 = segment->offset + segmentPos;
	auto s2 = s1 + segment->vector;
	auto s = segment->vector;
	auto p = point;
	auto a  = p - s1;
	auto b  = p - s2;
	auto d  = fabs(s.Cross(a)) / s.GetLength();
	return d;
}
