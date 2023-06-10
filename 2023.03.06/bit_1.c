#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int convert_hex(char **bin, char *input);

int main(int argc, char **argv) {
    char *bin;

    convert_hex(&bin, argv[1]);

    int sex = (int)(bin[strlen(bin) - 1] - '0');

    if (sex) {
        printf("ma\n");
    }

    else {
        printf("fe\n");
    }
    
    return 0;
}

int convert_hex(char **bin, char *input) {
    int input_len = strlen(input), i;
    char *quartets[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    *bin = (char *)calloc(4 * input_len, sizeof(char));

    for (i = 0; i < input_len; i++) {
        if (!isalpha(input[i])) {
            strcpy(*bin, quartets[(int)(input[i] - '0')]);
        }
        else {
            strcpy(*bin, quartets[(int)(input[i] - 'a' + 10)]);
        }
        *bin += 4;
    }

    for (i = 0; i < input_len; i++) {
        *bin -= 4;
    }

    return 1;
}