#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 20
void service(int isService, customers *current)
{
    int case_service;
    int day, month, year;
    int hour, minute;

    while (1)
    {
        printf("===============================\n");
        printf("Menu Service\n");
        printf("%s %s\n", customerData.fname, customerData.lname);
        printf("1: Braces\n");
        printf("2: Dental filling\n");
        printf("3: Scrape off tartar\n");
        printf("4: Tooth extraction\n");
        printf("5: Retrun to Customer Menu\n");
        printf("Select Service item: ");
        scanf("%d", &case_service);
        switch (case_service)
        {
        case 1:
        {
            FILE *servicefile;
            servicefile = fopen("service.csv", "a");
            if (!servicefile)
            {
                perror("Can not opening customer.csv!");
                exit(1);
            }
            printf("===============================\n");
            printf("Braces\n");
            printf("Day (01/xx/xxxx): ");
            scanf("%d", &day);
            printf("Month (xx/01/xxxx): ");
            scanf("%d", &month);
            printf("Year (xx/xx/2001): ");
            scanf("%d", &year);
            printf("Hour: ");
            scanf("%d", &hour);
            printf("Minute:");
            scanf("%d", &minute);

            fprintf(servicefile, "%s,%s,%d,%d,%d,%d,%d\n", customerData.id_card, customerData.username, day, month, year, hour, minute);
            printf("Booking Successfully!!!\n");
            fclose(servicefile);
            break;
        }
        break;
        case 2:
        {
            printf("2: Dental filling\n");
        }
        break;
        case 5:
            return;
        default:
        {
            printf("Invalid choice. Please try again.\n");
        }
        break;
        }
    }
}