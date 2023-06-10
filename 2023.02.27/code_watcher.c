#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TYPES {
    ARGUMENT_ADDRESS, ARGUMENT_VALUE, CODE
};

enum STATUS {
    NORMAL, SKIPPING
};

enum RESULTS {
    EQUAL, NOT_EQUAL
};

struct Argument {
    char address[6];
    int value;  
};

void realize_operation(char *operation, char *arg_1, char *arg_2, int *registers, struct Argument *arguments);
struct Argument *search(struct Argument *arguments, char *address);

int status = NORMAL, result = 0, program_ended = 0;
char go_to_value[6] = {};

int main() {
    FILE *f = fopen("3.txt", "r");
    char current[6] = {};
    char code[100][6] = {""};
    struct Argument arguments[10] = {0};
    int type = ARGUMENT_ADDRESS, i = 0, j = 0, k = 0, t = 0;
    char sym = '0';
    int registers[4] = {0};

    while (fscanf(f, "%s", current) != EOF) {
        if (!strcmp(current, "code:")) {
            type = CODE;
            continue;
        }

        switch (type)
        {
            case ARGUMENT_ADDRESS:
                strcpy((arguments[i]).address, current);
                type = ARGUMENT_VALUE;
                break;

            case ARGUMENT_VALUE:
                (arguments[i++]).value = atoi(current);
                type = ARGUMENT_ADDRESS;
                break;
    
            case CODE:
                strcpy(code[j++], current);
                break;
        
            default:
                break;
        }
    }
    
    k = 0;

    sym = getchar();

    while (code[k] && (sym != 'q') && !program_ended) {
        if (!strcmp(go_to_value, code[k])) {
            status = NORMAL;
        }

        if (status == SKIPPING) {
            k += 4;
            continue;
        }

        printf("\n\n\n\n>>>\n\nAguments:\n\n");
        for (t = 0; t < i; t++) {
            printf("\t%s:\t%d\n", (arguments[t]).address, (arguments[t]).value);
        }

        printf("\nRegisters:\n\n");
        for (t = 0; t < 4; t++) {
            printf("\t%d:\t%d\n", t, registers[t]);
        }

        printf("\nPosition:\t%s\n", code[k]);
        printf("\nOperation:\t%s\t%s\t%s\t[", code[k + 1], code[k + 2], code[k + 3]);
        realize_operation(code[k + 1], code[k + 2], code[k + 3], registers, arguments);
        printf("]\n\n<<<\n\n");
        k += 4;

        sym = getchar();
    }

    fclose(f);

    return 0;
}

void realize_operation(char *operation, char *arg_1, char *arg_2, int *registers, struct Argument *arguments) {
    if (!strcmp(operation, "00")) {
        registers[atoi(arg_1)] = (search(arguments, arg_2))->value;
        return;
    }

    if (!strcmp(operation, "25")) {
        if (registers[atoi(arg_1)] == registers[atoi(arg_2)]) {
            printf("%d == %d", registers[atoi(arg_1)], registers[atoi(arg_2)]);
            result = EQUAL;
            return;
        }

        result = NOT_EQUAL;
        printf("%d != %d", registers[atoi(arg_1)], registers[atoi(arg_2)]);
        return;
    }

    if (!strcmp(operation, "81")) {
        printf("go to %s", arg_2);
        if (result == EQUAL)
            status = SKIPPING;
        strcpy(go_to_value, arg_2);
        return;
    }

    if (!strcmp(operation, "21")) {
        registers[atoi(arg_1)] = registers[atoi(arg_1)] + registers[atoi(arg_2)];
        return;
    }

    if (!strcmp(operation, "10")) {
        (search(arguments, arg_2))->value = registers[atoi(arg_1)];
        return;
    }

    if (!strcmp(operation, "99")) {
        program_ended = 1;
        printf("program ended");
        return;
    }

    return;
}

struct Argument *search(struct Argument *arguments, char *address) {
    struct Argument *current = arguments;

    while (strcmp(current->address, address)) {
        current++;
    }

    return current;
}
