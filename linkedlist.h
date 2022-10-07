/********************
 * Liam Todd
 * the struct and its associated functions for 'linkedlist'
 * *****************/
#ifndef LINKEDLIST_H
#define LINKEDlIST_H
#include "node.h"
#include "movie.h"
//#include <iostream>
#include <stdlib.h>

//using namespace std;

struct Linked_List;

struct Linked_List* create_linkedlist();

int check_empty(struct node*);

void insert_firstelement(struct Linked_List*, struct movie*);
void add_front(struct Linked_List*, struct movie*);
void add_back(struct Linked_List*, struct movie*);

#endif
