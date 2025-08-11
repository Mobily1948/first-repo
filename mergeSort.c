// second time coding merge sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int len = 6;

void init(int arr[]){
    for(int i=0;i<len;i++)
        arr[i] = rand()%10;
}

void display(int arr[]){
    for(int i=0;i<len;i++)
        printf("%d->",arr[i]);
    printf("NULL\n");
}

void merge(int arr[],int left,int mid,int right){
    int n1 = mid-left+1;
    int n2 = right-mid;
    int arr1[n1],arr2[n2];
    int i,j,k = 0;
    for(i = 0; i < n1 ; i++) arr1[i] = arr[left+i];
    for(j = 0; j < n2 ; j++) arr2[j] = arr[mid+1+j];
    k = left;
    i = 0; j = 0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
    }
    
    while(i<n1) arr[k++] = arr1[i++];
    while(j<n2) arr[k++] = arr2[j++]; 
    
    //display(arr);
}

void mergeSort(int arr[],int left,int right){
    if(left < right){
        int mid = left + (right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
        display(arr);
    }
}

int main(){
    srand(time(NULL));
    
    int arr[len];
    init(arr);
    printf("arr: ");
    display(arr);
    
    mergeSort(arr,0,len-1);
    printf("arr dopo sorting: ");
    display(arr);
    
    return 0;
}
