#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num1, num2, l[20];
    printf("enter 2 numbers: ");
    scanf("%d%d",&num1,&num2);
    srand(time(NULL));
    for(int i=0;i<20;i++)
        l[i] = rand()%(num2+1-num1)+num1;
    printf("Numbers in that interval are: ");
    for(int i=0;i<20;i++)
        printf("%d ",l[i]);
    printf("\n");
    return 0;
}
