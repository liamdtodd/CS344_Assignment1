/*************************
 * Liam Todd
 * This file contains the struct for 'movie' and it's corresponding functions
 * ***********************/

#ifndef MOVIE_H
#define MOIVE_H
#include <string.h>
#include <stdlib.h>

struct movie/* {
	char* title;
	char* language;
	int year;
	double rating;
}*/;

struct movie* create_movie();
void free_movie(struct movie* film);

#endif
