#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
    printf("Rango de int: %d a %d\n", INT_MIN, INT_MAX);
    printf("Rango de float: %e a %e\n", FLT_MIN, FLT_MAX);
    printf("Rango de double: %e a %e\n", DBL_MIN, DBL_MAX);
    printf("Rango de long double: %Le a %Le\n", LDBL_MIN, LDBL_MAX);
    printf("Rango de caracteres: %u a %u\n", 0, UCHAR_MAX); //rango unsigned char
    return 0;
}
