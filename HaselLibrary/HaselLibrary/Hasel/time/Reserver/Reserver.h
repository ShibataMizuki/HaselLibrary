#pragma once

#include<functional>

#include"time/TimerBase.h"
#include"HaselAlias.h"

namespace hasel
{
	namespace time
	{
		/// <summary>
		/// 指定時間後に関数を呼び出すクラス
		/// </summary>
		class Reserver :public TimerBase
		{
		private:
			/// <summary>
			/// 呼び出す関数
			/// </summary>
			std::function<void()> function;

			/// <summary>
			/// 待機時間
			/// </summary>
			float waitTime;

		public:
			~Reserver();

			/// <summary>
			/// インスタンスを作成する
			/// </summary>
			/// <param name="waitTime">呼び出し待ち時間</param>
			/// <param name="function">呼び出し関数</param>
			/// <returns></returns>
			static sptr<Reserver> Create(float waitTime, const std::function<void()>& function);

			/// <summary>
			/// 更新処理
			/// </summary>
			void Update()override;

		};
	}
}