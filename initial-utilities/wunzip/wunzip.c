#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define buff_size 255

//take input from command line as 1 file and uncompresses into its multiple files

int main(int argc, char **argv) {
        //buffer buff 
        char buff[buff_size];

        
	//read one file at a time 
	if (argc == 1) {
		printf("wunzip: file1 [file2 ...]\n");
                exit(1);
	}
	for (int i = 1; i < argc; i++) {

		FILE *file = fopen(argv[i], "r");
        	//check that file can be opened 
        	if (file  == NULL) {
                	printf("wunzip: cannot open file\n");
                	exit(1);
                	//1 indicates failure 
      		}
        	//while we aren't at the end of file, get the line and uncompress it
		//to uncompress,  when turn n and a single instance of that character
        	//into that character repeated n times in a row 
		char position; 
		int count = 0;
		//find out how many counts there are for char position  and stores in count
		
		size_t num_counts = fread(&count, 4, 1, file);
		//read the position char and assign it as such
		fread(&position, 1, 1, file);
		//basically while you have a count to be read 
		while (num_counts == 1) {
			for (int i = 0; i < count; i++){
				fwrite(&position, 1,1, stdout);
			}
			//prints char position as many times as counter
			//now update counter to be the next number and position to tbe the next char
			num_counts= fread(&count, 4, 1, file);
			fread(&position, 1, 1, file);
		}
        	fclose(file); 
	}      
	
} 
