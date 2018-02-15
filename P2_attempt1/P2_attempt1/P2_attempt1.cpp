#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inputfile;
	inputfile.open("isa_gw.txt", ios::in, ios::out);
	int i = 0;
	char *s = argv[2];
	for (std::string line; getline(inputfile, line); )
		if (line.find(std::string str(s)) != std::npos)
			i++;
	std::cout << "Number of lines that contain"<< s <<": " << i << endl;
	inputfile.close();
	std::getchar();
	return 0;
}

