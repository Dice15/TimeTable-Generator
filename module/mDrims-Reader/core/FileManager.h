
#pragma once
#include "./C++Header.h"
#include "./Utility.h"


class FileManager
{
public:
	static vector<vector<string>> Read_CSV(string path, util::SplitType splitType, regex format)
	{
		vector<vector<string>> fileData;
		ifstream ifs(path);
	
		if (ifs.is_open()) {
			string buffer;

			while (!ifs.eof())
			{
				getline(ifs, buffer);
				auto line = util::Split(buffer, splitType, format);
				if (!line.empty()) fileData.push_back(line);
			}

			ifs.close();
		}

		return fileData;
	}

	static bool Write_CSV(string path, vector<vector<string>> &fileData)
	{
		ofstream ofs(path);

		if (ofs.is_open()) {
			for (auto& line : fileData) {
				for (int i = 0; i < (int)line.size(); i++) {
					ofs << line[i] << (i == (int)line.size() - 1 ? "\n" : ",");
				}
			}
			ofs.close();
			return true;
		}
		return false;
	}
};