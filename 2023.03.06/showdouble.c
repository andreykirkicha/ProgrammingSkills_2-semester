#include <stdio.h>

union number {
    char data[128];
    long double ldbl;
    double dbl;
    float flt;
} number;

int main() {
    char string[11];

    scanf("%[^\n]s", string);

    return 0;
}