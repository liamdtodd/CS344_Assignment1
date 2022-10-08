/******************
 * Liam Todd
 * The node struct for the struct Linked_List
 * ***************/
#ifndef NODE_H
#define NODE_H
#include "movie.h"

struct node {
	struct movie* video;
	struct node* next;
};

#endif
