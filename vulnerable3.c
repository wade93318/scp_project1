#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM_COORDINATES 512

struct coordinates_t {
	double x;
	double y;
	double z;
	int count;
};

void launch(char * cursor, int number_of_items)
{
	struct coordinates_t buffer[MAXIMUM_COORDINATES];
	
	if (number_of_items < MAXIMUM_COORDINATES) 
	{
		memcpy(buffer, cursor, number_of_items * sizeof(struct coordinates_t));
	}
}

int main(int argc, char * argv[])
{
	int number_of_items;
	char * cursor;
	
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [number of items],[data]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	number_of_items = strtoul(argv[1], &cursor, 10);
	
	if ((*cursor != ',') || (strlen(cursor + 1) < sizeof(struct coordinates_t) * number_of_items))
	{
		fprintf(stderr, "Usage: %s [number of items],[data]\n", argv[0]);
		exit(EXIT_FAILURE);		
	}

	cursor = cursor + 1;	
	launch(cursor, number_of_items);
	return(0);
}
