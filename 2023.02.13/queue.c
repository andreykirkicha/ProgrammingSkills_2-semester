#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue *Q = NULL;

void print_queue();
void add_to_rear(Item value);

int main()
{   
    int session_status = 1, choice, value;

    while (session_status) {
        printf("\n>>>\nQUEUE MENU\n"
                "0 - abort session\n"
                "1 - print queue\n<<<\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 0:
            session_status = 0;
            printf("session aborted\n");
            break;

        case 1:
            print_queue();
            printf("queue printed\n");
            break;

        case 2:
            scanf("%d", &value);
            add_to_rear()
        
        default:
            break;
        }
    }
    
    return 0;
}

void print_queue() {
    Node *current;
    current = Q->front;

	while (current != NULL) {
	    printf("| %d |", current->elem);
	    current = current->next;
    }

    printf("\n");
}

void add_to_rear(Item value) {
    Node *current = Q;

    while (current->next != NULL)
        current = current->next;

    List *new_element = (List *)malloc(sizeof(List));
    new_element->elem = elem;
    new_element->next = NULL;
    current->next = new_element;

    return;
}
