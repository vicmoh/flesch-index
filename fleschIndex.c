/* Vicky Mohammad
 * February 10, 2017
 * This program will output information of the txt file*/

/*import libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int main(int argc, char* argv[]){
	/*declare var*/
	FILE *txtFile;
	int line = 0;
	float index = 0;
	int wordCount = 0;
	int sentenceCount = 0;
	int vowelCount = 0;
	/*int preVowel = 0;*/
	int numLetter = 0;
	char string[999];
	int x = 0, e = 0, exit = 0;
	/*enter the file name*/
	/*open file, if doesn't exist print a message*/
	txtFile = fopen(argv[1], "r");
	if (txtFile == NULL){
		perror("Can't open file");
		return(0);
	}/*end of file*/
	
	/*loop until the end of file*/
	while(fgets(string, 999, txtFile)){
		line = line + 1;
		/*ignore, this is for debugging
		printf("Line %d: %s", line, string);
		preVowel = vowelCount;*/
		
		/*loop until null*/
		for (x = 0; string[x] != '\0'; x++){
			/*check for word count*/
			if ((string[x] == ' ' || string[x] == '\n') && string[x-1] != ' '){
				wordCount = wordCount + 1;
			}/*end if*/
			/*check the number of sentence*/
			if (string[x] == '.' || string[x] == '!' || 
				string[x] == '?' || string[x] == ';' || string[x] == ':'){
				if(string[x+1] == ' ' || string[x+1] == '\n' || string[x+1] == '\0'){
				sentenceCount = sentenceCount + 1;
				}/*end if*/
			}/*end if*/
			/********************************************************************/
			/*check for the number of single vowels*/
			if (string[x] == 'a' || string[x] == 'e' || 
				string[x] == 'i' || string[x] == 'o' || 
				string[x] == 'u' || string[x] == 'y' ||
				string[x] == 'A' || string[x] == 'E' || 
				string[x] == 'I' || string[x] == 'O' || 
				string[x] == 'U' || string[x] == 'Y'){
				if (string[x+1] != 'a' && string[x+1] != 'e' && 
					string[x+1] != 'i' && string[x+1] != 'o' && 
					string[x+1] != 'u' && string[x+1] != 'y'){
					vowelCount = vowelCount + 1;
				}/*end if*/
			}/*end if*/
			/*check vowel is next to vowel*/
			if (string[x] == 'a' || string[x] == 'e' || 
				string[x] == 'i' || string[x] == 'o' || 
				string[x] == 'u' || string[x] == 'y' ||
				string[x] == 'A' || string[x] == 'E' || 
				string[x] == 'I' || string[x] == 'O' || 
				string[x] == 'U' || string[x] == 'Y'){
				if (string[x+1] == 'a' && string[x+1] == 'e' && 
					string[x+1] == 'i' && string[x+1] == 'o' && 
					string[x+1] == 'u' && string[x+1] == 'y'){
					vowelCount = vowelCount + 1;
				}/*end if*/
			}/*end if*/
			numLetter = numLetter + 1;
			/*check if end of e then substrack*/
			if (string[x] == '\n' || string[x] == '\0'||
				string[x] == ' ' || string[x] == '.' || 
				string[x] == '!' || string[x] == '?' ||  
				string[x] == ';' || string[x] == ':' || string[x] == ',' ){
				/*if the end of the word is e*/
				if (string[x-1] == 'e'){
					/*loop until the number of letter in a word*/
					while (exit == 0){
						if(e<(numLetter-3)){
							e = e + 1;
							/*if there is a vowel when going through the word*/
							if (string[x-numLetter+e] == 'a' || string[x-numLetter+e] == 'e' || 
								string[x-numLetter+e] == 'i' || string[x-numLetter+e] == 'o' || 
								string[x-numLetter+e] == 'u' || string[x-numLetter+e] == 'y' ||
								string[x-numLetter+e] == 'A' || string[x-numLetter+e] == 'E' || 
								string[x-numLetter+e] == 'I' || string[x-numLetter+e] == 'O' || 
								string[x-numLetter+e] == 'U' || string[x-numLetter+e] == 'Y'){
								vowelCount = vowelCount - 1;
								exit = 1;
								numLetter = 0;
							}/*end if*/
						} else {
								exit = 1;
						}/*end if*/
					}/*else if*/
				}/*end while*/
				/*reset vars to 0*/
				numLetter = 0;
				exit = 0;
				e = 0;
			}/*end if*/	
			/********************************************************************/ 
		}/*end for loop*/
		
		/*reset numLetter to 0 just to make sure*/
		numLetter = 0;
		/*ignore this, it's for debugging to see what syllable is counting*/
		/*printf("(This line has %d syllables, totaling %d syllables) \n\n", (vowelCount-preVowel), vowelCount);*/
	}/*end while loop*/
	
	/*get the index value*/
	index = 206.835-84.6*(vowelCount/wordCount)-1.015*(wordCount/sentenceCount);
	/*print the counter*/
	printf("Flesch Index = %d\n", (int)(index+0.5));
	printf("Syllable Count = %d\n", vowelCount);
	printf("Word Count = %d\n", wordCount);
	printf("Sentence Count = %d\n", sentenceCount);
	fclose(txtFile);
	return(0);
}/*end main*/
