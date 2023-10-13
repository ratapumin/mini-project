#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void employeeMenu(int isEmployeeMenu)
{
    int login, logout;
    char username[20];
    char password[20];
    int found = 0;
    int i = 0;
    char *save_username, *save_password, *save_role, *save_fname, *save_lname, *save_id_card, *save_pnumber, *save_address;
    int save_day, save_month, save_year, save_age, save_time;

    while (1)
    {
        if (!(isEmployeeMenu))
        {
            printf("===============================\n");
            printf("        Menu For Customer      \n");
            printf("===============================\n");
            printf("1: Login\n");
            printf("2: Return to Main Menu\n");
            printf("Select the desired item: ");
        }
        else
        {
            printf("===============================\n");
            printf("Role: %s\n", save_role);
            printf("===============================\n");
            printf("1: View reservation list\n");
            printf("2: Edit service\n");
            printf("3: Delete service\n");
            printf("4: Logout\n");
            printf("Select the logout item: ");
            scanf("%d", &logout);

            switch (logout)
            {
            case 1:
            {
                printf("===============================\n");
                printf("Role: %s\n", save_role);
                printf("===============================\n");
                FILE *editservicefile;
                editservicefile = fopen("./CSV/service.csv", "r");
                if (!editservicefile)
                {
                    perror("Error opening file");
                    exit(1);
                }
                char line[1024];
                int row = 0;
                int column = 0;
                while (fgets(line, sizeof(line), editservicefile))
                {
                    if (row == 0)
                    {
                        strtok(line, ",");
                        row++;
                        continue;
                    }
                    char *token = strtok(line, ",");
                    char *save_id_card, *save_username, *save_service;
                    int save_day, save_month, save_year;
                    float save_time;

                    if (token != NULL)
                    {
                        save_id_card = strdup(token);
                        token = strtok(NULL, ",");
                    }
                    if (token != NULL)
                    {
                        save_username = strdup(token);
                        token = strtok(NULL, ",");
                    }
                    if (token != NULL)
                    {
                        save_service = strdup(token);
                        token = strtok(NULL, ",");
                    }
                    if (token != NULL)
                    {
                        save_day = atoi(token);
                        token = strtok(NULL, ",");
                    }
                    if (token != NULL)
                    {
                        save_month = atoi(token);
                        token = strtok(NULL, ",");
                    }
                    if (token != NULL)
                    {
                        save_year = atoi(token);
                        token = strtok(NULL, ",");
                    }
                    if (token != NULL)
                    {
                        save_time = atoi(token);
                        token = strtok(NULL, ",");
                    }
                    if (save_id_card != NULL)
                    {

                        printf("===============================================\n");
                        printf("BOOKING = %d\n", i + 1);
                        printf("===============================================\n");
                        printf("ID Card: %s\n", save_id_card);
                        printf("Username: %s\n", save_username);
                        printf("Service: %s\n", save_service);
                        printf("Day/Month/Year: %d/%d/%d\n",
                               save_day, save_month, save_year);
                        printf("Timer Service: %.2f\n", save_time);
                        printf("===============================================\n");
                    }
                    i++;
                }
                int re;
                printf("1: Return to EmployeeMenu\n");
                printf("Select the desired item: ");
                scanf("%d", &re);
                if (re == 1)
                {
                    employeeMenu(1);
                }
            }
            break;
            default:
                break;
            }
        }
        scanf("%d", &login);
        switch (login)
        {
        case 1:
        {
            if (!(isEmployeeMenu))
            {
                char username[20], password[20];
                printf("Username: ");
                scanf("%s", username);
                printf("Password: ");
                scanf("%s", password);
                FILE *empfile;
                empfile = fopen("./CSV/emplyee.csv", "r");
                if (!empfile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), empfile))
                {
                    char *token = strtok(line, ",");
                    if (token != NULL)
                    {
                        save_username = strdup(token);
                        token = strtok(NULL, ",");
                    }
                    if (token != NULL)
                    {
                        save_password = strdup(token);
                        token = strtok(NULL, ",");
                    }
                    if (token != NULL)
                    {
                        save_role = strdup(token);
                        token = strtok(NULL, ",");
                    }
                    if (strcmp(username, save_username) == 0 &&
                        strcmp(password, save_password) == 0)
                    {
                        found = 1;
                        isEmployeeMenu = 1;
                        printf("login success\n");
                    }
                }
            }
        }

        break;
        default:
            break;
        }
    }
} // end