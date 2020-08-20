#pragma once

#include<string>
#include<iostream>
#include<sstream>


class Car {
private:
	std::string manufacturerName;
	std::string model;
	int year;
	std::string colour;
public:

	Car();
	Car(const std::string& manufacturerName, const std::string& model, const int& year, const std::string& colour);


	std::string get_name() const { return this->manufacturerName; }
	std::string get_model() const { return this->model; }
	int get_year() const { return this->year; }
	std::string get_colour() const { return this->colour; }

	void set_model(const std::string model) { this->model = model; }
	void set_name(const std::string name) { this->manufacturerName = name; }
	void set_year(const int year) { this->year = year; }

	void set_colour(const std::string colour) { this->colour = colour; }

	bool operator==(const Car& element) { return this->model== element.get_model(); }

	std::string toString();
	friend std::ostream& operator<<(std::ostream& outStream, Car& item);
	friend std::istream& operator>>(std::istream& inStream, Car& item);

	bool operator<(const Car& item) { return this->manufacturerName < item.manufacturerName; }
};




