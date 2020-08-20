#pragma once
#include"Repository.h"

#include <vector>
#include <iostream>
#include<assert.h>
using namespace std;


class Service
{
private:
	Repository& repository;

public:
	Service(Repository& repo) : repository{ repo } {}
	Repository& getRepository() { return repository; }

	std::vector<Car> getAllElements() const;


	Car getElementByName(const std::string name);

	std::vector<Car> sortElements();

	/*
		Function that computes the number of cars by a given manufacturer
		Input: manufacturer - the manufacturer for which we compute the number of cars
		Output: the number of cars by that manufacturer
		
	*/
	int showCars(const std::string manufacturer);

	void Test_ShowCars(); 
};





