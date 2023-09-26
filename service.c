#include <stdio.h>
#include <stdlib.h>
#define maxSize 20

void service(int *isService)
{
    int case_service;
    char date_service[maxSize], time_service[maxSize];
    while (1)
    {
        printf("===============================\n");
        printf("Menu Service\n");
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

            fprintf(servicefile, "%s,%s,%s,\n", username, date_service, time_service);
            prinf("Booking Successfully!!!\n");
            fclose(servicefile);
            break;
        }
        break;

        default:
            break;
        }
    }
}