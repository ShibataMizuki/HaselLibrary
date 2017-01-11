#pragma once

#include"../Hasel/Math/MathInc.h"

namespace hasel
{
	namespace shape
	{
		class ShapeBase;
		class Circle;
	}

	namespace cs2d
	{
		/// <summary>
		/// �`�󓯎m�̌���������s��
		/// </summary>
		/// <param name="shapeA">���肷��}�`A</param>
		/// <param name="shapeB">���肷��}�`B</param>
		/// <param name="posA">�}�`A�̍��W</param>
		/// <param name="posB">�}�`B�̍��W</param>
		/// <returns>
		/// true :�������Ă���
		/// false:�������Ă��Ȃ�
		/// </returns>
		bool IsIntersectShape(shape::ShapeBase* shapeA, shape::ShapeBase* shapeB, const math::Vector2& posA, const math::Vector2& posB);

		/// <summary>
		/// �~���m�̌���������s��
		/// </summary>
		/// <param name="circleA">���肷��~A</param>
		/// <param name="circleB">���肷��~B</param>
		/// <param name="posA">�}�`A�̍��W</param>
		/// <param name="posB">�}�`B�̍��W</param>
		/// <returns></returns>
		bool IsIntersectCircle(shape::Circle* circleA, shape::Circle* circleB, const math::Vector2& posA, const math::Vector2& posB);
	}
}