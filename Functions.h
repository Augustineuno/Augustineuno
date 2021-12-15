#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <functional>
#include <math.h>
#include "Functions.h"
#include "Classes.h"


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
int FibNum(int index);
double Area(double radius);
double Area(double height, double width);
std::vector<int> GenerateFiblist(int maxNum);
void ShowArea(Shape& shape);