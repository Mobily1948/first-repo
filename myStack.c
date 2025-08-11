// trying for the first time a stack. implemented with linked lists.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// per quest'implementazione uso la testa della lista come top
// perché riduce la complessità (da O(n)-> O(1) per il pop) e il numero di variabiabili (top non è più richiesto)
typedef struct list{
    int value;
    struct list* next;
}ELEMENT;

typedef ELEMENT* STACK;

int isempty(STACK* s){
    return *s == NULL;
}
void printStack(STACK s){
    //if(isempty(s)) return;
    while(s != NULL){
        printf("%d->",s->value);
        s = s->next;
    }
    printf("NULL\n");
}

void push(STACK* s,int num){
    STACK node = malloc(sizeof(ELEMENT));
    node->value = num;
    node->next = *s;
    *s = node;
    //printStack(*s);
}

void pop(STACK* s){
    STACK temp = *s;
    *s = (*s)->next;
    printf("element removed: %d\n",temp->value);
    printStack(*s);
    free(temp);
}

void freeStack(STACK* s){
    STACK temp = *s;
    while(*s != NULL){
        temp = *s;
        *s = (*s)->next;
        free(temp);
    }
}

int main(){
    STACK s1 = NULL;
    if(isempty(&s1) == 1) printf("stack is empty\n");
    else printf("stack is not empty\n");
    
    srand(time(NULL));
    for(int i=0;i<10;i++) push(&s1,rand()%21);
    printStack(s1);
    
    for(int i=0;i<3;i++) pop(&s1);
    //printStack(s1);
    
    freeStack(&s1);
    return 0;
}
