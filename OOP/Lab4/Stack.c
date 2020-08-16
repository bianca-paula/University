#include "Stack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Operation* createOperation(Person* p, char* operationType)
{
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->person = createPerson(getProfileIdNumber(p), getPlaceOfBirth(p),getPsychologicalProfile(p),getYearsOfRecordedService(p));

	if (operationType != NULL)
	{
		o->operationType = (char*)malloc(sizeof(char) * strlen(operationType) + 1);
		strcpy(o->operationType, operationType);
	}
	else
		o->operationType = NULL;

	return o;
}

void destroyOperation(Operation* o)
{
	if (o == NULL)
		return;

	// first destroy the person
	destroyPerson(o->person);
	// then the operationType
	free(o->operationType);
	// then free the operation
	free(o);
}



char* getOperationType(Operation* o)
{
	return o->operationType;
}

Person* getPerson(Operation* o)
{
	return o->person;
}

// ---------------------------------------------------------------

OperationsStack* createStack()
{
	OperationsStack* s = (OperationsStack*)malloc(sizeof(OperationsStack));
	s->length = 0;

	return s;
}

void destroyStack(OperationsStack* s)
{
	if (s == NULL)
		return;

	// first deallocate memory of operations (this is allocated when a new operation is pushed onto the stack)
	for (int i = 0; i < s->length; i++)
		destroyOperation(s->operations[i]);

	// then free the stack
	free(s);
}

void push(OperationsStack* s, Operation* o)
{
	s->operations[s->length] = o;
	s->length++;
}

Operation* pop(OperationsStack* s)
{
	Operation* o;
	int i = s->length;
	i--;
	o = s->operations[i];
	s->length--;
	return o;
}

int isEmpty(OperationsStack* s)
{
	return (s->length == 0);
}

int isFull(OperationsStack* s)
{
	return s->length == 100;
}

int Empty(OperationsStack* s)
{
	if (s== NULL)
		return;
	s->length = 0;
}

