#pragma once

#include"../Hasel/HaselAlias.h"
#include<memory>
#include<vector>
#include<string>

namespace hasel
{
	namespace algo
	{
		/// <summary>
		/// 文字列を分割する
		/// </summary>
		/// <param name="str">分割する文字列</param>
		/// <param name="delim">区切り文字</param>
		/// <returns>分割された文字列のリスト</returns>
		std::vector<std::string> SplitString(const std::string& str, char delim);
	}
}