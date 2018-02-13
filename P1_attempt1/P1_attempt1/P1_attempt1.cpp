#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void read_write(char* argv, int i)
{
	ifstream inputFile;
	inputFile.open(argv, ios::in);
	ofstream outputFile;
	outputFile.open("abcde.txt"); //outputFile.open("out_t" + std::to_string(i) + ".txt");
	outputFile << "Hello world!";
	inputFile.close();
}

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		read_write(argv[i], i);
	return 0;
}

