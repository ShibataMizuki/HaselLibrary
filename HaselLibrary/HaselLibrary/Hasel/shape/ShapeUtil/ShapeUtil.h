#pragma once

#include"shape/Shape/Shape.h"
#include"math/MathInc.h"
namespace hasel
{
	namespace shape
	{
		class Segment;

		/// <summary>
		/// �~���쐬����
		/// </summary>
		/// <returns>�~</returns>
		Shape MakeCircle();

		/// <summary>
		/// �~���쐬����
		/// </summary>
		/// <param name="radius">���a</param>
		/// <returns>�~</returns>
		Shape MakeCircle(float radius);

		/// <summary>
		/// �~���쐬����
		/// </summary>
		/// <param name="offset">�I�t�Z�b�g���W</param>
		/// <param name="radius">���a</param>
		/// <returns>�~</returns>
		Shape MakeCircle(const math::Vector2& offset, float radius);

		Shape MakeSegment(const math::Vector2& start, const math::Vector2& end);

		float GetDistance(const math::Vector2& point, const shape::Segment* segment,const math::Vector2& segmentPos);
	}
}