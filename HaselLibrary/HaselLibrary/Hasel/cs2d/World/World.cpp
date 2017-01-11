#include "World.h"

#include"../Hasel/Hasel.h"

#include"cs2d/CallbackStorage/CallbackStorage.h"
#include"cs2d/RigidBodyStorage/RigidBodyStorage.h"
#include"cs2d/CollisionCallback/CollisionCallback.h"
#include"cs2d/CS2DUtil/CS2DUtil.h"


using namespace std;

using namespace hasel;
using namespace hasel::shape;
using namespace hasel::cs2d;

bool hasel::cs2d::World::is_intersect(RigidBody * bodyA, RigidBody * bodyB)
{
	bool result = false;

	auto shapesA = bodyA->GetShapes();
	auto shapesB = bodyB->GetShapes();

	for (auto& shapeA : shapesA)
	{
		for (auto& shapeB : shapesB)
		{
			result = cs2d::IsIntersectShape(
				shapeA.GetRaw(), shapeB.GetRaw(),
				bodyA->GetPosition(), bodyB->GetPosition());
			if (result)
				break;
		}
	}

	return result;
}

hasel::cs2d::World::World()
{
	rigidBodyStorage = make_shared<RigidBodyStorage>();
	callbackStorage = make_shared<CallbackStorage>();
}

wptr<RigidBody> hasel::cs2d::World::CreateRigidBody(const RigidBodyMold & mold)
{
	return rigidBodyStorage->CreateRigidBody(mold);
}

void hasel::cs2d::World::RemoveRigidBody(const wptr<RigidBody>& body)
{
	rigidBodyStorage->DestroyRigidBody(body);
}

std::list<wptr<RigidBody>> hasel::cs2d::World::GetRigidBodies() const
{
	return move(rigidBodyStorage->GetRigidBodies());
}

const std::list<wptr<RigidBody>>& hasel::cs2d::World::GetRigidBodies(int attribute) const
{
	return rigidBodyStorage->GetRigidBodies(attribute);
}

void hasel::cs2d::World::AddCallback(const Callback & callback)
{
	callbackStorage->AddCallback(callback);
}

void hasel::cs2d::World::RemoveCallback(const Callback & callback)
{
	callbackStorage->RemoveCallback(callback);
}

void hasel::cs2d::World::ExecuteCollision()
{
	
	for (auto& callback : callbackStorage->GetAllCallbacks())
	{
		for (auto& bodyA : rigidBodyStorage->GetRigidBodies(callback.GetAttributeA()))
		{
			for (auto& bodyB :rigidBodyStorage->GetRigidBodies(callback.GetAttributeB()))
			{
				bool isSame = bodyA.lock().get() == bodyB.lock().get();
				if (isSame)
					continue;

				bool isHitAABB = bodyA.lock()->GetAABB().IsIntersect(bodyB.lock()->GetAABB());
				if (!isHitAABB)
					continue;

				bool isHitShapes = is_intersect(bodyA.lock().get(), bodyB.lock().get());
				if (!isHitShapes)
					continue;

				callback(bodyA, bodyB);
			}
		}
	}
	
}
