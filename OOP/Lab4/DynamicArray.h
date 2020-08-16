#pragma once
#include "Profile.h"
#define CAPACITY 10

typedef Person* TElement;

typedef struct
{
	TElement* elems;
	int length;			// actual length of the array
	int capacity;		// maximum capacity of the array
} DynamicArray;

// Creates a dynamic array of generic elements, with a given capacity.
// Input: capacity - integer, maximum capacity for the dynamic array
// Output: A pointer the the created dynamic array
DynamicArray* createDynamicArray(int capacity);


// Destroys the dynamic array.
// Input : dynamicArray - the dynamic array to be destoyed.
// Output: A pointer the the created dynamic array
void destroy(DynamicArray* dynamicArray);


// Adds a generic to the dynamic array.
// Input: dynamicArray - the dynamic array
//        t - the element to be added
void addElement(DynamicArray* dynamicArray, TElement t);

// Deletes an element from a given position in the dynamic array.
// Input: dynamicArray - The dynamic array
//		  pos - integer - The position from which the element must be deleted. The position must be valid
void deleteElement(DynamicArray* dynamicArray, int pos);


// Updates an element with a given profileId
// Input: dynamicArray - the dynamic array
//		 profileId - int - the profileId of the element to be updated
//		 newPlace - char* - the new place of birth
//		 newPsycho - char* - the new psychological profile
//		 newYears - int - the new years of recorded service
// Output: the element which needs to be updated	 
int updateElement(DynamicArray* dynamicArray, int profileId, char* newPlace, char* newPsycho, int newYears);


// Returns the length of the dynamic array
// Input: dynamicArray - The dynamic array
// Output: the length of the dynamic array
int getLength(DynamicArray* dynamicArray);

// Returns the element on a given position
// Input: dynamicArray - the dynamic array
//		  pos - the position - must be a valid position
// Output: The element on the given position
TElement get(DynamicArray* dynamicArray, int pos);