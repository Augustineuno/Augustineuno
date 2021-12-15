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
#include "Classes.h"

void ShowArea(Shape& shape) {
	std::cout << "Area :" << shape.Area() << std::endl;
}

int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight) {
	this->name = name;
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}
Animal::Animal(std::string name, double height, double weight) {
	this->name = name;
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}
Animal::Animal() {
	this->name = "";
	this->weight = 0;
	this->height = 0;
	Animal::numOfAnimals++;
}

Animal::~Animal() {
	std::cout << "Animal " << this->name << " destroyed " << std::endl;
}

void Animal::toString() {
	std::cout << this->name << " is " << this->height << " cms tall and " <<
		this->weight << " kgs in weight " << std::endl;
}

Dog::Dog(std::string name, double height, double weight, std::string sound) :
	Animal(name, height, weight) {
	this->sound = sound;
}
void Dog::ToString() {
	std::cout << this->GetName() << " is " << this->GetHeight() << " cms tall and " <<
		this->GetWeight() << " kgs in weight and says " << this->sound << std::endl;
}