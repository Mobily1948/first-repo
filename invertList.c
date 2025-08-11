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

int length(LINK l){
    int count = 0;
    while(l != NULL){
        count++;
        l = l->next;
    }
    return count;
}

LINK roll(LINK *l,int i){
    LINK temp = *l;
    while(i>1){
        temp = temp->next;
        i--;
    }
    return temp;
}

void invert(LINK* l){
    if (*l ==NULL) return;
    int len = length(*l);
    LINK temp1 = *l,temp2 = roll(l,--len),prev;
    LINK new_head = temp2->next;
    prev = temp2->next;
    prev->next = temp2;
    while(len>1){
        temp2 = roll(l,--len);
        prev = temp2->next;
        prev->next = temp2;
    }
    temp1->next = NULL;
    *l = new_head;
        printList(*l);
}

int main(){
    LINK l = NULL;
    int len = 5;
    int arr[] = {2,6,5,8,9};
    l = createList(arr,len);
    printf("List 1:");
    printList(l);
    invert(&l);
    printf("List 1:");
    printList(l);
    freeList(&l);
    
    return 0;
}
