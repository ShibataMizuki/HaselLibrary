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
		/// �^�C�}�[�Ǘ��N���X
		/// </summary>
		class TimerManager :public Singletized<TimerManager>
		{
		private:
			std::list<wptr<TimerBase>> timers;

		public:
			/// <summary>
			/// �^�C�}�[��ǉ�����
			/// </summary>
			/// <param name="timer">�ǉ�����^�C�}�[</param>
			void Add(const wptr<TimerBase>& timer);

			/// <summary>
			/// �^�C�}�[����菜��
			/// </summary>
			/// <param name="timer">��菜���^�C�}�[</param>
			void Remove(TimerBase* timer);

			/// <summary>
			/// �X�V����
			/// </summary>
			/// <param name="dt">�i�߂鎞��</param>
			void Update(float dt);

		};

	}
}