#pragma once

#include<functional>

#include"time/TimerBase.h"
#include"HaselAlias.h"

namespace hasel
{
	namespace time
	{
		/// <summary>
		/// �w�莞�Ԍ�Ɋ֐����Ăяo���N���X
		/// </summary>
		class Reserver :public TimerBase
		{
		private:
			/// <summary>
			/// �Ăяo���֐�
			/// </summary>
			std::function<void()> function;

			/// <summary>
			/// �ҋ@����
			/// </summary>
			float waitTime;

		public:
			~Reserver();

			/// <summary>
			/// �C���X�^���X���쐬����
			/// </summary>
			/// <param name="waitTime">�Ăяo���҂�����</param>
			/// <param name="function">�Ăяo���֐�</param>
			/// <returns></returns>
			static sptr<Reserver> Create(float waitTime, const std::function<void()>& function);

			/// <summary>
			/// �X�V����
			/// </summary>
			void Update()override;

		};
	}
}