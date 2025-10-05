#include <stdio.h>

struct Employee {
    int empId;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
    float gross_salary;
};

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d:\n", i + 1);

        printf("Emp ID: ");
        scanf("%d", &emp[i].empId);
        getchar(); // To consume newline after ID

        printf("Name: ");
        fgets(emp[i].name, sizeof(emp[i].name), stdin);

        printf("Designation: ");
        fgets(emp[i].designation, sizeof(emp[i].designation), stdin);

        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);

        printf("HRA %%: ");
        scanf("%f", &emp[i].hra_percent);

        printf("DA %%: ");
        scanf("%f", &emp[i].da_percent);

        emp[i].gross_salary = emp[i].basic_salary +
                              (emp[i].basic_salary * emp[i].hra_percent / 100.0) +
                              (emp[i].basic_salary * emp[i].da_percent / 100.0);
    }

    printf("\nEmployee Details with Gross Salary:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmp ID: %d", emp[i].empId);
        printf("Name: %s", emp[i].name);
        printf("Designation: %s", emp[i].designation);
        printf("Gross Salary: %.2f\n", emp[i].gross_salary);
    }

    return 0;
}
