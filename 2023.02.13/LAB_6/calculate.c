#include <stdio.h>
#include <ctype.h>
#include <math.h>

#include "stack.h"
#include "calculate.h"

void calculating_value(struct Node_int **top) {
    FILE *in_file = fopen("postfix_notation.txt", "r");
    FILE *out_file = fopen("rez.dat", "w");
    char sym = 0;
    int a = 0, b = 0;

    while ((sym = getc(in_file)) != EOF) {
        if (isdigit(sym))
            push_int(top, sym - '0');

        else {
            switch (sym) {                
                case '+':
                    b = pop_int(top);
                    a = pop_int(top);
                    push_int(top, a + b);
                    break;

                case '-':
                    b = pop_int(top);
                    a = pop_int(top);
                    push_int(top, a - b);
                    break;

                case '*':
                    b = pop_int(top);
                    a = pop_int(top);
                    push_int(top, a * b);
                    break;

                case '/':
                    b = pop_int(top);
                    a = pop_int(top);
                    push_int(top, a / b);
                    break;

                case '^':
                    b = pop_int(top);
                    a = pop_int(top);
                    push_int(top, pow(a, b));
                    break;

                case '\n':
                    fprintf(out_file, "%d\n", pop_int(top));
                    break;
            
                default:
                    printf("ERROR: unknown symbol: %c\n", sym);
                    break;
            }
        }
    }

    fclose(in_file);
    fclose(out_file);
}
