// done in abt 1h18 mins. didn't copy code from elsewhere
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef Node* LINK;

LINK newNode(int num){
    LINK node = malloc(sizeof(Node));
    if(node == NULL) return NULL;
    node->value = num;
    node->next = NULL;
    
    return node;
}

LINK createList(int num[],int len){
    LINK head = NULL,temp = NULL;
    int i = 0;
    while(i < len){
        LINK node = newNode(num[i]);
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

void invert(LINK* head,LINK* l){
    if((*l) != NULL){
        LINK temp;
        temp = (*l)->next;
        (*l)->next = *head;
        if(*head == *l){ 
            (*head)->next = NULL;
            invert(l,&temp);
        }
        else{
            *head = temp;
            invert(l,head);
        }
    }
    
}

void inverts(LINK *l){
    invert(l,l);
}

int main(){
    LINK l = NULL;
    int len = 2;
    int arr[] = {2,6};
    l = createList(arr,len);
    /*LINK temp = l;
    for(int i=0; i<3 ;i++) temp = temp->next;*/
    printf("List 1:");
    printList(l);
    inverts(&l);
    printf("List 1:");
    printList(l);
    freeList(&l);
    
    return 0;
}
