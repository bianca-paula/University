#pragma once
#include"Domain.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class Repository
{
private:
	//std::vector<Item> elements{};

public:
	string name_of_file;
	void write_to_file(std::vector<Car> elements);
	std::vector <Car> read_from_file();
	Repository(const string& name_of_file);
	std::vector<Car> getElements() { return this->read_from_file(); };
	void setPath(const std::string& path);



};
