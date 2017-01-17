#pragma once

#include"shape/ShapeBase/ShapeBase.h"
#include"math/MathInc.h"

namespace hasel
{
	namespace shape
	{
		class Segment :public ShapeBase
		{
		public:
			//�x�N�g��
			math::Vector2 vector;

		public:
			Segment();

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			/// <param name="startPoint">�n�_</param>
			/// <param name="endPoint">�I�_</param>
			Segment(const math::Vector2& startPoint, const math::Vector2& endPoint);

			Segment(const Segment& src);

			sptr<ShapeBase> CloneShared()override;

		};
	}
}