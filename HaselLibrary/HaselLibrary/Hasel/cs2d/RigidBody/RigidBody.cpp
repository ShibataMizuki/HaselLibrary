#include "RigidBody.h"

#include"../Hasel/Hasel.h"
#include<algorithm>

using namespace hasel;
using namespace hasel::algo;
using namespace hasel::cs2d;
using namespace hasel::shape;
using namespace hasel::math;
using namespace std;

RigidBodyMold::RigidBodyMold()
{
}

RigidBodyMold& RigidBodyMold::SetPosition(const Vector2 & pos)
{
	this->pos = pos;
	return *this;
}

RigidBodyMold & hasel::cs2d::RigidBodyMold::AddShape(const Shape& shape)
{
	shapes.push_back(shape);
	return *this;
}

RigidBodyMold& RigidBodyMold::AddAttribute(int attribute)
{
	attributes.push_back(attribute);
	return *this;
}

RigidBodyMold& RigidBodyMold::SetUserData(void * userdata)
{
	this->userdata = userdata;
	return *this;
}

sptr<RigidBody> RigidBodyMold::MintShared()const
{
	return move(make_shared<RigidBody>(*this));
}

uptr<RigidBody> hasel::cs2d::RigidBodyMold::MintUnique()const
{
	return move(make_unique<RigidBody>(*this));
}

RigidBody * RigidBodyMold::MintRaw()const
{
	return new RigidBody(*this);
}

RigidBody::RigidBody(const RigidBodyMold & builder)
{
	pos = builder.pos;

	shapes.resize(builder.shapes.size());
	int count = 0;
	for (auto shape : builder.shapes)
	{
		shapes[count] = shape.Copy();
		count++;
	}

	attributes = builder.attributes;
	userdata = builder.userdata;

	aabb = shape::CreateAABBFromShapes(shapes, pos);

	isAABBChanged = false;
}

void hasel::cs2d::RigidBody::SetPosition(const Vector2 & pos)
{
	this->pos = pos;
	isAABBChanged = true;
}

const Vector2 & hasel::cs2d::RigidBody::GetPosition() const
{
	return pos;
}

void hasel::cs2d::RigidBody::AddAttribute(int attribute)
{
	attributes.push_back(attribute);
}

void hasel::cs2d::RigidBody::RemoveAttribute(int attribute)
{
	auto target = find(attributes.begin(), attributes.end(), attribute);
	attributes.erase(target);
}

bool hasel::cs2d::RigidBody::FindAttribute(int attribute) const
{
	auto target = find(attributes.begin(), attributes.end(), attribute);
	return target != attributes.end();
}

const std::vector<int>& hasel::cs2d::RigidBody::GetAttibutes() const
{
	return attributes;
}

void hasel::cs2d::RigidBody::SetUserdata(void * userdata)
{
	this->userdata = userdata;
}

void * hasel::cs2d::RigidBody::GetUserdataRaw() const
{
	return userdata;
}

const AABB& RigidBody::GetAABB()const
{
	if (!isAABBChanged)
		return aabb;

	aabb = shape::CreateAABBFromShapes(shapes, pos);
	isAABBChanged = false;
	return aabb;
}

const std::vector<shape::Shape>& hasel::cs2d::RigidBody::GetShapes() const
{
	return shapes;
}
