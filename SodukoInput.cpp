#include"stdafx.h"
using namespace std;
vector<int(*)[9]> SodukoInput(char * filename)
{
	ifstream file;
	file.open(filename, ios::in);
	int linenum = 0, curline = 0;
	vector<int (*)[9]> ProblemSet;
	int(*temp)[9] = new int[9][9];
	if (!file.is_open())
	{
		cout << "fail to open file!" << endl;
		return ProblemSet;
	}
	while (!file.eof())
	{
		string buffer;
		getline(file, buffer);
		if (buffer.empty())
			continue;
		linenum++;
		if (linenum % 9 == 1 )
		{
			temp = new int[9][9];
			curline = 0;
		}
		for (int i = 0; i < 9; ++i)
		{
			temp[curline][i] = buffer[2 * i] - '0';
		}
		curline++;
		if (linenum % 9 == 0)
		{
			ProblemSet.push_back(temp);
			temp = NULL;
		}
	}
	file.close();
	return ProblemSet;
}