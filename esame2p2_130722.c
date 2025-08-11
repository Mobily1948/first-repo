#include <stdio.h>
#include <stdlib.h>

/*CDL IN INFORMATICA - POLO DI VERCELLI - ESAME DI PROGRAMMAZIONE 2: FONDAMENTI DEL 13/07/2022
COGNOME___________________________NOME_______________________MATRICOLA_______________
Esercizio 2
Scrivere una funzione ricorsiva che date in input due liste L1 e L2 e un intero K, restituisca una nuova lista L3
contenente il massimo tra il valore dei nodi di L1, L2 e K. si supporr-> che valori mancanti della lista più corta
siano 0. Analizzare e motivare la complessit-> in spazio e in tempo.
Esempio K=3 L1: 2->3->1->9->1->NULL
L2: 4->5->2->5->NULL
RISULTATO
L3: 4->5->3->9->3->NULL*/

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

LINK copyNode(LINK node){
    LINK nodeN = malloc(sizeof(Node));
    if(nodeN == NULL) return NULL;
    nodeN->value = node->value;
    nodeN->next = NULL;
    
    return nodeN;
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

LINK max(LINK l1,LINK l2, int k){
    LINK head = NULL;
    if(l1 != NULL && l2 != NULL){
        if(l1->value > k || l2->value >k){
            if(l1->value > l2->value){
                head = copyNode(l1);
                l1 = l1->next;
                l2 = l2->next;
                head -> next = max(l1,l2,k);
            }
            else{
                head = copyNode(l2);
                l1 = l1->next;
                l2 = l2->next;
                head -> next = max(l1,l2,k);
            }
        }
        else{
            head = newNode(k);
            l1 = l1->next;
            l2 = l2->next;
            head -> next = max(l1,l2,k);
        }
    }
    // added the "l2 == NULL" just to be sure (Didn't want to crack my head on logic😅)
    if(l1!=NULL && l2 == NULL){
        if(l1->value > k){
                head = copyNode(l1);
                l1 = l1->next;
                head -> next = max(l1,l2,k);
         }
         else{
            head = newNode(k);
            l1 = l1->next;
            head -> next = max(l1,l2,k);
        }
    }
    // same here
    if(l2!=NULL && l1 == NULL){
        if(l2->value > k){
                head = copyNode(l2);
                l2 = l2->next;
                head -> next = max(l1,l2,k);
         }
         else{
            head = newNode(k);
            l2 = l2->next;
            head -> next = max(l1,l2,k);
        }
    }
    
    return head;
}

int main(){
    int arr1[] = {2,3,1,9,1};
    int arr2[] = {4,5,2,5};
    LINK l1 = createList(arr1,5);
    LINK l2 = createList(arr2,4);
    
    printf("lista L1: ");
    printList(l1);
    printf("lista L2: ");
    printList(l2);
    
    int k = 3;
    LINK l3 = max(l1,l2,k);
    printf("lista L3: ");
    printList(l3);
    
    freeList(&l1);
    freeList(&l2);
    freeList(&l3);
    
    return 0;
}
