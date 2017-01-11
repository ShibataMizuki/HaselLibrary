#pragma once

#include<functional>

#include"time/TimerBase.h"
#include"HaselAlias.h"

namespace hasel
{
	namespace time
	{
		/// <summary>
		/// ����I�ɓo�^���ꂽ�֐����Ăяo���N���X
		/// </summary>
		class Scheduler :public TimerBase
		{
		private:
			//�Ăяo���֐�
			std::function<void()> function;
			//�Ăяo���Ԋu
			float interval;
			//�Ăяo���t���O
			bool isSchedule;

		public:
			/// <summary>
			/// �C���X�^���X���쐬����
			/// </summary>
			/// <param name="interval">�Ăяo���Ԋu</param>
			/// <param name="function">�Ăяo���֐�</param>
			/// <returns>�C���X�^���X</returns>
			static sptr<Scheduler> Create(float interval,const std::function<void()>& function);

			~Scheduler();

			/// <summary>
			/// �X�V����
			/// </summary>
			void Update()override;
		};
	}
}