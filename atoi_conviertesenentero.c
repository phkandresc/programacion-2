#include <stdio.h>
int atoi(char s[]);
void get_line(char s[], int maxline);

int main()
{
    char s[10] = {'0', '2', '0', '0', '5'};
    printf("Numero en entero int %i\n", atoi(s));
}

int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}