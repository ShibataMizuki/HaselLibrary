#pragma once

#include"../Hasel/HaselAlias.h"
#include"../Hasel/meta/MetaInc.h"

#include<functional>
#include<vector>

namespace hasel
{
	namespace cs2d
	{
		class RigidBody;
		using CallbackFunction = std::function<void(const wptr<RigidBody>&, const wptr<RigidBody>&)>;

		/// <summary>
		/// �Փ˂����Ƃ��ɌĂ΂�鏈����o�^����N���X
		/// </summary>
		class Callback
		{
		private:
			static unsigned long long ConstructionCount;

			//�Փ˂��鍄�̂̑���A
			int attributeA;
			//�Փ˂��鍄�̂̑���B
			int attributeB;
			//�R�[���o�b�N
			std::function<void(const wptr<RigidBody>&, const wptr<RigidBody>&)> callback;
			//���j�[�N�ԍ�
			unsigned long long uniqueNum;

		public:

			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			/// <param name="attributeA">�Փ˂����鍄�̂̑���A</param>
			/// <param name="attributeB">�Փ˂����鍄�̂̑���B</param>
			/// <param name="callback">�Փˎ��ɌĂяo���֐�</param>
			Callback(int attributeA, int attributeB, const std::function<void(const wptr<RigidBody>&, const wptr<RigidBody>&)>& callback);

			/// <summary>
			/// ����A�̑������擾
			/// </summary>
			/// <returns>����</returns>
			int GetAttributeA()const;

			/// <summary>
			/// ����B�̑������擾
			/// </summary>
			/// <returns>����</returns>
			int GetAttributeB()const;

			/// <param name="bodyA">�Փ˂�������A</param>
			/// <param name="bodyB">�Փ˂�������B</param>
			void operator()(const wptr<RigidBody>& bodyA, const wptr<RigidBody>& bodyB)const;

			/// <param name="rhs">��r����l</param>
			/// <returns></returns>
			bool operator==(const Callback& rhs)const;
		};

	}
}