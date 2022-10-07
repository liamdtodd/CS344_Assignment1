/*************************
 * Liam Todd
 * This file contains the struct for 'movie' and it's corresponding functions
 * ***********************/

#ifndef MOVIE_H
#define MOIVE_H
//#include <iostream>
#include <string.h>
#include <stdlib.h>

//using namespace std;

struct movie;

struct movie* create_movie();
void free_movie(struct movie* film);
//struct movie& operator=(const struct movie&);

#endif
