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
		/// ������𕪊�����
		/// </summary>
		/// <param name="str">�������镶����</param>
		/// <param name="delim">��؂蕶��</param>
		/// <returns>�������ꂽ������̃��X�g</returns>
		std::vector<std::string> SplitString(const std::string& str, char delim);
	}
}