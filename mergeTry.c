// tried after watching chat's
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[],int left,int mid,int right){
    int i,j,k;
    int n1 = mid-left+1;
    int n2 = right-mid;
    int arr1[n1],arr2[n2];
    for(i=0;i<n1;i++) arr1[i] = arr[left+i];
    for(j=0;j<n2;j++) arr2[j] = arr[mid+j+1];
    i=0;j=0;k=left;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]) arr[k++] = arr1[i++];
        else arr[k++] = arr2[j++];
    }
    if(arr1[i]>arr2[j]) arr[k++] = arr1[i++];
    if(arr2[j]>arr1[i]) arr[k++] = arr2[j++];
}

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid = left + (right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void printList(int arr[],int len){
    for(int i=0;i<len;i++) printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int len=10,arr[len],i=0;
    srand(time(NULL));
    for(i=0;i<len;i++) arr[i] = rand()%10;
    printf("list before sorting: ");
    printList(arr,len);
    printf("list after sorting: ");
    mergeSort(arr,0,len-1);
    printList(arr,len);
    return 0;
}
