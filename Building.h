#pragma once
#include <vector>
#include "person.h"
#include "Elevator.h"
#include "Common.h"



class Building {
private:
	int numFloors;
	std::vector<Floor> floors;
	Elevator el;

public:
	Building() {
		this->numFloors = 3;
		for (int i = 0; i < this->numFloors; i++) {
			this->floors.push_back({ i });
		}
		el = Elevator(this->numFloors-1);
	}

	Building(int numFloors, std::vector<Person> people) {
		this->numFloors = numFloors;
		for (int i = 0; i < this->numFloors; i++) {
			this->floors.push_back({ i });
		}
		populate(people);
		el = Elevator(this->numFloors - 1);
	}

	void populate(std::vector<Person> people) {
		for (Person per : people) {
			(per.getStartFloor() < per.dest()) ?
				floors[per.getStartFloor()].goingUp.push_back(per) : floors[per.getStartFloor()].goingDown.push_back(per);
		}
	}

	void printBuilding() {
		for (auto floor : this->floors) {
			std::cout << "Floor Number: " << floor.floorNum << std::endl;
			std::cout << "GOING UP:" << std::endl;
			
			for (auto per : floor.goingUp) {
				std::cout << per.getName() << " is going to floor "
					<< per.dest() << " from floor " << per.getStartFloor() << std::endl;
			}

			std::cout << "GOING DOWN:" << std::endl;
			for (auto per : floor.goingDown) {
				std::cout << per.getName() << " is going to floor "
					<< per.dest() << " from floor " << per.getStartFloor() << std::endl;
			}
		}
	}

	void run() {
		int currentFloor = el.getCurrFloor();
		el.move(floors[currentFloor]);
	}
};
