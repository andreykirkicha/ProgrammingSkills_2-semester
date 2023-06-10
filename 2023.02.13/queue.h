typedef int Item;
typedef struct node {
    Item elem;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
    int items;
} Queue;
