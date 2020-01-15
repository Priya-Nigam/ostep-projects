#include <stdio.h>
#include <stdlib.h>

//take input from command line as file and print it out line by line 

int main(int argc, char **argv) {
        //buffer buff 
        char buff[255];

        //open file that user inputed
	//read only 1st file 
        FILE *file = fopen(argv[1], "r");
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
