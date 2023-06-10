#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int elem;
    struct list *next;
} List;

void print_list(List *head);
List *add_to_head(List *head, int elem);
void add_to_tail(List *head, int elem);
void add_after(List *head, int elem, int new_elem);
List *remove_head(List *head);
void remove_tail(List *head);
void remove_element(List *head, int elem);
void print_list_to_file(List *head, char *file_name);
List *delete_list(List *head);

int main()
{
    List *head = NULL, *current, *prev;
    int i, session_status = 1, choice, element, new_element;
    char file_name[10];

    for (i = 0; i < 10; i++) {
        current = (List *)malloc(sizeof(List));

        if (head == NULL)
            head = current;
        else
            prev->next = current;

        scanf("%d", &(current->elem));
        current->next = NULL;
        prev = current;
    }

    while (session_status) {
        printf("\n>>>\nLIST MENU\n"
                "0 - abort session\n"
                "1 - print list\n"
                "2 - add to head\n"
                "3 - add to tail\n"
                "4 - add after element\n"
                "5 - remove head\n"
                "6 - remove tail\n"\
                "7 - remove element\n"
                "8 - print list to file\n"
                "9 - delete list\n<<<\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 0:
            session_status = 0;
            printf("session aborted\n");
            break;

        case 1:
            print_list(head);
            printf("list printed\n");
            break;
        
        case 2:
            scanf("%d", &new_element);
            head = add_to_head(head, new_element);
            printf("new element added to head\n");
            break;

        case 3:
            scanf("%d", &new_element);
            add_to_tail(head, new_element);
            printf("new element added to tail\n");
            break;

        case 4:
            printf("element in list: ");
            scanf("%d", &element);
            printf("new element: ");
            scanf("%d", &new_element);
            add_after(head, element, new_element);
            printf("new element added after element: | %d |\n", element);
            break;
        
        case 5:
            head = remove_head(head);
            printf("head element removed\n");
            break;

        case 6:
            remove_tail(head);
            printf("tail element removed\n");
            break;

        case 7:
            printf("element in list: ");
            scanf("%d", &element);
            remove_element(head, element);
            printf("element removed\n");
            break;

        case 8:
            printf("file name: ");
            scanf("%s", file_name);
            print_list_to_file(head, file_name);
            printf("list printed to file\n");
            break;

        case 9:
            head = delete_list(head);
            printf("list deleted\n");
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}

void print_list(List *head) {
    List *current;
    current = head;

	while (current != NULL) {
	    printf("| %d |", current->elem);
	    current = current->next;
    }

    printf("\n");
}

List *add_to_head(List *head, int elem) {
    List *new_element = (List *)malloc(sizeof(List));

    new_element->elem = elem;
    new_element->next = head;
    
    return new_element;
}

void add_to_tail(List *head, int elem) {
    List *current = head;

    while (current->next != NULL)
        current = current->next;

    List *new_element = (List *)malloc(sizeof(List));
    new_element->elem = elem;
    new_element->next = NULL;
    current->next = new_element;
}

void add_after(List *head, int elem, int new_elem) {
    List *current = head;

    while (current->elem != elem)
    {
        if (current->next == NULL)
        {
            printf("couldn't find element: | %d |\n", elem);
            return;
        }
        current = current->next;
    }

    List *new_element = (List *)malloc(sizeof(List));
    new_element->elem = new_elem;
    new_element->next = current->next;
    current->next = new_element;
}

List *remove_head(List *head) {
    List *current = head;
    head = head->next;
    free(current);

    return head;
}

void remove_tail(List *head) {
    List *current = head;
    
    while (current->next->next != NULL)
        current = current->next;

    free(current->next);
    current->next = NULL;
}

void remove_element(List *head, int elem) {
    List *current = head;

    while (current->next->elem != elem)
    {
        if (current->next->next == NULL)
        {
            printf("couldn't find element: | %d |\n", elem);
            return;
        }
        current = current->next;   
    }

    List *tmp = current->next->next;
    free(current->next);
    current->next = tmp;
} 

void print_list_to_file(List *head, char *file_name) {
    FILE *f = fopen(file_name, "w");
    List *current = head;
    
    while (current != NULL)
    {
        fprintf(f, "| %d |", current->elem);
        current = current->next;
    }

    fclose(f);
}

List *delete_list(List *head) {
    while (head != NULL)
        head = remove_head(head);
    
    return head;
}
