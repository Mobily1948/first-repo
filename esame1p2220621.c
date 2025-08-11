/*Scrivere una funzione iterativa che data una lista in input e un intero k, calcoli la media dei primi k nodi nella
lista. Si analizzi e motivi la complessità in spazio e in tempo.
Es: 5à3à7à1à2àNULL k = 3 Risultato 5*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef Node* LINK;

LINK new_node(int val){
    LINK node = malloc(sizeof(Node));
    if(node == NULL) return NULL;
    node->value = val;
    node->next = NULL;
    return node;
}

void printList(LINK l){
    LINK temp=l;
    while(temp!=NULL){
        printf("%d->",temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

void createList(LINK* l,int vals[],int len){
    int i=0;
    LINK head = NULL,temp = NULL;
    while(i<len){
        LINK node = new_node(vals[i]);
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
    *l = head;
}

void freeList(LINK l){
    LINK temp=NULL;
    while(l!=NULL){
        temp=l;
        l=l->next;
        free(temp);
    }
}

float media(LINK l,int k){
    LINK temp = l;
    int i=0,sum=0;
    while(temp!=NULL && i<k){
        sum+=temp->value;
        temp=temp->next;
    }
    return (float)sum/(float)k;
}

int main(){
    srand(time(NULL));
    LINK l1 = NULL;
    int len = 10,vals1[len];
    for(int i=0;i<len;i++) vals1[i] = rand()%10;
    printf("\n"); 
    createList(&l1,vals1,len);
    printf("lista:");
    printList(l1);
    int num;
    printf("inserisci un numero: ");
    scanf("%d",&num);
    float mid = media(l1,num);
    printf("la media dele %d primi numeri della lista è: %f\n",num,mid);
    freeList(l1);
    
    return 0;
} 
    
