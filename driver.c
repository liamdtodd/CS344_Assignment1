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
	FILE* movieData = fopen(filepath, "r");
	
	if (movieData == NULL) {
		fprintf(stderr, "Could not open file: %s\n", filepath);
		exit(1);
	}

	fclose(movieData);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Not enough arguments entered! Example execution: 'a.out example.csv'\n");
		return 0;
	}							//ensuring that the program is started with a file name

	char* filepath = argv[1];
	struct Linked_List* list = create_linkedlist();

	readData(list, filepath);
	printf("Successfully read from %s and parsed through %d movies\n", filepath, list->length);

	free_listelements(list);
	free(list);

	return 0;
}
