/*Scrivere una funzione ricorsiva che prese in input una lista e un intero n > 0, rimuova dalla lista solamente i
nodi interni (escludendo il primo e l’ultimo nodo) a valore maggiore di > n.
Si analizzi e motivi la complessità in tempo e spazio della funzione proposta.
Esempio
L1:
Ouptut:
1à2à5à6à7à8
1à2à8*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef Node* LINK;

LINK new_node(int val){
    LINK node = malloc(sizeof(Node));
    if(node == NULL) return NULL;
    node->value = val;
    node->next = NULL;
    return node;
}

void printList(LINK l){
    LINK temp=l;
    while(temp!=NULL){
        printf("%d->",temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

void createList(LINK* l,int vals[],int len){
    int i=0;
    LINK head = NULL,temp = NULL;
    while(i<len){
        LINK node = new_node(vals[i]);
        if(head == NULL){
            head = node;
            temp = node;
        }
        else{
            temp->next = node;
            temp = node;
        }
        i++;
    }
    *l = head;
}

void freeList(LINK l){
    LINK temp=NULL;
    while(l!=NULL){
        temp=l;
        l=l->next;
        free(temp);
    }
}

void rimuove(LINK* l,int num){
    if((*l)->next==NULL) return;
    else{
        LINK temp = (*l)->next;
        LINK prev = (*l);
        if(num<temp->value){
          prev->next = temp->next;
          free(temp);
          temp=prev;
        }
        prev = temp;
        temp=temp->next;
        rimuove(&(temp->next),num);
    }
}

int main(){
    srand(time(NULL));
    LINK l1 = NULL;
    int len = 10,vals1[len];
    for(int i=0;i<len;i++) vals1[i] = rand()%10;
    printf("\n"); 
    createList(&l1,vals1,len);
    printf("lista:");
    printList(l1);
    int num;
    printf("inserisci un numero: ");
    scanf("%d",&num);
    rimuove(&l1,num);
    printf("nuova lista:");
    printList(l1);
    freeList(l1);
    
    return 0;
} 
