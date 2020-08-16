#include "UI.h"
#define _CRTDBG_MAP_ALLOC
#include<stdlib.h>
#include <crtdbg.h>

int main()
{

	/*
		---------------------------------ABOUT PROJECT-------------------------------------------------------------------

		The profile sorter is able to add, modify and dispose of unwanted profiles. It is also able to list all profiles, 
		and only profiles of maximum years of recorded service. It can also undo and redo any recent changes.
		All commands must be in the form:
		add profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService
		update profileIdNumber, newPlaceOfBirth, newPsychologicalProfile, newYearsOfRecordedService
		delete profileIdNumber
		list
		list maximumYearsOfRecordedService
		undo
		redo
	
	*/

	PersonRepo* repo = createRepository();
	OperationsStack* undoStack = createStack();
	OperationsStack* redoStack = createStack();
	Service* ctrl = createService(repo, undoStack, redoStack);
	
	UI* ui = createUI(ctrl);

	startUI(ui);
	destroyUI(ui);
	
	_CrtDumpMemoryLeaks();
	return 0;
}

