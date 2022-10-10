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

/*
struct Linked_List {
	int length;
	struct node* head;
	struct node* tail;
};
*/

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
/*
//this function will turn a string containing an integer into an integer type var
int string_to_int(int len, char* num) {
	int val = 0;
	int x = 0;
	int temp = 0;	

//	printf("before for loop...\n");
	for (x; x < len; x++) {
//		printf("%s\n", num);
		temp = atoi(num[x]);
		printf("temp assigned\n");	
		temp = temp - 48;

		if (x == 0)
			val = temp ;		//base case for the first value
		else {
			val = val * 10;		//moves the value in the 1's place to the 10's place, 1's place back at 0
			val = val + temp;	//assigns next integer value to 1's place
		}
	}

	return val;
}
*/
	
//this function is specifically for inserting the first element to the linked list
void insert_firstelement(struct Linked_List* list, struct movie* film) {
	struct node* n1 = malloc(sizeof(struct node));
	n1->video = film;
	
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
	char* tknptr = NULL;
	char* tempstr = malloc((strlen(temp->video->language) + 1) * sizeof(char));
	strcpy(tempstr, temp->video->language);
	
	token = strtok_r(tempstr, "[]", &tknptr);
	strcpy(tempstr, token);

	token = strtok_r(tempstr, ";", &tknptr);
	char* lang1 = malloc((strlen(token) + 1) * sizeof(char));
	strcpy(lang1, token);

	if (strcmp(lang1, lang) == 0) {
		free(tempstr);
		tempstr = NULL;
		free(lang1);
		lang1 = NULL;
		return 1;
	}

	free(tempstr);
	tempstr = NULL;
	free(lang1);
	lang1 = NULL;
	return 0;
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
	struct node* temp = list->head;
		
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
		free(temp);				//freeing the data in the linked list
		temp = NULL;
	}
	list->length = 0;
}	
