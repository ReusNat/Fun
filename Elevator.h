#pragma once
#include <vector>
#include "person.h"

class Elevator {

	private:
		int currFloor;
		bool goingUp = 1;
		std::vector<Person> people;

	public:
		Elevator() {
			this->currFloor = 0;
		}

		void move(int floorToGo) {

		}

		int getCurrFloor() { return this->currFloor; }

};
