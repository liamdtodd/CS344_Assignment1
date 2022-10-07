/*******************
 * Liam Todd
 * the .c file for node.h
 * *******************/
#include "node.h"
#include "movie.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

node::node(movie* video) {
	video = create_movie();
	next = NULL;
}
