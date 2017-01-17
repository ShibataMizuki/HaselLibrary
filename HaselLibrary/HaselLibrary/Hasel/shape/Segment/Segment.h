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
			//ベクトル
			math::Vector2 vector;

		public:
			Segment();

			/// <summary>
			/// コンストラクタ
			/// </summary>
			/// <param name="startPoint">始点</param>
			/// <param name="endPoint">終点</param>
			Segment(const math::Vector2& startPoint, const math::Vector2& endPoint);

			Segment(const Segment& src);

			sptr<ShapeBase> CloneShared()override;

		};
	}
}