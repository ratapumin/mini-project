#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer
{
    char username[20];
    char password[20];
    char fname[50];
    char lname[50];
    char date[12];
    int age;
    char id_card[13];
    char pnumber[10];
    char address[100];
    struct customer *next;

} customers;

typedef struct User
{
    char username[20];
    char password[20];
    char fname[50];
    char lname[50];
    char date[12];
    int age;
    char id_card[13];
    char pnumber[10];
    char address[100];

} User;

customers customerData;

void service(int isService, customers *current);
void EditService(int isEditService, customers customerData);
void customerMenu(int isCustomerLoggedIn)
{
    int login, logout;
    char save_username[20], save_password[20], save_fname[50], save_lname[50];
    char save_date[12], save_id_card[13], save_pnumber[10], save_address[100];
    int save_age;
    int isService = 0;
    int isEditService = 0;

    customers *cust = NULL, *current = NULL;

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

            printf("1: Booking service\n");
            printf("2: Edit service\n");
            printf("3: View reservation list\n");
            printf("4: Logout\n");
            printf("Select the logout item: ");
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
            case 4:

            {
                if (isCustomerLoggedIn)
                {
                    isCustomerLoggedIn = 0;
                    free(current);
                    current = NULL;
                    printf("Logout Successfully!\n");
                    return;
                }
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
                    // , save_fname, save_lname,save_date, &save_age, save_id_card, save_pnumber, save_address
                    // sscanf(line, "%[^,],%[^,],%[^,],%[^,],%10[^,],%[^,],%[^,],%[^,],%[^,\n]",
                    sscanf(line, "%[^,],%[^,],%[^,],%[^,],%10[^,],%d,%[^,],%[^,],%[^,\n]", save_username, save_password, save_fname, save_lname,
                           save_date, &save_age, save_id_card, save_pnumber, save_address);

                    if (strcmp(username, save_username) == 0 && strcmp(password, save_password) == 0)
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
                        strcpy(current->date, save_date);
                        current->age = save_age;
                        strcpy(current->id_card, save_id_card);
                        strcpy(current->pnumber, save_pnumber);
                        strcpy(current->address, save_address);

                        strcpy(customerData.username, current->username);
                        strcpy(customerData.password, current->password);
                        strcpy(customerData.fname, current->fname);
                        strcpy(customerData.lname, current->lname);
                        strcpy(customerData.date, current->date);
                        customerData.age = save_age;
                        strcpy(customerData.id_card, current->id_card);
                        strcpy(customerData.pnumber, current->pnumber);
                        strcpy(customerData.address, current->address);

                        printf("Login Successfully!\n");
                        printf("user: %s password: %s \n", customerData.username, customerData.password);
                        printf("fname: %s lname: %s\n", customerData.fname, customerData.lname);
                        printf("date: %s age: %d\n", customerData.date, customerData.age);
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
                FILE *cusfile;
                cusfile = fopen("./CSV/customer.csv", "a");

                if (!cusfile)
                {
                    perror("Error opening file");
                    exit(1); // Exit the program if the file couldn't be opened
                }

                // fgets(input, maxSize, stdin);
                cust = (customers *)malloc(sizeof(customers));
                if (cust == NULL)
                {
                    perror("cust == NULL");
                    exit(1);
                }
                printf("Register\n");
                printf("Username: ");
                scanf("%s", cust->username);
                printf("Password: ");
                scanf("%s", cust->password);
                printf("First Name: ");
                scanf("%s", cust->fname);
                printf("Last Name: ");
                scanf("%s", cust->lname);
                printf("Date of birth (dd/mm/yyyy): ");
                scanf("%s", cust->date);
                printf("Age: ");
                scanf("%d", &cust->age);
                printf("Id Card: ");
                scanf("%s", cust->id_card);
                printf("Phone Number: ");
                scanf("%s", cust->pnumber);
                printf("Address: ");
                scanf("%s", cust->address);

                // savefile
                fprintf(cusfile, "%s,%s,%s,%s,%s,%d,%s,%s,%s\n", cust->username, cust->password, cust->fname, cust->lname, cust->date, cust->age, cust->id_card, cust->pnumber, cust->address);
                printf("Register Successfully\n");

                fclose(cusfile);
                free(cust);
                break;
            }
        }
        break;
        case 3:
        {
            printf("forget password\n");
        }
        break;
        case 4:
            return; // Return to the caller (main menu)
        default:
            printf("Invalid choice. Please try again.\n");
            if (login == 4)
            {
                break;
            }
            break;
        } // close switch case login
    }
}
