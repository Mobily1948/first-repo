#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef Node* LINK;

LINK newNode(int num);
LINK createList(int arr[],int len);
void printList(LINK l);
int len(LINK l);
LINK gemilli(LINK* node,LINK temp,int half);
void sommaGemilli(LINK* node,LINK front,int* max,int count,int half);
void freeList(LINK* l);

int main(){
    int arr[] = {4,2,2,3,10,5};
    LINK l = createList(arr,6);
    printf("List: ");
    printList(l);
    int max = 0,mid = len(l)/2;
    sommaGemilli(&l,l,&max,mid,mid);
    printf("somma max tra i gemilli: %d\n",max);
    freeList(&l);
}

LINK newNode(int num){
    LINK node = malloc(sizeof(Node));
    if(node == NULL) return NULL;
    node->value = num;
    node->next = NULL;
    
    return node;
}

LINK createList(int arr[],int len){
    LINK head = NULL, temp = NULL;
    int i = 0;
    while(i < len){
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
    LINK temp ;
    while(*l != NULL){
        temp = *l;
        *l = (*l)->next;
        free(temp);
    }
}
int len(LINK l){
    int count;
    while(l != NULL){
        count++;
        l = l->next;
    }
    return count;
}

LINK gemilli(LINK* node,LINK temp,int half){
    int position = 1;
    LINK count = *node;
    while(count != temp){
        position++;
        count = count->next;
    }
    position = 2*(half-position+1);
    while(position>1){
        position--;
        count = count->next;
    }
    
    return count;
}

void sommaGemilli(LINK* node,LINK front,int* max,int count,int half){
    if(count ==  0) return;
    else{
        LINK temp1 = front;
        LINK temp2 = gemilli(node,temp1,half);
        int sum = temp1->value + temp2->value;
        sommaGemilli(node,temp1->next,max,--count,half);
        if(sum > *max) *max = sum;
    }
}
