
#include<stdio.h>

void copyArray(int ani[], int sani[], int n){
    for(int i=0; i<n; i++)
        sani[i] = ani[i];
}

int main(){
    int n, sani[50], ani[50];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for(int i=0; i<n; i++)
        scanf("%d", &ani[i]);

    copyArray(ani, sani, n);
    
    printf("Copied Array: \n");
    for(int i=0; i<n; i++)
        printf("%d ", sani[i]);
    printf("\n");
    
    return 0;
}
