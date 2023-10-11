#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef struct ServiceData
{
    char id_card[14];
    char username[20];
    int day;
    int month;
    int year;
    float time;

} ServiceData;

typedef struct ServiceList
{
    ServiceData data;
    struct ServiceList *next;
} ServiceList;

void EditService(int isEditService, customers customarData)
{
    int case_edit, case_time;
    char save_id_card[14], save_username[30];
    int day, month, year;
    int save_day, save_month, save_year;
    float add_time, save_time;
    int found = 0;
    int i = 0;

    ServiceData *servicedata = NULL;
    ServiceList *servicelist = NULL, *head = NULL, *current = NULL, *ptr = NULL;

    system("cls");
    printf("You: f:%s l:%s id:%s\n",
           customerData.fname,
           customerData.lname,
           customerData.id_card);
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
        // if (row == 0)
        // {
        //     strtok(line, ",");
        //     row++;
        //     continue;
        // }
        char *token = strtok(line, ",");
        char *save_id_card, *save_username;
        int save_day, save_month, save_year, save_time;

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
        servicedata = (ServiceData *)malloc(sizeof(ServiceData));
        strcpy(servicedata->id_card, save_id_card);
        strcpy(servicedata->username, save_username);
        servicedata->day = save_day;
        servicedata->month = save_month;
        servicedata->year = save_year;
        servicedata->time = save_time;

        if (servicedata == NULL)
        {
            perror("can not service!\n");
            exit(1);
        }

        servicelist = (ServiceList *)malloc(sizeof(ServiceList));
        servicelist->data = *servicedata;
        servicelist->next = NULL;

        if (!head)
        {
            head = servicelist;
            current = head;
        }
        else
        {
            current->next = servicelist;
            current = current->next;
        }

        if (servicelist != NULL)
        {
            if (strcmp(customerData.id_card, servicelist->data.id_card) == 0 &&
                strcmp(customarData.username, servicelist->data.username) == 0)
            {
                found = 1;
                printf("===============================================\n");
                printf("BOOKING = %d\n", i + 1);
                printf("===============================================\n");
                printf("ID Card: %s\n", servicelist->data.id_card);
                printf("Username: %s\n", servicelist->data.username);
                printf("Day/Month/Year: %d/%d/%d\n",
                       servicelist->data.day, servicelist->data.month, servicelist->data.year);
                printf("Timer Service: %.2f\n", servicelist->data.time);
                printf("===============================================\n");

                i++;
            }
            printf("\n");
        }
        else
        {
            printf("No booking information\n");
            printf("===============================\n");
            break;
        }
    }
    fclose(editservicefile);

    if (found)
    {
        printf("Enter The booking number you want to edit: ");
        scanf("%d", &case_edit);

        if (case_edit < 1 || case_edit > i)
        {
            printf("Invalid booking number. Please enter a valid number.\n");
        }
        else
        {
            int current_booking = 0;
            ptr = head;

            while (ptr != NULL)
            {

                if (strcmp(customerData.id_card, ptr->data.id_card) == 0 &&
                    strcmp(customerData.username, ptr->data.username) == 0)
                    current_booking++;

                if (current_booking == case_edit)
                {
                    system("cls");
                    printf("===============================================\n");
                    printf("BOOKING = %d\n", case_edit);
                    printf("===============================================\n");
                    printf("ID Card: %s\n", ptr->data.id_card);
                    printf("Username: %s\n", ptr->data.username);
                    printf("Day/Month/Year: %d/%d/%d\n",
                           ptr->data.day, ptr->data.month, ptr->data.year);
                    printf("Timer Service: %.2f\n", ptr->data.time);
                    printf("===============================================\n");

                    printf("===============================================\n");
                    printf("|                 EDIT BOOKING                 |\n");
                    printf("===============================================\n");
                    printf("ID Card: %s\n", ptr->data.id_card);
                    printf("Username: %s\n", ptr->data.username);
                    printf("Date, month, year that you want to change\n");
                    printf("Day: ");
                    scanf("%d", &day);
                    printf("Month: ");
                    scanf("%d", &month);
                    printf("Year: ");
                    scanf("%d", &year);

                    printf("Time to change\n");
                    printf("Open 10.00 - 19.00\n");
                    printf("time: ");
                    scanf("%f", &add_time);
                    ptr->data.day = day;
                    ptr->data.month = month;
                    ptr->data.year = year;
                    ptr->data.time = add_time;

                    break;
                }
                ptr = ptr->next;
            }
            FILE *editservicefile;
            editservicefile = fopen("./CSV/service.csv", "w");
            if (!editservicefile)
            {
                perror("Error opening file");
                exit(1);
            }

            ServiceList *current = head;
            while (current != NULL)
            {
                fprintf(editservicefile, "%s,%s,%d,%d,%d,%.2f\n", current->data.id_card, current->data.username,
                        current->data.day, current->data.month, current->data.year, current->data.time);
                current = current->next;
            }

            fclose(editservicefile);

            printf("Booking updated successfully!\n");
            customerMenu(1);
        }
    }

} // end

// i = 0;

// printf("head\n");
// while (head != NULL)
// {

//     printf("===============================================\n");
//     printf("BOOKING = %d\n", i);
//     printf("===============================================\n");
//     printf("ID Card: %s\n", head->data.id_card);
//     printf("Username: %s\n", head->data.username);
//     printf("Day/Month/Year: %d/%d/%d\n",
//            head->data.day, head->data.month, head->data.year);
//     printf("Timer Service: %.2f\n", head->data.time);
//     printf("===============================================\n");
//     head = head->next;
//     i++;
// }

// i = 1;
// ptr = head;
// while (ptr != NULL)
// {

//     printf("===============================================\n");
//     printf("BOOKING = %d\n", i);
//     printf("===============================================\n");
//     printf("ID Card: %s\n", ptr->data.id_card);
//     printf("Username: %s\n", ptr->data.username);
//     printf("Day/Month/Year: %d/%d/%d\n",
//            ptr->data.day, ptr->data.month, ptr->data.year);
//     printf("Timer Service: %.2f\n", ptr->data.time);
//     printf("===============================================\n");
//     ptr = ptr->next;
//     i++;
// }