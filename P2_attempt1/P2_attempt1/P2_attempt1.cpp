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
	for (std::string line; getline(inputfile, line); )
		if (line.find("PUBLISH(") != 0)
			i++;
	std::cout << "Number of lines that contain 'PUBLISH(': " << i << endl;
	inputfile.close();
	std::getchar();
	return 0;
}

