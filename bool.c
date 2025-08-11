#include <stdio.h>
#include <stdbool.h>

int main(){
    enum days {monday,tuesday,wednesday,thursday,friday,saturday,sunday};
    enum days today;
    int num;
    printf("chose a date:");
    scanf("%d",&num);
    today = (enum days)num -1;
    switch (today){ 
    
    
    case monday: 
        printf("today is monday");
        break;
    case tuesday: 
        printf("today is tueday");
        break;
    case wednesday: 
        printf("today is Wednesday");
        break;
    case thursday: 
        printf("today is thursday");
        break;
    case friday: 
        printf("today is friday");
        break;
    case saturday: 
        printf("today is saturday");
        break;
    case sunday: 
        printf("today is sunday");
        break;
    }

    return 0;
}
