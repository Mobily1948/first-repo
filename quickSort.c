// second time coding a quick sort.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int len = 5;

void init(int arr[]){
    for(int i=0;i<len;i++)
        arr[i] = rand()%10;
}

void display(int arr[]){
    for(int i=0;i<len;i++)
        printf("%d->",arr[i]);
    printf("NULL\n");
}
void swap(int* i,int* j){
    int temp =*i;
    *i = *j;
    *j = temp;
}

int pivot(int arr[],int left,int pi){
    int i=-1,j=0;
    
    while(j<pi){
        if(arr[j]<arr[pi]){
            i++;
            swap(&arr[j],&arr[i]);
        }
        j++;
    }
    i++;
    swap(&arr[i],&arr[pi]);
    display(arr);
    
    return i;
}

void quickSort(int arr[],int left,int right){
    if(left < right){
        int pi = pivot(arr,left,right);
        quickSort(arr,left,pi-1);
        quickSort(arr,pi+1,right);
    }
}

int main(){
    srand(time(NULL));
    
    int arr[len];
    init(arr);
    printf("arr: ");
    display(arr);
    
    quickSort(arr,0,len-1);
    printf("arr dopo sorting: ");
    display(arr);
    
    return 0;
}
