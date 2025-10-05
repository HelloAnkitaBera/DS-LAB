#include<stdio.h>

int sumofDivisors(int n) {
    int sum = 0;
    for(int i=1;i<=n/2;i++){
        if(n%i == 0)
        sum +=i;
    }
    return sum;
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);

    int sum = sumofDivisors(num);
    printf("Sum of divisors = %d\n",sum);

    if(sum == num)
    printf("%d is a perfect number\n",num);
    else
    printf("%d is not a perfect number\n",num);

    return 0;
}