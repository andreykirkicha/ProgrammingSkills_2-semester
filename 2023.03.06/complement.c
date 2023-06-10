#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *convert_to_bin(int number);
void get_complement(char *number);

int main() {
    int input_number = 0;

    scanf("%d", &input_number);

    printf("%s\n", convert_to_bin(input_number));

    return 0;
}

char *convert_to_bin(int number) {
    char *result = (char *)calloc(9, sizeof(char));
    int i = 0, flag = 0;
    
    for (i = 0; i < 8; i++) {
        result[i] = '0';
    }

    if (number < 0) {
        flag = 1;
    }

    i = 0;

    while (number != 0) {
        result[7 - i] = abs(number % 2) + '0';
        number /= 2;
        i++;
    }

    if (flag) {
        get_complement(result);
    }

    return result;
}

void get_complement(char *number) {
    int i = 0;

    for (i = 0; i < 8; i++) {
        if (number[i] == '0') {
            number[i] = '1';
        }
        else {
            number[i] = '0';
        }
    }

    i = 7;

    if (number[7] == '0') {
        number[7] = '1';
    }

    else {
        while (number[i] == '1') {
            number[i] = '0';
            i--;
        }

        number[i] = '1';
    }
}