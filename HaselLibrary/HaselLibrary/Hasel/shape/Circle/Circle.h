#pragma once

#include"HaselAlias.h"
#include"Math/MathInc.h"
#include"shape/ShapeBase/ShapeBase.h"

#include<memory>
#include<type_traits>

namespace hasel
{
	namespace shape
	{
		/// <summary>
		/// 円形状クラス
		/// </summary>
		class Circle :public ShapeBase
		{
		public:
			//円の半径
			float radius;

		public:
			/// <summary>
			/// コンストラクタ
			/// </summary>
			Circle() = default;

			/// <summary>
			/// コンストラクタ
			/// </summary>
			/// <param name="radius">半径</param>
			Circle(float radius);

			/// <summary>
			/// コンストラクタ
			/// </summary>
			/// <param name="offset">オフセット座標</param>
			/// <param name="radius">半径</param>
			Circle(const math::Vector2& offset, float radius);


			sptr<ShapeBase> CloneShared()override;
		};
	}
}