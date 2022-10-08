/*************************
 * Liam Todd
 * This file contains the struct for 'movie' and it's corresponding functions
 * ***********************/

#ifndef MOVIE_H
#define MOVIE_H
#include <string.h>
#include <stdlib.h>

struct movie {
	char* title;
	char* language;
	char* year;
	char* rating;
};

//struct movie* create_movie();
void fill_movieData(struct movie*, char*);
void free_movie(struct movie* film);

#endif
