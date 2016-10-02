#pragma once
#ifndef __RECORDPARSER__
#define __RECORDPARSER__

#include <string>
using namespace std;

struct PersonalDetail
{
	string firsName;
	string secondName;
	int  score;

	PersonalDetail(string firstName, string secondName, int score);
	PersonalDetail(const PersonalDetail &personalDt);
	PersonalDetail()
	{
		firsName = "";
		secondName = "";
		score = 0;
	};
	PersonalDetail & operator =(const PersonalDetail &arg);



	friend bool operator <(const PersonalDetail &op1, const PersonalDetail &op2);

};


struct Sorter
{
	bool operator()(const PersonalDetail& operand1, const PersonalDetail& operand2) const;
	
};

int ReadRecodrds(string fileName, std::vector<PersonalDetail> &records);
int WriteRecords(string fileName, const std::vector<PersonalDetail> &records);

#endif