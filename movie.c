/*******************
 * Liam Todd
 * the .c implementation of movie.h
 * *****************/
#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//receives a line from the file, stores the data
void fill_movieData(struct movie* film, char* dataline) {
	char* token = NULL;
	char* tknptr = NULL;

	token = strtok_r(dataline, ",", &tknptr);
	film->title = malloc((strlen(token) + 1)* sizeof(char));
	strcpy(film->title, token);			//title data stored

	token = strtok_r(NULL, ",", &tknptr);
	film->year = malloc((strlen(token) + 1)* sizeof(char));
	strcpy(film->year, token);			//film data stored

	token = strtok_r(NULL, ",", &tknptr);
	film->language = malloc((strlen(token) + 1)* sizeof(char));
	strcpy(film->language, token);			//language data stored

	token = strtok_r(NULL, "\n", &tknptr);
	film->rating = malloc((strlen(token) + 1)* sizeof(char));
	strcpy(film->rating, token);			//rating data stored
}
	

//frees all the dynamically allocated data of the movie struct
void free_movie(struct movie* film) {
	free(film->year);
	film->year = NULL;
	free(film->year);
	film->year = NULL;
	free(film->language);
	film->language = NULL;
	free(film->rating);
	film->rating = NULL;

	free(film);
	film = NULL;			//all dynamic allocated variables are freed
}
