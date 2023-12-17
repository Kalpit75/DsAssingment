#include<stdio.h>

int factorial(int){
    if(n == 1){
        return n;
    }else{
        n = n* factorial(n-1);
    }
}

int main(){
    int a,b;
    printf("enter the total num of objects: ");
    scanf("%d", &a);
    printf("enter the total num of objects selected: ");
    scanf("%d", &b);
    int fa= factorial(a);
    int fb= factorial(b);
    printf("premutation: %d", (fa/factorial(a-b)));
    printf("combination: %d", (fa/(factorial(a-b)*fb)));
    return 0;
    
}