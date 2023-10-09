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
    int case_edit;
    char save_id_card[14], save_username[30];
    int day, month, year;
    int save_day, save_month, save_year;
    float save_time;
    int found = 0;

    ServiceData *servicedata = NULL;
    ServiceList *servicelist = NULL, *head = NULL, *current = NULL, *ptr = NULL;

    system("cls");
    printf("You: f:%s l:%s id:%s\n", customerData.fname, customerData.lname, customerData.id_card);
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
    printf("===============================================1\n");

    while (fgets(line, sizeof(line), editservicefile))
    {
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
            perror("can not service!");
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
        if (strcmp(customerData.id_card, current->data.id_card) == 0 &&
            strcmp(customarData.username, current->data.username) == 0)
        {
            if (current != NULL)
            {
                found = 1;
                printf("Found = 1\n");
                printf("===============================================\n");
                printf("In servicelist\n");
                printf("ID Card: %s\n", current->data.id_card);
                printf("Username: %s\n", current->data.username);
                printf("Day/Month/Year: %d/%d/%d\n",
                       current->data.day, current->data.month, current->data.year);
                printf("Timer Service: %.2f\n", current->data.time);
            }
        }

        // else
        // {
        //     printf("No booking information\n");
        //     printf("===============================\n");
        //     break;
        // }
        printf("\n");
        printf("===============================================\n");
    }
    fclose(editservicefile);
}

// printf("eiei \n");

// printf("ID Card: %s\n", servicedata->id_card);
// printf("Username: %s\n", servicedata->username);
// printf("Day/Month/Year: %d %d %d\n", servicedata->day, servicedata->month, servicedata->year);
// printf("Timer Service: %.2f\n", servicedata->time);
