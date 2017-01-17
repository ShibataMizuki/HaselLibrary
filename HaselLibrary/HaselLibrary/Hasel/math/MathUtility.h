#pragma once

#include"math/Vector2/Vector2.h"

namespace hasel
{
	namespace math
	{
		/// <summary>
		/// 円周率
		/// </summary>
		constexpr float PI = 3.141592654f;

		/// <summary>
		/// 誤差丸め用の極小値
		/// </summary>
		constexpr float Epsilon = 0.00001f;

		/// <summary>
		/// radian値をdegree値に変換する
		/// </summary>
		/// <param name="rad">変換するradian値</param>
		/// <returns>変換された値(degree)</returns>
		constexpr float ToDegree(float rad)
		{
			return rad / (PI / 180.f);
		}

		/// <summary>
		/// degree値をradian値に変換する
		/// </summary>
		/// <param name="deg">変換するdegree値</param>
		/// <returns>変換された値</returns>
		constexpr float ToRadian(float deg)
		{
			return deg*(PI / 180.f);
		}

		/// <summary>
		/// 値を指定の最小値と最大値の間に丸め込む
		/// </summary>
		/// <param name="value">丸め込む値</param>
		/// <param name="minimum">最小値</param>
		/// <param name="maximum">最大値</param>
		/// <returns>丸め込まれた値</returns>
		template<typename Type>
		Type Clamp(Type value, Type minimum, Type maximum)
		{
			return std::min(std::max(value, minimum), maximum);
		}
	}
}