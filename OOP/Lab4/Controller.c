#include "Controller.h"
#include <stdlib.h>
#include <string.h>

Service* createService(PersonRepo* r, OperationsStack* undoS, OperationsStack* redoS)
{
	Service* s = (Service*)malloc(sizeof(Service));
	if (s == NULL)
		return NULL;
	s->repo = r;
	s->undoStack = undoS;
	s->redoStack = redoS;

	return s;
}

void destroyService(Service* s)
{
	// first destroy the repository inside
	destroyRepository(s->repo);

	// then the operation stack
	destroyStack(s->undoStack);

	destroyStack(s->redoStack);

	// then free the memory
	free(s);
}

int addPersonServ(Service* s, int profileId, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
	Person* p = createPerson(profileId, placeOfBirth, psychologicalProfile,yearsOfRecordedService);

	int res = addPerson(s->repo, p);

	if (res == 1) // 
	{
		char* opType = "add";
		Operation* o = createOperation(p, opType);
		push(s->undoStack, o);
	}
	return res;
}


int deletePersonServ(Service* s, int profileId) {
	Person* p = createPerson(profileId, "", "", 0);
	int position = findPositionOfPerson(s->repo, p);
	if (position != -1)
	{
		Person* full_person = getPersonOnPos(s->repo, position);
		char* opType = "delete";
		Operation* operation = createOperation(full_person,opType);
		push(s->undoStack, operation);
		Empty(s->redoStack);
		destroyPerson(p);
	}
	return deletePerson(s->repo, profileId);

}

int updatePersonServ(Service* s, int profileId, char* place, char* psycho, int years) {
	Person* old_p = createPerson(profileId, "", "", 0);
	int pos = findPositionOfPerson(s->repo, old_p);

	Person* person = getPersonOnPos(s->repo, pos);
	Operation* operation = createOperation(person, "update");
	push(s->undoStack, operation);
	Empty(s->redoStack);
	
	destroyPerson(old_p);
	return updatePerson(s->repo, profileId, place, psycho, years);
	
}

UndoUpdateSrv(Service* s, int profileId, char* place, char* psycho, int years)
{
	Person* old_p = createPerson(profileId, "", "", 0);

	int pos = findPositionOfPerson(s->repo, old_p);
	Person* person = getPersonOnPos(s->repo, pos);


	Operation* operation = createOperation(person, "update");
	push(s->redoStack, operation);


	destroyPerson(old_p);

	return updatePerson(s->repo, profileId, place, psycho, years);

}


PersonRepo* getRepo(Service* s)
{
	return s->repo;
}




int undo(Service* s)
{
	if (isEmpty(s->undoStack))
	{
		return 0;
	}

	Operation* operation = pop(s->undoStack);
	char opType[50] = "";
	strcpy(opType, getOperationType(operation));

	if (strcmp(opType, "add") == 0)
	{
		Person* person = getPerson(operation);
		int profileId;
		profileId = getProfileIdNumber(person);
		deletePerson(s->repo, profileId);
		char newOpType[100] = "";
		strcpy(newOpType,"delete");
		Operation* newO = createOperation(person, newOpType);
		push(s->redoStack, newO);
	}
	else if (strcmp(opType, "delete") == 0) {
		Person* person = getPerson(operation);
		int profileId;
		profileId = getProfileIdNumber(person);
		char place[20];
		strcpy(place, getPlaceOfBirth(person));
		char psycho[20];
		strcpy(psycho, getPsychologicalProfile(person));

		int years;
		years = getYearsOfRecordedService(person);
		addPersonServ(s, profileId, place, psycho, years);
		char newOpType[100] = "";
		strcpy(newOpType, "add");
		Operation* newO = createOperation(person, newOpType);
		push(s->redoStack, newO);
	}
	else if (strcmp(opType, "update") == 0) {
		Person* p = getPerson(operation);
		int profileId = 0;
		profileId = getProfileIdNumber(p);
		char place[50] = "";
		strcpy(place, getPlaceOfBirth(p));
		char psycho[20];
		strcpy(psycho, getPsychologicalProfile(p));

		int years;
		years = getYearsOfRecordedService(p);
		UndoUpdateSrv(s, profileId, place, psycho, years);




	}

	// the operation must be destroyed
	destroyOperation(operation);

	return 1;
}

int redo(Service* s) {
	if (isEmpty(s->redoStack))
	{
		return 0;
	}
	Operation* operation = pop(s->redoStack);
	char opType[50] = "";
	strcpy(opType, getOperationType(operation));
	if (strcmp(opType, "delete") == 0)
	{
		Person* person = getPerson(operation);
		addPerson(s->repo, person);
		char newOpType[100] = "";
		strcpy(newOpType, "add");
		Operation* newO = createOperation(person, newOpType);
		push(s->undoStack, newO);
	}
	else if (strcmp(opType, "add") == 0)
	{
		Person* person = getPerson(operation);
		int profileId;
		profileId = getProfileIdNumber(person);
		deletePerson(s->repo, profileId);
		char newOpType[100] = "";
		strcpy(newOpType, "delete");
		Operation* newO = createOperation(person, newOpType);
		push(s->undoStack, newO);

	}
	else if (strcmp(opType, "update")== 0) {
		Person* p = getPerson(operation);
		int profileId = 0;
		profileId = getProfileIdNumber(p);
		char place[50] = "";
		strcpy(place, getPlaceOfBirth(p));
		char psycho[20];
		strcpy(psycho, getPsychologicalProfile(p));

		int years;
		years = getYearsOfRecordedService(p);
		updatePersonServ(s, profileId, place, psycho, years);
		Person* n = createPerson(profileId, place, psycho, years);
		char newOpType[100] = "";
		strcpy(newOpType, "update");
		Operation* newO = createOperation(n, newOpType);
		push(s->undoStack, newO);

	}

}

