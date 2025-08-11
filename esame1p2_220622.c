#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Scrivere una funzione iterativa che prenda in input due liste e restituisca in output la lunghezza della sequenza
comune (con posizione corrispondente) più lunga. Analizzare e motivare la complessit, in tempo e spazio
della funzione proposta.
Esempio
L1: 1,1,2,2,2,3,3,3,3,1,1
L2: 1,1,2,2,7,7,3,3,3,1,3
Output: 4*/

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

int lunghezza(LINK l1, LINK l2){
    LINK temp1=l1, temp2=l2;
    int count = 0,quant_max=0;
    while(temp1!=NULL){
        count =  1;
        if(temp1->next!=NULL && temp1->value==temp1->next->value)
            while(temp1->value==temp1->next->value){
                count++;
                temp1=temp1->next;
            }
        else temp1=temp1->next;
        if(count>quant_max) quant_max = count;
    }
    printf("space\n");
    while(temp2!=NULL){
        count = 1;
        if(temp2->next != NULL && temp2->value==temp2->next->value)
            while(temp2->value==temp2->next->value){
                count++;
                temp2=temp2->next;
            }
        else temp2=temp2->next;
        if(count>quant_max) quant_max = count;
    }
    return quant_max;
}

int serie_commune(LINK l1,LINK l2){ //BONUS per dare il numero di serie identiche delle due liste
    LINK temp1 = l1,temp2 = l2;
    int count = 1;
    printf("%d",count);
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->value==temp2->value)
            while(temp1->value==temp2->value){
                temp1=temp1->next;
                temp2=temp2->next;
            }
        else {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        count++;
    }
    return count;
}

int main(){
     srand(time(NULL));
     LINK l1 = NULL,l2=NULL;
     int len = 10,vals1[]={1,1,2,2,2,3,3,3,3,1,1},vals2[]={1,1,2,2,7,7,3,3,3,1,3};
     //for(int i=0;i<len;i++) vals1[i] = rand()%10;
     //for(int i=0;i<len;i++) vals2[i] = rand()%10;
     printf("\n"); 
     createList(&l1,vals1,len);
     createList(&l2,vals2,len);
     printf("prima lista:");
     printList(l1);
     printf("seconda lista:");
     printList(l2);
     int lungo = lunghezza(l1,l2);
     printf("la seria più lunga a %d valori\n",lungo);
     int sc = serie_commune(l1,l2);
     printf("Le stringhe hanno %d serie commune\n",sc);
     freeList(l1);
     freeList(l2);
     
     return 0; 
}
