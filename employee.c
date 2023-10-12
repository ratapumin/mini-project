#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void employeeMenu(int isEmployeeMenu)
{
    int case_emp;
    char username[20];
    char password[20];

    while (1)
    {
        printf("===============================\n");
        printf("Menu For Customer\n");
        printf("1: Login\n");
        printf("2: Return to Main Menu\n");
        printf("Select the desired item: ");
        scanf("%d", &case_emp);
        printf("===============================\n");

        switch (case_emp)
        {
        case 1:
        {
            printf("Username: ");
            scanf("")
            printf("Password: ");
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

                FILE *empfile;
                char *name;
                empfile = fopen("./CSV/employee", "w");

                if (!empfile)
                {
                    perror("Error opening file");
                    exit(1);
                }
                else
                {
                    char emp_file[1024];
                    int row = 0;
                    int column = 0;
                    while (fgets(emp_file, 1024, empfile))
                    {
                        column = 0;
                        row++;

                        if (row == 1)
                            continue;
                        char *value = strtok(emp_file, ",");
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
                break;
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
}