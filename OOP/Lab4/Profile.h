#pragma once

typedef struct
{
	int profileIdNumber;
	char* placeOfBirth;
	char* psychologicalProfile;
	int yearsOfRecordedService;
} Person;

Person* createPerson(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService);


int getProfileIdNumber(Person* p);
char* getPlaceOfBirth(Person* p);
char* getPsychologicalProfile(Person* p);
int getYearsOfRecordedService(Person* p);

void toString(Person* p, char str[]);

void destroyPerson(Person* p);
Person* copyPerson(Person* p);


