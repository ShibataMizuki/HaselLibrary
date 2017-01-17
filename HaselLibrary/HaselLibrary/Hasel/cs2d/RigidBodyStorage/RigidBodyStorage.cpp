#include "RigidBodyStorage.h"

#include"cs2d/RigidBody/RigidBody.h"

using namespace std;
using namespace hasel;
using namespace hasel::cs2d;

wptr<RigidBody> hasel::cs2d::RigidBodyStorage::CreateRigidBody(const RigidBodyMold & mold)
{
	auto body = mold.MintShared();
	rigidBodyies.push_back(body);

	for (auto& attribute : body->GetAttibutes())
		groupedRigidBodies[attribute].push_back(body);

	return body;
}

void hasel::cs2d::RigidBodyStorage::DestroyRigidBody(const wptr<RigidBody>& body)
{
	auto NativeEqual=[&](const wptr<RigidBody>& lhs)
	{
		return lhs.lock() == body.lock();
	};

	for (auto& bodies : groupedRigidBodies)
		bodies.second.remove_if(NativeEqual);

	rigidBodyies.remove(body.lock());
}

std::list<wptr<RigidBody>> hasel::cs2d::RigidBodyStorage::GetRigidBodies() const
{
	list<wptr<RigidBody>> result;

	result.insert(result.end(), rigidBodyies.begin(), rigidBodyies.end());

	return move(result);
}

const std::list<wptr<RigidBody>>& hasel::cs2d::RigidBodyStorage::GetRigidBodies(int attribute) const
{
	return groupedRigidBodies.at(attribute);
}

void hasel::cs2d::RigidBodyStorage::RemoveAll()
{
	rigidBodyies.clear();
	groupedRigidBodies.clear();
}
