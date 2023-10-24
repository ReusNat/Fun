#pragma once
#include <vector>
#include <algorithm>
#include "Person.h"
#include "Common.h"

class Elevator {

	private:
		int currFloor;
		int topFloor;
		bool goingUp = 1;
		std::vector<Person> people;

	public:
		Elevator() {
			this->currFloor = 0;
			this->topFloor = 0;
		}
		Elevator(int topFloor) {
			this->currFloor = 0;
			this->topFloor = topFloor;
		}

		void move(Floor& floor) {

			while (goingUp) {
				if (currFloor == topFloor) {
					goingUp = 0;
				}


				for (Person person : people) {
					if (currFloor == person.dest()) {
						auto p = std::find_if(people.begin(), people.end(),
							[&person](Person p) {
								return person == p;
							});
						people.erase(p);

					}
				}

				for (Person person : floor.goingUp) {
					people.push_back(person);
				}
				floor.goingUp.clear();

				currFloor++;
			}	

			while (currFloor != 0) {
				
				for (Person person : people) {
					if (currFloor == person.dest()) {
						auto p = std::find_if(people.begin(), people.end(),
							[&person](Person p) {
								return person == p;
							});
						people.erase(p);

					}
				}

				for (Person person : floor.goingDown) {
					people.push_back(person);
				}
				floor.goingDown.clear();

				currFloor--;
			}
		}

		int getCurrFloor() { return this->currFloor; }

};
