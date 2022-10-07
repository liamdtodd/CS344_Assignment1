/******************
 * Liam Todd
 * The node struct for the struct Linked_List
 * ***************/
#ifndef NODE_H
#define NODE_H
//#include <iostream>
#include "movie.h"

//using namespace std;

struct node {
	struct movie* video;
	struct node* next;
};

//struct node* create_node();

#endif
