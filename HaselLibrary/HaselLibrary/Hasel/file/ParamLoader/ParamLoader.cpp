#include "ParamLoader.h"

#include<fstream>
#include"Hasel.h"

using namespace std;
using namespace hasel;

hasel::file::ParamLoader::ParamLoader()
{
	errorLog = "-----------ERROR_LOG-----------\n";
}

void hasel::file::ParamLoader::Load(const std::string & path)
{
	ifstream ifs;
	ifs.open(path, ios::in);
	if (ifs.fail())
	{
		errorLog += path + "�̓ǂݍ��݂Ɏ��s���܂���\n";
		return;
	}

	string line;
	int line_cnt = 0;

	while (getline(ifs, line))
	{
		line_cnt++;
		char prev = '\0';

		bool is_comment = false;
		string key;
		string value;

		for (auto elem : line)
		{
			if (elem == '/'&&prev == '/')
			{
				is_comment = true;
				break;
			}
			prev = elem;
		}
		if (is_comment)
			continue;

		auto v = algo::SplitString(line, ' ');
		if (v.size() != 2)
		{
			errorLog += "[syntax error]" + to_string(line_cnt) + "�s��:" + "\"key value\"�̌`�ɂȂ��Ă��܂���\n";
			continue;
		}
		key = v[0];
		value = v[1];

		params[key] = value;
	}
}

std::string hasel::file::ParamLoader::GetErrorLog() const
{
	return errorLog + "-------------------------------\n";
}

int hasel::file::ParamLoader::GetAsInt(const std::string & param_name)const
{
	if (params.find(param_name) == params.end())
	{
		errorLog += "�p�����[�^\"" + param_name + "\"�͑��݂��܂���\n";
		return -1;
	}

	return stoi(params.at(param_name));
}

float hasel::file::ParamLoader::GetAsFloat(const std::string & param_name)const
{
	if (params.find(param_name) == params.end())
	{
		errorLog += "�p�����[�^\"" + param_name + "\"�͑��݂��܂���\n";
		return -1.f;
	}
	return stof(params.at(param_name));
}

std::string hasel::file::ParamLoader::GetAsString(const std::string & param_name)const
{
	if (params.find(param_name) == params.end())
	{
		errorLog += "�p�����[�^\"" + param_name + "\"�͑��݂��܂���\n";
		return "Nan";
	}
	return params.at(param_name);
}
