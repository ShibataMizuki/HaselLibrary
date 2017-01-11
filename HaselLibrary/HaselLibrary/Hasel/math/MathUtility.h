#pragma once

namespace hasel
{
	namespace math
	{
		/// <summary>
		/// �~����
		/// </summary>
		constexpr float PI = 3.141592654f;

		/// <summary>
		/// radian�l��degree�l�ɕϊ�����
		/// </summary>
		/// <param name="rad">�ϊ�����radian�l</param>
		/// <returns>�ϊ����ꂽ�l(degree)</returns>
		constexpr float ToDegree(float rad)
		{
			return rad / (PI / 180.f);
		}

		/// <summary>
		/// degree�l��radian�l�ɕϊ�����
		/// </summary>
		/// <param name="deg">�ϊ�����degree�l</param>
		/// <returns>�ϊ����ꂽ�l</returns>
		constexpr float ToRadian(float deg)
		{
			return deg*(PI / 180.f);
		}

		/// <summary>
		/// �l���w��̍ŏ��l�ƍő�l�̊ԂɊۂߍ���
		/// </summary>
		/// <param name="value">�ۂߍ��ޒl</param>
		/// <param name="minimum">�ŏ��l</param>
		/// <param name="maximum">�ő�l</param>
		/// <returns>�ۂߍ��܂ꂽ�l</returns>
		template<typename Type>
		Type Clamp(Type value, Type minimum, Type maximum)
		{
			return std::min(std::max(value, minimum), maximum);
		}
	}
}