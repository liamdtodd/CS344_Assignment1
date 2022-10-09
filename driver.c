/***************************
 * Liam Todd
 * This is the driver file that has UI interaction and calls the other structs and functions
 * ************************/
#include "node.h"
#include "movie.h"
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readData(struct Linked_List* list, char* filepath) {
	size_t length = -5;
	size_t nread;	
	char* dataline = NULL;

	FILE* movieData = fopen(filepath, "r");
	
	if (movieData == NULL) {
		fprintf(stderr, "Could not open file: %s\n", filepath);
		exit(1);
	}
	
	nread = getline(&dataline, &length, movieData);

//	struct movie* temp = malloc(sizeof(struct movie));

	while ((nread = getline(&dataline, &length, movieData)) != -1) {
		struct movie* temp = malloc(sizeof(struct movie));
//		printf("before getting data...\n");
		fill_movieData(temp, dataline);
		add_back(list, temp);
		//free(temp);
		//temp = NULL;		
	}	

	//free(temp);
	//temp = NULL;
	free(dataline);
	dataline = NULL;
	fclose(movieData);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Not enough arguments entered! Example execution: 'a.out example.csv'\n");
		return 0;
	}							//ensuring that the program is started with a file name

	char* filepath = argv[1];
	struct Linked_List* list = create_linkedlist();

	printf("node: %d\n", sizeof(struct node));
	printf("movie: %d\n", sizeof(struct movie));
	printf("list: %d\n", sizeof(struct Linked_List));
	readData(list, filepath);
	printf("Successfully read from %s and parsed through %d movies\n", filepath, list->length);

	free_listelements(list);
	free(list);
	list = NULL;
	//free(filepath);

	return 0;
}
