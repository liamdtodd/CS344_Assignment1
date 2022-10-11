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
	
	nread = getline(&dataline, &length, movieData);			//takes in first line of file, then 'deletes' it (not from file, just moves cursor)

	while ((nread = getline(&dataline, &length, movieData)) != -1) {
		struct movie* temp = malloc(sizeof(struct movie));
		fill_movieData(temp, dataline);		//line of file is sent to be stored
		add_back(list, temp);	//stores movie's data into a node of a linked list
	}	

	dataline = NULL;
	fclose(movieData);
}

//this function will show the movies released from a specified year
void moviesYear(struct Linked_List* list) {
	int ans = 0;
	printf("Please enter a year from 1900 to 2021, inclusive\n");
	scanf("%d", &ans);

	if ((ans < 1900) || (ans > 2021)) {
		do {
			printf("The number you entered is invalid: %d. Please enter a number from 1900-2021, inclusive\n", ans);
			scanf("%d", &ans);
		} while ((ans < 1900) || (ans > 2021));		//will repeatedly ask for value b/w 1900-2021 until successful
	}	

	printf("\nMovies from %d:\n", ans);
	displayYear(list, ans);		//this function will go through the list and print the movies from the specified year
}

//this function will show the highest rated movie from each year
void moviesYearRating(struct Linked_List* list) {
	double highRating = 0.0;
	int x;
	char* highTitle = NULL;
	int highYear = 0;
	struct node* temp = malloc(sizeof(struct node));
	temp = list->head;

	for (x = 1900; x < 2021; x++) {			//loop through the years 1900-2021, inclusive
		while (temp != NULL) {
			if ((x == atoi(temp->video->year) && (highRating < strtod(temp->video->rating, NULL)))) {
				highRating = strtod(temp->video->rating, NULL);
				highTitle = temp->video->title;
				highYear = atoi(temp->video->year);
			}				//checking to see if this node has a higher rating value
			temp = temp->next;
		}					//checked the entire list at x year for the highest rating value
		temp = list->head;			//reset to head of list
		
		while (temp != NULL) {			
			if ((highRating == strtod(temp->video->rating, NULL)) && (highYear == atoi(temp->video->year))) {
				printf("%d %.1f %s\n", highYear, highRating, highTitle);	//print x year's highest rating
				highRating = 0.0;
				highTitle = NULL;
				highYear = 0;		//reset highest rating value for the next x year
			}
			temp = temp->next;		//reset to head of list
		}
		temp = list->head;			//reset to head of list
	}	
		
	temp = NULL;
	free(temp);
	temp = NULL;
	printf("\n");
}

//this function will show the title and year of a movie from a specified language
void movieLanguage(struct Linked_List* list) {
	char* lang = malloc(20 * sizeof(char));
	printf("Please enter the language you'd like to search for: ");
	scanf("%s", lang);
	
	printf("\nMovies in the language %s:\n", lang);
	displayLang(list, lang);				//called function will display the movie if it matches the specified language

	free(lang);
	lang = NULL;
}

//This function will interact with the user's choice for how to display the movies
//Once the choice is inputted, it will call the corresponding function to accomdate the user's request
void userInteractive(struct Linked_List* list) {
	int ans = 0;
	
	printf("1. Show movies released in a specified year\n");
	printf("2. Show highest rated movie from each year\n");
	printf("3. Show title and year of a movie from a specified language\n");
	printf("4. Exit\n");
	printf("\nPlease select an option: ");
	scanf("%d", &ans);
	printf("\n");

	while (ans != 4) {
		if (ans == 1)
			moviesYear(list);			//movies released in a specified year
		else if (ans == 2)
			moviesYearRating(list);			//highest rated movie from each year
		else if (ans == 3)
			movieLanguage(list);			//the title and year of a movie from a specified language
		else {
			do {
				printf("You have entered an invalid number: %d. Please enter a number 1-4\n", ans);
				scanf("%d", &ans);
			} while ((ans < 1) && (ans > 4));	//if user doesn't enter a number 1-4, will repeat until they do
		}

		if (ans != 4) {					//if the user initially entered an invalid number, and then 4, this will take care of that
			printf("1. Show movies released in a specified year\n");
			printf("2. Show highest rated movie from each year\n");
			printf("3. Show title and year of a movie from a specified language\n");
			printf("4. Exit\n");
			printf("\nPlease select an option: ");
			scanf("%d", &ans);
			printf("\n");
		}				
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Wrong arguments entered! Example execution: 'a.out example.csv'\n");
		return 0;
	}							//ensuring that the program is started with a file name

	char* filepath = argv[1];				//file's name
	struct Linked_List* list = create_linkedlist();

	readData(list, filepath);
	printf("Successfully read from %s and parsed through %d movies\n", filepath, list->length);

	userInteractive(list);					//all user interaction comes from called function

	free_listelements(list);				//free dynamic allocated linked list's elements
	free(list);						//free dynamic allocated linked list
	list = NULL;

	return 0;
}
