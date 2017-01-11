#pragma once

#include<string>

namespace hasel
{
	namespace math
	{
		/// <summary>
		/// 二次元ベクトルクラス
		/// </summary>
		class Vector2
		{
		public:
			/// <summary>
			/// X要素
			/// </summary>
			float x;

			/// <summary>
			/// Y要素
			/// </summary>
			float y;

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Vector2();

			/// <summary>
			/// コンストラクタ
			/// </summary>
			/// <param name="x">X要素</param>
			/// <param name="y">Y要素</param>
			Vector2(float x, float y);

			Vector2 operator+(const Vector2& rv)const;
			Vector2 operator-(const Vector2& rv)const;
			Vector2 operator*(float rv)const;
			Vector2 operator/(float rv)const;
			void operator+=(const Vector2& rv);
			void operator-=(const Vector2& rv);

			/// <summary>
			/// ベクトルの長さを取得する
			/// </summary>
			/// <returns>ベクトルの長さ</returns>
			float GetLength()const;
			
			/// <summary>
			/// ベクトルを正規化する
			/// </summary>
			void Normalize();

			/// <summary>
			/// 正規化済みのベクトルを取得
			/// </summary>
			/// <returns>正規化済みのベクトル</returns>
			Vector2 GetNormalized()const;

			/// <summary>
			/// ベクトルの内積を求める
			/// </summary>
			/// <param name="rv">右辺値</param>
			/// <returns>内積値</returns>
			float Dot(const Vector2& rv)const;

			/// <summary>
			/// ベクトルの外積を求める
			/// </summary>
			/// <param name="rv">右辺値</param>
			/// <returns>外積値</returns>
			float Cross(const Vector2& rv)const;

			/// <summary>
			/// ダンプ文字列を取得する
			/// </summary>
			/// <returns>ダンプされた文字列</returns>
			std::string Dump()const;
		};
	}
}