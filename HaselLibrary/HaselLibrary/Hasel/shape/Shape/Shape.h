#pragma once

#include"HaselAlias.h"

namespace hasel
{
	namespace shape
	{
		class ShapeBase;

		/// <summary>
		/// 形状クラス
		/// </summary>
		class Shape
		{
		private:
			//形状インスタンス
			sptr<ShapeBase> shape;

		public:
			Shape();

			Shape(const sptr<ShapeBase>& shape);

			/// <summary>
			/// インスタンスの生のポインタを取得する
			/// </summary>
			/// <returns></returns>
			ShapeBase* GetRaw()const;

			Shape Copy();

			ShapeBase* operator->()const;
		};
	}
}