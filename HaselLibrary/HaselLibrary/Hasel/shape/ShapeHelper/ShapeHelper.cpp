#include"ShapeHelper.h"

#include"../Hasel/Hasel.h"

using namespace std;
using namespace hasel;
using namespace hasel::shape;
using namespace hasel::math;

AABB hasel::shape::MergeAABB(const AABB & lhs, const AABB & rhs)
{
	Vector2 lowerL = lhs.GetLower(), upperL = lhs.GetUpper();
	Vector2 lowerR = rhs.GetLower(), upperR = rhs.GetUpper();
	Vector2 lower, upper;

	lower.x = min(lowerL.x, lowerR.x);
	lower.y = min(lowerL.y, lowerR.y);
	upper.x = max(upperL.x, upperR.x);
	upper.y = max(upperL.y, upperR.y);

	return move(AABB(lower, upper));
}

AABB hasel::shape::CreateAABBFromShapes(const std::vector<Shape>& shapes, const hasel::math::Vector2 & pos)
{
	AABB result = AABB(pos, 0.f, 0.f);
	for (auto shape : shapes)
	{
		AABB merger = shape->aabb;
		merger.centerPos = shape->offset + pos;
		result = MergeAABB(result, merger);
	}
	return move(result);
}
