/*******************
 * Liam Todd
 * the .c implementation of linkedlist and it's associated functions
 * ****************/
#include "node.h"
#include "movie.h"
#include "linkedlist.h"
//#include <iostream>
#include <stdlib.h>

//using namespace std;

struct Linked_List {
	int length;
	struct node* head;
	struct node* tail;
};

struct Linked_List* create_linkedlist() {
	struct Linked_List* list = malloc(sizeof(struct Linked_List));
	list->length = 0;
	list->head = NULL;
	list->tail = NULL;
	
	return list;
}

int check_empty(struct node* head_temp) {
	if (head_temp == NULL)
		return 1;
	return 0;
}

void insert_firstelement(struct Linked_List* list, struct movie* film) {
	struct node* n1 = malloc(sizeof(struct node));
	n1->video = film;
	
	list->head = n1;
	list->tail = n1;
}

void add_front(struct Linked_List* list, struct movie* film) {
	if (check_empty(list->head) == 1)
		insert_firstelement(list, film);
	else {
		struct node* n1 = malloc(sizeof(struct node));
		n1->video = film;
		n1->next = NULL;
		list->tail->next = n1;
		list->tail = n1;
	}
	
	list->length++;
}

void add_back(struct Linked_List* list, struct movie* film) {
	if (check_empty(list->head) == 1)
		insert_firstelement(list, film);
	else {
		struct node* n1 = malloc(sizeof(struct node));
		n1->video = film;
		n1->next = list->head;
		list->head = n1;
	}
	
	list->length++;
}
