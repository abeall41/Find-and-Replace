#include <stdio.h>
#include <string.h>
#include "mylib.h"

#define SIZE 20                 // maximum number of characters in the pattern
#define LINE_SIZE 60            // maximum number of characters in one line

void Greeting()
{
	// print out the welcome messages, check the sample executable 
	printf("\t\tWelcome to ENEE 140 final project!\nIn this project, you will implement find and replace for plain text files.\n");
}
FILE* OpenFile(char *name)
{
	// prompt the user to enter a file name
	// open the file for read only 
	// return the file pointer (NULL if the file cannot be open) 
	// file name is also saved in variable "name"
	char xtr;
	
	printf("\n\tEnter a File name:");
	scanf("%s", name);
	FILE *Input;
	Input = fopen(name, "r");
	return(Input);
	
	
}
void PrintMenu(char *name)
{
	// print out the menu for user options.
	// prompt the user to enter a choice (1, 2, or 3)
	// note that file name will be used in the menu
	
	printf("\n\tOptions Menu\n");
	printf("Please select an option for file %s \n", name);
	printf("\t1: Find a pattern\n");
	printf("\t2: Replace a pattern\n");
	printf("\t3: Quit\n\n");

}
void GetPattern(char *name)
{
	// prompt the user for the pattern to be found/replaced
	// note: any character, including ' ', maybe be part of the pattern
	// we assume that the pattern has no more than 20 characters. If the 
	// enters more than 20 characters, only the first 20 will be used.
	int i;
	
	
	if (i>=21)
	{
		fgetc(stdin);
	}
	
	fgets(name, SIZE+1, stdin);
	for(i=0; i<=SIZE; i++)
	{
		if(name[i]=='\n')
		{
			name[i] = '\0';
			break;
		}
	}
	
}	
FILE* CreateFile()
{
	// prompt the user to enter a string as file name
	// you need to check whether the file name has illegal characters
	// only _, 0-9, a-z, and A-Z are legal and the first character cannot
	// be 0-9.
	// check to see whether the file already exists. If so, ask the user 
	// to confirm that the existing file is overwritten. 
	// open the file for write only
	// terminate the program if the file cannot be open after 3 attempts
	// return the file point
	
	int i, d=0, j=30; 
	char newfile[31], Over;
	FILE *Check;
	FILE *OutFile;
		
while(d == 0)
{
		printf("Enter a file name:");
		//fgetc(stdin);
		fgets(newfile, 30, stdin);
		printf("\tFile: %s", newfile);
		

	//check if name is valid
		if((newfile[0] >= 48) && (newfile[0] <= 57))
			{
				printf("Invalid File name");
				continue;
			}
		for(i=0; i<j; i++)
		{
			if((newfile[i] >= 48) && (newfile[i] <= 57))
			{
				//printf("Number - character %d\n", i);
				continue;
			}
			if((newfile[i] >= 65) && (newfile[i] <= 90))
			{
				//printf("UpperCase - character %d\n", i);
				continue;
			}	
			if((newfile[i] >= 97) && (newfile[i] <= 122))
			{
				//printf("LowerCase - character %d\n", i);
				continue;
			}
			if(newfile[i] == '\n')
			{
				newfile[i] = '\0';
				d = 1;
				j = i;
				continue;
			}
			else
			{
				printf("Invalid File name\n");
				break;
			}
		}
	//Check if name already esists
	
			//printf("Check File existance\n");
			Check = fopen(newfile, "r");
			if(Check == NULL)
			{
				//File does not exist
				//printf("File Does not exist");
				d=1;
				continue;
			}
			printf("File %s already exists. Would you like to overwrite? (Y or N)", newfile);
			scanf("%c", &Over);
			if(Over == 'N')
			{
				printf("exit");
				d=0;
			}
			if(Over == 'Y')
			{
				d=1;
			}
			fclose(Check);
	}
	
printf("\nOpening file to Write\n");
	//Open the file
		
		OutFile = fopen(newfile, "w");
		if (OutFile == NULL)
		{
			printf("File %s cannot open!\n", newfile);
		}

	return OutFile;
	
	
}
void Find(FILE* in, char* pattern, FILE* out)
{
	// find the occurence of "pattern" in file "in"
	// note that there are certain "find" options for user to choose
	// write the correpsonding information to file "out" as (pattern=user)
	// line 4:      	// prompt the user to enter a file name
 	// line 8:			// print out the menu for user options.
	// line 15:         // prompt the user to enter a choice
	int opt[3];
	
		
	printf("\n\n\tFind Option 1:\n0. Case Sensitive\n1. Case Insensitive\n\tSelect 0...1:");
	scanf("%d", &opt[0]);
	printf("\tOption %d selected\n", opt[0]);
	
	printf("\n\n\tFind Option 2:\n0. Check all charachters\n1. ignore non-alphabet\n\tSelect 0...1:");
	scanf("%d", &opt[1]);	 
	printf("\tOption %d selected\n", opt[1]);

	printf("\n\n\tFind Option 3:\n0. substring\n1. prefix\n2. suffix\n3. exact pattern\n\tSelect 0...3:");
	scanf("%d", &opt[2]);
	printf("\tOption %d selected\n", opt[2]);
	
	printf("option selected: %d%d%d\n", opt[0],opt[1],opt[2]);
	
	char line[61], LINE[61];
	int i, j, z, n, count=0, u=0, v=0;
	
	printf("\t\tpattern:%s\n", pattern);
	
//_ _ 0 _____________________________________________________________________________________________________________________________________________________________
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

	// 0,0,0 =====================================================================================
	if((opt[0] == 0)&&(opt[1] == 0)&&(opt[2] == 0))
	{
		fprintf(out, "\tCase sensitive 000\n");
		fprintf(out, "\tAll characters 000\n");
		fprintf(out, "\tsubstring 000\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(line[i]=='\n')
				{
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if(line[u]==pattern[0])
				{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if(pattern[j]!=line[u+j])
						{
							printf("No match\n");
							break;
						}
					}
				}
			}
		}
	}
	
	// 1,0,0 ===============================================================================================
	if((opt[0] == 1)&&(opt[1] == 0)&&(opt[2] == 0))
	{
		fprintf(out, "\tCase insensitive 100\n");
		fprintf(out, "\tAll characters 100\n");
		fprintf(out, "\tsubstring 100\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(line[i]=='\n')
				{
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if((line[u]-'A'+'a'== pattern[0])||(line[u]-'a'+'A' == pattern[0])||(line[u] == pattern[0]))
				{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if((pattern[j]!=line[u+j]-'a'+'A')&&(pattern[j]!=line[u+j]-'A'+'a')&&(pattern[j]!=line[u+j]))
						{
							printf("No match\n");
							break;
						}
					}
				}
			}
		}
	}
	
	
	// 0,1,0 ====================================================================================
	if((opt[0] == 0)&&(opt[1] == 1)&&(opt[2] == 0))
	{
		fprintf(out, "\tCase sensitive 010\n");
		fprintf(out, "\tAlphabet only 010\n");
		fprintf(out, "\tsubstring 010\n");
	
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			v=0;
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(((line[i]>='a')&&(line[i]<='z'))||((line[i]>='A')&&(line[i]<='Z'))||(line[i]==' '))
				{
					LINE[v] = line[i];
					v++;
					continue;
				}
				if(line[i]=='\n')
				{
					LINE[v] = '\0';
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				v=0;
				if(LINE[u]==pattern[0])
				{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if(pattern[j]!=LINE[u+j])
						{
							printf("No match\n");
							break;
						}
					}
				}
			}
		}
	}
	
	// 1,1,0 =======================================================================================
	if((opt[0] == 1)&&(opt[1] == 1)&&(opt[2] == 0))
	{
		fprintf(out, "\tCase insensitive 110\n");

		fprintf(out, "\tAlphabet only 110\n");

		fprintf(out, "\tsubstring 110\n");

		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			v=0;
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(((line[i]>='a')&&(line[i]<='z'))||((line[i]>='A')&&(line[i]<='Z'))||(line[i]==' '))
				{
					LINE[v] = line[i];
					v++;
					continue;
				}
				if(line[i]=='\n')
				{
					LINE[v] = '\0';
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if((LINE[u]-'A'+'a'== pattern[0])||(LINE[u]-'a'+'A' == pattern[0])||(LINE[u] == pattern[0]))
				{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if((pattern[j]!=LINE[u+j]-'a'+'A')&&(pattern[j]!=LINE[u+j]-'A'+'a')&&(pattern[j]!=LINE[u+j]))
						{
							printf("No match\n");
							break;
						}
					}
				}
			}
		}
	}
	
//_ _ 1 _____________________________________________________________________________________________________________________________________________________________
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5

	// 0,0,1 =====================================================================================
	if((opt[0] == 0)&&(opt[1] == 0)&&(opt[2] == 1))
	{
		fprintf(out, "\tCase sensitive 001\n");

		fprintf(out, "\tAll characters 001\n");

		fprintf(out, "\tPrefix 001\n");
		
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(line[i]=='\n')
				{
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if(line[u]==pattern[0])
				{
					if(line[u-1]==' ')
					{	
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((line[u+j+1]==' ')||(line[u+j+1]=='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if(pattern[j]!=line[u+j])
						{
							printf("No match\n");
							break;
						}
					}
					}
				}
			}
		}
	}
	
	// 1,0,1 ===============================================================================================
	if((opt[0] == 1)&&(opt[1] == 0)&&(opt[2] == 1))
	{
		fprintf(out, "\tCase insensitive 101\n");
		fprintf(out, "\tAll characters 101\n");
		fprintf(out, "\tPrefix 101\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(line[i]=='\n')
				{
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if((line[u]-'A'+'a'== pattern[0])||(line[u]-'a'+'A' == pattern[0])||(line[u] == pattern[0]))
				{
					if(line[u-1]==' ')
					{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((line[u+j+1]==' ')||(line[u+j+1]=='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if((pattern[j]!=line[u+j]-'a'+'A')&&(pattern[j]!=line[u+j]-'A'+'a')&&(pattern[j]!=line[u+j]))
						{
							printf("No match\n");
							break;
						}
					}
					}
				}
			}
		}
	}
	
	
	// 0,1,1 ====================================================================================
	if((opt[0] == 0)&&(opt[1] == 1)&&(opt[2] == 1))
	{
		fprintf(out, "\tCase sensitive 010\n");
		fprintf(out, "\tAlphabet only 010\n");
		fprintf(out, "\tPrefix 011\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			v=0;
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(((line[i]>='a')&&(line[i]<='z'))||((line[i]>='A')&&(line[i]<='Z'))||(line[i]==' '))
				{
					LINE[v] = line[i];
					v++;
					continue;
				}
				if(line[i]=='\n')
				{
					LINE[v] = '\0';
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				v=0;
				if(LINE[u]==pattern[0])
				{
					if(line[u-1]==' ')
					{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((line[u+j+1]==' ')||(line[u+j+1]=='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if(pattern[j]!=LINE[u+j])
						{
							printf("No match\n");
							break;
						}
					}
					}
				}
			}
		}
	}
	
	// 1,1,1 =======================================================================================
	if((opt[0] == 1)&&(opt[1] == 1)&&(opt[2] == 1))
	{
		fprintf(out, "\tCase insensitive 110\n");
		fprintf(out, "\tAlphabet only 110\n");
		fprintf(out, "\tPrefix 111\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			v=0;
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(((LINE[i]>='a')&&(line[i]<='z'))||((LINE[i]>='A')&&(line[i]<='Z'))||(line[i]==' '))
				{
					LINE[v] = line[i];
					v++;
					continue;
				}
				if(line[i]=='\n')
				{
					LINE[v] = '\0';
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if((LINE[u]-'A'+'a'== pattern[0])||(LINE[u]-'a'+'A' == pattern[0])||(LINE[u] == pattern[0]))
				{
					if(LINE[u-1]==' ')
					{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((LINE[u+j+1]==' ')||(LINE[u+j+1]=='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if((pattern[j]!=LINE[u+j]-'a'+'A')&&(pattern[j]!=LINE[u+j]-'A'+'a')&&(pattern[j]!=LINE[u+j]))
						{
							printf("No match\n");
							break;
						}
					}
					}
				}
			}
		}
	}
	
//_ _ 2_____________________________________________________________________________________________________________________________________________________________
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


	// 0,0,2 =====================================================================================
	if((opt[0] == 0)&&(opt[1] == 0)&&(opt[2] == 2))
	{
		fprintf(out, "\tCase sensitive 002\n");

		fprintf(out, "\tAll characters 002\n");

		fprintf(out, "\tSuffix 002\n");

		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(line[i]=='\n')
				{
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if(line[u]==pattern[0])
				{
					if(line[u-1]!=' ')
					{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((line[u+j+1]!=' ')&&(line[u+j+1]!='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if(pattern[j]!=line[u+j])
						{
							printf("No match\n");
							break;
						}
					}
					}
				}
			}
		}
	}
	
	// 1,0,2 ===============================================================================================
	if((opt[0] == 1)&&(opt[1] == 0)&&(opt[2] == 2))
	{
		fprintf(out, "\tCase insensitive 102\n");
		
		fprintf(out, "\tAll characters 102\n");
		
		fprintf(out, "\tSuffix 102\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(line[i]=='\n')
				{
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if((line[u]-'A'+'a'== pattern[0])||(line[u]-'a'+'A' == pattern[0])||(line[u] == pattern[0]))
				{
					if(line[u-1]!=' ')
					{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((line[u+j+1]!=' ')&&(line[u+j+1]!='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if((pattern[j]!=line[u+j]-'a'+'A')&&(pattern[j]!=line[u+j]-'A'+'a')&&(pattern[j]!=line[u+j]))
						{
							printf("No match\n");
							break;
						}
					}
					}
				}
			}
		}
	}
	
	
	// 0,1,2 ====================================================================================
	if((opt[0] == 0)&&(opt[1] == 1)&&(opt[2] == 2))
	{
		fprintf(out, "\tCase sensitive 012\n");

		fprintf(out, "\tAlphabet only 012\n");

		fprintf(out, "\tSuffix 012\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			v=0;
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(((line[i]>='a')&&(line[i]<='z'))||((line[i]>='A')&&(line[i]<='Z'))||(line[i]==' '))
				{
					LINE[v] = line[i];
					v++;
					continue;
				}
				if(line[i]=='\n')
				{
					LINE[v] = '\0';
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				v=0;
				if(LINE[u]==pattern[0])
				{
					if(line[u-1]!=' ')
					{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((LINE[u+j+1]!=' ')&&(LINE[u+j+1]!='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if(pattern[j]!=LINE[u+j])
						{
							printf("No match\n");
							break;
						}
					}
					}
				}
			}
		}
	}
	
	// 1,1,2 =======================================================================================
	if((opt[0] == 1)&&(opt[1] == 1)&&(opt[2] == 2))
	{
		fprintf(out, "\tCase insensitive 110\n");
		
		fprintf(out, "\tAlphabet only 110\n");
		
		fprintf(out, "\tSuffix 112\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			v=0;
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(((line[i]>='a')&&(line[i]<='z'))||((line[i]>='A')&&(line[i]<='Z'))||(line[i]==' '))
				{
					LINE[v] = line[i];
					v++;
					continue;
				}
				if(line[i]=='\n')
				{
					LINE[v] = '\0';
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if((LINE[u]-'A'+'a'== pattern[0])||(LINE[u]-'a'+'A' == pattern[0])||(LINE[u] == pattern[0]))
				{
					if(line[u-1]!=' ')
					{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((LINE[u+j+1]!=' ')&&(LINE[u+j+1]!='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if((pattern[j]!=LINE[u+j]-'a'+'A')&&(pattern[j]!=LINE[u+j]-'A'+'a')&&(pattern[j]!=LINE[u+j]))
						{
							printf("No match\n");
							break;
						}
					}
					}
				}
			}
		}
	}
	
// _ _ 3 _____________________________________________________________________________________________________________________________________________________________
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

	// 0,0,3 =====================================================================================
	if((opt[0] == 0)&&(opt[1] == 0)&&(opt[2] == 3))
	{
		fprintf(out, "\tCase sensitive 003\n");

		fprintf(out, "\tAll characters 003\n");
		
		fprintf(out, "\texact 003\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(line[i]=='\n')
				{
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if(line[u]==pattern[0])
				{
					if(line[u-1]==' ')
					{	
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((line[u+j+1]!=' ')&&(line[u+j+1]!='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if(pattern[j]!=line[u+j])
						{
							printf("No match\n");
							break;
						}
					}
					}
				}
			}
		}
	}
	
	// 1,0,3 ===============================================================================================
	if((opt[0] == 1)&&(opt[1] == 0)&&(opt[2] == 3))
	{
		fprintf(out, "\tCase insensitive 103\n");
		
		fprintf(out, "\tAll characters 103\n");
		
		fprintf(out, "\texact 103\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(line[i]=='\n')
				{
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if((line[u]-'A'+'a'== pattern[0])||(line[u]-'a'+'A' == pattern[0])||(line[u] == pattern[0]))
				{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((line[u+j+1]!=' ')&&(line[u+j+1]!='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if((pattern[j]!=line[u+j]-'a'+'A')&&(pattern[j]!=line[u+j]-'A'+'a')&&(pattern[j]!=line[u+j]))
						{
							printf("No match\n");
							break;
						}
					}
				}
			}
		}
	}
	
	
	// 0,1,3 ====================================================================================
	if((opt[0] == 0)&&(opt[1] == 1)&&(opt[2] == 3))
	{
		fprintf(out, "\tCase sensitive 013\n");
		
		fprintf(out, "\tAlphabet only 013\n");
		
		fprintf(out, "\texact 013\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			v=0;
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(((line[i]>='a')&&(line[i]<='z'))||((line[i]>='A')&&(line[i]<='Z'))||(line[i]==' '))
				{
					LINE[v] = line[i];
					v++;
					continue;
				}
				if(line[i]=='\n')
				{
					LINE[v] = '\0';
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				v=0;
				if(LINE[u]==pattern[0])
				{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((LINE[u+j+1]!=' ')&&(LINE[u+j+1]!='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if(pattern[j]!=LINE[u+j])
						{
							printf("No match\n");
							break;
						}
					}
				}
			}
		}
	}
	
	// 1,1,3 =======================================================================================
	if((opt[0] == 1)&&(opt[1] == 1)&&(opt[2] == 3))
	{
		fprintf(out, "\tCase insensitive 113\n");
		
		fprintf(out, "\tAlphabet only 113\n");
		
		fprintf(out, "\texact 113\n");
		for(z=0; z<=100; z++)
		{
			count=0;
			if(fgets(line, sizeof(line), in) == NULL)
			{break;
			}
			v=0;
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(((line[i]>='a')&&(line[i]<='z'))||((line[i]>='A')&&(line[i]<='Z'))||(line[i]==' '))
				{
					LINE[v] = line[i];
					v++;
					continue;
				}
				if(line[i]=='\n')
				{
					LINE[v] = '\0';
					line[i] = '\0';
					break;
				}
			}
			
			for(u=0; u<=count; u++)
			{
				if((LINE[u]-'A'+'a'== pattern[0])||(LINE[u]-'a'+'A' == pattern[0])||(LINE[u] == pattern[0]))
				{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							if((LINE[u+j+1]!=' ')&&(LINE[u+j+1]!='\0'))
							{
							printf("No match\n");
							break;
							}
							printf("\tMatch found!\n");
							fprintf(out, "Line %d: %s\n", z, line);
							break;
						}
						if((pattern[j]!=LINE[u+j]-'a'+'A')&&(pattern[j]!=LINE[u+j]-'A'+'a')&&(pattern[j]!=LINE[u+j]))
						{
							printf("No match\n");
							break;
						}
					}
				}
			}
		}
	}
}
void Replace(FILE *in, char *pattern, char *replacement, FILE *out)
{
	// replace "pattern" in file "in" by "replacement
	// there are also options for replacement that user needs to choose
	// write the output to file "out"
	printf("\n*Inside Replace function*\n");
	
	int i=0, j=0, u=0, r=0, k=0, z=0, x=0, count=0, count2=0, l=0, m=0;
	char line[LINE_SIZE], linebak[100][LINE_SIZE];
	
	//Find Lenther of replacment
	count2=0;
	for(i=0; i<=SIZE; i++)
			{
				if(replacement[i]=='\0')
				{
					break;
				}
				count2++;
			}
	
	printf("Replacing %s with %s ...\n", pattern, replacement);
	
	//Replace
	for(z=0; z<=100; z++)
		{
			count=0;

			if(fgets(line, sizeof(line), in) == NULL)
			{
				break;
			}
			
			//get size of line
			for(i=0; i<=sizeof(line); i++)
			{
				count++;
				if(line[i]=='\n')
				{
					line[i] = '\0';
					break;
				}
			}
			//printf("\ncount:%d  count2:%d\n", count, count2);
			
			//make a backup line array
			printf("LB:");
			for(i=0; i<=count; i++)
			{
				linebak[z+1][i] = line[i];
				//printf("%c", linebak[z][i]);
				//printf("\t%c / %c\n", line[i], linebak[z][i]);
			}
			printf("%s", linebak[z+1]);
			printf("  --- Z=%d\n", z);
			//Find match then replace word and reprint remaining line
			m=0;
			for(u=0; u<=count; u++)
			{
				
				//printf("%c", line[u]);
				if(line[u]==pattern[0])
				{
					for(j=1; j<=SIZE; j++)
					{
						if(pattern[j]=='\0')
						{
							printf("\tMatch found!\n");
							m=1;
							r++;
							//l=0;
							//replace the word
							for(k=0; k<=SIZE; k++)
							{
								if(replacement[k] == '\0')
								{
									break;
								}
								line[k+u] = replacement[k];
								printf("%c", replacement[k]);
								//l++;
							}
							break;
						}
						if(pattern[j]!=line[u+j])
						{
							//printf("No match\n");
							break;
						}
					}
					if (m==1)
					{
						break;
					}
				}
				
				
				
			}
			printf("\n\tJ = %d; K = %d; Z = %d; U = %d\nCH:", j, k, z, u);
			//complete remaining line
				if(m==1)
				{
				for(x=u; x<=100; x++)
				{
					/*if(u+k >= LINE_SIZE)
					{
						break;
					}*/
					if (linebak[z+1][x+j] == '\0')
					{
						line[x+k] = linebak[z+1][x+j];
						break;
					}
					line[x+k] = linebak[z+1][x+j];
					//printf("%c", line[x+l]);
				}
				}
				
			//printf("%s\n*****\n", line);
			fprintf(out, "%s\n", line);
		}
		printf("Total of %d replacements.\n", r);
	}

