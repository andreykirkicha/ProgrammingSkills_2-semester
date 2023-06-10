#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void convert_to_hex(char *bin, char **hex);

int main() {
    char bin[8] = {'0'};
    char *str = (char *)malloc(30 * sizeof(char));
    char buffer[12][3];
    char **hex;
    int i = 0, k = 0, j = 0;

    fgets(str, 30, stdin);
    printf("%s\n", str);

    while (str[i] != '\0') {
        if (j < 2) {
            buffer[k][j++] = str[i];
        }
        else {
            buffer[k][j] = '\0';
            j = 0, k++;
        }
        i++;
    }

    for (j = 0; j < k + 1; j++) {
        if (!strcmp(buffer[j], "ma"))
            bin[7] = '1';
        if (!strcmp(buffer[j], "fe"))
            bin[7] = '0';
        if (!strcmp(buffer[j], "cl"))
            bin[6] = '1';
        if (!strcmp(buffer[j], "du"))
            bin[6] = '0';
        if (!strcmp(buffer[j], "ha"))
            bin[5] = '1';
        if (!strcmp(buffer[j], "nh"))
            bin[5] = '0';
        if (!strcmp(buffer[j], "tr"))
            bin[4] = '1';
        if (!strcmp(buffer[j], "sk"))
            bin[4] = '0';
        if (!strcmp(buffer[j], "bn")) {
            bin[3] = '0';
            bin[2] = '0';
        }
        if (!strcmp(buffer[j], "rd")) {
            bin[3] = '0';
            bin[2] = '1';
        }
        if (!strcmp(buffer[j], "bw")) {
            bin[3] = '1';
            bin[2] = '0';
        }
        if (!strcmp(buffer[j], "bk")) {
            bin[3] = '1';
            bin[2] = '1';
        }
        if (!strcmp(buffer[j], "bu")) {
            bin[1] = '0';
            bin[0] = '0';
        }
        if (!strcmp(buffer[j], "ge")) {
            bin[1] = '0';
            bin[0] = '1';
        }
        if (!strcmp(buffer[j], "gy")) {
            bin[1] = '1';
            bin[0] = '0';
        }
        if (!strcmp(buffer[j], "da")) {
            bin[1] = '1';
            bin[0] = '1';
        }
    }

    convert_to_hex(bin, hex);
    
    return 0;
}

void convert_to_hex(char *bin, char **hex) {
    *hex = (char *)calloc(2, sizeof(char));
    int k = 0;
    int res[2] = {0};
    
    while (k < 2) {
        for (int i = 1; i <= 4; i++) {
            printf("%c\n", bin[4 - i]);
            if (bin[4 - i] == '1') {
                res[k] += pow(2, i - 1);
            }
        }
        k++;
    }
    
    printf("%d %d\n", res[0], res[1]);
}