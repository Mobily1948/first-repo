//esame1p2210621.c
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
bool presente(LINK* l,int val);
void elimina(LINK* l,int m,int n);

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
    
    
    int m,n;
    printf("Inserisci i numeri di cui l'entrvallo è da cancellare : ");
    scanf("%d%d",&m,&n);
    elimina(&l,m,n);
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

bool presente(LINK* l,int val){
    LINK temp = *l;
    while(temp!=NULL){
        if(temp->value==val) return true;
        temp = temp->next;
    }
    return false;
}

void elimina(LINK* l,int m,int n){
    if(*l== NULL) return;
    if((!presente(l,m)) || (!presente(l,n))) return;
    LINK temp = *l,prev = NULL;
    while(temp!=NULL && temp->value!=m){
        prev = temp;
        temp = temp->next;
    }
    while(temp!=NULL && temp->value!=n){
        LINK del = temp;
        temp = temp->next;
        free(del); 
    }
    if(temp!=NULL && temp->value == n){
        LINK del = temp;
        temp = temp->next;
        free(del);
    }
    if(prev==NULL) *l = temp;
    else prev->next = temp;
}

            
