#pragma once
#include "Profile.h"
#include "DynamicArray.h"
#include <string.h>

typedef struct
{
	Person* person;
	char* operationType;
} Operation;

Operation* createOperation(Person* p, char* operationType);
void destroyOperation(Operation* o);
char* getOperationType(Operation* o);
Person* getPerson(Operation* o);

// ---------------------------------------------------------------
typedef struct
{
	Operation* operations[100];
	int length;
} OperationsStack;

OperationsStack* createStack();
void destroyStack(OperationsStack* s);
void push(OperationsStack* s, Operation* o);
Operation* pop(OperationsStack* s);
int isEmpty(OperationsStack* s);
int isFull(OperationsStack* s);
int Empty(OperationsStack* s);