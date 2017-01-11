#pragma once

namespace hasel
{
	/// <summary>
	/// �p������V���O���g��������N���X
	/// </summary>
	template<class Type>
	class Singletized
	{
	protected:
		//�C���X�^���X
		static Type* instance;

		Singletized() = default;
		~Singletized() = default;

	public:
		/// <summary>
		/// �C���X�^���X���擾����
		/// </summary>
		/// <returns>�C���X�^���X</returns>
		static Type* GetInstance()
		{
			if (!instance)
				instance = new Type();
			return instance;
		}

	};

	template<class Type>
	Type* Singletized<Type>::instance = nullptr;
}