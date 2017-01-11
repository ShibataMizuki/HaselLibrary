#pragma once

namespace hasel
{
	namespace meta
	{
		/// <summary>
		/// <para>�֐����Ăяo���\����������</para>
		/// <para>Func    �t�@���N�^�^�C�v</para>
		/// <para>Args... �������X�g</para>
		/// </summary>
		template<typename Func, typename... Args>
		struct is_callable
		{
		private:
			template<typename CheckType>
			static std::true_type check(decltype(std::declval<CheckType>()(std::declval<Args>()...))*);

			template<typename CheckType>
			static std::false_type check(...);
		public:
			typedef decltype(check<Func>(nullptr)) type;
			static constexpr bool value = type::value;
		};
	}
}