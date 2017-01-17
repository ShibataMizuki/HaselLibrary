#pragma once

#include"math/Vector2/Vector2.h"

namespace hasel
{
	namespace shape
	{
		/// <summary>
		/// AABBクラス
		/// </summary>
		class AABB
		{
		public:
			//中心座標
			math::Vector2 centerPos;
			//幅
			float width;
			//高さ
			float height;

		public:
			AABB() = default;
			
			/// <summary>
			/// コンストラクタ
			/// </summary>
			/// <param name="centerPos">中心座標</param>
			/// <param name="width">幅</param>
			/// <param name="height">高さ</param>
			AABB(const math::Vector2& centerPos, float width, float height);

			/// <summary>
			/// コンストラクタ
			/// </summary>
			/// <param name="lower">最小座標</param>
			/// <param name="upper">最大座標</param>
			AABB(const math::Vector2& lower, const math::Vector2& upper);

			~AABB() = default;

			/// <summary>
			/// サイズの設定
			/// </summary>
			/// <param name="width">幅</param>
			/// <param name="height">高さ</param>
			void SetSize(float width, float height);

			/// <summary>
			/// 最大座標の取得
			/// </summary>
			/// <returns>最大座標</returns>
			math::Vector2 GetUpper()const;

			/// <summary>
			/// 最小座標の取得
			/// </summary>
			/// <returns>最小座標</returns>
			math::Vector2 GetLower()const;

			/// <summary>
			/// AABB同士の交差判定
			/// </summary>
			/// <param name="aabb">判定するAABB</param>
			/// <returns>
			/// true :交差している
			/// false:交差していない
			/// </returns>
			bool IsIntersect(const AABB& aabb)const;

			/**
			@brief 2つのAABBを合成する
			@return 合成したAABB
			*/
			static AABB Merge(const AABB& aabb1, const AABB& aabb2);

			void Dump()const;
		};
	}
}