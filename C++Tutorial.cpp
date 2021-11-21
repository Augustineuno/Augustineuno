// C++Tutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>

//Functon Prototypes

std::vector<std::string> stringToVector(std::string theString, char seperator);
std::string TrimWhiteSpaces(std::string theString);
std::string vectorToString(std::vector<std::string>& vec, char seperator);
std::vector<int> FindsubString(std::string theString, std::string subString);
std::string replaceSubstr(std::string theString, std::string substring, std::string newString);


int main()
{
	

	std::cout << replaceSubstr("To know or not to know", "know", "be") << std::endl;
}



// ALL FUNCTONS
/////////
/////////

std::string TrimWhiteSpaces(std::string theString) {
	std::string whiteSpaces(" \t\f\n\r");
	theString.erase(theString.find_last_not_of(whiteSpaces) + 1);
	theString.erase(0, theString.find_first_not_of(whiteSpaces));

	return theString;
}

std::string vectorToString(std::vector<std::string>& vec, char seperator) {
	std::string theString = " ";
	for (auto cust : vec)
		theString += cust + seperator;
	return theString;
}

std::vector<int> FindsubString(std::string theString, std::string subString) {
	std::vector<int> MatchingIndex;
	int index = theString.find(subString, 0);
	while (index != std::string::npos) {
		MatchingIndex.push_back(index);
		index = theString.find(subString, index + 1);
	}

	return MatchingIndex;
}



std::vector<std::string> stringToVector(std::string theString,
	char seperator) {

	std::vector<std::string> vecWords;
	std::stringstream ss(theString);
	std::string indivStr;
	while (getline(ss, indivStr, seperator))
	{
		vecWords.push_back(indivStr);
	}

	return vecWords;
}

std::string VectorToString(std::vector<std::string>& vec, char seperator) {
	std::string theString = "";
	for (auto cust : vec) {
		theString += cust + seperator;
	}
	return theString;
}

std::string replaceSubstr(std::string theString, std::string subString, std::string newString) {
	std::vector<int> matches = FindsubString(theString, subString);

	if (matches.size() != 0){
		int lenghtDifference = newString.size() - subString.size();
		int timeslooped = 0;
		for (auto index : matches) {
			theString.replace(index + (timeslooped * lenghtDifference), subString.size(), newString);
			timeslooped++;
		}
}
	return theString;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
/*
char seperator = ' ';
	std::vector<std::string> vecWords;
	std::stringstream ss(theString);
	std::string indivStr;
	while (getline(ss, indivStr, seperator))
	{
		vecWords.push_back(indivStr);
		for (int i = 0; i < vecWords.size(); ++i)
		{
			if (vecWords[i] == subString) {
				vecWords[i] = newString;
				++i;
			}

			theString += vecWords[i] + seperator;


		}

	}


	return theString;

*/