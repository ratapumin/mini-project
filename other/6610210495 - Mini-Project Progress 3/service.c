#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 20
void service(int isService, customers customerData)
{
    int case_service, case_time;
    int day, month, year;
    int save_day, save_month, save_year;
    float add_time;
    float save_time;
    // char save_id_card[13];
    // strcpy(save_id_card, customerData.id_card);
    while (1)
    {
        printf("===============================\n");
        printf("Menu Service\n");
        printf("%s %s \n", customerData.fname, customerData.lname);
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
            printf("%s %s\n", customerData.fname, customerData.lname);
            printf("Date: ");
            scanf("%d", &day);
            printf("Mounth: ");
            scanf("%d", &month);
            printf("Year: ");
            scanf("%d", &year);
            printf("Plase Choose the desired time\n");
            printf("Open 10.00 - 19.00\n");
            printf("1: 10.00\n");
            printf("2: 10.30\n");
            printf("3: 11.00\n");
            printf("4: 11.30\n");
            printf("5: 13.00\n");
            printf("6: 13.30\n");
            printf("7: 14.00\n");
            printf("8: 14.30\n");
            printf("9: 15.00\n");
            printf("10: 15.30\n");
            printf("11: 16.00\n");
            printf("12: 16.30\n");
            printf("13: 17.00\n");
            printf("14: 17.30\n");
            printf("15: 18.00\n");
            printf("16: 18.30\n");
            printf("Please select a time period: ");
            scanf("%d", &case_time);

            switch (case_time)
            {
            case 1:
            {
                add_time = 10.00;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                    printf("%s %s\n", customerData.fname, customerData.lname);
                }
            }
            break;
            case 2:
            {

                add_time = 10.30;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
                    {
                        found = 1;
                        printf("%d\n", found);
                        printf("%s %s\n", customerData.fname, customerData.lname);
                        printf("This time slot has been reserved.\n");
                        break;
                    }
                }
                fclose(servicefile);

                if (!found)
                {

                    printf("%d\n", found);
                    FILE *servicefile;
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 3:
            {

                add_time = 11.00;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 4:
            {

                add_time = 11.30;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 5:
            {

                add_time = 13.00;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 6:
            {

                add_time = 13.30;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 7:
            {

                add_time = 14.00;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 8:
            {

                add_time = 14.30;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 9:
            {

                add_time = 15.00;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 10:
            {

                add_time = 15.30;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 11:
            {

                add_time = 16.00;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 12:
            {

                add_time = 16.30;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 13:
            {

                add_time = 17.00;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 14:
            {

                add_time = 17.30;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);

                    fclose(servicefile);
                }
            }
            break;
            case 15:
            {

                add_time = 18.00;
                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    fclose(servicefile);
                }
            }
            break;
            case 16:
            {

                add_time = 18.30;
                FILE *servicefile;
                servicefile = fopen("./CSV/./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not opening customer.csv!");
                    exit(1);
                }
                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    sscanf(line, "%d,%d,%d,%f", &save_day, &save_month, &save_year, &save_time);
                    if (add_time == save_time && day == save_day && month == save_month && year == save_year)
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
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username, day, month, year, add_time);
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