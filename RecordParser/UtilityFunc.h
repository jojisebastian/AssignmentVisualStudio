#pragma once

#ifndef __UTILITYFUNC__
#define __UTILITYFUNC__
#include <string>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <vector>

using namespace std;

void split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);
void  TrimString(vector<string> &vectorStrings, vector<string> &trimmedString);
std::string Remove_extension(const string& filename);

static inline void ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		std::not1(std::ptr_fun<int, int>(std::isspace))));
}


static inline void rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}


static inline void trim(std::string &s)
{
	ltrim(s);
	rtrim(s);
}

static inline std::string ltrimmed(std::string s)
{
	ltrim(s);
	return s;
}

static inline std::string rtrimmed(std::string s)
{
	rtrim(s);
	return s;
}

static inline std::string trimmed(std::string s)
{
	trim(s);
	return s;
}




#endif