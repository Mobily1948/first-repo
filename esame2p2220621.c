#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef Node* LINK;

void printList(LINK l);
void freeList(LINK l);
LINK newNode(int num);
LINK createList(int arr[],int len);
void cancella(LINK l, int k);

int count = 2;

int main(){
    int len;
    printf("Inserisci il numero di righe: ");
    scanf("%d",&len);
    int arr[len];
    srand(time(NULL));
    for(int i=0;i<len;i++) arr[i] = rand()%6;
    LINK l = createList(arr,len);
    printf("la lista è:");
    printList(l);
    
    int k;
    printf("Inserisci il numero da cancellare in caso di posizione pari: ");
    scanf("%d",&k);
    cancella(l,k);
    printf("Lista dopo cancellazione dei nodi pari: ");  
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

void cancella(LINK l, int k){
    if(l==NULL) return;
    LINK temp = l,prev = temp;
    temp = temp->next;
    if(count%2==0 && temp->value==k){
        //printf("done\n");
        prev->next = temp->next;
        free(temp);
        temp = prev;
    }
    else{
        prev = temp;
        //printList(l);
    }
    count++;
    cancella(temp,k);
}
// done in about 2h
            
