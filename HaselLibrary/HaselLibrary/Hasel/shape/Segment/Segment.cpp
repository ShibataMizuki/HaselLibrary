#include "Segment.h"
#include<algorithm>

using namespace std;
using namespace hasel;
using namespace hasel::math;

hasel::shape::Segment::Segment()
{
}

hasel::shape::Segment::Segment(const math::Vector2 & startPoint, const math::Vector2 & endPoint) :
	ShapeBase(startPoint)
{
	vector = endPoint - startPoint;
	aabb.width = fabs(startPoint.x - endPoint.x) + 5.f;
	aabb.height = fabs(startPoint.y - endPoint.y) + 5.f;
	aabb.centerPos = vector / 2.f;
}

hasel::shape::Segment::Segment(const Segment & src):
	ShapeBase(src.offset)
{
	aabb = src.aabb;
	vector = src.vector;
}

hasel::sptr<hasel::shape::ShapeBase> hasel::shape::Segment::CloneShared()
{
	return move(make_shared<Segment>(*this));
}
