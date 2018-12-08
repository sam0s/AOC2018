// AOC_DAY3_PT1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


int main()
{

	std::ifstream inFile;

	std::vector< std::vector<int> > world(1000, std::vector<int>(1000));

	std::vector< std::vector<int> > masterPosVec(1500, std::vector<int>(2));

	std::vector< std::vector<int> > masterSizeVec(1500, std::vector<int>(2));

	std::string blank,pos,size = "";

	inFile.open("inputFile.txt");

	int id = 0;

	while (!inFile.eof()) {
		inFile >> blank >> blank >> pos >> size;

		std::vector<int> posVec;
		std::vector<int> sizeVec;

		std::stringstream ssp(pos);
		std::stringstream sss(size);
		id += 1;
		int i;
		while (ssp >> i) {
			posVec.push_back(i);
			if (ssp.peek() == ',' || ssp.peek() == ':')
				ssp.ignore();
		}

		while (sss >> i) {
			sizeVec.push_back(i);
			if (sss.peek() == 'x')
				sss.ignore();
		}

		masterPosVec[id] = {posVec[0],posVec[1]};
		masterSizeVec[id] = { sizeVec[0],sizeVec[1] };

		int y = 0, x = 0;
		
		while (y < sizeVec[1]) {
			while (x < sizeVec[0]) {
				
				if (world[posVec[1] + y][posVec[0] + x] == 0) {
					world[posVec[1] + y][posVec[0] + x] = 1;
				}
				else {
					world[posVec[1] + y][posVec[0] + x] = 2;
				}
				x++;
			}
			y += 1;
			x = 0;
		}

	}

	int y = 0, x = 0, overlap = 0, add = 0;
	while (y < 1000) {
		while (x < 1000) {
			add = 0;
			if (world[y][x] == 2) { add = 1; }
			overlap += add;
			x++;
		}
		y += 1;
		x = 0;

	}
	std::cout << " \n ***** " << overlap << "\n *****\n";
	
	system("pause");

	// i = id
	// ii = x pos
	// iii = y pos
	bool win = false;
	for (int i = 1; i < masterPosVec.size(); i++) {
		win = true;
		
		for (int ii = 0; ii < masterSizeVec[i][0]; ii++) {
			for (int iii = 0; iii < masterSizeVec[i][1]; iii++) {
				if(world[masterPosVec[i][1] + iii][masterPosVec[i][0] + ii] !=1){ win = false; }
			}
		}
		if (win == true) {
			std::cout << "Clean ID: " << i << std::endl;
			i= masterPosVec.size();

		}
		
	}





	system("pause");
    return 0;
}