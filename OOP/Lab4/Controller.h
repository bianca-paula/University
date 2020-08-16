#pragma once
#include "Stack.h"
#include "Repository.h"


typedef struct
{
	PersonRepo* repo;
	OperationsStack* undoStack;
	OperationsStack* redoStack;
} Service;

Service* createService(PersonRepo* r, OperationsStack* undoS, OperationsStack* redoS);
void destroyService(Service* s);
int addPersonServ(Service* s,int profileId, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService);
int deletePersonServ(Service* s, int profileId);
int updatePersonServ(Service* s, int profileId, char* place, char* psycho, int years);
PersonRepo* getRepo(Service* s);
int undo(Service* s);
int redo(Service* s);
UndoUpdateSrv(Service* s, int profileId, char* place, char* psycho, int years);