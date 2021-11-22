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
std::vector<int> Range(int start, int max, int step);
std::vector<std::string> stringToVector(std::string theString, char seperator);
std::string TrimWhiteSpaces(std::string theString);
std::string vectorToString(std::vector<std::string>& vec, char seperator);
std::vector<int> FindsubString(std::string theString, std::string subString);
std::string replaceSubstr(std::string theString, std::string substring, std::string newString);
std::string CaesarCipher(std::string theString, int key, bool encrypt);
std::vector<int> GenerateRandVec(int numOfNums, int min, int max);
void SolveForX(std::string theEquation);
std::vector<int> GetPrime(int maxNum);
bool IsPrime(int num);
void BubbleSort(std::vector<int>& theVec);
int Factorial(int number);
void printHorVector(std::vector<int>& theVec);
int Fib(int index);


int main()
{
	int index;
	std::cout << "Get fibonacci index : ";
	std::cin >> index;
	printf("Fib(%d) = %d\n", index, Fib(index));
}



// ALL FUNCTONS
///////// Make boolean return True or False instead of 1 or 0 std::cout.setf(std::ios::boolalpha);
///////// x + 5 = 9

int Fib(int index) {
	if (index < 2) {
		return index;
	}
	else{
		return Fib(index - 1) + Fib(index - 2);
	}
	
}

void printHorVector(std::vector<int>& theVec) {
	int dashes = theVec.size() * 5;
	for (int n = 0; n < dashes; n++)
		std::cout << "-";
	std::cout << "|\n";

	for (int n = 0; n < theVec.size(); n++)
		printf("| %2d ", n);
	std::cout << "|\n";

	for (int n = 0; n < dashes; n++)
		std::cout << "-";
	std::cout << "|\n";

	for (int n = 0; n < theVec.size(); n++)
		printf("| %2d ", theVec[n]);
	std::cout << "|\n";

	for (int n = 0; n < dashes; n++)
		std::cout << "-";
	std::cout << "\n";
}

int Factorial(int number) {
	if (number == 1) {
		return 1;
	}
	else
	{
		int result = number * Factorial(number - 1);
		return result;
	}
}
void BubbleSort(std::vector<int>& theVec) {
	int i = theVec.size() - 1;
	while (i >= 1) {
		int j = 0;
		while (j < i) {
			printf("\nis %d > %d\n", theVec[j], theVec[j + 1]);
			if (theVec[j] >= theVec[j + 1]) {
				std::cout << "Switch" << std::endl;
				int temp = theVec[j];
				theVec[j] = theVec[j + 1];
				theVec[j + 1] = temp;
			}
			else
			{ 
				std::cout << "Dont Switch" << std::endl; 
			}
			j += 1;
			for (auto k : theVec)
				std::cout << k << ", ";
		}
		std::cout << "\n End of Round\n";
		i -= 1;
	}
}

std::vector<int> GenerateRandVec(int numOfNums, int min, int max) {
	std::vector<int> vecValue;
	srand(time(NULL));
	int i = 0, randVal = 0;
	while (i < numOfNums) {
		randVal = min + std::rand() % ((max + 1) - min);
		vecValue.push_back(randVal);
		i++;
	}
	return vecValue;
}
bool IsPrime(int num) {
	for (auto n : Range(2, num - 1, 1)) {
		if ((num % n) == 0)
			return false;
	}
	return true;
}

std::vector<int> GetPrime(int maxNum) {
	std::vector<int> vecPrimes;
	for (auto x : Range(2, maxNum, 1)) {
		if (IsPrime(x))
			vecPrimes.push_back(x);
	}
	return vecPrimes;
}

std::vector<int> Range(int start, int max, int step) {
	int i = start;
	std::vector<int> range;
	while (i <= max) {
		range.push_back(i);
		i += step;
	}
	return range;
}

void SolveForX(std::string theEquation) {
	int returnNum = 0;

	
	std::vector<std::string> operators =
		stringToVector(theEquation, ' ');
	
	std::string Operan = operators[1];  // + or -
	int secondops = std::stoi(operators[2]);  // 5
	int lastops = std::stoi(operators[4]);  // 9

	if (Operan == "+") {
		returnNum = lastops - secondops;
	}
	else if (Operan == "-") {
		returnNum = lastops + secondops;
	}
	std::cout << "x = " << returnNum << std::endl;


}

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

std::string CaesarCipher(std::string theString, int key,
	bool encrypt)
{
	std::string returnString = "";
	int charCode = 0;
	char letter;

	// The key will shift and unshift character codes
	if (encrypt) key = key * -1;

	// Cycle through each character
	for (char& c : theString) {

		// Check if it's a letter and if not don't chage it
		if (isalpha(c)) {

			// Convert from char to int and shift the char code
			charCode = (int)c;
			charCode += key;

			if (isupper(c)) {

				if (charCode > (int)'Z') {
					charCode -= 26;
				}
				else if (charCode < (int)'A') {
					charCode += 26;
				}
			}
			else {
				// Do the same for lowercase letters
				if (charCode > (int)'z') {
					charCode -= 26;
				}
				else if (charCode < (int)'a') {
					charCode += 26;
				}
			}
			// Convert from int to char and add the returning string
			letter = charCode;
			returnString += letter;

		}
		else {
			letter = c;
			returnString += c;
			std::cout << c << "\n";
		}
	}
	return returnString;
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
* 
* 
* std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
	BubbleSort(vecVals);
	for (auto x : vecVals)
		std::cout << x << std::endl;
* 
* 
* int num = 0;
	std::cout << "Number to check ";
	std::cin >> num;

	std::cout.setf(std::ios::boolalpha);
	std::cout << "is" << num << "prime"<<  IsPrime(num)<< std::endl;
	std::cout << "Generate Prime numbers ";
	int maxPrime;
	std::cin >> maxPrime;
	std::vector<int> primelist = GetPrime(maxPrime);
	for (auto x : primelist)
		std::cout << x << std::endl;
* 
* 
* 
void SolveForX(std::string theEquation) {
	int returnNum = 0;

	char seperator = ' ';
	std::vector<std::string> operators;
	std::stringstream ss(theEquation);
	std::string indivOps;
	while (getline(ss, indivOps, seperator))
	{
		operators.push_back(indivOps);
	}
	std::string Operan = operators[1];  // +
	int secondops = std::stoi(operators[2]);  // 5
	int lastops = std::stoi(operators[4]);  // 9

	if (Operan == "+") {
		returnNum = lastops - secondops;
	}
	else if (Operan == "-") {
		returnNum = lastops + secondops;
	}
	std::cout << "x = " << returnNum << std::endl;


}


*/