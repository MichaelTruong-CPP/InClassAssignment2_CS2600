#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main() {
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);
    
    
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1001); 
    //match employee number
    if (matchPtr != NULL) {  
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    }
    else {
        printf("Employee ID 1045 is not found in the record\n");
    }

    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1234);
    //no match employee number
    if (matchPtr != NULL) {
        printf("Employee ID 1234 is in record %d\n", matchPtr - EmployeeTable);
    }
    else {
        printf("Employee ID 1234 is not found in the record\n");
    }


    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    //match employee name
    if (matchPtr != NULL) {
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    }
    else {
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Michael Truong");
    //no match employee name
    if (matchPtr != NULL) {
        printf("Employee Michael Truong is in record %d\n", matchPtr - EmployeeTable);
    }
    else {
        printf("Employee Michael Truong is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "213-555-1212");
    //match employee phone number 
    if (matchPtr != NULL) {
        printf("Employee phone number 213-555-1212 is in record %d\n", matchPtr - EmployeeTable);
    }
    else {
        printf("Employee phone number 213-555-1212 is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "714-123-1234");
    //no match employee phone number 
    if (matchPtr != NULL) {
        printf("Employee phone number 714-123-1234 is in record %d\n", matchPtr - EmployeeTable);
    }
    else {
        printf("Employee phone number 714-123-1234 is NOT found in the record\n");
    }

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
    //match employee salary
    if (matchPtr != NULL) {
        printf("Employee salary $8.32 is in record %d\n", matchPtr - EmployeeTable);
    }
    else {
        printf("Employee salary $8.32 is NOT found in the record\n");
    }

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 40.00);
    //no match employee salary
    if (matchPtr != NULL) {
        printf("Employee salary $40.00 is in record %d\n", matchPtr - EmployeeTable);
    }
    else {
        printf("Employee salary $40.00 is NOT found in the record\n");
    }


    return EXIT_SUCCESS;



}