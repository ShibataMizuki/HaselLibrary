#pragma once

#include"shape/Shape/Shape.h"
#include"math/MathInc.h"
namespace hasel
{
	namespace shape
	{
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
	}
}