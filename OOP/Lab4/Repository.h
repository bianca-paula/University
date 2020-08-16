#pragma once
#include "Profile.h"
#include "DynamicArray.h"

typedef struct
{
	DynamicArray* profiles;
}PersonRepo;

// Creates a new repository
PersonRepo* createRepository();

// Destroys a given repository. The memory is freed.
void destroyRepository(PersonRepo* repo);

/*
	Adds a new person to the repository
	Input:  - repo - pointer to the PersonRepo
			- p - an object of type Person
	Output: 1 - if the person was added successfully, 0 - if the person already exists
*/
int addPerson(PersonRepo* repo, Person* p);

/*
	Deletes the person with the given profileId from the repository.
	Input:  - repo - pointer to the PersonRepo
			- profileId - an integer, the profileId which identifies the person to be deleted.
	Output: 0 - if the person was successfully deleted, 1 - otherwise, if the person is not in the repository
*/
int deletePerson(PersonRepo* repo, int profileId);

// Updates an element with a given profileId
// Input: repo - pointer to the PersonRepo
//		 profileId - int - the profileId of the element to be updated
//		 newPlace - char* - the new place of birth
//		 newPsycho - char* - the new psychological profile
//		 newYears - int - the new years of recorded service
// Output: the element which needs to be updated	 
int updatePerson(PersonRepo* repo, int profileId, char* newPlace, char* newPsycho, int newYears);

//Returns the length of the repository
int getRepoLength(PersonRepo* repo);

// Finds the person with the given profileId
// Input:  repo - pointer to the PersonRepo
//		   profileId - the profileId to search for
// Output: The pointer to the person with the given profileId, or null, if such a person does not exist
int findPerson(PersonRepo* repo, int profileId);

/*
	Returns the position on the given person in the persons vector.
	Input:	repo - the person repository;
			person - the person to search for
	Output: the position of the person in the repo
*/
int findPositionOfPerson(PersonRepo* repo, Person* person);

/*
	Returns the person on the given position in the persons vector.
	Input:	repo - the person repository;
			pos - integer, the position;
	Output: the person on the given potision, or an "empty" person.
*/
Person* getPersonOnPos(PersonRepo* repo, int pos);

