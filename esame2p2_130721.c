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
int sum(LINK* l);

int main(){
    int arr1[] = {13,21,34,55};
    int arr2[] = {2,3,5};
    LINK l1 = createList(arr1,4);
    LINK l2 = createList(arr2,3);
    
    printf("Lista 1: ");
    printList(l1);
    printf("Lista 2: ");
    printList(l2);
    
    int sum1 = sum(&l1);
    int sum2 = sum(&l2);
    printf("%d numeri sono la somma delle 2 precedenti nella Lista 1\n",sum1);
    printf("%d numeri sono la somma delle 2 precedenti nella Lista 2\n",sum2);
    
    freeList(&l1);
    freeList(&l2);
    
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
