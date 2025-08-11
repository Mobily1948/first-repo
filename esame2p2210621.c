//esame2p2210621.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef Node* LINK;

void printList(LINK l);
void freeList(LINK l);
LINK newNode(int num);
LINK createList(int arr[],int len);
LINK cancella(LINK* l,int k,int m);

int main(){
    int len;
    printf("Inserisci il numero di righe: ");
    scanf("%d",&len);
    int arr[len];
    srand(time(NULL));
    for(int i=0;i<len;i++) arr[i] = rand()%21 +1;
    LINK l = createList(arr,len);
    printf("la lista è :");
    printList(l);
    
    int k,m;
    printf("Inserisci la pozizione del numero da cancellare ");
    scanf("%d",&k);
    printf("Inserisci il numero il cui deve essere più grande : ");
    scanf("%d",&m);
    cancella(&l,k,m);
    printf("\n");
    printf("Lista dopo cancellazione : ");  
    printList(l);
    
    free(l);
    
    return 0;
}

void printList(LINK l){
    LINK temp = l;
    while(temp!=NULL){
        printf("%d->",temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(LINK l){
    LINK temp = l;
    while(l!=NULL){
        temp = l;
        l = l->next;
        free(temp);
    }
}

LINK newNode(int num){
    LINK node = malloc(sizeof(Node));
    if(node == NULL) return NULL;
    node->value = num;
    node->next = NULL;
    
    return node;
}

LINK createList(int arr[],int len){
    LINK head = NULL,temp = NULL;
    for(int i = 0; i < len; i++){
        LINK node = newNode(arr[i]);
        if(head == NULL){
            head = node;
            temp = node;
        }
        else{
            temp->next = node;
            temp = node;
        }
    }
    return head;
}
//Guess who wishes to Die...🙃
LINK cancella(LINK* l,int k,int m){
    if(*l == NULL) return NULL;
    LINK temp = *l,prev = NULL;
    if(k==0 && temp->value>m){
        // cancellare il nodo se trovato
        LINK del = temp;
        temp = temp->next;
        free(del);
    }
    else{
        // se non trovato andare al elemento seguente tenendo traccia del precedente
        prev = temp;
        temp = temp->next;
        k--;
        prev->next = cancella(&temp,k,m);
    }
    
    // questo qua ... non so. l'ho messo perché era in un altro codice abbastanza simile 
    // e quando lo rimuovo il codice non funziona più bene.
    
    if(prev == NULL) *l = temp;
    else prev->next = temp;
    
    return temp;
}
//my code works and I don't know why
