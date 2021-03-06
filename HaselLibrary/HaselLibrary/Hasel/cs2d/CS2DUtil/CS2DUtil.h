#pragma once

#include"../Hasel/Math/MathInc.h"

namespace hasel
{
	namespace shape
	{
		class ShapeBase;
		class Circle;
		class Segment;
		class Shape;
	}

	namespace cs2d
	{
		/// <summary>
		/// 形状同士の交差判定を行う
		/// </summary>
		/// <param name="shapeA">判定する図形A</param>
		/// <param name="shapeB">判定する図形B</param>
		/// <param name="posA">図形Aの座標</param>
		/// <param name="posB">図形Bの座標</param>
		/// <returns>
		/// true :交差している
		/// false:交差していない
		/// </returns>
		bool IsIntersectShape(shape::ShapeBase* shapeA, shape::ShapeBase* shapeB, const math::Vector2& posA, const math::Vector2& posB, math::Vector2* inter = nullptr);

		/// <summary>
		/// 円同士の交差判定を行う
		/// </summary>
		/// <param name="circleA">判定する円A</param>
		/// <param name="circleB">判定する円B</param>
		/// <param name="posA">図形Aの座標</param>
		/// <param name="posB">図形Bの座標</param>
		/// <returns></returns>
		bool IsIntersectCircle(shape::Circle* circleA, shape::Circle* circleB, const math::Vector2& posA, const math::Vector2& posB, math::Vector2* inter = nullptr);


		bool IsIntersectCicrleSegment(shape::Circle* circle, shape::Segment* segment, const math::Vector2& posA, const math::Vector2& posB, math::Vector2* inter = nullptr);
	}
}