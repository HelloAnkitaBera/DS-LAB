#include<stdio.h>
int compare(int *a , int *b){
    if(*a > *b){
        printf("%d is greater than the %d",*a,*b);
    }
    else if (*a < *b)
    {
       printf("%d is less than %d",*a,*b);
    }
    else
    {
       printf("%d is equal to %d",*a,*b);
    }
}
int main(){
    int a,b;
    printf("Enter two number: ");
    scanf("%d %d",&a, &b);
    compare(&a,&b);
return 0;
}