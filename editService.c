#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    struct ServiceNode *next;
} ServiceList;

void EditService(int isEditService, customers customarData)
{
    int case_edit;
    char save_id_card[14], save_username[30];
    int day, month, year;
    int save_day, save_month, save_year;
    float save_time;

    ServiceData *servicedata = NULL;
    ServiceList *servicelist = NULL;

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
        sscanf(line, "%[^,],%[^,],%d,%d,%d,%f", save_id_card, save_username,
               &save_day, &save_month, &save_year, &save_time);

        // char *token = strtok(line, ",");
        // char *save_id_card, *save_username;
        // int save_day, save_month, save_year, save_time;
        // if (token != NULL)
        // {
        //     save_id_card = strdup(token);
        //     token = strtok(NULL, ",");
        // }
        // if (token != NULL)
        // {
        //     save_username = strdup(token);
        //     token = strtok(NULL, ",");
        // }
        // if (token != NULL)
        // {
        //     save_day = atoi(token);
        //     token = strtok(NULL, ",");
        // }
        // if (token != NULL)
        // {
        //     save_month = atoi(token);
        //     token = strtok(NULL, ",");
        // }
        // if (token != NULL)
        // {
        //     save_year = atoi(token);
        //     token = strtok(NULL, ",");
        // }
        // if (token != NULL)
        // {
        //     save_time = atoi(token);
        //     token = strtok(NULL, ",");
        // }

        // strcpy(servicedata->id_card, save_id_card);
        // strcpy(servicedata->username, save_username);
        // strcpy(servicedata->day, save_day);
        // strcpy(servicedata->month, save_month);
        // strcpy(servicedata->year, save_year);
        // servicedata->time = save_time;
        // // servicedata->next = NULL;

        // printf("ID Card: %d", servicedata->id_card);
        // printf("Username: %s", servicedata->username);
        // printf("Day/Month/Year: %d %d %d", servicedata->day, servicedata->month, servicedata->year);
        // printf("Timer Service: %.2f", servicedata->time);
        // // servicelist = servicedata;
        if (strcmp(customerData.id_card, save_id_card) == 0)
        {
            column = 0;
            row++;
            if (row == 0)
                continue;
            char *value = strtok(line, ",");
            while (value)
            {
                if (column == 0)
                {
                    printf("id_card: ");
                }
                if (column == 1)
                {
                    printf("\nusername: ");
                }
                if (column == 2)
                {
                    printf("\ndate: ");
                }
                if (column == 3)
                {
                    printf("\nmonth: ");
                }
                if (column == 4)
                {
                    printf("\nyear: ");
                }
                if (column == 5)
                {
                    printf("\ntime: ");
                }
                printf("%s ", value);
                value = strtok(NULL, ",");
                column++;
            }
            printf("\n");
            printf("===============================================\n");
        }
        // else
        // {
        //     printf("No booking information\n");
        //     break;
        // }
    }
    fclose(editservicefile);
}