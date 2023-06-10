#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int elem;
    struct stack *next;
} Stack;

Stack *top = NULL;

void print_stack();
int is_empty();
void push(int value);
void pop(int *value);
void print_top_value();
int elements_count();
void *delete_stack();

int main()
{
    int session_status = 1, value, choice, popped = 0;

    while (session_status) {
        printf("\n>>>\nSTACK MENU\n"
                "0 - abort session\n"
                "1 - print stack\n"
                "2 - push\n"
                "3 - pop\n"
                "4 - print top value\n"
                "5 - count elements\n"
                "6 - delete stack\n<<<\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 0:
            session_status = 0;
            printf("session aborted\n");
            break;

        case 1:
            print_stack();
            printf("stack printed\n");
            break;
        
        case 2:
            scanf("%d", &value);
            push(value);
            printf("new element pushed\n");
            break;

        case 3:
            pop(&popped);
            break;

        case 4:
            print_top_value();
            break;

        case 5:
            printf("%d\n", elements_count());
            printf("elements counted\n");
            break;

        case 6:
            delete_stack();
            printf("stack deleted\n");
            break;

        default:
            break;
        }
    }
    
    return 0;
}

void print_stack() {
    Stack *current;
    current = top;

	while (current != NULL) {
	    printf("| %d |", current->elem);
	    current = current->next;
    }

    printf("\n");
}

int is_empty() {
    return top == NULL;
}

void push(int value) {
    Stack *s;

    s = (Stack *)malloc(sizeof(Stack));
    s->elem = value;
    s->next = top;
    top = s;

    return;
}

void pop(int *value) {
    if (is_empty()) {
        printf("stack is empty\n");
        return;
    }

    Stack *s;
    s = top;
    *value = top->elem;
    top = top->next;
    free(s);
    
    printf("element | %d | popped\n", *value);

    return;
}

void print_top_value() {
    if (is_empty()) {
        printf("stack is empty\n");
        return;
    }

    printf("| %d |\n", top->elem);
    printf("top value printed\n");
    
    return;
}

int elements_count() {
    Stack *current;
    current = top;
    int counter = 0;

    if (is_empty())
        return 0;

	while (current != NULL) {
	    current = current->next;
        counter++;
    }

    return counter;
}

void *delete_stack() {
    int value = 0;

    while (top != NULL)
        pop(&value);
    
    return top;
}
