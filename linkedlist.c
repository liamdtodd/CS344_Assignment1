/*******************
 * Liam Todd
 * the .c implementation of linkedlist and it's associated functions
 * ****************/
#include "node.h"
#include "movie.h"
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//this function dynamically creates the linked list
struct Linked_List* create_linkedlist() {
	struct Linked_List* list = malloc(sizeof(struct Linked_List));
	list->length = 0;
	list->head = NULL;
	list->tail = NULL;
	
	return list;
}

//this function checks to see if the list is empty
int check_empty(struct node* head_temp) {
	if (head_temp == NULL)
		return 1;	//1 is true
	return 0;		//0 is false
}
	
//this function is specifically for inserting the first element to the linked list
void insert_firstelement(struct Linked_List* list, struct movie* film) {
	struct node* n1 = malloc(sizeof(struct node));
	n1->video = film;
	n1->next = NULL;
	
	list->head = n1;
	list->tail = n1;
}

//this function adds to the front of the linked list, at the head
void add_front(struct Linked_List* list, struct movie* film) {
	if (check_empty(list->head) == 1)
		insert_firstelement(list, film);		//checking to see if this will be the first element inserted
	else {
		struct node* n1 = malloc(sizeof(struct node));
		n1->video = film;
		n1->next = NULL;
		list->tail->next = n1;
		list->tail = n1;
	}
	
	list->length++;
}

//this function adds to the back of the linked list, at the tail
void add_back(struct Linked_List* list, struct movie* film) {
	if (check_empty(list->head) == 1)
		insert_firstelement(list, film);		//checking to see if this will be the first element inserted
	else {
		struct node* n1 = malloc(sizeof(struct node));
		n1->video = film;
		n1->next = list->head;
		list->head = n1;
	}
	
	list->length++;
}

//this function will return 1 or 0 (true/false) if the movie contains the inputted language
int movieLang(struct Linked_List* list, struct node* temp, char* lang) {
	char* token = NULL;
	char* subtoken = NULL;
	char* tknptr = NULL;
	char* subtknptr = NULL;
	char* tempstr = NULL;
	int x;

	char* check_key;
	char* longstr = malloc((strlen(temp->video->language) + 1) * sizeof(char));
	strcpy(longstr, temp->video->language);

	for (x = 1; ; x++, longstr = NULL) {
		token = strtok_r(longstr, "[]", &tknptr);
		if (token == NULL)
			break;
		
		for (tempstr = token; ; tempstr = NULL) {
			subtoken = strtok_r(tempstr, ";", &subtknptr);
			if (subtoken == NULL)
				break;
			check_key = malloc((strlen(subtoken) + 1) * sizeof(char));
			strcpy(check_key, subtoken);
			if (strcmp(check_key, lang) == 0) {
				token = NULL;
				subtoken = NULL;
				return 1;
			}
		}
	}
	
	free(check_key);
	check_key = NULL;

	return 0;					//free memory, return that this movie does not have the specified language
}

//this function will display the movies from a specified year
void displayYear(struct Linked_List* list, int year) {
	int len = 0;
	int localYear = 0;
	int count = 0;
	struct node* temp = list->head;

	while (temp != NULL) {
		len = strlen(temp->video->year);
		localYear = atoi(temp->video->year);

		if (localYear == year)
			printf("%s\n", temp->video->title);
		else 
			count++;
	
		temp = temp->next;
	}
	
	if (count == list->length)
		printf("No movie data for the year: %d\n", year);

	printf("\n");		
}

//this function will display the movie title and year correlating to an inputted language
void displayLang(struct Linked_List* list, char* lang) {
	int count = 0;
	int boolean = -1;
	struct node* temp = malloc(sizeof(struct node));
	temp = list->head;
		
	while (temp != NULL) {
		boolean = movieLang(list, temp, lang);	//getting a true/false value (1 or 0) if movie has the language
		
		if (boolean == 1) 
			printf("%s %s\n", temp->video->year, temp->video->title);	//displays movie of the inputted language
		else
			count++;
	
		temp = temp->next;
	}

	if (count == list->length)
		printf("No movide data for the language: %s\n", lang);

	free(temp);
	temp = NULL;

	printf("\n");
}
//this function frees all the dynamically allocated data associated with the linked list
void free_listelements(struct Linked_List* list) {
	int x = 0;
	struct node* temp = NULL;
	for (x; x < list->length; x++) {
		//struct node* temp;
		temp = list->head;
		list->head = list->head->next;
		free_movie(temp->video);		//freeing the data within the node
		//free(temp->video);				//freeing the data in the linked list
		free(temp);
		temp = NULL;
	}
	list->length = 0;
}	
