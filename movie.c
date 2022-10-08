/*******************
 * Liam Todd
 * the .c implementation of movie.h
 * *****************/
#include "movie.h"
#include <stdlib.h>
#include <string.h>


struct movie {
	char* title;
	char* language;
	int year;
	double rating;
};


//creates the movie data, initialized
struct movie* create_movie() {
	struct movie* film = malloc(sizeof(struct movie));
	
	film->title = malloc(20 * sizeof(char));			//this needs to be changed to a var amount of bytes!
	film->year = -1;
	film->language = malloc(20 * sizeof(char));		// this needs to be changed to a var amount of bytes!
	film->rating = -1;
	
	return film;
}

//frees all the dynamically allocated data of the movie struct
void free_movie(struct movie* film) {
	free(film->title);
	free(film->language);
	film->title = NULL;
	film->language = NULL;
}

