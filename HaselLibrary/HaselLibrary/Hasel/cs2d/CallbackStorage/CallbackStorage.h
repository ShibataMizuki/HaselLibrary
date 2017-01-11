#pragma once

#include<map>
#include<list>
#include<functional>

#include"HaselAlias.h"

namespace hasel
{
	namespace cs2d
	{
		class RigidBody;
		class Callback;

		/// <summary>
		/// �Փ˃R�[���o�b�N�ۊǃN���X
		/// </summary>
		class CallbackStorage
		{
		private:
			std::map<std::pair<int,int>,std::list<Callback>> callbacks;

		public:
			/// <summary>
			/// �Փ˃S�[���o�b�N��ǉ�����
			/// </summary>
			/// <param name="callback">�ǉ�����Փ˃R�[���o�b�N</param>
			void AddCallback(const Callback& callback);

			/// <summary>
			/// �Փ˃R�[���o�b�N����菜��
			/// </summary>
			/// <param name="callback">��菜���Փ˃R�[���o�b�N</param>
			void RemoveCallback(const Callback& callback);

			/// <summary>
			/// �Փ˃R�[���o�b�N���X�g���擾����
			/// </summary>
			/// <param name="attributeA">����A</param>
			/// <param name="attributeB">����B</param>
			/// <returns>�Փ˃R�[���o�b�N���X�g</returns>
			const std::list<Callback>& GetCallbacks(int attributeA, int attributeB)const;

			std::list<Callback> GetAllCallbacks()const;

		};
	}
}