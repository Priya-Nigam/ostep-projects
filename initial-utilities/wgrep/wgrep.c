#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#define buff_size 255

int main(int argc, char **argv) {
	//buffer buff
	char buff[buff_size];

	//first establish what we are looking for
	
	char *keyword = argv[1];
	//if we get a file or multiple files
	if (argc > 2) {
	//now go through each file and check for the keyword
		for (int i = 2; i < argc; i++) { 
			FILE *file = fopen(argv[i], "r");
			if (file == NULL) {
				printf("wgrep: cannot open file\n");
				exit(1);
				//1 indicates failure
			}
			//look thru each line and check for word 
			//while we aren't at the end of file, get the line and print it
        		while(fgets(buff, buff_size, (FILE*) file)) {
        			//char *line = malloc(buff_size);
				//int length = strlen(line);
				if ((strstr(buff,keyword)) != NULL) {
					printf("%s", buff); 
				}
			}
	
        		fclose(file); 
		}
	} else if (argc < 2 ) {
		printf("wgrep: searchterm [file...]\n");
		exit(1);
	} else if (argc = 2) { //search for keyword from keyboard input
		
		//look thru each line and check for word 
                //while we aren't at the end of file, get the line and print it
                while(fgets(buff, buff_size, stdin)) {
                                //char *line = malloc(buff_size);
                                //int length = strlen(line);
                        if ((strstr(buff,keyword)) != NULL) {
                                        printf("%s", buff); 
                        }
             	}
        
            		
	} else {
		exit(0);
	}
}
