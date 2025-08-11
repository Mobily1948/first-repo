// esame1p2_110222.c
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

int main(){
    int arr[] = {1,1,2,1,7,1,2,2,2,1,2,1,1,1,1,1,8};
    LINK l = createList(arr,17);
    
    printf("Lista 1: ");
    printList(l);
    
    int max = lunghezza(l);
    printf("la serie più lungha della lista a %d nodi \n",max);
    
    freeList(&l);
    
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
    int count = 1,max = 0;
    LINK temp = l;
    while(temp!=NULL){
        while(temp->next != NULL && temp->value == temp->next->value ){
            count++;
            temp = temp->next;
        }
        temp = temp->next;
        if(count>max) max = count;
        count = 1;
    }
    return max;
}
