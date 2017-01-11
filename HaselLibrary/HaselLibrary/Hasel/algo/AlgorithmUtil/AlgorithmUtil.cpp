#include "AlgorithmUtil.h"

#include<sstream>

using namespace std;

std::vector<std::string> hasel::algo::SplitString(const std::string & str, char delim)
{
	vector<string> result;
	stringstream ss(str);
	string buf;
	while (getline(ss, buf, delim))
		result.push_back(buf);
	return result;
}