#ifndef mylib
#define mylib

#define SIZE 20                 // maximum number of characters in the pattern
#define LINE_SIZE 60            // maximum number of characters in one line

void Greeting();
	// print out the welcome messages, check the sample executable 

FILE* OpenFile(char *name);
	// prompt the user to enter a file name
	// open the file for read only 
	// return the file pointer (NULL if the file cannot be open) 
	// file name is also saved in variable "name"

void PrintMenu(char *name);
	// print out the menu for user options.
	// prompt the user to enter a choice (1, 2, or 3)
	// note that file name will be used in the menu

void GetPattern(char *);
	// prompt the user for the pattern to be found/replaced
	// note: any character, including ' ', maybe be part of the pattern
	// we assume that the pattern has no more than 20 characters. If the 
	// enters more than 20 characters, only the first 20 will be used.

FILE* CreateFile();
	// prompt the user to enter a string as file name
	// you need to check whether the file name has illegal characters
	// only _, 0-9, a-z, and A-Z are legal and the first character cannot
	// be 0-9.
	// check to see whether the file already exists. If so, ask the user 
	// to confirm that the existing file is overwritten. 
	// open the file for write only
	// terminate the program if the file cannot be open after 3 attempts
	// return the file point

void Find(FILE* in, char* pattern, FILE* out);
	// find the occurence of "pattern" in file "in"
	// note that there are certain "find" options for user to choose
	// write the correpsonding information to file "out" as (pattern=user)
	// line 4:         // prompt the user to enter a file name
 	// line 8:// print out the menu for user options.
	// line 15:         // prompt the user to enter a choice
 

void Replace(FILE *in, char *pattern, char *replacement, FILE *out);
	// replace "pattern" in file "in" by "replacement
	// there are also options for replacement that user needs to choose
	// write the output to file "out"

#endif
