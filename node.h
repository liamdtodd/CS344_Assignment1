/******************
 * Liam Todd
 * The node struct for the struct Linked_List
 * ***************/
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <movie.h>

using namespace std;

struct node {
	movie* video;
	node* next;
};

#endif
