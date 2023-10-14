#pragma once
#include <vector>
#include <queue>
#include "person.h"

class Building {
private:
	struct Floor {
		int floorNum;
		std::queue<Person> goingUp;
		std::queue<Person> goingDown;
	} typedef Floor;

	int numFloors;
	int currFloor = 0;
	bool goingUp = 1;
	std::vector<Floor> floors;

public:
	Building() {
		this->numFloors = 3;
		for (int i = 0; i < this->numFloors; i++) {
			this->floors.push_back({this->numFloors});
		}
	}

	void populate(std::vector<Person> people){
		bool up;
		for (Person per : people) {
			(per.startFloor() < per.dest()) ? up = 1 : up = 0;

			up ? floors[per.startFloor()].goingUp.push(per) : floors[per.startFloor()].goingDown.push(per);
		}
	}

};