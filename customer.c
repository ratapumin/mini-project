#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct customer
{
    char username[20];
    char password[20];
    char fname[50];
    char lname[50];
    int day;
    int month;
    int year;
    int age;
    char id_card[14];
    char pnumber[11];
    char address[100];
    struct customer *next;

} customers;

customers customerData;

void service(int isService, customers *current);
void EditService(int isEditService, customers customerData);
void delectService(int isdeleteService, customers customerData);

char *getTel(int pass_len)
{
    const int PASS_LEN = pass_len;
    char *tel = (char *)malloc((PASS_LEN + 1) * sizeof(char)); // +1 for null terminator
    char ch;
    int i = 0;

    while (i <= PASS_LEN)
    {
        ch = getch();

        if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch >= '0' && ch <= '9' && i < PASS_LEN)
        { // Only accept numeric characters and up to 6 digits
            tel[i] = ch;
            printf("%c", tel[i]);
            i++;
        }

        if (ch == 13 && i < PASS_LEN)
        {
            break;
        }

        if (i == PASS_LEN && ch == 13)
        {
            tel[i] = '\0';
            printf("\n");
            break;
        }
    }

    printf("\n");
    return tel;
}
void customerMenu(int isCustomerLoggedIn)
{
    int login, logout;
    int isService = 0;
    int isEditService = 0;
    int isdeleteService = 0;
    int i = 0;
    customers *cust = NULL,
              *current = NULL;

    while (1)
    {
        printf("===============================\n");
        printf("       Menu For Customer       \n");
        printf("===============================\n");

        if (!(isCustomerLoggedIn))
        {
            printf("1: Login\n");
            printf("2: Register\n");
            printf("3: Forget Password\n");
            printf("4: Return to Main Menu\n");
            printf("Select the desired item: ");
            if (scanf("%d", &login) == 1)
            {
                switch (login)
                {
                case 1:
                {
                    if (!(isCustomerLoggedIn))
                    {
                        char username[20], password[20];
                        printf("Username: ");
                        scanf("%s", username);
                        printf("Password: ");
                        scanf("%s", password);

                        FILE *cusfile;
                        cusfile = fopen("./CSV/customer.csv", "r");
                        if (!cusfile)
                        {
                            perror("Can not opening customer.csv!");
                            exit(1);
                        }
                        int found = 0;
                        char line[1024];
                        while (fgets(line, sizeof(line), cusfile))
                        {

                            char *token = strtok(line, ",");
                            char *save_username, *save_password, *save_fname, *save_lname, *save_id_card, *save_pnumber, *save_address;
                            int save_day, save_month, save_year, save_age;
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
                                save_fname = strdup(token);
                                token = strtok(NULL, ",");
                            }
                            if (token != NULL)
                            {
                                save_lname = strdup(token);
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
                                save_age = atoi(token);
                                token = strtok(NULL, ",");
                            }
                            if (token != NULL)
                            {
                                save_id_card = strdup(token);
                                token = strtok(NULL, ",");
                            }
                            if (token != NULL)
                            {
                                save_pnumber = strdup(token);
                                token = strtok(NULL, ",");
                            }
                            if (token != NULL)
                            {
                                save_address = strdup(token);
                                // token = strtok(NULL, ",");
                            }

                            if (strcmp(username, save_username) == 0 &&
                                strcmp(password, save_password) == 0)
                            {
                                found = 1;
                                isCustomerLoggedIn = 1;
                                // system("cls");

                                current = (customers *)malloc(sizeof(customers));
                                if (current == NULL)
                                {
                                    perror("current == NULL");
                                    exit(1);
                                }
                                strcpy(current->username, save_username);
                                strcpy(current->password, save_password);
                                strcpy(current->fname, save_fname);
                                strcpy(current->lname, save_lname);
                                current->day = save_day;
                                current->month = save_month;
                                current->year = save_year;
                                current->age = save_age;
                                strcpy(current->id_card, save_id_card);
                                strcpy(current->pnumber, save_pnumber);
                                strcpy(current->address, save_address);

                                /* --------------------------------------------------- */

                                strcpy(customerData.username, current->username);
                                strcpy(customerData.password, current->password);
                                strcpy(customerData.fname, current->fname);
                                strcpy(customerData.lname, current->lname);
                                customerData.day = save_day;
                                customerData.month = save_month;
                                customerData.year = save_year;
                                customerData.age = save_age;

                                strcpy(customerData.id_card, current->id_card);
                                strcpy(customerData.pnumber, current->pnumber);
                                strcpy(customerData.address, current->address);

                                // system("cls");
                                break;
                            }
                        }
                        fclose(cusfile);
                        if (!found)
                        {
                            printf("Login failed. Wrong username or password.\n");
                        }
                    }
                    else
                    {
                        printf("You are logged in.\n");
                    }
                }
                break;
                case 2:
                {
                    {
                        // add customer
                        printf("Register\n");
                        cust = (customers *)malloc(sizeof(customers));
                        if (cust == NULL)
                        {
                            perror("cust == NULL");
                            exit(1);
                        }
                        printf("Username: ");
                        scanf("%s", cust->username);
                        printf("Password: ");
                        scanf("%s", cust->password);
                        printf("First Name: ");
                        scanf("%s", cust->fname);
                        printf("Last Name: ");
                        scanf("%s", cust->lname);
                        printf("Date of birth (dd/mm/yyyy)\n");
                        printf("Day(01/mm/yyyy): ");
                        scanf("%d", &cust->day);
                        printf("Month(dd/01/yyyy): ");
                        scanf("%d", &cust->month);
                        printf("Year(dd/mm/2543): ");
                        scanf("%d", &cust->year);
                        printf("Age: ");
                        scanf("%d", &cust->age);
                        while (getchar() != '\n')
                            ;
                        printf("Id Card: ");
                        strcpy(cust->id_card, getTel(13));
                        printf("Phone Number: ");
                        strcpy(cust->pnumber, getTel(10));
                        printf("Address: ");
                        fgets(cust->address, sizeof(cust->address), stdin);

                        cust->address[strcspn(cust->address, "\n")] = '\0';

                        FILE *cusfile;
                        cusfile = fopen("./CSV/customer.csv", "r");

                        if (!cusfile)
                        {
                            perror("Error opening file");
                            exit(1); // Exit the program if the file couldn't be opened
                        }

                        // fgets(input, maxSize, stdin);
                        int found = 0;
                        char line[1024];
                        while (fgets(line, sizeof(line), cusfile))
                        {

                            char *token = strtok(line, ",");
                            char *save_username, *save_password, *save_fname, *save_lname, *save_id_card, *save_pnumber, *save_address;
                            int save_day, save_month, save_year, save_age;
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
                                save_fname = strdup(token);
                                token = strtok(NULL, ",");
                            }
                            if (token != NULL)
                            {
                                save_lname = strdup(token);
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
                                save_age = atoi(token);
                                token = strtok(NULL, ",");
                            }
                            if (token != NULL)
                            {
                                save_id_card = strdup(token);
                                token = strtok(NULL, ",");
                            }
                            if (token != NULL)
                            {
                                save_pnumber = strdup(token);
                                token = strtok(NULL, ",");
                            }
                            if (token != NULL)
                            {
                                save_address = strdup(token);
                                // token = strtok(NULL, ",");
                            }
                            if (strcmp(cust->username, save_username) == 0)

                            {
                                found = 1;
                                printf("Sorry, this Username already exists.\n");
                            }
                            if (strcmp(cust->id_card, save_id_card) == 0)
                            {
                                found = 1;
                                printf("Sorry, this ID card already exists.\n");
                                break;
                            }
                        }
                        fclose(cusfile);

                        // savefile
                        if (!found)
                        {
                            cusfile = fopen("./CSV/customer.csv", "a");
                            if (!cusfile)
                            {
                                perror("Can not opening customer.csv!");
                                exit(1);
                            }
                            fprintf(cusfile, "%s,%s,%s,%s,%d,%d,%d,%d,%s,%s,%s\n",
                                    cust->username,
                                    cust->password,
                                    cust->fname,
                                    cust->lname,
                                    cust->day,
                                    cust->month,
                                    cust->year,
                                    cust->age,
                                    cust->id_card,
                                    cust->pnumber,
                                    cust->address);
                            printf("Register Successfully\n");

                            fclose(cusfile);
                            free(cust);
                            break;
                        }
                    }
                }
                break;
                case 3:
                {
                    printf("forget password\n");
                }
                break;
                case 4:
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
            } // close switch case login
        }
        else
        {

            printf("You: %s %s\n", customerData.fname, customerData.lname);
            printf("1: Booking service\n");
            printf("2: Edit service\n");
            printf("3: Delete service\n");
            printf("4: View reservation list\n");
            printf("5: Logout\n");
            printf("Select the desired item: ");
            if (scanf("%d", &logout) == 1)
            {
                switch (logout)
                {
                case 1:

                    if (isCustomerLoggedIn)
                    {
                        service(isService, current);
                    }

                    break;
                case 2:

                    if (isCustomerLoggedIn)
                    {
                        EditService(isEditService, customerData);
                    }

                    break;
                case 3:

                    delectService(isdeleteService, customerData);
                    break;
                case 4:
                {
                    printf("===============================\n");
                    printf("You: %s %s\n", current->fname, current->lname);
                    printf("===============================\n");

                    FILE *viewServiceFile;
                    viewServiceFile = fopen("./CSV/service.csv", "r");
                    if (!viewServiceFile)
                    {
                        perror("Error opening file");
                        exit(1);
                    }

                    char line[1024];
                    int row = 0;

                    while (fgets(line, sizeof(line), viewServiceFile))
                    {
                        if (row == 0)
                        {
                            strtok(line, ","); // Skip the header row
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
                            save_service = strdup(token); // Read and save the service correctly
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
                            save_time = atof(token); // Use atof for floating-point numbers
                            token = strtok(NULL, ",");
                        }

                        if (save_id_card != NULL && save_service != NULL) // Make sure save_service is not NULL
                        {
                            if (strcmp(customerData.id_card, save_id_card) == 0 && strcmp(customerData.username, save_username) == 0)
                            {
                                printf("===============================================\n");
                                printf("BOOKING = %d\n", row);
                                printf("===============================================\n");
                                printf("ID Card: %s\n", save_id_card);
                                printf("Username: %s\n", save_username);
                                printf("Service: %s\n", save_service);
                                printf("Day/Month/Year: %d/%d/%d\n", save_day, save_month, save_year);
                                printf("Timer Service: %.2f\n", save_time);
                                printf("===============================================\n");
                            }
                        }
                        row++;
                    }

                    fclose(viewServiceFile);
                    break;
                }

                case 5:

                    if (isCustomerLoggedIn)
                    {
                        current = NULL;
                        free(current);
                        isCustomerLoggedIn = 0;
                        customerMenu(0);
                        return;
                    }
                    break;
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
} // end