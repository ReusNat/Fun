#pragma once
#include <vector>
#include "person.h"

class Building {
private:
	struct Floor {
		int floorNum;
		std::vector<Person> goingUp;
		std::vector<Person> goingDown;
	} typedef Floor;

	int numFloors;
	int currFloor = 0;
	bool goingUp = 1;
	std::vector<Floor> floors;

public:
	Building() {
		this->numFloors = 3;
		for (int i = 0; i < this->numFloors; i++) {
			this->floors.push_back({ i });
		}
	}

	Building(int numFloors, std::vector<Person> people) {
		this->numFloors = numFloors;
		for (int i = 0; i < this->numFloors; i++) {
			this->floors.push_back({ i });
		}
		populate(people);
	}

	void populate(std::vector<Person> people) {
		for (Person per : people) {
			(per.startFloor() < per.dest()) ?
				floors[per.startFloor()].goingUp.push_back(per) : floors[per.startFloor()].goingDown.push_back(per);
		}
	}

	void printBuilding() {
		for (auto floor : this->floors) {
			std::cout << "Floor Number: " << floor.floorNum << std::endl;
			std::cout << "GOING UP:" << std::endl;
			
			for (auto per : floor.goingUp) {
				std::cout << per.getName() << " is going to floor "
					<< per.dest() << " from floor " << per.startFloor() << std::endl;
			}

			std::cout << "GOING DOWN:" << std::endl;
			for (auto per : floor.goingDown) {
				std::cout << per.getName() << " is going to floor "
					<< per.dest() << " from floor " << per.startFloor() << std::endl;
			}
		}
	} 

};
