#pragma once

#include"math/Vector2/Vector2.h"

namespace hasel
{
	namespace shape
	{
		/// <summary>
		/// AABB�N���X
		/// </summary>
		class AABB
		{
		public:
			//���S���W
			math::Vector2 centerPos;
			//��
			float width;
			//����
			float height;

		public:
			AABB() = default;
			
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			/// <param name="centerPos">���S���W</param>
			/// <param name="width">��</param>
			/// <param name="height">����</param>
			AABB(const math::Vector2& centerPos, float width, float height);

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			/// <param name="lower">�ŏ����W</param>
			/// <param name="upper">�ő���W</param>
			AABB(const math::Vector2& lower, const math::Vector2& upper);

			~AABB() = default;

			/// <summary>
			/// �T�C�Y�̐ݒ�
			/// </summary>
			/// <param name="width">��</param>
			/// <param name="height">����</param>
			void SetSize(float width, float height);

			/// <summary>
			/// �ő���W�̎擾
			/// </summary>
			/// <returns>�ő���W</returns>
			math::Vector2 GetUpper()const;

			/// <summary>
			/// �ŏ����W�̎擾
			/// </summary>
			/// <returns>�ŏ����W</returns>
			math::Vector2 GetLower()const;

			/// <summary>
			/// AABB���m�̌�������
			/// </summary>
			/// <param name="aabb">���肷��AABB</param>
			/// <returns>
			/// true :�������Ă���
			/// false:�������Ă��Ȃ�
			/// </returns>
			bool IsIntersect(const AABB& aabb)const;

			/**
			@brief 2��AABB����������
			@return ��������AABB
			*/
			static AABB Merge(const AABB& aabb1, const AABB& aabb2);

			void Dump()const;
		};
	}
}