#include<stdio.h>

int factorial(int n){
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
    printf("enter the num of objects selected: ");
    scanf("%d", &b);
    printf("premutation: %d \n", (factorial(a)/factorial(a-b)));
    printf("combination: %d", (factorial(a)/(factorial(a-b)*factorial(b))));
    return 0;
    
}