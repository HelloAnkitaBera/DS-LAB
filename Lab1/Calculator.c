
// WAP to develop a calculator for following
// Sum
// Difference
// Product
// Division
// The program should display a menu for taking choice
// from the user. All operations must be in form of functions

#include<stdio.h>
int sum(int a, int b) {
    
	return a + b;
}
int difference(int a, int b) {
    return a-b;
}
int multiplication(int a, int b) {
	return a * b;
}
int divide(int a, int b){
    return a/b;
}
int main(){
    int a, b, choice;
    while(1){
        printf("\nSample Calculator\n");
        printf("1. Sum\n");
        printf("2. Difference\n");
        printf("3. Multiplication\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 5){
            printf("Exit\n");
            break;
        }

        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);

        switch(choice){
            case 1:
                printf("Sum = %d\n", sum(a, b));
                break;
            case 2:
                printf("Difference = %d\n", difference(a, b));
                                break;
          case 3:
                printf("Multiplication = %d\n", multiplication(a, b));
                                break;
          case 4:
                 if (b != 0)
                printf("Divide = %d\n", divide(a, b));
                else
                printf("Error: Division by zero\n");
                break;
                default:
                printf("Invalid choice\n");
                break;
                        }
                    }
                    return 0;
                }