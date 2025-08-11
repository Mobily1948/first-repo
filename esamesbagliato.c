#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef Node* LINK;

LINK newNode(int num);
LINK createList(int arr[],int len);
void printList(LINK l);
void freeList(LINK* l);
int lunghezza(LINK l);
void gira(LINK* l,int num);

int main(){
    int arr1[] = {2,2,5,6,7,9};
    LINK l1 = createList(arr1,6);
    
    printf("Lista 1: ");
    printList(l1);
    
    gira(&l1,13);
    printf("Lista 1: ");
    printList(l1);
    
    freeList(&l1);
    
    return 0;
}

LINK newNode(int num){
    LINK node = malloc(sizeof(Node));
    if(node == NULL) return NULL;
    node->value = num;
    node->next = NULL;
    
    return node;
}

LINK createList(int arr[],int len){
    int i=0;
    LINK head = NULL, temp = NULL;
    while(i<len){
        LINK node = newNode(arr[i]);
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
    return head;
}

void printList(LINK l){
    while(l != NULL){
        printf("%d->",l->value);
        l = l->next;
    }
    printf("NULL\n");
}

void freeList(LINK* l){
    LINK temp;
    while(*l != NULL){
        temp = *l;
        *l = (*l)->next;
        free(temp);
    }
}

int lunghezza(LINK l){
    int count = 0;
    while(l != NULL){
        count++;
        l = l->next;
    }
    return count;
}

void gira(LINK* l,int num){
    if(*l == NULL) return;
    LINK head = *l,temp = *l,prev;
    int count = 1;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    temp->next = head;
    temp = head;
    int i = 0;
    while(i < count-num%count){
        prev = temp;
        temp = temp->next;
        i++;
    }
    head = temp;
    prev->next = NULL;
    *l = head;
}
