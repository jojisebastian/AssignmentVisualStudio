
#include "stdafx.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector> 

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <sstream>

#include "RecordParser.h"
#include "UtilityFunc.h"


PersonalDetail & PersonalDetail::operator =(const PersonalDetail &arg)
{
	if (this != &arg)
	{
		this->firsName = arg.firsName;
		this->secondName = arg.secondName;
		this->score = arg.score;
	}

	return *this;
}

PersonalDetail::PersonalDetail(const PersonalDetail &personalDt)
{
	firsName = personalDt.firsName;
	secondName = personalDt.secondName;
	score = personalDt.score;
}

PersonalDetail::PersonalDetail(string firstName, string secondName, int score)
{
	this->firsName = firstName;
	this->secondName = secondName;
	this->score = score;
}

bool operator <(const PersonalDetail &operand1, const PersonalDetail &operand2)
{
	bool retValue = false;
	if (operand1.score == operand2.score)
	{
		if (operand1.firsName.compare(operand2.firsName)<0)
		{
			retValue = true;
		}
		else
		{
			retValue = false;
		}
	}
	else if (operand1.score<operand2.score)
	{
		retValue = operand1.score<operand2.score;
	}

	return retValue;
}



	bool Sorter::operator()(const PersonalDetail& operand1, const PersonalDetail& operand2) const
	{
		bool retValue = true;
		if (operand1.score == operand2.score)
		{
			if (operand1.firsName.compare(operand2.firsName)>0)
			{
				retValue = false;
			}
			else
			{
				retValue = true;
			}
		}
		else if (operand1.score<operand2.score)
		{
			retValue = operand1.score>operand2.score;
		}

		return retValue;
	}





int ReadRecodrds(string fileName, std::vector<PersonalDetail> &records)
{
	int retValue = 0;
	ifstream inputfile;
	int recordCount = 0;
	int recordParsed = 0;

	inputfile.open(fileName.c_str());
	if (inputfile.is_open()) {
		while (!inputfile.eof())
		{
			string tempValue;
			getline(inputfile, tempValue);
			recordCount++;
			vector<string> spliteString = split(tempValue, ',');
			if (spliteString.size()<3)
			{
				if (spliteString.size()>1)
				{
					cout << "Record is incorrect -->" << tempValue << "\n";
				}
				continue;
			}

			recordParsed++;
			vector<string>strippedString;
			TrimString(spliteString, strippedString);
			string scoreString = strippedString[2];

			int isNumber = true;
			for (string::const_iterator k = scoreString.begin(); k != scoreString.end(); ++k) {
				isNumber &= isdigit(*k);
			}
			if (isNumber == false) {
				cout << "Record should be numeric  at -->" << tempValue << tempValue << "\n";
			}
			int scores = atoi(scoreString.c_str());
			PersonalDetail personRecord = PersonalDetail(strippedString[0], strippedString[1], scores);
			records.push_back(personRecord);
		}
		inputfile.close();

		cout << "Recod Total=" << recordCount - 1 << "Record Parsed=" << recordParsed << "\n";

	}
	else
	{
		cout << "File Could not opened ->" << fileName << "\n";
		retValue = -1;
	}
	return retValue;
}


int WriteRecords(string fileName, const std::vector<PersonalDetail> &records)
{
	int retValue = -1;
	ofstream outputFile(fileName.c_str());
	if (outputFile.is_open())
	{
		for (int i = 0; i<records.size(); i++)
		{
			PersonalDetail tmpDt = records[i];
			outputFile << tmpDt.firsName << "," << tmpDt.secondName << "," << tmpDt.score << "\n";
		}

		retValue = 0;
		outputFile.close();
	}

	return retValue;
}


int main2(int argc, char *argv[])
{
	string fileName = "names.txt";
	int retValue = 0;

	if (argc >= 2)
	{
		fileName = string(argv[1]);

	}

	string outputFile = Remove_extension(fileName);
	outputFile = outputFile + "-graded.txt";

	vector<PersonalDetail>  personalDt;
	if (ReadRecodrds(fileName, personalDt) == 0)
	{
		if (personalDt.size()>0)
		{
			//std::sort (personalDt.begin(), personalDt.end());//Ascending order
			std::sort(personalDt.begin(), personalDt.end(), Sorter());
		}

		if (WriteRecords(outputFile, personalDt) != 0)
		{
			retValue = 1;
		}
	}
	else
	{
		retValue = 2;
	}




	return retValue;
}

