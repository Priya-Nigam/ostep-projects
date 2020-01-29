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
	//if you have 2 files and one ends with aaa and next starts with aaa will read as aaaaaa
	int turnover_count = 0;
	char turnover_char;
	int count = 0;
	char position;	
	for (int i = 1; i < argc; i++) {

		FILE *file = fopen(argv[i], "r");
        	//check that file can be opened 
        	if (file  == NULL) {
                	printf("wzip: cannot open file\n");
                	exit(1);
                	//1 indicates failure 
      		}
        	//while we aren't at the end of file, get the line and compress it
		//to compress,  when encounter n characters of same type in a row, turn into n and a single instance of that character
        //	int count = 0;
	//	char position; 
		//if there is a carryover 
		if (turnover_count != 0) {
			count =  turnover_count;
			position = turnover_char;
		} else {
		//no carryover from previous file
			count = 1;
			//initiate counter
			position = fgetc(file);
		}
		while((position != EOF)) {
          
			char upcoming = fgetc(file);
			while ((upcoming == position) && (upcoming !=EOF)) {
			
				//if the next one is also the same char
				count++;
				upcoming = fgetc(file);
			} 	
			
			//if the next char isn't new line or the end of a file
			if (i== (argc-1) || (upcoming != EOF)) {
		
                                fwrite(&count,4,1,stdout);
                                fwrite(&position,1,1,stdout);
				position = upcoming;
				//reinitiate turnover_count
				count = 1;
				turnover_count = 0;				
				
			} else {
			//if you have to get next char from the next file
				if (upcoming == EOF) {
				//if at the end of the file, store the count and position and move to next file
					turnover_count = count; 
					turnover_char= position;
				} 
				position = upcoming;
			//update the position
				
			}
		}
        	fclose(file); 
	}      
	exit(0);	
} 	
