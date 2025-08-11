#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int len;
int sum(int arr[]);

int main(){
    srand(time(NULL));
    printf("enter a number: ");
    scanf("%d",&len);
    int arr[len],i;
    for(i=0;i<len;i++) arr[i] = rand()%10;
    int somma = sum(arr);
    for(--i;i>-1;i--) printf("%d->",arr[i]);
    printf("done\nsum = %d\n",somma);
    return 0;
}

int sum(int arr[]){
    if(len == 0) return 0;
    else
        return arr[--len] + sum(arr);
}
