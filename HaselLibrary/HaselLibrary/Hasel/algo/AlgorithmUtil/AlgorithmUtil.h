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
		/// •¶š—ñ‚ğ•ªŠ„‚·‚é
		/// </summary>
		/// <param name="str">•ªŠ„‚·‚é•¶š—ñ</param>
		/// <param name="delim">‹æØ‚è•¶š</param>
		/// <returns>•ªŠ„‚³‚ê‚½•¶š—ñ‚ÌƒŠƒXƒg</returns>
		std::vector<std::string> SplitString(const std::string& str, char delim);
	}
}