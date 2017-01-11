#pragma once

namespace hasel
{
	namespace time
	{
		/// <summary>
		/// �^�C�}�[�̊��N���X
		/// </summary>
		class TimerBase
		{
		protected:
			//�o�ߎ���
			float elapsedTime;
			//�L���t���O
			bool isActive;

		public:
			TimerBase() :elapsedTime(0),isActive(true) {}
			virtual ~TimerBase() = default;

			/// <summary>
			/// ���Ԃ�i�߂�
			/// </summary>
			/// <param name="dt">�i�߂鎞��</param>
			void Step(float dt) { elapsedTime += dt; }

			/// <summary>
			/// ���Ԃ�0�ɖ߂�
			/// </summary>
			void Reset() { elapsedTime = 0.f; }

			/// <summary>
			/// �o�ߎ��Ԃ��擾����
			/// </summary>
			/// <returns>�o�ߎ���</returns>
			float Get()const { return elapsedTime; }

			/// <summary>
			/// �L�����t���O��ݒ肷��
			/// </summary>
			/// <param name="IsActive"></param>
			void SetActive(bool isActive) { this->isActive = isActive; }

			/// <summary>
			/// �L�����ǂ���
			/// </summary>
			/// <returns>
			/// true :�L���ł���
			/// false:�L���łȂ�
			/// </returns>
			bool IsActive()const { return isActive; }

			/// <summary>
			/// �X�V����
			/// </summary>
			virtual void Update() = 0;
		};
	}
}