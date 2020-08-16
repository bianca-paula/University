#include "Profile.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Person* createPerson(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
	Person* p = (Person*)malloc(sizeof(Person));
	p->profileIdNumber = profileIdNumber;
	p->placeOfBirth = (char*)malloc(sizeof(char) * (strlen(placeOfBirth) + 1));
	strcpy(p->placeOfBirth, placeOfBirth);

	p->psychologicalProfile = (char*)malloc(sizeof(char) * (strlen(psychologicalProfile) + 1));
	strcpy(p->psychologicalProfile, psychologicalProfile);
	p->yearsOfRecordedService = yearsOfRecordedService;
	return p;
}


int getProfileIdNumber(Person* p)
{
	if (p == NULL)
		return -1;
	return p->profileIdNumber;
}

char* getPlaceOfBirth(Person* p)
{
	if (p == NULL)
		return NULL;
	return p->placeOfBirth;
}

char* getPsychologicalProfile(Person* p)
{
	if (p == NULL)
		return NULL;
	return p->psychologicalProfile;
}

int getYearsOfRecordedService(Person* p)
{
	if (p == NULL)
		return -1;
	return p->yearsOfRecordedService;
}

void toString(Person* p, char str[])
{
	if (p == NULL)
		return;
	sprintf(str, "Id: %d  Place: %s  Psychological: %s  Years: %d", p->profileIdNumber, p->placeOfBirth, p->psychologicalProfile, p->yearsOfRecordedService);

}

void destroyPerson(Person* p)
{
	if (p == NULL)
		return;
	free(p->placeOfBirth);
	free(p->psychologicalProfile);

	free(p);
}

Person* copyPerson(Person* p)
{
	if (p == NULL)
		return NULL;
	Person* newPerson = createPerson(getProfileIdNumber(p), getPlaceOfBirth(p), getPsychologicalProfile(p), getYearsOfRecordedService(p));
	return newPerson;
}