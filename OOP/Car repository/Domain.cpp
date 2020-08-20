#include "Domain.h"
#include <Windows.h>
#include <shellapi.h>
#include <string>
#include <vector>
#include <sstream>
#include<stdlib.h>
#include<fstream>
#include<algorithm>


Car::Car() : manufacturerName(""), model(""), year(0) , colour(""){}

Car::Car(const std::string& manufacturerName, const std::string& model, const int& year, const std::string& colour)
{
	this->manufacturerName = manufacturerName;
	this->model = model;
	this->year = year;
	this->colour = colour;
}

std::string Car::toString()
{
	return this->manufacturerName + "," + this->model + "," + std::to_string(this->year)+","+this->colour;
}

std::ostream& operator<<(std::ostream& outStream, Car& item)
{
	// TODO: insert return statement here
	outStream << item.get_name() << "|" << item.get_model() + "|" + std::to_string(item.get_year()) + "|" + item.get_colour();
	return outStream;
}

std::istream& operator>>(std::istream& inStream, Car& item)
{
	// TODO: insert return statement here
	std::string name;
	std::string model;
	int year;
	std::string colour;
	std::string line;

	getline(inStream, line);
	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
	size_t position = line.find("|");
	name = line.substr(0, position);
	line.erase(0, position + 1);

	position = line.find("|");
	model = line.substr(0, position);
	line.erase(0, position + 1);

	position = line.find("|");
	year = atoi(line.substr(0, position).c_str());
	line.erase(0, position + 1);


	//position = line.find("|");
	//priority = atoi(line.substr(0, position).c_str());
	colour = line;


	item.set_name(name);
	item.set_model(model);
	item.set_year(year);
	item.set_colour(colour);
	return inStream;



}


std::vector<std::string> Split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	bool ok = false;
	while (std::getline(tokenStream, token, delimiter))
	{
		ok = true;
		tokens.push_back(token);
	}
	return tokens;
}
