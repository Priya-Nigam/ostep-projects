#include <stdlib.h>
#include <stdio.h>

int main(void) {
	//buffer buff 
	char buff[255];

	//open file that user inputed
	FILE *file = fopen("main.c", "r");
	//check that file can be opened 
	if (file  == NULL) {
 		printf("\nSorry! We cannot open that file\n");
 		exit(1);
		//1 indicates failure 
	}
	//while we aren't at the end of file, get the line and print it

	//first try to print one line 
	fgets(buff, 255, (FILE*) file);
	printf("%s",buff);
	fclose(file);	
} 

