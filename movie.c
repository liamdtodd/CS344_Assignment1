/*******************
 * Liam Todd
 * the .c implementation of movie.h
 * *****************/
#include "movie.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

movie* create_movie() {
	movie* film = malloc(sizeof(movie));
	
	film.title = malloc(20 * sizeof(char));			//this needs to be changed to a var amount of bytes!
	film.year = -1;
	film.language = malloc(20 * sizeof(char));		// this needs to be changed to a var amount of bytes!
	film.rating = -1;
	
	return film;
}

void free_movie(movie* film) {
	free(film.title);
	free(film.language);
	film.title = NULL;
	film.language = NULL;
}	
