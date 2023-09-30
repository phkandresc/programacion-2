#include <stdio.h>

#define MAXLINE 1000
int get_line(char line[], int maxline);
void copy(char to[], char from[]);


int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("Se ingresa una palabra\n");
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
    {
        printf("%s", longest);
    }
    return 0;
}

int get_line(char line[], int maxline)
{
    int c, i;
    /*

    */

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
        //if (c == '\n')
        //{
        //    printf("salto de linea\n");
        //    line[i] = c;
        //    i++;
        //}
    }
    line[i] = '\0'; //'\0' marca el fin de una cadena de caracteres
    printf("valor de i: %d\n", i);
    return i;
}

void copy(char to[], char from[]){
    int i;

    i=0;
    while((to[i] = from[i]) != '\0'){
        i++;
    }
}
