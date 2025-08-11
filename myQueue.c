// trying for the first time a QUEUE. implemented with linked lists.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// per quest'implementazione uso la testa della lista come top
// perché riduce la complessità (da O(n)-> O(1) per il pop) e il numero di variabiabili (top non è più richiesto)
typedef struct list{
    int value;
    struct list* next;
}ELEMENT;

typedef struct{
    ELEMENT* head;
    ELEMENT* tail;
}POS;

typedef ELEMENT* QUEUE;

int isempty(QUEUE* s){
    return *s == NULL;
}
void printQUEUE(QUEUE s){
    //if(isempty(s)) return;
    while(s != NULL){
        printf("%d->",s->value);
        s = s->tail;
    }
    printf("NULL\n");
}

void push(QUEUE* q,int num){
    QUEUE node = malloc(sizeof(ELEMENT));
    node->value = num;
    node->next = *q;
    *q = node;
    //printQUEUE(*s);
}

void pop(QUEUE* q){
    if(isempty(q)) return;
    QUEUE temp = *q, prev = temp;
    if(temp->next == NULL){
        *q = NULL;
        printf("element removed: %d\n",temp->value);
        free(temp);
        return;
    }
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("element removed: %d\n",temp->value);
    //printQUEUE(*q);
    
    free(temp);
}

void freeQUEUE(QUEUE* q){
    QUEUE temp = *q;
    while(*q != NULL){
        temp = *q;
        *q = (*q)->next;
        free(temp);
    }
}

int main(){
    QUEUE q1 = NULL;
    if(isempty(&q1) == 1) printf("QUEUE is empty\n");
    else printf("QUEUE is not empty\n");
    
    srand(time(NULL));
    for(int i=0;i<1;i++) push(&q1,rand()%21);
    printQUEUE(q1);
    
    //for(int i=0;i<3;i++) 
        pop(&q1);
    //printQUEUE(s1);
    
    freeQUEUE(&q1);
    return 0;
}
