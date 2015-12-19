/* This is the main program for project 4. You should not make any changes
	to this file. Instead, work on mylib.h and mylib.c
   To compile the project, you need to do the following:
        gcc -c mylib.c -o mylib.o
        gcc p4.c mylib.o -o a.out

								Gang Qu
								Dec. 1, 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int main(void)
{ int attempt=0, option=-1;
  char pattern[SIZE+1], replacement[SIZE+1];
  char name[20];		// assume that the lenght of file name is < 20 
  FILE *in, *out;		// two file pointers for input and output

  Greeting();
   
  do
  { in = OpenFile(name);
    attempt++;
  }while (in == NULL && attempt < 3);
 
  if (attempt == 3) 
  { printf("You have reached the file open limit.\nPlease double check the file name and re-run the program.\n----Goodbye!----\n");
    exit(0);
  }

  PrintMenu(name);
  do
  { scanf("%d", &option);
  } while (option<=0 || option>=4); 

// 1. find and output to a file
// 2. replace to a new file
// 3. quit

  switch(option)
  { case 1: printf("Enter the pattern to find:");
	    GetPattern(pattern); 
	    out = CreateFile();
            Find(in, pattern, out);
            fclose(in);
            fclose(out);
            break;

    case 2: printf("Enter the pattern to be replaced:");
	    GetPattern(pattern);
            printf("Enter the pattern of replacement:");
            GetPattern(replacement);
            out = CreateFile();
            Replace(in, pattern, replacement, out);
            fclose(in);
            fclose(out);
            break;

    case 3: printf("----Goodbye!----\n"); 
            break;
    default: printf("Error! You should not come here.\n");
  }

  return 0;
}
