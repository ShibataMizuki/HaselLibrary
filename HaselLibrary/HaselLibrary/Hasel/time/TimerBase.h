#pragma once

namespace hasel
{
	namespace time
	{
		/// <summary>
		/// タイマーの基底クラス
		/// </summary>
		class TimerBase
		{
		protected:
			//経過時間
			float elapsedTime;
			//有効フラグ
			bool isActive;

		public:
			TimerBase() :elapsedTime(0),isActive(true) {}
			virtual ~TimerBase() = default;

			/// <summary>
			/// 時間を進める
			/// </summary>
			/// <param name="dt">進める時間</param>
			void Step(float dt) { elapsedTime += dt; }

			/// <summary>
			/// 時間を0に戻す
			/// </summary>
			void Reset() { elapsedTime = 0.f; }

			/// <summary>
			/// 経過時間を取得する
			/// </summary>
			/// <returns>経過時間</returns>
			float Get()const { return elapsedTime; }

			/// <summary>
			/// 有効化フラグを設定する
			/// </summary>
			/// <param name="IsActive"></param>
			void SetActive(bool isActive) { this->isActive = isActive; }

			/// <summary>
			/// 有効かどうか
			/// </summary>
			/// <returns>
			/// true :有効である
			/// false:有効でない
			/// </returns>
			bool IsActive()const { return isActive; }

			/// <summary>
			/// 更新する
			/// </summary>
			virtual void Update() = 0;
		};
	}
}