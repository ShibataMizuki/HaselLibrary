#pragma once

#include"../Hasel/HaselAlias.h"
#include"../Hasel/Math/MathInc.h"
#include"../Hasel/Shape/AABB/AABB.h"
#include"shape/Shape/Shape.h"

#include<algorithm>
#include<vector>

namespace hasel
{
	namespace shape
	{
		/// <summary>
		/// 2つのAABBを合成する
		/// </summary>
		/// <param name="lhs">合成するAABB1</param>
		/// <param name="rhs">合成するAABB2</param>
		/// <returns>合成されたAABB</returns>
		AABB MergeAABB(const AABB& lhs, const AABB& rhs);

		/// <summary>
		/// 複数の形状から、それを内包するAABBを作成する
		/// </summary>
		/// <param name="shapes">形状リスト</param>
		/// <param name="pos">オブジェクトの座標</param>
		/// <returns>作成されたAABB</returns>
		AABB CreateAABBFromShapes(const std::vector<Shape>& shapes, const hasel::math::Vector2& pos);
	}
}