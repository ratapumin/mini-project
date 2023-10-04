#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.c"
#include "service.c"

void customerMenu(int isCustomerLoggedIn);

int main()
{
    int choice, case_emp, case_pub, case_service;

    char ch = 'y';
    int isCustomerLoggedIn = 0;

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
            printf("===============================\n");
            customerMenu(isCustomerLoggedIn);
            break;
        }
        break;
        case 2:
            printf("Menu For employees\n");
            printf("1: Dental appointment queue list\n");
            printf("2: Book a dental appointment\n");
            printf("Select the desired item: ");
            scanf("%d", &case_emp);
            switch (case_emp)
            {
            case 1:
            {

                FILE *cusfile;
                char *name;
                cusfile = fopen("customer.csv", "r");

                if (!cusfile)
                {
                    perror("Error opening file");
                    exit(1); // Exit the program if the file couldn't be opened
                }
                else
                {
                    char customerfile[1024];
                    int row = 0;
                    int column = 0;
                    while (fgets(customerfile, 1024, cusfile))
                    {
                        column = 0;
                        row++;

                        if (row == 1)
                            continue;
                        char *value = strtok(customerfile, ",");
                        while (value)
                        {
                            if (column == 0)
                            {
                                printf("username: ");
                            }
                            if (column == 1)
                            {
                                printf("\tpassword: ");
                            }
                            if (column == 2)
                            {
                                printf("\tfname: ");
                            }
                            if (column == 3)
                            {
                                printf("\tlname: ");
                            }
                            if (column == 4)
                            {
                                printf("\tdate: ");
                            }
                            if (column == 5)
                            {
                                printf("\tage: ");
                            }
                            if (column == 6)
                            {
                                printf("\tid_card: ");
                            }
                            if (column == 7)
                            {
                                printf("\tpnumber: ");
                            }
                            if (column == 8)
                            {
                                printf("\taddress: ");
                            }
                            printf("%s ", value);
                            value = strtok(NULL, ",");
                            column++;
                        }
                        printf("\n");
                    }
                }
            }
            break;
            case 2:
            {
            }
            default:
                break;
            }
            break;
        case 3:
            printf("Exit\n");
            exit(0);
        default:
            break;
        }
    }
    return 0;
}