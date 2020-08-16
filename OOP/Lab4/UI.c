#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

UI* createUI(Service* s)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->serv = s;

	return ui;
}

void destroyUI(UI* ui)
{
	// first destroy the Service
	destroyService(ui->serv);
	// free the UI memory
	free(ui);
}

int deletePersonUI(UI* ui)
{
	int profileIdNumber_as_int = 0;
	char user_command_as_input[100];
	char* token_from_the_user_input;
	char profileIdNumber[50];

	fgets(user_command_as_input, 100, stdin);
	token_from_the_user_input = strtok(user_command_as_input, " ,");
	strcpy(profileIdNumber, token_from_the_user_input);
	profileIdNumber_as_int = atoi(profileIdNumber);
	int res= deletePersonServ(ui->serv,profileIdNumber_as_int);
	if (res == 1)
		printf("No!\n");
}



int addPersonUI(UI* ui)
{
	int profileIdNumber_as_int = 0;
	int yearsOfRecordedService_as_int = 0;
	char user_command_as_input[100];
	char* token_from_the_user_input;
	char profileIdNumber[50];
	char placeOfBirth[50];
	char psychologicalProfile[50];
	char yearsOfRecordedService[50];

	fgets(user_command_as_input, 100, stdin);
	token_from_the_user_input = strtok(user_command_as_input, " ,");
	strcpy(profileIdNumber, token_from_the_user_input);

	token_from_the_user_input = strtok(NULL, " ,");
	if (NULL != token_from_the_user_input)
		strcpy(placeOfBirth, token_from_the_user_input);

	token_from_the_user_input = strtok(NULL, " ,");
	if (NULL != token_from_the_user_input)
		strcpy(psychologicalProfile, token_from_the_user_input);

	token_from_the_user_input = strtok(NULL, " ,");
	if (NULL != token_from_the_user_input)
		strcpy(yearsOfRecordedService, token_from_the_user_input);

	profileIdNumber_as_int = atoi(profileIdNumber);
	yearsOfRecordedService_as_int = atoi(yearsOfRecordedService);


	int res= addPersonServ(ui->serv, profileIdNumber_as_int, placeOfBirth, psychologicalProfile, yearsOfRecordedService_as_int);
	if (res == 0)
		printf("No!\n");
}

void listAllPersons(UI* ui)
{
	if (ui == NULL)
		return;

	PersonRepo* repo = getRepo(ui->serv);
	int length = getRepoLength(repo);
	char check_if_there_are_parameters;
	char psychoProfile[50];
	int input_as_int;
	Person* list_maximum_value[200];
	Person* auxiliar;

	int listlength = 0;


	scanf("%c", &check_if_there_are_parameters);
	if (check_if_there_are_parameters != '\n') {
		int j = 0;
		scanf("%s", psychoProfile);
		input_as_int = atoi(psychoProfile);
		if (input_as_int > 0 && input_as_int < 1000)
		{
			for (int i = 0; i < length; i++) {
				Person* person = getPersonOnPos(repo, i);
				if (person->yearsOfRecordedService < input_as_int)
				{
					list_maximum_value[listlength] = person;
					listlength++;
				}
			}
			for (int i = 0; i < listlength - 1; i++)
				for (j = i + 1; j < listlength; j++)
					if (strcmp(list_maximum_value[i]->placeOfBirth, list_maximum_value[j]->placeOfBirth) > 0)
					{
						auxiliar = list_maximum_value[i];
						list_maximum_value[i] = list_maximum_value[j];
						list_maximum_value[j] = auxiliar;
					}
			for (int i = 0; i < listlength; i++)
			{
				char personString[200];
				toString(list_maximum_value[i], personString);
				printf("%s\n", personString);
			}
		}


		else {
			for (int i = 0; i < length; i++)
			{
				Person* person = getPersonOnPos(repo, i);
				char personString[200];
				if (strcmp(person->psychologicalProfile, psychoProfile) == 0) {
					toString(person, personString);
					printf("%s\n", personString);
				}
			}
		}
	}
	else  {
		for (int i = 0; i < length; i++)
		{
			Person* person = getPersonOnPos(repo, i);
			char personString[200];
			toString(person, personString);
			printf("%s\n", personString);
		}


	}
}

int updatePersonUI(UI* ui) {
	int profileIdNumber_as_int = 0;
	int yearsOfRecordedService_as_int = 0;
	char user_command_as_input[100];
	char* token_from_the_user_input;
	char profileIdNumber[50];
	char placeOfBirth[50];
	char psychologicalProfile[50];
	char yearsOfRecordedService[50];

	fgets(user_command_as_input, 100, stdin);
	token_from_the_user_input = strtok(user_command_as_input, " ,");
	strcpy(profileIdNumber, token_from_the_user_input);
	profileIdNumber_as_int = atoi(profileIdNumber);
	token_from_the_user_input = strtok(NULL, " ,");
	if (NULL != token_from_the_user_input)
		strcpy(placeOfBirth, token_from_the_user_input);

	token_from_the_user_input = strtok(NULL, " ,");
	if (NULL != token_from_the_user_input)
		strcpy(psychologicalProfile, token_from_the_user_input);

	token_from_the_user_input = strtok(NULL, " ,");
	if (NULL != token_from_the_user_input)
		strcpy(yearsOfRecordedService, token_from_the_user_input);

	yearsOfRecordedService_as_int = atoi(yearsOfRecordedService);
	updatePersonServ(ui->serv,profileIdNumber_as_int, placeOfBirth, psychologicalProfile, yearsOfRecordedService_as_int);
}

void startUI(UI* ui)
{
	while (1)
	{
		char command[20];
		scanf("%s", &command);

		if (strcmp(command, "exit") == 0)
			break;
		else if (strcmp(command, "add") == 0)
			addPersonUI(ui);
		else if (strcmp(command, "list") == 0)
			listAllPersons(ui);
		else if (strcmp(command, "delete") == 0)
			deletePersonUI(ui);
		else if (strcmp(command, "undo") == 0)
			undo(ui->serv);
		else if (strcmp(command, "redo") == 0)
			redo(ui->serv);
		else if (strcmp(command, "update") == 0)
			updatePersonUI(ui);

	}
	return 0;
}