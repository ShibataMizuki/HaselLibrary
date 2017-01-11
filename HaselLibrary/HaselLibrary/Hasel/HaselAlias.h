#pragma once

#include<memory>

namespace hasel
{
	template<class Type>
	using sptr = std::shared_ptr<Type>;
	template<class Type>
	using wptr = std::weak_ptr<Type>;
	template<class Type>
	using uptr = std::unique_ptr<Type>;
}