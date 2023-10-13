#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 20
void service(int isService, customers *current)
{
    int case_service, case_time;
    int day, month, year = 2566;
    int save_day, save_month, save_year;
    char save_id_card[14], save_username[30];
    int inputError = 0;
    float add_time;
    float save_time;

    while (1)
    {
        printf("===============================\n");
        printf("        Menu For Service       \n");
        printf("===============================\n");
        printf("You: %s %s\n", customerData.fname, customerData.lname, customerData.id_card);
        printf("1: Braces\n");
        printf("2: Dental filling\n");
        printf("3: Scrape off tartar\n");
        printf("4: Tooth extraction\n");
        printf("5: Retrun to Customer Menu\n");
        printf("Select Service item: ");
        if (scanf("%d", &case_service) == 1)
        {

            switch (case_service)
            {
            case 1:
            {
                char save_service[30];
                add_time = 0;
                day = 0;
                month = 0;
                year = 2566;
                strcpy(save_service, "Braces");
                printf("===============================\n");
                printf("You%s %s\n", customerData.fname,
                       customerData.lname);
                printf("Service: %s\n", save_service);
                printf("Day: ");
                if (scanf("%d", &day) == 1)
                {
                    if (day < 1 || day > 31)
                    {
                        printf("Please enter a day between 1 and 31.\n");
                        inputError = 1;
                        continue;
                    }
                }
                else
                {
                    printf("Invalid input for the day. Please enter a numeric value.\n");
                    inputError = 1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    continue;
                }

                printf("Month: ");
                if (scanf("%d", &month) == 1)
                {
                    if (month < 1 || month > 12)
                    {
                        printf("Please enter a month between 1 and 12.\n");
                        inputError = 1;
                        continue;
                    }
                }
                else
                {
                    printf("Invalid input for the day. Please enter a numeric value.\n");
                    inputError = 1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    continue;
                }
                if (month == 2 && day > 28)
                {
                    printf("Please Enter again!! February has 28 days.\n");
                    inputError = 1;
                    continue;
                }
                printf("Year: 2566\n");
                printf("Plase Choose the desired time\n");
                printf("Open Booking 10.00 - 19.00\n");
                printf("1: 10.00\n");
                printf("2: 10.30\n");
                printf("3: 11.00\n");
                printf("4: 11.30\n");
                printf("12.00-13.00 Lunch break !!\n");
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
                if (scanf("%d", &case_time) != 1 || case_time < 1 || case_time > 16)
                {
                    printf("Invalid time slot selection.\n");
                    inputError = 1;
                    continue;
                }
                switch (case_time)
                {
                case 1:
                    add_time = 10.00;
                    break;
                case 2:
                    add_time = 10.30;
                    break;
                case 3:
                    add_time = 11.00;
                    break;
                case 4:
                    add_time = 11.30;
                    break;
                case 5:
                    add_time = 13.00;
                    break;
                case 6:
                    add_time = 13.30;
                    break;
                case 7:
                    add_time = 14.00;
                    break;
                case 8:
                    add_time = 14.30;
                    break;
                case 9:
                    add_time = 15.00;
                    break;
                case 10:
                    add_time = 15.30;
                    break;
                case 11:
                    add_time = 16.00;
                    break;
                case 12:
                    add_time = 16.30;
                    break;
                case 13:
                    add_time = 17.00;
                    break;
                case 14:
                    add_time = 17.30;
                    break;
                case 15:
                    add_time = 18.00;
                    break;
                case 16:
                    add_time = 18.30;
                    break;
                default:
                    printf("Invalid time slot selection.\n");
                    return;
                }

                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not open service.csv!");
                    exit(1);
                }

                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    char *token = strtok(line, ",");
                    char *save_id_card, *save_username, *ssave_service;
                    int save_day, save_month, save_year;
                    float saved_time;
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
                        ssave_service = strdup(token);
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
                        saved_time = atof(token); // Use atof to read as a floating-point number
                        token = strtok(NULL, ",");
                    }
                    if (add_time == saved_time && day == save_day &&
                        month == save_month && year == save_year &&
                        strcmp(ssave_service, save_service) == 0)
                    {
                        found = 1;
                        printf("This time slot has been reserved.\n");
                        break;
                    }
                }

                fclose(servicefile);

                if (!found)
                {
                    FILE *servicefile;
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username,
                            save_service, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    printf("%s\n", save_service);
                    fclose(servicefile);
                }
            }
            break;
            case 2:
            {
                char save_service[30];
                add_time = 0;
                day = 0;
                month = 0;
                year = 2566;
                strcpy(save_service, "Dental filling");

                printf("===============================\n");
                printf("You%s %s\n", customerData.fname,
                       customerData.lname);
                printf("Service: %s\n", save_service);
                printf("Day: ");
                if (scanf("%d", &day) == 1)
                {
                    if (day < 1 || day > 31)
                    {
                        printf("Please enter a day between 1 and 31.\n");
                        inputError = 1;
                        continue;
                    }
                }
                else
                {
                    printf("Invalid input for the day. Please enter a numeric value.\n");
                    inputError = 1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    continue;
                }

                printf("Month: ");
                if (scanf("%d", &month) == 1)
                {
                    if (month < 1 || month > 12)
                    {
                        printf("Please enter a month between 1 and 12.\n");
                        inputError = 1;
                        continue;
                    }
                }
                else
                {
                    printf("Invalid input for the day. Please enter a numeric value.\n");
                    inputError = 1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    continue;
                }
                if (month == 2 && day > 28)
                {
                    printf("Please Enter again!! February has 28 days.\n");
                    inputError = 1;
                    continue;
                }
                printf("Year: 2566\n");
                printf("Plase Choose the desired time\n");
                printf("Open Booking 10.00 - 19.00\n");
                printf("1: 10.00\n");
                printf("2: 10.30\n");
                printf("3: 11.00\n");
                printf("4: 11.30\n");
                printf("12.00-13.00 Lunch break !!\n");
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
                if (scanf("%d", &case_time) != 1 || case_time < 1 || case_time > 16)
                {
                    printf("Invalid time slot selection.\n");
                    inputError = 1;
                    continue;
                }
                switch (case_time)
                {
                case 1:
                    add_time = 10.00;
                    break;
                case 2:
                    add_time = 10.30;
                    break;
                case 3:
                    add_time = 11.00;
                    break;
                case 4:
                    add_time = 11.30;
                    break;
                case 5:
                    add_time = 13.00;
                    break;
                case 6:
                    add_time = 13.30;
                    break;
                case 7:
                    add_time = 14.00;
                    break;
                case 8:
                    add_time = 14.30;
                    break;
                case 9:
                    add_time = 15.00;
                    break;
                case 10:
                    add_time = 15.30;
                    break;
                case 11:
                    add_time = 16.00;
                    break;
                case 12:
                    add_time = 16.30;
                    break;
                case 13:
                    add_time = 17.00;
                    break;
                case 14:
                    add_time = 17.30;
                    break;
                case 15:
                    add_time = 18.00;
                    break;
                case 16:
                    add_time = 18.30;
                    break;
                default:
                    printf("Invalid time slot selection.\n");
                    return;
                }

                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not open service.csv!");
                    exit(1);
                }

                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    char *token = strtok(line, ",");
                    char *save_id_card, *save_username, *ssave_service;
                    int save_day, save_month, save_year;
                    float saved_time;
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
                        ssave_service = strdup(token);
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
                        saved_time = atof(token); // Use atof to read as a floating-point number
                        token = strtok(NULL, ",");
                    }
                    if (add_time == saved_time && day == save_day &&
                        month == save_month && year == save_year &&
                        strcmp(ssave_service, save_service) == 0)
                    {
                        found = 1;
                        printf("This time slot has been reserved.\n");
                        break;
                    }
                }

                fclose(servicefile);

                if (!found)
                {
                    FILE *servicefile;
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username,
                            save_service, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    printf("%s\n", save_service);
                    fclose(servicefile);
                }
            }
            break;
            case 3:
            {

                char save_service[30];
                add_time = 0;
                day = 0;
                month = 0;
                year = 2566;
                strcpy(save_service, "Scrape off tartar");

                printf("===============================\n");
                printf("You%s %s\n", customerData.fname,
                       customerData.lname);
                printf("Service: %s\n", save_service);
                printf("Day: ");
                if (scanf("%d", &day) == 1)
                {
                    if (day < 1 || day > 31)
                    {
                        printf("Please enter a day between 1 and 31.\n");
                        inputError = 1;
                        continue;
                    }
                }
                else
                {
                    printf("Invalid input for the day. Please enter a numeric value.\n");
                    inputError = 1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    continue;
                }

                printf("Month: ");
                if (scanf("%d", &month) == 1)
                {
                    if (month < 1 || month > 12)
                    {
                        printf("Please enter a month between 1 and 12.\n");
                        inputError = 1;
                        continue;
                    }
                }
                else
                {
                    printf("Invalid input for the day. Please enter a numeric value.\n");
                    inputError = 1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    continue;
                }
                if (month == 2 && day > 28)
                {
                    printf("Please Enter again!! February has 28 days.\n");
                    inputError = 1;
                    continue;
                }
                printf("Year: 2566\n");
                printf("Plase Choose the desired time\n");
                printf("Open Booking 10.00 - 19.00\n");
                printf("1: 10.00\n");
                printf("2: 10.30\n");
                printf("3: 11.00\n");
                printf("4: 11.30\n");
                printf("12.00-13.00 Lunch break !!\n");
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
                if (scanf("%d", &case_time) != 1 || case_time < 1 || case_time > 16)
                {
                    printf("Invalid time slot selection.\n");
                    inputError = 1;
                    continue;
                }
                switch (case_time)
                {
                case 1:
                    add_time = 10.00;
                    break;
                case 2:
                    add_time = 10.30;
                    break;
                case 3:
                    add_time = 11.00;
                    break;
                case 4:
                    add_time = 11.30;
                    break;
                case 5:
                    add_time = 13.00;
                    break;
                case 6:
                    add_time = 13.30;
                    break;
                case 7:
                    add_time = 14.00;
                    break;
                case 8:
                    add_time = 14.30;
                    break;
                case 9:
                    add_time = 15.00;
                    break;
                case 10:
                    add_time = 15.30;
                    break;
                case 11:
                    add_time = 16.00;
                    break;
                case 12:
                    add_time = 16.30;
                    break;
                case 13:
                    add_time = 17.00;
                    break;
                case 14:
                    add_time = 17.30;
                    break;
                case 15:
                    add_time = 18.00;
                    break;
                case 16:
                    add_time = 18.30;
                    break;
                default:
                    printf("Invalid time slot selection.\n");
                    return;
                }

                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not open service.csv!");
                    exit(1);
                }

                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    char *token = strtok(line, ",");
                    char *save_id_card, *save_username, *ssave_service;
                    int save_day, save_month, save_year;
                    float saved_time;
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
                        ssave_service = strdup(token);
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
                        saved_time = atof(token); // Use atof to read as a floating-point number
                        token = strtok(NULL, ",");
                    }
                    if (add_time == saved_time && day == save_day &&
                        month == save_month && year == save_year &&
                        strcmp(ssave_service, save_service) == 0)
                    {
                        found = 1;
                        printf("This time slot has been reserved.\n");
                        break;
                    }
                }

                fclose(servicefile);
                if (!found)
                {
                    FILE *servicefile;
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username,
                            save_service, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    printf("%s\n", save_service);
                    fclose(servicefile);
                }
            }
            break;
            case 4:
            {
                char save_service[30];
                add_time = 0;
                day = 0;
                month = 0;
                year = 2566;
                strcpy(save_service, "Tooth extraction");

                printf("===============================\n");
                printf("You%s %s\n", customerData.fname,
                       customerData.lname);
                printf("Service: %s\n", save_service);
                printf("Day: ");
                if (scanf("%d", &day) == 1)
                {
                    if (day < 1 || day > 31)
                    {
                        printf("Please enter a day between 1 and 31.\n");
                        inputError = 1;
                        continue;
                    }
                }
                else
                {
                    printf("Invalid input for the day. Please enter a numeric value.\n");
                    inputError = 1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    continue;
                }

                printf("Month: ");
                if (scanf("%d", &month) == 1)
                {
                    if (month < 1 || month > 12)
                    {
                        printf("Please enter a month between 1 and 12.\n");
                        inputError = 1;
                        continue;
                    }
                }
                else
                {
                    printf("Invalid input for the day. Please enter a numeric value.\n");
                    inputError = 1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    continue;
                }
                if (month == 2 && day > 28)
                {
                    printf("Please Enter again!! February has 28 days.\n");
                    inputError = 1;
                    continue;
                }
                printf("Year: 2566\n");
                printf("Plase Choose the desired time\n");
                printf("Open Booking 10.00 - 19.00\n");
                printf("1: 10.00\n");
                printf("2: 10.30\n");
                printf("3: 11.00\n");
                printf("4: 11.30\n");
                printf("12.00-13.00 Lunch break !!\n");
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
                if (scanf("%d", &case_time) != 1 || case_time < 1 || case_time > 16)
                {
                    printf("Invalid time slot selection.\n");
                    inputError = 1;
                    continue;
                }
                switch (case_time)
                {
                case 1:
                    add_time = 10.00;
                    break;
                case 2:
                    add_time = 10.30;
                    break;
                case 3:
                    add_time = 11.00;
                    break;
                case 4:
                    add_time = 11.30;
                    break;
                case 5:
                    add_time = 13.00;
                    break;
                case 6:
                    add_time = 13.30;
                    break;
                case 7:
                    add_time = 14.00;
                    break;
                case 8:
                    add_time = 14.30;
                    break;
                case 9:
                    add_time = 15.00;
                    break;
                case 10:
                    add_time = 15.30;
                    break;
                case 11:
                    add_time = 16.00;
                    break;
                case 12:
                    add_time = 16.30;
                    break;
                case 13:
                    add_time = 17.00;
                    break;
                case 14:
                    add_time = 17.30;
                    break;
                case 15:
                    add_time = 18.00;
                    break;
                case 16:
                    add_time = 18.30;
                    break;
                default:
                    printf("Invalid time slot selection.\n");
                    return;
                }

                FILE *servicefile;
                servicefile = fopen("./CSV/service.csv", "r");
                if (!servicefile)
                {
                    perror("Can not open service.csv!");
                    exit(1);
                }

                int found = 0;
                char line[1024];
                while (fgets(line, sizeof(line), servicefile))
                {
                    char *token = strtok(line, ",");
                    char *save_id_card, *save_username, *ssave_service;
                    int save_day, save_month, save_year;
                    float saved_time;
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
                        ssave_service = strdup(token);
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
                        saved_time = atof(token); // Use atof to read as a floating-point number
                        token = strtok(NULL, ",");
                    }
                    if (add_time == saved_time && day == save_day &&
                        month == save_month && year == save_year &&
                        strcmp(ssave_service, save_service) == 0)
                    {
                        found = 1;
                        printf("This time slot has been reserved.\n");
                        break;
                    }
                }

                fclose(servicefile);
                if (!found)
                {
                    FILE *servicefile;
                    servicefile = fopen("./CSV/service.csv", "a");
                    if (!servicefile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }
                    fprintf(servicefile, "%s,%s,%s,%d,%d,%d,%.2f\n", customerData.id_card, customerData.username,
                            save_service, day, month, year, add_time);
                    printf("Booking Successfully!!!\n");
                    printf("%.2f\n", add_time);
                    printf("%s\n", save_service);
                    fclose(servicefile);
                }
            }
            case 5:
                customerMenu(1);
                return;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
        else
        {
            printf("Invalid choice. Please enter a numeric choice.\n");
            // Consume any remaining characters in the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    }
}