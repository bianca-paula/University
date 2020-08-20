#include "Service.h"
#include <vector>
#include <algorithm>
#include<exception>



std::vector<Car> Service::getAllElements() const
{
	return repository.getElements();
}



std::vector<Car> Service::sortElements() {

	vector<Car> elementsSorted = repository.getElements();
	std::sort(elementsSorted.begin(), elementsSorted.end());

	return elementsSorted;
}

int Service::showCars(const std::string manufacturer)
{
	vector<Car> elements = repository.getElements();
	int numberCars = 0;

	for (auto element : elements) {
		if (element.get_name() == manufacturer)
			numberCars++;
	}
	return numberCars;
}



Car Service::getElementByName(const std::string name) {
	vector<Car> all_elements = this->repository.getElements();

	for (auto element : all_elements) {
		if (element.get_name() == name)
			return element;
	}
}


void Service::Test_ShowCars() {

	Repository repository{ "fortests.txt" };

	Service service{ repository };

	int numberofCars = service.showCars("Audi");

	assert(numberofCars == 3);

	int numberOfNonExistentCars = 0;
	numberOfNonExistentCars= service.showCars("Lamborghini");
	assert(numberOfNonExistentCars == 0);

}