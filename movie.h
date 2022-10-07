/*************************
 * Liam Todd
 * This file contains the struct for 'movie' and it's corresponding functions
 * ***********************/

#ifndef MOVIE_H
#define MOIVE_H
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

/*
struct moviebook {
	struct movie* data;
};
*/

struct movie {
	char* title;
	int year;
	char* language;	
	double rating;
};

/*
moviebook* create_moviebook(int num) {
	moviebook* book = malloc(num * sizeof(moviebook));
	int x = 0;
	for (x = 0; x < num; x++);
		book[x].data = create_movie();
	return book;
}
*/

movie* create_movie() {
	movie* film = malloc(sizeof(movie));
	
	film.title = malloc(20 * sizeof(char));		//this needs to change to a var of bytes!
	film.year = -1;
	film.language = malloc(20 * sizeof(char));		//this needs to change to a var of bytes!
	film.rating = -1;
	
	return film;
}

void free_movie(movie* video) {
	free(video.film);
	free(video.language);
	video.film = NULL;
	video.language = NULL;
}
	
#endif
