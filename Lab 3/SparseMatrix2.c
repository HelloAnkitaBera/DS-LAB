#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int row;
    int col;
    int value;
} Triplet;

Triplet triplet[MAX];
int tripletSize = 0;


void createTriplet(int matrix[MAX][MAX], int rows, int cols) {
    tripletSize = 1; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplet[tripletSize].row = i;
                triplet[tripletSize].col = j;
                triplet[tripletSize].value = matrix[i][j];
                tripletSize++;
            }
        }
    }
    triplet[0].row = rows;
    triplet[0].col = cols;
    triplet[0].value = tripletSize - 1;  
}


void displayTriplet() {
    printf("\nTriplet Representation:\n");
    printf("Row Col Value\n");
    for (int i = 0; i < tripletSize; i++) {
        printf("%3d %4d %5d\n", triplet[i].row, triplet[i].col, triplet[i].value);
    }
}


void displayRowMajor() {
    printf("\nRow-Major Order of Triplet:\n");
    printf("Row Col Value\n");
    printf("%3d %4d %5d\n", triplet[0].row, triplet[0].col, triplet[0].value);
    for (int i = 1; i < tripletSize; i++) {
        for (int j = i + 1; j < tripletSize; j++) {
            if (triplet[i].row > triplet[j].row || 
               (triplet[i].row == triplet[j].row && triplet[i].col > triplet[j].col)) {
                Triplet temp = triplet[i];
                triplet[i] = triplet[j];
                triplet[j] = temp;
            }
        }
    }
    for (int i = 1; i < tripletSize; i++) {
        printf("%3d %4d %5d\n", triplet[i].row, triplet[i].col, triplet[i].value);
    }
}


void displayColumnMajor() {
    printf("\nColumn-Major Order of Triplet:\n");
    printf("Row Col Value\n");
    printf("%3d %4d %5d\n", triplet[0].row, triplet[0].col, triplet[0].value);
    for (int i = 1; i < tripletSize; i++) {
        for (int j = i + 1; j < tripletSize; j++) {
            if (triplet[i].col > triplet[j].col || 
               (triplet[i].col == triplet[j].col && triplet[i].row > triplet[j].row)) {
                Triplet temp = triplet[i];
                triplet[i] = triplet[j];
                triplet[j] = temp;
            }
        }
    }
    for (int i = 1; i < tripletSize; i++) {
        printf("%3d %4d %5d\n", triplet[i].row, triplet[i].col, triplet[i].value);
    }
}


int main() {
    int matrix[MAX][MAX], rows, cols;
    int choice;

    printf("Enter number of rows and columns of matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    createTriplet(matrix, rows, cols);

    do {
        printf("\nMenu:\n");
        printf("1. Display Triplet Representation\n");
        printf("2. Display in Row-Major Order\n");
        printf("3. Display in Column-Major Order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTriplet();
                break;
            case 2:
                displayRowMajor();
                break;
            case 3:
                displayColumnMajor();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
