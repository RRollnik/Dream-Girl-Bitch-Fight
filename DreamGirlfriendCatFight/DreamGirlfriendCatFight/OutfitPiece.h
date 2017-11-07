#pragma once
#include "Sprite.h"
#include <fstream>
#include <string>
#include <sstream>


class OutfitPiece : public Sprite
{
public:
	OutfitPiece();
	~OutfitPiece();

	void GetStats(std::string _filename);

private:
	std::vector<int> stats; //stats is a vector representing the outfits STATS, we iterate through the vector and add them on to the actual stat

};

OutfitPiece::OutfitPiece()
{
}

OutfitPiece::~OutfitPiece()
{
}

void OutfitPiece::GetStats(std::string _filename)
{
	{
		std::ifstream inFile;
		inFile.open(_filename);
		std::string input;
		std::vector<int> numbers;

		if (!inFile) //makes sure file exists
		{
			std::cout << "Unable to open file";
		}
		else
		{
			int count = 0;
			while (std::getline(inFile, input)) //while theres a line
			{
				if (input.empty())//make sure we have something to work with
				{
					"Line was empty";
				}
				while (input.find("$") != std::string::npos) //until we get tot he last $ sign
				{
					std::string stringystring = input.substr(0, input.find("$")); //find a dollar sign and add everything up to that point to stringystring
					input.erase(0, input.find("$") + 1); //erase the dollar sign and everything up to that point
					std::stringstream number(stringystring); //make a stringstream using stringystream
					int temp = 0;
					number >> temp; //add the number we got from stringystring into temp
					stats.insert(stats.begin() + (count), temp); //insert temp into stats
					count++; //makes sure we don't overwrite anything in the array

				}
			}
			inFile.close(); //closes the file
		}
