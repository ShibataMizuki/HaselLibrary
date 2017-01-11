#pragma once
#include"../Hasel/HaselAlias.h"
#include"../Hasel/Math/MathInc.h"
#include"../Hasel/Shape/AABB/AABB.h"
#include"shape/ShapeInc.h"

#include<memory>
#include<vector>

namespace hasel
{
	namespace cs2d
	{
		/// <summary>
		/// RigidBody�r���_�[
		/// </summary>
		class RigidBodyMold
		{
			friend class RigidBody;
		private:
			//�`��r���_���X�g
			std::vector<shape::Shape> shapes;
			// �������X�g
			std::vector<int> attributes;
			// ���[�U�[�f�[�^
			void* userdata;
			// ���W
			math::Vector2 pos;

			/// <summary>
			/// ���[�֐�
			/// </summary>
			void SetAttributes() { attributes.clear();}

		public:
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			RigidBodyMold();

			/// <summary>
			/// ���W�ݒ�֐�
			/// </summary>
			/// <param name="pos">�ݒ肷����W</param>
			/// <returns>���g�̃C���X�^���X</returns>
			RigidBodyMold& SetPosition(const math::Vector2& pos);

			/// <summary>
			/// �`���ǉ�����
			/// </summary>
			/// <param name="shape">�`��N���X</param>
			/// <returns>���g�̃C���X�^���X</returns>
			RigidBodyMold& AddShape(const shape::Shape& shape);

			/// <summary>
			/// �������X�g�ݒ�֐�
			/// </summary>
			/// <param name="head">�ݒ肷�鑮�����X�g</param>
			/// <param name="...tails">�ݒ肷�鑮�����X�g</param>
			/// <returns>���g�̃C���X�^���X</returns>
			template<class Head = int, class... Tails>
			RigidBodyMold& SetAttributes(const Head& head,const Tails&... tails)
			{
				SetAttributes(tails...);
				attributes.push_back(head);
				return *this;
			}

			/// <summary>
			/// ������ǉ�����
			/// </summary>
			/// <param name="attribute">�ǉ����鑮��</param>
			/// <returns>���g�̃C���X�^���X</returns>
			RigidBodyMold& AddAttribute(int attribute);

			/**
			@brief ���[�U�[�f�[�^�ݒ�֐�
			@param userdata �ݒ肷�郆�[�U�[�f�[�^
			*/
			/// <summary>
			/// �C�Ӄf�[�^��ݒ肷��
			/// </summary>
			/// <param name="userdata">�ݒ肷��f�[�^</param>
			/// <returns>���g�̃C���X�^���X</returns>
			RigidBodyMold& SetUserData(void* userdata);

			
			/// <summary>
			///	�C���X�^���X�쐬�֐�
			/// </summary>
			/// <returns>�쐬���ꂽ����</returns>
			sptr<RigidBody> MintShared()const;

			/// <summary>
			/// �C���X�^���X�쐬�֐�
			/// </summary>
			/// <returns>�쐬���ꂽ����</returns>
			uptr<RigidBody> MintUnique()const;

			/// <summary>
			/// �C���X�^���X�쐬�֐�
			/// </summary>
			/// <returns>�쐬���ꂽ����</returns>
			RigidBody* MintRaw()const;
		};

		/// <summary>
		/// ���̃N���X
		/// </summary>
		class RigidBody
		{
		private:
			// ���W
			math::Vector2 pos;
			// �}�`���X�g
			std::vector<shape::Shape> shapes;
			// �������X�g
			std::vector<int> attributes;
			// ���[�U�[�f�[�^
			void* userdata;
			// AABB
			mutable shape::AABB aabb;
			// AABB���ύX���ꂽ��
			mutable bool isAABBChanged;

		public:
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			/// <param name="builder">�r���_�[</param>
			RigidBody(const RigidBodyMold& mold);

			/// <summary>
			/// ���W��ݒ肷��
			/// </summary>
			/// <param name="pos">���W</param>
			void SetPosition(const math::Vector2& pos);

			/// <summary>
			/// ���W���擾����
			/// </summary>
			/// <returns>���W</returns>
			const math::Vector2& GetPosition()const;

			/// <summary>
			/// ������ǉ�����
			/// </summary>
			/// <param name="attribute">�ǉ����鑮��</param>
			void AddAttribute(int attribute);

			/// <summary>
			/// �������O��
			/// </summary>
			/// <param name="attribute">�O������</param>
			void RemoveAttribute(int attribute);

			/**
			@brief ���������݂��邩�ǂ����T��
			@param attribute �T������
			@return true  :���݂���
					false :���݂��Ȃ�
			*/
			/// <summary>
			/// ���������݂��邩�ǂ������؂���
			/// </summary>
			/// <param name="attribute">�T������</param>
			/// <returns>
			/// true :���݂���
			/// false:���݂��Ȃ�
			/// </returns>
			bool FindAttribute(int attribute)const;

			
			/// <summary>
			/// �������X�g�擾�֐�
			/// </summary>
			/// <returns>�������X�g</returns>
			const std::vector<int>& GetAttibutes()const;

			/// <summary>
			/// �C�Ӄf�[�^��ݒ肷��
			/// </summary>
			/// <param name="userdata">�C�Ӄf�[�^</param>
			void SetUserdata(void* userdata);

			/// <summary>
			/// �C�Ӄf�[�^���擾����
			/// </summary>
			/// <returns>�C�Ӄf�[�^</returns>
			void* GetUserdataRaw()const;

			/// <summary>
			/// �C�Ӄf�[�^���擾����
			/// Type �C�Ӄf�[�^�̌^
			/// </summary>
			/// <returns>�C�Ӄf�[�^</returns>
			template<typename Type>
			Type* GetUserdata()const
			{
				return static_cast<Type*>(userdata);
			}

			/// <summary>
			/// AABB���擾����
			/// </summary>
			/// <returns>AABB</returns>
			const shape::AABB& GetAABB()const;

			/// <summary>
			/// �`�󃊃X�g���擾����
			/// </summary>
			/// <returns>�`�󃊃X�g</returns>
			const std::vector<shape::Shape>& GetShapes()const;

		};
	}
}