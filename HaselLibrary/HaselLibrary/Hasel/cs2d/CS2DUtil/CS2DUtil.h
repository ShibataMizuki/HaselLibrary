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
		/// Œ`ó“¯m‚ÌŒğ·”»’è‚ğs‚¤
		/// </summary>
		/// <param name="shapeA">”»’è‚·‚é}Œ`A</param>
		/// <param name="shapeB">”»’è‚·‚é}Œ`B</param>
		/// <param name="posA">}Œ`A‚ÌÀ•W</param>
		/// <param name="posB">}Œ`B‚ÌÀ•W</param>
		/// <returns>
		/// true :Œğ·‚µ‚Ä‚¢‚é
		/// false:Œğ·‚µ‚Ä‚¢‚È‚¢
		/// </returns>
		bool IsIntersectShape(shape::ShapeBase* shapeA, shape::ShapeBase* shapeB, const math::Vector2& posA, const math::Vector2& posB);

		/// <summary>
		/// ‰~“¯m‚ÌŒğ·”»’è‚ğs‚¤
		/// </summary>
		/// <param name="circleA">”»’è‚·‚é‰~A</param>
		/// <param name="circleB">”»’è‚·‚é‰~B</param>
		/// <param name="posA">}Œ`A‚ÌÀ•W</param>
		/// <param name="posB">}Œ`B‚ÌÀ•W</param>
		/// <returns></returns>
		bool IsIntersectCircle(shape::Circle* circleA, shape::Circle* circleB, const math::Vector2& posA, const math::Vector2& posB);
	}
}