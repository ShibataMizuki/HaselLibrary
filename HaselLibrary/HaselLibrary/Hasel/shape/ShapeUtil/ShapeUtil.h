#pragma once

#include"shape/Shape/Shape.h"
#include"math/MathInc.h"
namespace hasel
{
	namespace shape
	{
		class Segment;

		/// <summary>
		/// ‰~‚ğì¬‚·‚é
		/// </summary>
		/// <returns>‰~</returns>
		Shape MakeCircle();

		/// <summary>
		/// ‰~‚ğì¬‚·‚é
		/// </summary>
		/// <param name="radius">”¼Œa</param>
		/// <returns>‰~</returns>
		Shape MakeCircle(float radius);

		/// <summary>
		/// ‰~‚ğì¬‚·‚é
		/// </summary>
		/// <param name="offset">ƒIƒtƒZƒbƒgÀ•W</param>
		/// <param name="radius">”¼Œa</param>
		/// <returns>‰~</returns>
		Shape MakeCircle(const math::Vector2& offset, float radius);

		Shape MakeSegment(const math::Vector2& start, const math::Vector2& end);

		float GetDistance(const math::Vector2& point, const shape::Segment* segment,const math::Vector2& segmentPos);
	}
}