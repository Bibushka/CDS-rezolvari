#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

int checkArguments(int argc, char* argv[])
{
	if (argc != 3)
		return 0;
	return 1;
}

int main(int argc, char* argv[])
{
	if (checkArguments(argc, argv) == 0)
	{
		cout << "Please enter the program arguments as followed:" << endl <<
			"'program name' 'input file address' 'sequence to be searched for'" << endl <<
			"all delimited by one space character:" << endl;
		exit(0);
	}
	ifstream inputFile;
	inputFile.open("isa_gw.log", ios::in);
	int lineCount = 0;
	const string sequenceToFind = argv[2];
	for (std::string line; getline(inputFile, line); )
		if (line.find(sequenceToFind) != std::string::npos)
			lineCount++;
	std::cout << "Number of lines that contain '" << sequenceToFind << "': " << lineCount << endl;
	inputFile.close();
	return 0;
}