#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define buff_size 255

//take input from command line as files and compresses into one file

int main(int argc, char **argv) {
        //buffer buff 
        char buff[buff_size];
	
	
	
        //open file that user inputed
	//read one file at a time       
	if (argc == 1) {
		printf("wzip: file1 [file2 ...]\n");
                exit(1);
	}
	for (int i = 1; i < argc; i++) {

		FILE *file = fopen(argv[i], "r");
        	//check that file can be opened 
        	if (file  == NULL) {
                	printf("wzip: file1 [file2 ...]\n");
                	exit(1);
                	//1 indicates failure 
      		}
        	//while we aren't at the end of file, get the line and compress it
		//to compress,  when encounter n characters of same type in a row, turn into n and a single instance of that character
        	while(fgets(buff, buff_size, (FILE*) file)) {
            		int length = strlen(buff);
			char *line = malloc(sizeof(char) * (2*length+1));
                    	int position = 0;
			char tracker[buff_size];
			for (int i = 0; i < length-1 ; i++) {
			//for (int i = 0; i < length; i++) {
				int count = 1;
				//count occurence of this char
				while (i < length -1 && buff[i] == buff[i+1]) {
					count++;
					i++;
					//increment every time we have a letter that is the same as the previous
				}
				//count number of occurrences of new character
				sprintf(tracker, "%d", count);
				for (int j = 0; *(tracker + j); j++, position++) {
					line[position] = tracker[j];

				}	
				line[position++] = buff[i];
				//line[position] = buff[i];
				//store number then letter
			
			}
			//null terminator for string
			line[position] = '\0';
				         
                        fwrite(line, strlen(line), 1, stdout);
			
             	}
	
        	fclose(file); 
	}      
	
} 	
