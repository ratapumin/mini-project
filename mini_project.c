#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "customer.c"
#include "service.c"
#include "editService.c"
#include "deleteService.c"
#include "employee.c"
void customerMenu(int isCustomerLoggedIn);
void employeeMenu(int isEmployeeMenu);

int main()
{
    int choice;
    char input[100]; // Buffer to read user input

    int isCustomerLoggedIn = 0;
    int isEmployeeMenu = 0;

    while (1)
    {
        printf("===============================\n");
        printf("          Main For Menu        \n");
        printf("===============================\n");
        printf("1: Customer\n");
        printf("2: Employee\n");
        printf("3: Exit\n");
        printf("Select the desired item: ");
        if (scanf("%d", &choice) == 1)
        {
            switch (choice)
            {
            case 1:
                customerMenu(isCustomerLoggedIn);
                break;
            case 2:
                employeeMenu(isEmployeeMenu);
                break;
            case 3:
                printf("Exit\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
        else
        {
            printf("Invalid choice. Please enter a numeric choice.\n");
            // Consume any remaining characters in the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    }
}
