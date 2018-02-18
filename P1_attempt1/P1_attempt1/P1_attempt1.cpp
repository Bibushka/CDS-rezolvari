#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int checkArgumets(int argc, char* argv[])
{
	if (argc == 1)
		return 0;
	return 1;
}

void getTimestampAndNumberOfDevices(string argv)
{
	const string fileName = argv;
	ifstream inputFile;
	inputFile.open(fileName);
	for (std::string line; getline(inputFile, line);)
	{
		if (line.find("Subnet") != std::string::npos)
			std::cout << line.substr(0, line.find("Subnet") - 2) << endl;
		if (line.find("Nr. devices: ") == 0)
			std::cout << line.substr(0, line.find(",")) << endl << endl;
	}
	inputFile.close();
}

int main(int argc, char **argv)
{
	if (checkArgumentss(argc, argv) == 0)
	{
		cout << "Please enter the program arguments as followed:" << endl <<
			"'program name' 'first input file address' 'second input file address' ... " << endl <<
			"'n'th input file address', all delimited by one space character:" << endl;
		exit(0);
	}
	for (int argcount = 1; argcount < argc; argcount++)
	{
		getTimestampAndNumberOfDevices(argv[argcount]);
		cout << endl;
	}
	return 0;
}