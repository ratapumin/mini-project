#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.c"
#include "service.c"
#include "editService.c"
#include "deleteService.c"
#include "employee.c"
void customerMenu(int isCustomerLoggedIn);
void employeeMenu(int isEmployeeMenu);

int main()
{
    int choice, case_emp, case_pub, case_service;

    char ch = 'y';
    int isCustomerLoggedIn = 0;
    int isEmployeeMenu = 0;

    while (1)
    {
        printf("===============================\n");
        printf("Main menu\n");
        printf("1: Customer\n");
        printf("2: Employee\n");
        printf("3: Exit\n");
        printf("Select the desired item: ");
        scanf("%d", &choice);
        printf("===============================\n");

        switch (choice)
        {
        case 1:
        {
            customerMenu(isCustomerLoggedIn);
            break;
        }
        break;
        case 2:
        {
            employeeMenu(isEmployeeMenu);
        }
        break;
        case 3:
            printf("Exit\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}