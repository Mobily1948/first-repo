//esame1p2_130722
#include <stdio.h>
#include <stdlib.h>

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

LINK createList(int arr[],int len){
    int i=0;
    LINK head = NULL,temp = NULL;
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
    if(l==NULL) printf("NULL\n");
    else{
        printf("%d->",l->value);
        printList(l->next);
    }
}

void freeList(LINK* l){
    LINK temp = *l;
    while(*l != NULL){
        temp = *l;
        (*l) = (*l)->next;
        free(temp);
    }
}

int sommaPrecedenti(LINK l){
    LINK temp = l,prev;
    int count = 0,i=0;
    // count the number of elements
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(count<4) return 0;
    temp = l;
    count-=3;
    // set an array to store the sum of the three last elements in each field
    int sum[count];
    for(int k=0;k<count;k++) sum[k] = 0;
    count = 0;
    while(temp != NULL && temp->next !=NULL && temp->next->next !=NULL && temp->next->next->next!=NULL){
        prev = temp;
        i = 0;
        while(i<3){
            sum[count] += temp->value;
            temp = temp->next;
            i++;
        }
        temp = prev;
        temp = temp->next;
        count++;
    }
    temp = l->next->next->next;
    count = 0;i = 0;
    // compare each element of the list with the corresponding element in "sum[]" 
    while(temp != NULL){
        if(temp->value == sum[i]) count++;
        temp = temp->next;
        i++;
    }
    
    return count;
}

int main(){
    int arr1[] = {1 , 1 , 2 , 4 , 7 , 0 , 11 };
    int arr2[] = {2,3,5,10};
    LINK l1 = createList(arr1,7);
    LINK l2 = createList(arr2,4);
    
    printf("lista L1: ");
    printList(l1);
    printf("lista L2: ");
    printList(l2);
    
    int sum1 = sommaPrecedenti(l1);
    int sum2 = sommaPrecedenti(l2);
    
    freeList(&l1);
    freeList(&l2);
    
    printf("lista L1 a %d le cui è sono le somme delle 3 precedenti valori\n",sum1);
    printf("lista L2 a %d le cui è sono le somme delle 3 precedenti valori\n",sum2);
    
    return 0,
}
