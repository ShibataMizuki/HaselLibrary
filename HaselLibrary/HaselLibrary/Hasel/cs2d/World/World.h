#pragma once

#include<map>
#include<list>

#include"math/MathInc.h"
#include"HaselAlias.h"

namespace hasel
{
	namespace shape
	{
		class Shape;
	}

	namespace cs2d
	{
		class RigidBody;
		class RigidBodyMold;
		class Callback;
		class RigidBodyStorage;
		class CallbackStorage;

		/// <summary>
		/// �Փ˔���t�@�T�[�h
		/// </summary>
		class World
		{
		private:
			sptr<RigidBodyStorage> rigidBodyStorage;
			sptr<CallbackStorage> callbackStorage;

			bool is_intersect(RigidBody* bodyA, RigidBody* bodyB);

		public:
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			World();

			/// <summary>
			/// ���̂��쐬����
			/// </summary>
			/// <param name="mold">���̒��^</param>
			/// <returns>���̂ւ̎�Q��</returns>
			wptr<RigidBody> CreateRigidBody(const RigidBodyMold& mold);

			/// <summary>
			/// ���̂��폜����
			/// </summary>
			/// <param name="body">�폜���鍄��</param>
			void RemoveRigidBody(const wptr<RigidBody>& body);

			/// <summary>
			/// ���̃��X�g���擾����
			/// </summary>
			/// <returns>���̃��X�g</returns>
			std::list<wptr<RigidBody>> GetRigidBodies()const;

			/// <summary>
			/// ���̃��X�g���擾����(�����w��t��)
			/// </summary>
			/// <param name="attribute">�擾���鍄�̂̎�����</param>
			/// <returns>�������X�g</returns>
			const std::list<wptr<RigidBody>>& GetRigidBodies(int attribute)const;

			/// <summary>
			/// �Փ˃R�[���o�b�N��ǉ�����
			/// </summary>
			/// <param name="callback">�ǉ�����R�[���o�b�N</param>
			void AddCallback(const Callback& callback);

			/// <summary>
			/// �Փ˃R�[���o�b�N
			/// </summary>
			/// <param name="callback"></param>
			void RemoveCallback(const Callback& callback);

			/// <summary>
			/// �Փ˂̌��m�y�уR�[���o�b�N�֐��̌Ăяo�����s��
			/// </summary>
			void ExecuteCollision();
		};
	}
}