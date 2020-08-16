#include "Repository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

PersonRepo* createRepository()
{
	PersonRepo* repo = (PersonRepo*)malloc(sizeof(PersonRepo));
	if (repo == NULL)
		return NULL;
	repo->profiles = createDynamicArray(CAPACITY);

	return repo;
}

void destroyRepository(PersonRepo* repo)
{
	if (repo == NULL)
		return;

	destroy(repo->profiles);
	free(repo);
}


int updatePerson(PersonRepo* repo, int profileId, char* newPlace, char* newPsycho, int newYears) {
	Person* person=	updateElement(repo->profiles, profileId, newPlace, newPsycho, newYears);
	return person;
	
}
int addPerson(PersonRepo* repo, Person* p)
{
	if (repo == NULL || p == NULL)
		return 0;

	if (findPerson(repo, getProfileIdNumber(p)) == -1)
	{
		addElement(repo->profiles, p);
		return 1;
	}
	else
		return 0;
}

int findPerson(PersonRepo* repo, int profileId) {
	int length = getLength(repo->profiles);
	for (int i = 0; i < length; ++i)
		if (get(repo->profiles, i)->profileIdNumber == profileId)
			return i;
	return -1;
}


int findPositionOfPerson(PersonRepo* repo, Person* person) {
	int length = getLength(repo->profiles);
	for (int i = 0; i < length; i++)
		if (get(repo->profiles, i)->profileIdNumber == person->profileIdNumber)
			return i;
	return -1;
}

int deletePerson(PersonRepo* repo, int profileId)
{
	int position;
	position = findPerson(repo, profileId);
	if (repo == NULL)
		return 1;
	if (position == -1)
		return 1;
	deleteElement(repo->profiles, position);
	return 0;
	
}

int getRepoLength(PersonRepo* repo)
{
	if (repo == NULL)
		return -1;

	return getLength(repo->profiles);
}

Person* getPersonOnPos(PersonRepo* repo, int pos)
{
	if (repo == NULL)
		return NULL;
	return get(repo->profiles, pos);
}

