#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 20
void service(int isService, customers *current)
{
    int case_service, case_time;
    int day, month, year;
    float add_time;
    float save_time;

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

            system("cls");
            printf("===============================\n");
            printf("Plase Choose the desired time\n");
            printf("Time 10.00 - 19.00\n");
            printf("1: 10.00\n");
            printf("2: 10.30\n");
            printf("3: 11.00\n");
            printf("4: 11.30\n");
            printf("5: 13.00\n");
            printf("6: 13.30\n");
            printf("7: 14.00\n");
            printf("8: 14.30\n");
            printf("9: 15.30\n");
            printf("10: 16.00\n");
            printf("11: 16.30\n");
            printf("12: 17.00\n");
            printf("13: 17.30\n");
            printf("14: 18.00\n");
            printf("15: 18.30\n");
            printf("16: 19.00\n");
            printf("Please select a time period: ");
            scanf("%d", &case_time);

            switch (case_time)
            {
            case 1:
            {

                add_time = 10.00;
                FILE *servicefile;
                servicefile = fopen("service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%[^,],%[^,],%f", customerData.id_card, customerData.username, &save_time);
                    if (add_time == save_time)
                    {
                        found = 1;
                        printf("%d\n", found);
                        printf("This time slot has been reserved.\n");
                        break;
                    }
                }
                fclose(servicefile);

                if (!found)
                {

                    printf("%d\n", found);
                    FILE *servicefile;
                    servicefile = fopen("service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%.2f\n", customerData.id_card, customerData.username, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;

            default:
                break;
            }
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