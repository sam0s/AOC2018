#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

int main()
{
	//init vars
	std::ifstream ifile;
	ifile.open("input.txt");
	int sum = 0;
	std::string hold = "";

	//read file and add/subtract to sum
	while (!ifile.eof()) {
		ifile >> hold;
		if (hold.substr(0, 1) == "+")
			sum+=stoi(hold.substr(1));
		else
			sum-=stoi(hold.substr(1));
	}

	//close file, output total
	ifile.close();
	std::cout << sum;

	//halt program before termination
	std::cin >> hold;

	//eof
    return 0;
}

