#include <string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++) // search until end of table  ptr++ will increment by what??
    {
        if (ptr->number == targetNumber) // check if it equals the Employee number
            return (PtrToEmployee)ptr;   // return location of the number to callee.
    }
    return NULL; // this will only happen if no Employee number matches in loop above
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++)
    {
        if (strcmp(ptr->name, targetName) == 0)
            return (PtrToEmployee)ptr;
    }

    return NULL;
}

// Implementation of these two functions is very similar to the previous two

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char *targetName)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++)     // search until end of table
    {
        if (strcmp(ptr->phone, targetName) == 0)    // check if Employee phone # is equal to what is passed into function
            return (PtrToEmployee)ptr;
    }
    return NULL;    // function returns NULL if no match is found
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetNumber)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)         // search until end of table
    {
        if (ptr->salary == targetNumber) // check if Employee salary is equal to value passed into function
            return (PtrToEmployee)ptr;
    }
    return NULL; // function returns NULL if no match is found
}