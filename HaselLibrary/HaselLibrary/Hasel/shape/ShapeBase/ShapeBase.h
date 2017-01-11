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
			//オフセット座標
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