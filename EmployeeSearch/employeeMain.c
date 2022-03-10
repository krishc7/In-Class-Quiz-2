// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"


int main(void)
{
    // defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);

    // defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration

    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // Newly added searches start from here

    // Example NOT found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries,10.00);
    
    if (matchPtr != NULL)
        printf("\nEmployee Salary: 10.00 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("\nEmployee Salary: 10.00 is NOT found in the record\n"); 

    // Example found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries,6.34);

    if (matchPtr != NULL)
        printf("Employee Salary: 6.34 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Salary: 6.34 is NOT found in the record\n");

    // Example NOT found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "405-655-2897");

    if (matchPtr != NULL)
        printf("Employee phone number: 405-655-2897 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number: 405-655-2897 is NOT found in the record\n");

    // Example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");

    if (matchPtr != NULL)
        printf("Employee phone number: 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number: 909-555-2134 is NOT found in the record\n");

    return EXIT_SUCCESS;
}