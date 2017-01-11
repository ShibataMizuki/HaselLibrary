#pragma once

#include<string>

namespace hasel
{
	namespace math
	{
		/// <summary>
		/// �񎟌��x�N�g���N���X
		/// </summary>
		class Vector2
		{
		public:
			/// <summary>
			/// X�v�f
			/// </summary>
			float x;

			/// <summary>
			/// Y�v�f
			/// </summary>
			float y;

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Vector2();

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			/// <param name="x">X�v�f</param>
			/// <param name="y">Y�v�f</param>
			Vector2(float x, float y);

			Vector2 operator+(const Vector2& rv)const;
			Vector2 operator-(const Vector2& rv)const;
			Vector2 operator*(float rv)const;
			Vector2 operator/(float rv)const;
			void operator+=(const Vector2& rv);
			void operator-=(const Vector2& rv);

			/// <summary>
			/// �x�N�g���̒������擾����
			/// </summary>
			/// <returns>�x�N�g���̒���</returns>
			float GetLength()const;
			
			/// <summary>
			/// �x�N�g���𐳋K������
			/// </summary>
			void Normalize();

			/// <summary>
			/// ���K���ς݂̃x�N�g�����擾
			/// </summary>
			/// <returns>���K���ς݂̃x�N�g��</returns>
			Vector2 GetNormalized()const;

			/// <summary>
			/// �x�N�g���̓��ς����߂�
			/// </summary>
			/// <param name="rv">�E�Ӓl</param>
			/// <returns>���ϒl</returns>
			float Dot(const Vector2& rv)const;

			/// <summary>
			/// �x�N�g���̊O�ς����߂�
			/// </summary>
			/// <param name="rv">�E�Ӓl</param>
			/// <returns>�O�ϒl</returns>
			float Cross(const Vector2& rv)const;

			/// <summary>
			/// �_���v��������擾����
			/// </summary>
			/// <returns>�_���v���ꂽ������</returns>
			std::string Dump()const;
		};
	}
}