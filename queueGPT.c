#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct {
    Node* front; // inizio della coda (primo elemento)
    Node* rear;  // fine della coda (ultimo elemento)
} Queue;

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void printQueue(Queue* q) {
    Node* curr = q->front;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void enqueue(Queue* q, int num) {
    Node* node = malloc(sizeof(Node));
    node->value = num;
    node->next = NULL;

    if (isEmpty(q)) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue vuota, impossibile rimuovere.\n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) { // se la coda è diventata vuota
        q->rear = NULL;
    }

    printf("Elemento rimosso: %d\n", temp->value);
    free(temp);
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

int main() {
    Queue q = {NULL, NULL};

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        enqueue(&q, rand() % 21);
    }

    printf("Coda iniziale:\n");
    printQueue(&q);

    for (int i = 0; i < 3; i++) {
        dequeue(&q);
        printQueue(&q);
    }

    freeQueue(&q);
    dequeue(&q);
    
    return 0;
}

