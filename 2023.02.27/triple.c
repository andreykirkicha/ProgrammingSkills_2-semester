#include <stdio.h>
#include <string.h>
#include <math.h>

int convert_triple(char *input);

int main() {
    char input[7] = "";
    
    printf("input value: ");
    scanf("%s", input);
    
    printf("%d\n", convert_triple(input));

    return 0;
}

int convert_triple(char *input) {
    int input_len = strlen(input), i, result = 0;
    
    for (i = 0; i < input_len; i++) {
        result += (int)(input[input_len - 1 - i] - '0') * (int)pow(3, i);
    }

    return result;
}
