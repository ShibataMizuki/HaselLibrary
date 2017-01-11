#pragma once

#include<functional>

#include"time/TimerBase.h"
#include"HaselAlias.h"

namespace hasel
{
	namespace time
	{
		/// <summary>
		/// 定期的に登録された関数を呼び出すクラス
		/// </summary>
		class Scheduler :public TimerBase
		{
		private:
			//呼び出す関数
			std::function<void()> function;
			//呼び出し間隔
			float interval;
			//呼び出しフラグ
			bool isSchedule;

		public:
			/// <summary>
			/// インスタンスを作成する
			/// </summary>
			/// <param name="interval">呼び出し間隔</param>
			/// <param name="function">呼び出し関数</param>
			/// <returns>インスタンス</returns>
			static sptr<Scheduler> Create(float interval,const std::function<void()>& function);

			~Scheduler();

			/// <summary>
			/// 更新処理
			/// </summary>
			void Update()override;
		};
	}
}