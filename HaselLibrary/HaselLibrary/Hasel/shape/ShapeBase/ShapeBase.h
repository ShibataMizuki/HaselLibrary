#pragma once

#include"HaselAlias.h"
#include"math/MathInc.h"
#include"shape/AABB/AABB.h"

namespace hasel
{
	namespace shape
	{
		class ShapeBase
		{
		public:
			//�I�t�Z�b�g���W
			math::Vector2 offset;
			//AABB
			AABB aabb;

		public:
			ShapeBase() = default;
			
			ShapeBase(const math::Vector2& offset) :offset(offset) {}

			virtual sptr<ShapeBase> CloneShared() = 0;

			virtual ~ShapeBase() = default;

		};
	}
}