#pragma once

#include<list>
#include<map>
#include<sstream>

#include"HaselAlias.h"

namespace hasel
{
	namespace cs2d
	{
		class RigidBody;
		class RigidBodyMold;

		/// <summary>
		/// ���̃C���X�^���X�ۊǃN���X
		/// </summary>
		class RigidBodyStorage
		{
		private:
			//���̃��X�g
			std::list<sptr<RigidBody>> rigidBodyies;
			//�O���[�s���O�ςݍ��̃��X�g <���̂̑���,����>
			std::map<int, std::list<wptr<RigidBody>>> groupedRigidBodies;

		public:
			/// <summary>
			/// ���̃C���X�^���X���쐬����
			/// </summary>
			/// <param name="mold">�쐬�Ɏg�p���鍄�̒��^</param>
			/// <returns>�쐬���ꂽ���̂ւ̎�Q��</returns>
			wptr<RigidBody> CreateRigidBody(const RigidBodyMold& mold);

			/// <summary>
			/// ���̃C���X�^���X���폜����
			/// </summary>
			/// <param name="body">�폜���鍄�̃C���X�^���X�ւ̎�Q��</param>
			void DestroyRigidBody(const wptr<RigidBody>& body);

			/// <summary>
			/// ���̃C���X�^���X���X�g���擾����
			/// </summary>
			/// <returns>���̃C���X�^���X���X�g</returns>
			std::list<wptr<RigidBody>> GetRigidBodies()const;

			/// <summary>
			/// ���̃C���X�^���X���X�g���擾����(�����w��)
			/// </summary>
			/// <param name="attribute">�w�肷�鑮��</param>
			/// <returns>���̃C���X�^���X���X�g</returns>
			const std::list<wptr<RigidBody>>& GetRigidBodies(int attribute)const;
		};
	}
}