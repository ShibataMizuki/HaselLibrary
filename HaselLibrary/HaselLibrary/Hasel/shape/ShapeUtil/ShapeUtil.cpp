#include "ShapeUtil.h"
#include"shape/Circle/Circle.h"

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
