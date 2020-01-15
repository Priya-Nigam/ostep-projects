#include <stdio.h>
#include <stdlib.h>

//take input from command line as file and print it out line by line 

int main(int argc, char **argv) {
        //buffer buff 
        char buff[255];

        //open file that user inputed
	//read one file at a time       
	for (int i = 1; i < argc; i++) {

		FILE *file = fopen(argv[i], "r");
        	//check that file can be opened 
        	if (file  == NULL) {
                	printf("wcat: cannot open file\n");
                	exit(1);
                	//1 indicates failure 
      		}
        	//while we aren't at the end of file, get the line and print it
        	while(fgets(buff, 255, (FILE*) file)) {
        		printf("%s",buff);
		}
	
        	fclose(file); 
	}      
} 	
