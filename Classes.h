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

class Shape {
protected:
    double height;
    double width;

public:
    Shape(double lenght) {
        height = lenght;
        width = lenght;
    }

    Shape(double h, double w) {
        height = h;
        width = w;
    }

    virtual double Area() {
        return height * width;
    }
};

class Circle : public Shape {
public:
    Circle(double w) :
        Shape(w) {

    }
    double Area() {
        return 3.14159 * std::pow((width / 2), 2);
    }
};


class Animal {
private:
	std::string name;
	double height;
	double weight;

	static int numOfAnimals;

public:
	std::string GetName() { return name; }
	void setName(std::string name) { this->name = name; }
	double GetHeight() { return height; }
	void setHeight(double height) { this->height = height; }
	double GetWeight() { return weight; }
	void setWeight(double weight) { this->weight = weight; }

	void SetAll(std::string, double, double);
	Animal(std::string, double, double);
	Animal();
	~Animal();
	static int GetNumOfAnimal() { return numOfAnimals; }
	void toString();



};


class Dog : public Animal {
private:
	std::string sound = "Woof";
public:
	void MakeSound() {
		std::cout << "The Dog " << this->GetName() <<
			" says " << this->sound << std::endl;
	}
	Dog(std::string, double, double, std::string);
	Dog() : Animal() {};
	void ToString();

};

class Warrior {
private:
    int attkMax;
    int blockMax;
public:
    std::string name;
    int health;
    Warrior(std::string name, int health,
        int attkMax, int blockMax) {
        this->name = name;
        this->health = health;
        this->attkMax = attkMax;
        this->blockMax = blockMax;
    }

    // The attack and block amount will be random
    int Attack() {
        return std::rand() % this->attkMax;
    }
    int Block() {
        return std::rand() % this->blockMax;
    }
};

class Battle {
public:
    // We pass warriors into the function by reference so we can
    // track continued damage to each

    // We continue to loop having each warrior take turns attacking
    // until a warriors health < 0
    static void StartFight(Warrior& warrior1, Warrior& warrior2) {
        while (true) {
            if (Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0) {
                std::cout << "Game Over\n";
                break;
            }
            if (Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0) {
                std::cout << "Game Over\n";
                break;
            }
        }
    }

    static std::string GetAttackResult(Warrior& warriorA,
        Warrior& warriorB) {
        // Get random attack & block amounts and calculate damage
        int warriorAAttkAmt = warriorA.Attack();
        int warriorBBlockAmt = warriorB.Block();
        int damage2WarriorB = ceil(warriorAAttkAmt - warriorBBlockAmt);

        // Change health total if > 0 and output changes
        damage2WarriorB = (damage2WarriorB <= 0) ? 0 : damage2WarriorB;
        warriorB.health = warriorB.health - damage2WarriorB;
        printf("%s attacks %s and deals %d damage\n",
            warriorA.name.c_str(), warriorB.name.c_str(),
            damage2WarriorB);
        printf("%s is down to %d health\n", warriorB.name.c_str(),
            warriorB.health);

        // Once health < 0 end game by passing back Game Over
        if (warriorB.health <= 0) {
            printf("%s has Died and %s is Victorious\n",
                warriorB.name.c_str(), warriorA.name.c_str());
            return "Game Over";
        }
        else {
            return "Fight Again";
        }
    }
};






