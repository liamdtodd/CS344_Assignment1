/*******************
 * Liam Todd
 * the .c implementation of linkedlist and it's associated functions
 * ****************/
#include "node.h"
#include "movie.h"
#include "linkedlist.h"
#include <stdlib.h>

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

//this function frees all the dynamically allocated data associated with the linked list
void free_listelements(struct Linked_List* list) {
	int x = 0;
	for (x; x < list->length; x++) {
		struct node* temp;
		temp = list->head;
		list->head = list->head->next;
		free_movie(temp->video);		//freeing the data within the node
		free(temp);				//freeing the data in the linked list
	}
}	
