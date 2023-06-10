#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int convert_octal(char **bin, char *input);

int main() {
    char oct[3] = {};
    char *bin;
    char *letters[3] = {"r", "w", "x"};

    scanf("%s", oct);
    convert_octal(&bin, oct);
    printf("%s\n", bin);

    for (int i = 0; i < 9; i++) {
        if ((int)(bin[i] - '0')) {
            printf("%s", letters[i % 3]);
        }
        else {
            printf("-");
        }
    }
    
    printf("\n");

    return 0;
}

int convert_octal(char **bin, char *input) {
    int input_len = strlen(input), i;
    char *triads[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    *bin = (char *)calloc(3 * input_len, sizeof(char));

    if (!input) {
        printf("ERROR: empty string\n");
        return 0;
    }

    for (i = 0; i < input_len; i++) {
        if (input[i] < '0' || input[i] > '7') {
            printf("ERROR: incorrect symbol in number\n");
            return 0;
        }
    }

    for (i = 0; i < input_len; i++) {
        strcpy(*bin, triads[(int)(input[i] - '0')]);
        *bin += 3;
    }

    for (i = 0; i < input_len; i++) {
        *bin -= 3;
    }

    return 1;
}