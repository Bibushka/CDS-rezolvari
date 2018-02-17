#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void read_write(string argv, int index)
{
	const string fileName = argv.substr(argv.rfind("/") + 1, string::npos);
	ifstream inputFile;
	inputFile.open(fileName, ios::in);
	ofstream outputFile;
	outputFile.open("out_t" + std::to_string(index) + ".txt");
	const string deviceNumber = "Nr. devices: ";
	outputFile << "yo yo";
	for (std::string line; getline(inputFile, line);)
	{
		if (line.empty())
		{
			getline(inputFile, line);
			std::cout << line.substr(0, 18) << endl;
			outputFile << line.substr(0, 18) << endl;
		}
		if (line.find(deviceNumber) == 0)
		{
			std::cout << line.substr(0, line.find(",") - 1) << endl;
			outputFile << line.substr(0, line.find(",") - 1) << endl << endl;
		}
	}
	inputFile.close();
}


int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		read_write(argv[i], i);
		cout << endl;
	}
	return 0;
}