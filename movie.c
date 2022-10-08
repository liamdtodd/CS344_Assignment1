/*******************
 * Liam Todd
 * the .c implementation of movie.h
 * *****************/
#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct movie {
	char* title;
	char* language;
	char* year;
	char* rating;
};
*/

//creates the movie data, initialized
/*
struct movie* create_movie() {
	struct movie* film = malloc(sizeof(struct movie));
	
	film->title = malloc(20 * sizeof(char));			//this needs to be changed to a var amount of bytes!
	film->year = -1;
	film->language = malloc(20 * sizeof(char));		// this needs to be changed to a var amount of bytes!
	film->rating = -1;
	
	return film;
}
*/
void fill_movieData(struct movie* film, char* dataline) {
	char* token;
	char* tknptr;

	token = strtok_r(dataline, ",", &tknptr);
	film->title = calloc((strlen(token) + 1), sizeof(char));
	strcpy(film->title, token);
	printf("title data...\t%s\n", film->title);

	token = strtok_r(NULL, ",", &tknptr);
	film->year = calloc((strlen(token) + 1), sizeof(char));
	strcpy(film->year, token);
	printf("year data...\t%s\n", film->year);

	token = strtok_r(NULL, ",", &tknptr);
	film->language = calloc((strlen(token) + 1), sizeof(char));
	strcpy(film->language, token);
	printf("language data...\t%s\n", film->language);

	token = strtok_r(NULL, "\n", &tknptr);
	film->rating = calloc((strlen(token) + 1), sizeof(char));
	strcpy(film->rating, token);
	printf("rating data...\t%s\n", film->rating);

}
	

//frees all the dynamically allocated data of the movie struct
void free_movie(struct movie* film) {
	free(film->year);
	free(film->rating);
	free(film->title);
	free(film->language);
	film->title = NULL;
	film->language = NULL;
	film->year = NULL;
	film->rating = NULL;
}

