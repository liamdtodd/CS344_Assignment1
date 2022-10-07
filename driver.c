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

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Not enough arguments entered! Example execution: 'a.out example.csv'\n");
		return 0;
	}
	struct Linked_List* list = create_linkedlist();

	free_listelements(list);

	free(list);

	return 0;
}
