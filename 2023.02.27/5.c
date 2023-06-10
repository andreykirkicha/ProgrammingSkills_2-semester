#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convert_octal(char **bin, char *input);

int main() {
    char input[100] = "";
    char *bin;

    printf("input value: ");
    scanf("%s", input);
    
    if (convert_octal(&bin, input))
        printf("RESULT: %s\n", bin);

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

    if (input_len > 100) {
        printf("ERROR: lenght is more than 100 symbols\n");
        return 0;
    }

    if (input[0] == '0' && input_len > 1) {
        printf("ERROR: number can't start with symbol \'0\'\n");
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