// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>

/*structure to hold the details of an employee*/
typedef struct employee
{
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];

}employee_t;

/* Read the employee details using scanf*/
void readData(int n, employee_t* s)
{
    // Add your code here
    for(int i = 0; i < n; i++) {
        printf("\nEnter the employeeID, Name, Designation, and Department of Employee %d:\n", i + 1);
        scanf("%d", &(s[i].empId));
        scanf("%s", s[i].Name);
        scanf("%s", s[i].Designation);
        scanf("%s", s[i].Dept);
    }
}

/* Function to print the employee details*/
void display(int n, employee_t * s)
{
    // Add your code here
    for(int i = 0; i < n; i++) {
        printf("\nThe details of Employee %d:\n", i + 1);
        printf("empID: %d\n", s[i].empId);
        printf("Name: %s\n", s[i].Name);
        printf("Designation: %s\n", s[i].Designation);
        printf("Dept: %s\n", s[i].Dept);
    }
}

/*----------Main Program--------*/
int main()

{
    // Main Function to print the employee details
    // Add your code here
    int numOfEmployees;

    // Read the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &numOfEmployees);

    // Allocate memory for employees
    employee_t *employees = (employee_t *)malloc(numOfEmployees * sizeof(employee_t));

    // Read the employee details
    readData(numOfEmployees, employees);

    // Display the employee details
    display(numOfEmployees, employees);

    // Free the memory allocated for employees
    free(employees);

    return 0;
}
