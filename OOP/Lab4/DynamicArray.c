#include "DynamicArray.h"
#include <stdlib.h>
#include <string.h>

DynamicArray* createDynamicArray(int capacity)
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
	// make sure that the space was allocated
	if (da == NULL)
		return NULL;

	da->capacity = capacity;
	da->length = 0;

	// allocate space for the elements
	da->elems = (TElement*)malloc(capacity * sizeof(TElement));
	if (da->elems == NULL)
		return NULL;

	return da;
}

void destroy(DynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	for (int i = 0; i < dynamicArray->length; i++)
		destroyPerson(dynamicArray->elems[i]);

	free(dynamicArray->elems);
	dynamicArray->elems = NULL;


	free(dynamicArray);
}

// Resizes the array, allocating more space.
// If more space cannot be allocated, returns -1, else it returns 0.
int resize(DynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return -1;

	dynamicArray->capacity *= 2;

	// allocate new memory, copy everything and deallocate the old memory
	TElement* aux = (TElement*)malloc(dynamicArray->capacity * sizeof(TElement));
	if (aux == NULL)
		return -1;
	for (int i = 0; i < dynamicArray->length; i++)
		aux[i] = dynamicArray->elems[i];
	free(dynamicArray->elems);
	dynamicArray->elems = aux;

	return 0;
}

void addElement(DynamicArray* dynamicArray, TElement t)
{
	if (dynamicArray == NULL)
		return;
	if (dynamicArray->elems == NULL)
		return;

	// resize the array, if necessary
	if (dynamicArray->length == dynamicArray->capacity)
		resize(dynamicArray);
	dynamicArray->elems[dynamicArray->length++] = t;
}

void deleteElement(DynamicArray* dynamicArray, int pos)
{
	if (pos < 0 || pos >= dynamicArray->length || dynamicArray->length == 0)
		return -1;
	destroyPerson(dynamicArray->elems[pos]);

	for (int i = pos; i < dynamicArray->length - 1; i++)
	{
		dynamicArray->elems[i] = dynamicArray->elems[i + 1];
		
	}
	dynamicArray->length--;
	return 1;
}


int updateElement(DynamicArray* dynamicArray, int profileId, char* newPlace, char* newPsycho, int newYears)
{
	int pos = 0;
	for(int i=0;i<dynamicArray->length;i++)
		if (dynamicArray->elems[i]->profileIdNumber == profileId)
		{
			pos = i;
			strcpy(dynamicArray->elems[i]->placeOfBirth, newPlace);
			strcpy(dynamicArray->elems[i]->psychologicalProfile, newPsycho);
			dynamicArray->elems[i]->yearsOfRecordedService = newYears;
		}
	return dynamicArray->elems[pos];
}

int getLength(DynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return -1;

	return dynamicArray->length;
}

TElement get(DynamicArray* dynamicArray, int pos)
{
	if (dynamicArray == NULL)
		return NULL;
	if (pos < 0 || pos >= dynamicArray->length)
		return NULL;
	return dynamicArray->elems[pos];
}

