#include "Repository.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Domain.h"


Repository::Repository(const string& name_of_file)
{
	this->name_of_file = name_of_file;
}


void Repository::setPath(const std::string& path)
{
	this->name_of_file = path;
}



void Repository::write_to_file(std::vector<Car> elements)
{
	std::ofstream out;

	out.open(name_of_file, std::ofstream::out | std::ofstream::trunc);
	out.close();

	std::ofstream fout(name_of_file);

	for (auto& element : elements)
		fout << element << endl;

	fout.close();
}


std::vector<Car> Repository::read_from_file()
{
	std::vector<Car> elements{};
	Car element;
	std::ifstream fin(this->name_of_file);

	while (fin >> element) {
		elements.push_back(element);
	}

	fin.close();
	return elements;
}





















