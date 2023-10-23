#pragma once

class Person {

private:
	std::string name;
	int desiredFloor;
	int startFloor;

public:

	// Constructor with passed in values
	Person(std::string personName, int startFloor, int desiredFloor) {
		this->name = personName;
		this->startFloor = startFloor;
		this->desiredFloor = desiredFloor;
	}

	int dest() {
		return this->desiredFloor;
	}

	int startFloor() {
		return this->startFloor;
	}

	std::string getName() {
		return this->name;
	}

	// Destructor
	~Person() {
		delete this;
	}

};
