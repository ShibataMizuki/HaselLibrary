#include "Shape.h"
#include"shape/ShapeBase/ShapeBase.h"

using namespace std;
using namespace hasel;

hasel::shape::Shape::Shape() :
	shape(nullptr)
{
}

hasel::shape::Shape::Shape(const sptr<ShapeBase>& shape) :
	shape(shape)
{
}

shape::ShapeBase * hasel::shape::Shape::GetRaw() const
{
	return shape.get();
}

shape::Shape hasel::shape::Shape::Copy()
{
	shape::Shape result(shape->CloneShared());
	return move(result);
}

shape::ShapeBase * hasel::shape::Shape::operator->()const
{
	return shape.get();
}
