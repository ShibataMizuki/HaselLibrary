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
		/// 2��AABB����������
		/// </summary>
		/// <param name="lhs">��������AABB1</param>
		/// <param name="rhs">��������AABB2</param>
		/// <returns>�������ꂽAABB</returns>
		AABB MergeAABB(const AABB& lhs, const AABB& rhs);

		/// <summary>
		/// �����̌`�󂩂�A���������AABB���쐬����
		/// </summary>
		/// <param name="shapes">�`�󃊃X�g</param>
		/// <param name="pos">�I�u�W�F�N�g�̍��W</param>
		/// <returns>�쐬���ꂽAABB</returns>
		AABB CreateAABBFromShapes(const std::vector<Shape>& shapes, const hasel::math::Vector2& pos);
	}
}