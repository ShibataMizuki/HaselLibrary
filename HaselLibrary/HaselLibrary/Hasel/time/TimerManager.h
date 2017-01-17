#pragma once

#include<list>

#include"HaselAlias.h"
#include"Singletized.h"

namespace hasel
{
	namespace time
	{
		class TimerBase;

		/// <summary>
		/// タイマー管理クラス
		/// </summary>
		class TimerManager :public Singletized<TimerManager>
		{
		private:
			std::list<sptr<TimerBase>> timers;

		public:
			/// <summary>
			/// タイマーを追加する
			/// </summary>
			/// <param name="timer">追加するタイマー</param>
			void Add(const sptr<TimerBase>& timer);

			/// <summary>
			/// タイマーを取り除く
			/// </summary>
			/// <param name="timer">取り除くタイマー</param>
			void Remove(TimerBase* timer);

			/// <summary>
			/// 更新処理
			/// </summary>
			/// <param name="dt">進める時間</param>
			void Update(float dt);

			/// <summary>
			/// 全てのタイマーを取り除く
			/// </summary>
			void RemoveAll();

		};

	}
}