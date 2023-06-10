#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hash_node {
    int key;
    char data[50];
    struct hash_node *next;
};

const int SIZE = 30;

int get_hash(int number);
void add_node(struct hash_node **table, const char *surname, int number);
void search(struct hash_node **table, int number);
void delete_node(struct hash_node **table, int number);
void print_table(struct hash_node *table);

int main() {
    int session_status = 1, choice, i, number;
    char surname[50];
    struct hash_node *table[SIZE];

    for (i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }

    while (session_status) {
        printf("\n>>>\nHASH MENU\n"
                "0 - abort session\n"
                "1 - search\n"
                "2 - add node\n"
                "3 - delete node\n"
                "4 - print table\n<<<\n");

        scanf("%d", &choice);
        switch(choice) {
            case 0:
                session_status = 0;
                printf("session aborted\n");
                break;

            case 1:
                printf("number:\t");
                scanf("%d", &number);
                search(table, number);
                break;

            case 2:
                printf("name:\t");
                scanf("%s", surname);
                printf("number:\t");
                scanf("%d", &number);
                add_node(table, surname, number);
                break;

            case 3:
                printf("number:\t");
                scanf("%d", &number);
                delete_node(table, number);
                break;

            case 4:
                for (i = 0; i < SIZE; i++) {
                    print_table(table[i]);
                }
                printf("table printed\n");
                break;
        
            default:
                break;
        }
    }

    return 0;
}

int get_hash(int number) {
    return number % SIZE;
}

void add_node(struct hash_node **table, const char *surname, int number) {
    int hash = get_hash(number);
    struct hash_node *new_node = (struct hash_node *)malloc(sizeof(struct hash_node));

    new_node->key = number;
    strcpy(new_node->data, surname);

    new_node->next = table[hash];
    table[hash] = new_node;

    printf("new node added: %s, %d\n", table[hash]->data, table[hash]->key);

    return;
}

void search(struct hash_node **table, int number) {
    int i, hash = get_hash(number);
    struct hash_node *current = table[hash];

    if (current == NULL) {
        printf("couldn't find node\n");
        return;    
    }
    
    while (current != NULL) {
        if (current->key == number) {
            printf("%s: %d\n", current->data, current->key);
            printf("search completed\n");
            return;
        }
        current = current->next;
    }

    printf("couldn't find node\n");
    
    return;
}

void print_table(struct hash_node *table) {
    struct hash_node *current = table;

    while (current != NULL) {
        printf("%s: %d\n", current->data, current->key);    
        current = current->next;
    }

    return;
}

void delete_node(struct hash_node **table, int number) {
    int hash = get_hash(number);
    
    if (table[hash] == NULL) {
        printf("couldn't find required number\n");
        return;
    }

    struct hash_node *current = table[hash];

    if (current->key == number) {
        struct hash_node *tmp = current;
        table[hash] = current->next;
        free(tmp);
        return;
    }

    while (current->next != NULL && current->next->key != number) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("couldn't find required number\n");
        return;
    }

    struct hash_node *tmp = current->next;
    current->next = current->next->next;
    free(tmp);

    return;
}
