#include <stdio.h>
int sum_of_digit(int n)
{
    int r;
    int sum = 0;
    while (n != 0)
    {
        r = n % 10;    // separate first digit of a number
        sum = sum + r; // add the separated digit in the
        n = n / 10;    // delete first digit of a number
    }
    return sum;
}
int main()
{
    int num = 1234;
    int result = sum_of_digit(num);
    printf("Sum of digits in %d is %d\n", num, result);
    return 0;
}