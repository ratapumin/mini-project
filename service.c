#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 20
typedef struct customer
{
    char username[20];
    char password[20];
    char fname[50];
    char lname[50];
    char date[10];
    int age;
    char id_card[13];
    char pnumber[10];
    char address[100];
    struct customer *next;
} customers;
void service(int *isService, customers *current)
{
    int case_service;
    char save_username[20];
    char save_id_card[13];
    char date_service[maxSize], time_service[maxSize];

    strcpy(save_username, current->username);
    strcpy(save_id_card, current->id_card);
    while (1)
    {
        printf("===============================\n");
        printf("Menu Service\n");
        printf("%s", save_username);
        printf("1: Braces\n");
        printf("2: Dental filling\n");
        printf("3: Scrape off tartar\n");
        printf("4: Tooth extraction\n");
        printf("Select Service item\n");
        scanf("%d", &case_service);
        switch (case_service)
        {
        case 1:
        {
            FILE *servicefile;
            servicefile = fopen("service.csv", "w");
            if (!servicefile)
            {
                perror("Can not opening customer.csv!");
                exit(1);
            }
            printf("===============================\n");
            printf("Braces\n");
            printf("Date: ");
            fgets(date_service, maxSize, stdin);
            printf("Time: ");
            fgets(time_service, maxSize, stdin);

            fprintf(servicefile, "%s,%s,%s,%s\n", save_id_card, save_username, date_service, time_service);
            printf("Booking Successfully!!!\n");
            fclose(servicefile);
            break;
        }
        break;

        default:
            break;
        }
    }
}