#ifdef _WIN32
#include <windows.h>    // for win32 API functions
#include <io.h>         // for _get_osfhandle()
#else
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
#endif
#include <unistd.h>     // for isatty()
#endif
#include<stdlib.h>		

#include<stdio.h>		/* Has the information for all input, output related functions 
						   eg: printf, scanf, */
#include<string.h>		/* Has the information for all string manipulation functions
						   eg: strcmp(), strcpy() */

struct phone			// Struct phone refers to indivual contact's datas
{
	char name[100];		// name array for contact's name can hold up to 100 characters
	char num[100];		// num array for contact's phone number can hold up to 100 characters
	
}p[100];				// p array refers to 100 spaces for individual contact's data

// use an enum for platform-independent interface:
typedef enum TextColor
{
    TC_BLACK = 0,
    TC_BLUE = 1,
    TC_GREEN = 2,
    TC_CYAN = 3,
    TC_RED = 4,
    TC_MAGENTA = 5,
    TC_BROWN = 6,
    TC_LIGHTGRAY = 7,
    TC_DARKGRAY = 8,
    TC_LIGHTBLUE = 9,
    TC_LIGHTGREEN = 10,
    TC_LIGHTCYAN = 11,
    TC_LIGHTRED = 12,
    TC_LIGHTMAGENTA = 13,
    TC_YELLOW = 14,
    TC_WHITE = 15
} TextColor;

// set output color on the given stream:
void setTextColor(FILE *stream, TextColor color);

int main(void)					// main function: Starting point of program execution
{
    char name,num;				// C uses char type to store characters and letters
	void insert(int);
	void deleteinfo(int);		// void is used as a function return type, it indicates the
	void search(int);			// function does not return a value. When void appears in a
	void Namesort(int);			// pointer declaration, that pointer is universal 
	void display(int);										
										
	int choice, i=0;		// choice is to store an integer value for variable choice
							// i is declared as 0
    do
    {	setTextColor(stdout, TC_LIGHTMAGENTA);
    	printf("\n\n\t=======================================================");
		setTextColor(stdout, TC_WHITE);
    	printf(" \n\t Welcome to telephone directory for a cellular service\n");
		setTextColor(stdout, TC_LIGHTMAGENTA);
    	printf("\t=======================================================");
    	setTextColor(stdout, TC_BROWN);
    	printf("\n\t Menu : ");
    	setTextColor(stdout, TC_WHITE);
    	printf("\n\t\t1 Add new contact\n\t\t2 Delete specific contact via name");
		printf("\n\t\t3 Search contact\n\t\t4 Sort all existing contact");
		printf("\n\t\t5 Display all the contact\n\t\t6 Exit\n");
    	setTextColor(stdout, TC_LIGHTMAGENTA);
    	printf("\t=======================================================\n\n");
        printf("\t-------------------------------------------------------\n");
        setTextColor(stdout, TC_LIGHTCYAN);
        printf("\t\t******************\n");
		printf("\t\t* Enter Choice:  ");
        scanf("%d", &choice);
        printf("\t\t******************\n");
        setTextColor(stdout, TC_LIGHTMAGENTA);
        printf("\t-------------------------------------------------------\n\n");
        setTextColor(stdout, TC_YELLOW);
        
		switch (choice)			// For users to choose which action by entering 1 - 6 as choice 
        {	case 1:			// 1: Goes to insert function to insert new contact info
            	insert(i);
            	i=i+1;				// i: Is increased by 1 to prepare for next possible insertion
                break;					// Break out from choosen case
            case 2:			// 2: Goes to deleteinfo function to delete specific contact info
            	deleteinfo(i);   
            	i=i-1;				// i: Is decreased by 1 as 1 contact info has been deleted
				display(i);  		// shows latest contact list after deletion
				break;					// Break out from choosen case
            case 3:			// 3: Goes to search function to search for specific contact info
            	search(i);
            	break;					// Break out from choosen case
            case 4:			/* 4:	Goes to Namesort function to sort existing contact list
									in alphabetical order */
				Namesort(i);
            	display(i);			// Shows latest contact list after sorting
            	break;					// Break out from choosen case
			case 5:					// 5: Goes to display function to show latest contact list
            	display(i);
            	break;					// Break out from choosen case
            case 6:			/* 6: 	Exit the program by falsify the test expression of 
									do...while body then proceed to return 0 */
            	exit(1);
            	break;					// Break out from choosen case
        }
    } while (choice != 6); 			/*	Test expression only evaluated after body of do...while 
										loop is executed once. True test expression execute
    									the body of loop again until test expression is false */
}

#ifdef _WIN32
void setTextColor(FILE *stream, TextColor color)
{	int outfd = fileno(stream);
    HANDLE out = (HANDLE)_get_osfhandle(outfd);
    DWORD outType = GetFileType(out);
    DWORD mode;
    if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
    {	// we're directly outputting to a win32 console if the file type
        // is FILE_TYPE_CHAR and GetConsoleMode() returns success
		SetConsoleTextAttribute(out, color);
        // the enum constants are defined to the same values
        // SetConsoleTextAttribute() uses, so just pass on.
    }
}
#else
static const char *ansiColorSequences[] =
{	"\x1B[0;30m",
    "\x1B[0;34m",
    "\x1B[0;32m",
    "\x1B[0;36m",
    "\x1B[0;31m",
    "\x1B[0;35m",
    "\x1B[0;33m",
    "\x1B[0;37m",
    "\x1B[1;30m",
    "\x1B[1;34m",
    "\x1B[1;32m",
    "\x1B[1;36m",
    "\x1B[1;31m",
    "\x1B[1;35m",
    "\x1B[1;33m",
    "\x1B[1;37m"
};
static const char *ansiColorTerms[] =
{	"xterm",
    "rxvt",
    "vt100",
    "linux",
    "screen",
    0		// there are probably missing a few others
};
// get current terminal and check whether it's in our list of terminals
// supporting ANSI colors:
static int isAnsiColorTerm(void)
{	char *term = getenv("TERM");
    for (const char **ansiTerm = &ansiColorTerms[0]; *ansiTerm; ++ansiTerm)
    {
        int match = 1;
        const char *t = term;
        const char *a = *ansiTerm;
        while (*a && *t)
        {
            if (*a++ != *t++)
            {match = 0;
                break;}
        }
        if (match) return 1;
    }
    return 0;}
void setTextColor(FILE *stream, TextColor color)
{	int outfd = fileno(stream);
    if (isatty(outfd) && isAnsiColorTerm())
    {
        // we're directly outputting to a terminal supporting ANSI colors,
        // so send the appropriate sequence:
        fputs(ansiColorSequences[color], stream);
    }
}
#endif

void insert(int i)						// insert function to register new contact info
										// int i refers to current number of existing contacts
{
	int j;
	char tempName[100], tempNum[100];	// tempName and tempNum act as temporary register for new contact info
	
	if(i<100)							// if existing contact is less than 100, proceed to if body
	{
		setTextColor(stdout, TC_YELLOW);
	    printf("\t Enter name: ");
        scanf("%s", &tempName);
        printf("\t Enter phone number: ");
        scanf("%s", &tempNum);
        for(j=0;j<i;j++)				// for loop using increment of j to call each existing contact info
        {
        	setTextColor(stdout, TC_RED);
        	if(strcmp(p[j].name,tempName)==0)		/*	String compare(strcmp) if any existing
														contact name is the same with
														tempName, proceed into if body */
        	{
				setTextColor(stdout, TC_WHITE);
   			 	printf("\n\t  < This name ");
				setTextColor(stdout, TC_RED);
				printf("already exist ");
				setTextColor(stdout, TC_WHITE);
				printf("in the contact >");
				printf("\n\t    *  Please Enter another contact info  *\n\n");
				return insert(i);		// return into insert function to register another name
			}
			else if(strcmp(p[j].num,tempNum)==0)	/*	String compare(strcmp) if any existing
														contact phone number is the same
														with tempNum, proceed into if body */
			{
				setTextColor(stdout, TC_WHITE);
    			printf("\n\t  < This number ");
				setTextColor(stdout, TC_RED);
				printf("already exist ");
				setTextColor(stdout, TC_WHITE);
				printf("in the contact >");
				printf("\n\t    *  Please Enter another contact info  *\n\n");
				return insert(i);		// return into insert function to register another number
			}
	    }
	    strcpy(p[i].name, tempName);	// Successfully exited for loop means no same cantact info
		strcpy(p[i].num, tempNum);		/*	Proceed to register new contact info 
											into array using string copy(strcpy) */
	    									 
		return;							// return to main function
    }
}

void deleteinfo(int i)					// deleteinfo function to delete specific contact info
{										// int i refers to current number of existing contacts
    int j, n;
    char tmp[100];						// tmp act as temporary register for deleting contact info 
    
	setTextColor(stdout, TC_YELLOW);
    printf("\tEnter contact name or phone number you want to ");
    setTextColor(stdout, TC_LIGHTRED);
    printf("delete");
    setTextColor(stdout, TC_YELLOW);
    printf(": ");
    scanf("%s",&tmp);		// Enter contact name or phone number desired to be deleted
    
	for(j=0;j<i;j++)		// for loop using increment of j to call each existing contact info
	{
		if(strcmp(p[j].name,tmp)==0 || strcmp(p[j].num,tmp)==0)
// String compare(strcmp) if any existing contact info is the same with tmp, proceed into if body
		{
			setTextColor(stdout, TC_WHITE);
    		printf("\n\t _________Successfully deleted_________ ");
    		printf("\n\t|                                      |");
    		printf("\n\t|          Name  : %-10s          |",p[j].name);
    		printf("\n\t|          Number: %-10s          |",p[j].num);
    		printf("\n\t|                                      |");
    		printf("\n\t --------------------------------------\n\n");
    		
        	strcpy(p[j].name, p[j + 1].name);
        	strcpy(p[j].num, p[j + 1].num);		/*	String copy(strcpy) replaces selected contact 
        											info [j] with next contact info [j+1] */
        											
			for(n=j+1;n<i;n++)			// n refers to +1 of selected contact info
			{							// Goes through each contact info after the deleted one
				strcpy(p[n].name, p[n + 1].name);
        		strcpy(p[n].num, p[n + 1].num);
				// Replaces n contact info into the next one and so on
			}
    	return;		// return to main function
		}
    }
    // Exited from for loop means selected contact info does not exist
    
    setTextColor(stdout, TC_WHITE);
    printf("\n\t< This contact info ");
	setTextColor(stdout, TC_RED);
	printf("does not exist ");
	setTextColor(stdout, TC_WHITE);
	printf("in the contact >");
	printf("\n\t     *   Please Enter another contact info   *\n\n");
	return deleteinfo(i);					// return into deleteinfo function to enter another 
}											// contact info to be deleted

void search(int i)					// search function to search specific contact info
									// int i refers to current number of existing contacts
{
	char search[100];				// search act as temporary register for searching contact name
	int j;
	
	setTextColor(stdout, TC_YELLOW);
    printf("\tEnter contact name you want to ");
    setTextColor(stdout, TC_LIGHTCYAN);
    printf("search");
    setTextColor(stdout, TC_YELLOW);
    printf(": ");
	scanf("%s", &search);		// Enter contact name to search
	
	for(j=0;j<i;j++)			// for loop using increment of j to call each existing contact info
	{
		if(strcmp(p[j].name,search)==0)		/*	string compare(strcmp) if any existing contact info
												is the same with search, proceed into if body */
		{
			printf("\n\tName: %s", p[j].name);
			printf("\n\tPhone number: %s\n", p[j].num);
											// Print out selected contact info
			return;							// return to main function
		}
	}
	// Exited from for loop means selected contact info is not found
	
	setTextColor(stdout, TC_WHITE);
    printf("\n\t< This name is ");
	setTextColor(stdout, TC_RED);
	printf("not found ");
	setTextColor(stdout, TC_WHITE);
	printf("in the contact >");
}

void Namesort(int i)			// Namesort function to sort contact info in alphabetical order
								// int i refers to current number of existing contacts
{	
	int n, j;
	char tempName[100], tempNum[100];		// tempName and tempNum act as temporary register
	
    for(n = 0; n < i - 1 ; n++)				/*	Nested for loop. n refers to earlier contact
    											name to be compared with next contact name */
    {
        for(j = n + 1; j < i; j++)			// j refers to the next of n until last contact name
        {
            if(strcmp(p[n].name, p[j].name)>0)	/*	String compare(strcmp)(a<z) if name in [n]
													has higher value of character than name in
													[j], proceed into if body */
            {
                strcpy(tempName, p[n].name);	// name in [n] is registered into tempName
                strcpy(p[n].name, p[j].name);	// name in [j] is registered into [n]
                strcpy(p[j].name, tempName);	// name in tempName is registered into [j]
                								
                strcpy(tempNum, p[n].num);	// phone number in [n] is registered into tempNum
                strcpy(p[n].num, p[j].num);	// phone number in [j] is registered into [n]
                strcpy(p[j].num, tempNum);	// phone number in tempNum is registered into [j]
            }
        }						// Exited from for loop means all earlier contact name has
	}							// smaller character value to the next contact name and so on
	
	return;						// return to main function
}

void display(int i)						// display function to show latest contact list
										// int i refers to current number of existing contacts
{
	int n;
	setTextColor(stdout, TC_WHITE);
	printf("\n\tLatest list of the contact\n");
	printf("\n\tName\t\t\tPhone number\n");
	printf("\t---------------------------------------\n");
	
	for(n=0;n<i;n++)		// for loop using increment of n to call each existing contact info
	{
	    printf("\t%-15s\t\t%-15s\n", p[n].name, p[n].num);	// Print out all contact info
    }
    printf("\t---------------------------------------\n");
    return;													// return to main function
}
