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
    // char save_username[20], save_password[20], save_fname[50], save_lname[50];
    // char save_id_card[13], save_pnumber[10], save_address[100];
    // int save_age;
    // int save_day, save_month, save_year;
    int isService = 0;
    int isEditService = 0;
    int isdeleteService = 0;

    customers *cust = NULL,
              *current = NULL;

    while (1)
    {
        printf("===============================\n");
        printf("Menu For Customer\n");

        if (!(isCustomerLoggedIn))
        {
            printf("1: Login\n");
            printf("2: Register\n");
            printf("3: Forget Password\n");
            printf("4: Return to Main Menu\n");
            printf("Select the desired item: ");
        }
        else
        {

            printf("===============================\n");
            printf("fname: %s lname: %s\n", customerData.fname, customerData.lname);
            printf("id_card: %s \n", customerData.id_card);
            printf("1: Booking service\n");
            printf("2: Edit service\n");
            printf("3: Delete service\n");
            printf("4: Logout\n");
            printf("Select the desired item: ");
            scanf("%d", &logout);
            switch (logout)
            {
            case 1:
            {

                if (isCustomerLoggedIn)
                {
                    service(isService, current);
                }
            }
            break;
            case 2:
            {
                if (isCustomerLoggedIn)
                {
                    EditService(isEditService, customerData);
                }
            }
            break;
            case 3:
            {
                delectService(isdeleteService, customerData);
            }
            break;

            case 4:

                if (isCustomerLoggedIn)
                {
                    current = NULL;
                    free(current);
                    isCustomerLoggedIn = 0;
                    printf("Logout Successfully!\n");
                    return free(current);
                }
                break;
            default:
                break;
            }
        }
        scanf("%d", &login);
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
                        printf("===============================\n");
                        printf("Login Successfully!\n");
                        printf("user: %s password: %s \n", customerData.username, customerData.password);
                        printf("fname: %s lname: %s\n", customerData.fname, customerData.lname);
                        printf("day: %d month: %d year: %d age: %d\n", customerData.day, customerData.month, customerData.year, customerData.age);
                        printf("id_card: %s pnumber:(+66) %s\n", customerData.id_card, customerData.pnumber);
                        printf("address: %s\n", customerData.address);
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
                        printf("has username\n");
                    }
                    if (strcmp(cust->id_card, save_id_card) == 0)
                    {
                        found = 1;
                        printf("has id_card\n");
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
            if (login == 4)
            {
                return;
            }
            break;
        } // close switch case login
    }
} // end