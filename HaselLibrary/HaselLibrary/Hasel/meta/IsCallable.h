#pragma once

namespace hasel
{
	namespace meta
	{
		/// <summary>
		/// <para>関数が呼び出し可能か検査する</para>
		/// <para>Func    ファンクタタイプ</para>
		/// <para>Args... 引数リスト</para>
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