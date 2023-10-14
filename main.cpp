#include <iostream>
#include <random>
#include <string>
#include "Building.h"

int main() {
	srand(9898989898);
	std::cout << "Hello" << std::endl;
	std::vector<Person> people;

	for (int i = 0; i < 50; i++) {
		people.push_back(Person(std::to_string(i), rand() % 10, rand() % 10));
	}

	Building build = Building(10, people);

	build.printBuilding();

	return 0;
}
