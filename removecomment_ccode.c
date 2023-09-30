/**
 Tuesday, 10/07/2013

 Exercise 1.23
 Write a program to remove all comments from a C 
 program. Don't forget to handle quoted strings 
 and character constants properly. C comments   
 don't nest.
**/

#include <stdio.h>
#define MAX_LENGTH 65536
#define NOT_IN_COMMENT 0
#define SINGLE_COMMENT 1
#define MULTI_COMMENT  2

int main()
{
    char code[MAX_LENGTH];        /* Buffer that stores the inputted code */
    int size = 0;                 /* Length of the inputted code */
    int loop;                     /* Integer used for the for loop */
    char c;                       /* Character to input into */
    int status = NOT_IN_COMMENT;  /* Are we in a comment? What type? */
    int in_string = 0;            /* Are we inside of a string constant? */
    char last_character;          /* Value of the last character */


    /* Input all code into the buffer until escape sequence pressed */
    while ((c = getchar()) != EOF)
        code[size++] = c; 
    code[size] = '\0'; 


    /* Remove all comments from the code and display results to user */
    for (loop = 0; loop < size; loop++) {
        char current = code[loop]; 

        if (in_string) {
            if (current == '"') in_string = 0; 
            putchar(current);
        }

        else {
            if (status == NOT_IN_COMMENT) {
                if (current == '"') {
                    putchar(current);
                    in_string = 1; 
                    continue; 
                }

                if (current == '/' && last_character == '/') status = SINGLE_COMMENT;
                else if (current == '*' && last_character == '/') status = MULTI_COMMENT; 
                else if (current != '/' || (current == '/' && loop < size-1 && !(code[loop+1] == '/' || code[loop+1] == '*'))) putchar(current); 
            }

            else if (status == SINGLE_COMMENT) {
                if (current == '\n') {
                    status = NOT_IN_COMMENT; 
                    putchar('\n');
                }
            }

            else if (status == MULTI_COMMENT) {
                if (current == '/' && last_character == '*') status = NOT_IN_COMMENT; 
            }
        }

        last_character = current; 
    }
}