// RecordParser.cpp : Defines the entry point for the console application.
//

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

int main(int argc, char *argv[])
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

