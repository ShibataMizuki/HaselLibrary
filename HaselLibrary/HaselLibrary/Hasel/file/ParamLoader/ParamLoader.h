#pragma once

#include<string>
#include<map>

namespace hasel
{
	namespace file
	{
		/// <summary>
		/// �e�L�X�g�t�@�C������p�����[�^���擾����N���X
		/// </summary>
		class ParamLoader
		{
		private:
			//�p�����[�^�ۑ��p�ϐ�
			std::map<std::string, std::string> params;
			//�G���[���O
			mutable std::string errorLog;

		public:
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			ParamLoader();

			/// <summary>
			/// �e�L�X�g�t�@�C������p�����[�^�����[�h����
			/// </summary>
			/// <param name="path">�t�@�C���p�X</param>
			void Load(const std::string& path);

			/// <summary>
			/// int�^�Ƃ��ăp�����[�^���擾����
			/// </summary>
			/// <param name="paramName">�p�����[�^��</param>
			/// <returns>�p�����[�^</returns>
			int GetAsInt(const std::string& paramName)const;

			/// <summary>
			/// float�^�Ƃ��ăp�����[�^���擾����
			/// </summary>
			/// <param name="paramName">�p�����[�^��</param>
			/// <returns>�p�����[�^</returns>
			float GetAsFloat(const std::string& paramName)const;

			/// <summary>
			/// string�^�Ƃ��ăp�����[�^���擾����
			/// </summary>
			/// <param name="paramName">�p�����[�^��</param>
			/// <returns>�p�����[�^</returns>
			std::string GetAsString(const std::string& paramName)const;

			/// <summary>
			/// �G���[���O���擾����
			/// </summary>
			/// <returns>�G���[���O������</returns>
			std::string GetErrorLog()const;
		};
	}
}