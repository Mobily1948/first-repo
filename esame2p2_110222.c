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
int uguali(LINK l1,LINK l2,int num);

int main(){
    int arr1[] = {2,2,5,6,7,9};
    int arr2[] = {2,51,16,6,7,9};
    LINK l1 = createList(arr1,6);
    LINK l2 = createList(arr2,6);
    
    printf("Lista 1: ");
    printList(l1);
    printf("Lista 2: ");
    printList(l2);
    
    int num = uguali(l1,l2,3);
    if(num == 1) printf("sono uguali\n");
    else printf("non sono uguali\n");
    
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

int uguali(LINK l1,LINK l2,int num){
    if(l1 == NULL || l2 == NULL){
        if(num < 1) return 1;
        else return 0;
    }
    else{                                   //REMEMBER TO USE THE CORRECT INCREMENTATION AND DECREMENTATION METHODS
        if(num >= 1) return uguali(l1->next,l2->next,--num); 
        else{
            if(l1->value != l2->value) return 0;
            else{
                printf("enterd\n");
                return uguali(l1->next,l2->next,num--);
            }
        }
    }
}
