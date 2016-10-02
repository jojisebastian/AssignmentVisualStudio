
#include "UtilityFunc.h"
#include <sstream>

void split(const string &s, char delim, vector<string> &elems)
{
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim))
	{
		elems.push_back(item);
	}
}


vector<string> split(const string &s, char delim)
{
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}



void  TrimString(vector<string> &vectorStrings, vector<string> &trimmedString)
{

	vector<string>::iterator it = vectorStrings.begin();
	trimmedString.clear();
	while (it != vectorStrings.end())
	{
		string tempString = trimmed(*it);
		trimmedString.push_back(tempString);
		it++;
	}
}

std::string Remove_extension(const string& filename)
{
	size_t lastdot = filename.find_last_of(".");
	if (lastdot == std::string::npos) {
		return filename;
	}
	return filename.substr(0, lastdot);
}
