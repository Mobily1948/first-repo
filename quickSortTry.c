//quickSortTry.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pivot(int arr[],int left,int right);
void quickSort(int arr[],int left,int right);
void printArray(int arr[],int len);

int main(){
    int i,num;
    printf("Inserisci il numero di elementi: ");
    scanf("%d",&num);
    int arr[num];
    for(i=0;i<num;i++) arr[i] = rand()%10;
    printf("Array before sorting: ");
    printArray(arr,num);
    quickSort(arr,0,num-1);
    printf("Array after sorting: ");
    printArray(arr,num);
    
    return 0;
}

int pivot(int arr[],int left,int right){
    int i=left-1,j=left,temp;
    while(j<right){ 
        if(arr[j]<=arr[right]){
            i++;
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
        j++;
    }
    i++;
    temp=arr[i];
    arr[i]=arr[right];
    arr[right]=temp;
    
    return i;
}

void quickSort(int arr[],int left,int right){
    if(left<right){
        int pi = pivot(arr,left,right);
        quickSort(arr,left,pi-1);
        quickSort(arr,pi+1,right);
    }
}

void printArray(int arr[],int len){
    for(int i=0;i<len;i++) printf("%d ",arr[i]);
    printf("\n");
}

