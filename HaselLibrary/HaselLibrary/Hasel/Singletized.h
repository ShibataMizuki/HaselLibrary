#pragma once

namespace hasel
{
	/// <summary>
	/// 継承先をシングルトン化するクラス
	/// </summary>
	template<class Type>
	class Singletized
	{
	protected:
		//インスタンス
		static Type* instance;

		Singletized() = default;
		~Singletized() = default;

	public:
		/// <summary>
		/// インスタンスを取得する
		/// </summary>
		/// <returns>インスタンス</returns>
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