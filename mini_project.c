#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
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
    struct person *next;
} persons;

int main()
{
    int choice, case_emp, case_pub, case_service;
    persons customer, *head = NULL, *current, *ptr;
    char ch = 'y';
    int isCustomerLoggedIn = 0;

    while (1)
    {
        printf("===============================\n");
        printf("Main menu\n");
        printf("1: Customer\n");
        printf("2: Employee\n");
        printf("3: Exit\n");
        printf("Select the desired item: ");
        scanf("%d", &choice);
        printf("===============================\n");

        switch (choice)
        {
        case 1:
            while (1)
            {
                printf("===============================\n");

                printf("Menu For Customer\n");
                if (!isCustomerLoggedIn)
                {
                    printf("1: Login\n");
                    printf("2: Register\n");
                    printf("3: Forget Password\n");
                    printf("4: Return to Menu\n");
                    printf("Select the desired item: ");
                }
                else
                {
                    // system("cls");
                    printf("===============================\n");
                    printf("Select service\n");
                    printf("1: Scrape off tartar\n");
                    printf("2: Tooth filling\n");
                    printf("3: Tooth extraction\n");
                    printf("4: Logout\n");
                    printf("Select service item: ");
                    scanf("%d", &case_service);
                    switch (case_service)
                    {
                    case 1:
                    {
                        printf("Scrape off tartar");
                    }
                    break;
                    case 2:
                    {
                        printf("Tooth filling");
                    }
                    break;
                    case 3:
                    {
                        printf("Tooth extraction");
                    }
                    break;
                    case 4:
                    {

                        if (isCustomerLoggedIn)
                        {
                            isCustomerLoggedIn = 0; // Logout by resetting the login flag
                            printf("Logout successfuly!\n");
                            printf("===============================\n");
                            printf("Menu For Customer\n");
                            printf("1: Login\n");
                            printf("2: Register\n");
                            printf("4: Forget Password\n");
                            printf("5: Return to Menu\n");
                            printf("Select the desired item: ");
                        }
                        else
                        {
                            printf("You are not logged in.\n");
                        }
                    }
                    break;
                    default:
                        break;
                    }
                }

                scanf("%d", &case_pub);
                switch (case_pub)
                {
                case 1:
                    if (!isCustomerLoggedIn)
                    {
                        char username[20], password[20];
                        printf("Username: ");
                        scanf("%s", username);
                        printf("Password: ");
                        scanf("%s", password);

                        // Open the CSV file for reading
                        FILE *cusfile;
                        cusfile = fopen("customer.csv", "r");

                        if (!cusfile)
                        {
                            perror("Error opening file");
                            exit(1); // Exit the program if the file couldn't be opened
                        }

                        int found = 0;
                        char line[256];
                        while (fgets(line, sizeof(line), cusfile))
                        {
                            char saved_username[20], saved_password[20];
                            sscanf(line, "%[^,],%[^,]", saved_username, saved_password);

                            // Compare the provided username and password with saved credentials
                            if (strcmp(username, saved_username) == 0 && strcmp(password, saved_password) == 0)
                            {
                                found = 1;
                                isCustomerLoggedIn = 1; // Set the login flag to true
                                system("cls");
                                printf("Login successful!\n");
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
                        printf("You are already logged in.\n");
                    }
                    break;
                case 2:
                {
                    {
                        // add customer
                        FILE *cusfile;
                        cusfile = fopen("customer.csv", "a");

                        if (!cusfile)
                        {
                            perror("Error opening file");
                            exit(1); // Exit the program if the file couldn't be opened
                        }

                        // fgets(input, maxSize, stdin);

                        printf("Register\n");
                        printf("Username: ");
                        scanf("%s", customer.username);
                        printf("Password: ");
                        scanf("%s", customer.password);
                        printf("First Name: ");
                        scanf("%s", customer.fname);
                        printf("Last Name: ");
                        scanf("%s", customer.lname);
                        printf("Date of birth (dd/mm/yyyy): ");
                        scanf("%s", customer.date);
                        printf("Age: ");
                        scanf("%d", &customer.age);
                        printf("Id Card: ");
                        scanf("%s", customer.id_card);
                        printf("Phone Number: ");
                        scanf("%s", customer.pnumber);
                        printf("Address: ");
                        scanf("%s", customer.address);

                        // savefile
                        fprintf(cusfile, "%s,%s,%s,%s,%s,%d,%s,%s,%s\n", customer.username, customer.password, customer.fname, customer.lname, customer.date, customer.age, customer.id_card, customer.password, customer.address);
                        printf("Register Successfully\n");

                        fclose(cusfile);
                        return 0;
                    }
                }
                break;
                // case 3:
                //    {}
                //     break;
                case 3:
                    // Implement forget password functionality
                    break;
                case 4:
                    // Return to the main menu by breaking out of the customer menu loop
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                }
                if (case_pub == 4)
                {
                    break; // Exit the customer menu loop when returning to the main menu
                }
            }
            break;
        case 2:
            printf("Menu For employees\n");
            printf("1: Dental appointment queue list\n");
            printf("2: Book a dental appointment\n");
            printf("Select the desired item: ");
            scanf("%d", &case_emp);
            switch (case_emp)
            {
            case 1:
            {

                FILE *cusfile;
                char *name;
                cusfile = fopen("customer.csv", "r");

                if (!cusfile)
                {
                    perror("Error opening file");
                    exit(1); // Exit the program if the file couldn't be opened
                }
                else
                {
                    char customerfile[1024];
                    int row = 0;
                    int column = 0;
                    while (fgets(customerfile, 1024, cusfile))
                    {
                        column = 0;
                        row++;

                        if (row == 1)
                            continue;
                        char *value = strtok(customerfile, ",");
                        while (value)
                        {
                            if (column == 0)
                            {
                                printf("username: ");
                            }
                            if (column == 1)
                            {
                                printf("\tpassword: ");
                            }
                            if (column == 2)
                            {
                                printf("\tfname: ");
                            }
                            if (column == 3)
                            {
                                printf("\tlname: ");
                            }
                            if (column == 4)
                            {
                                printf("\tdate: ");
                            }
                            if (column == 5)
                            {
                                printf("\tage: ");
                            }
                            if (column == 6)
                            {
                                printf("\tid_card: ");
                            }
                            if (column == 7)
                            {
                                printf("\tpnumber: ");
                            }
                            if (column == 8)
                            {
                                printf("\taddress: ");
                            }
                            printf("%s ", value);
                            value = strtok(NULL, ",");
                            column++;
                        }
                        printf("\n");
                    }
                }
            }
            break;
            case 2:
            {
            }
            default:
                break;
            }
            break;
        case 3:
            printf("Exit\n");
            exit(0); // Terminate the program when the user chooses "Exit"
        default:
            break;
        }
    }
    return 0;
}

// ทำแทรกข้อมูลระหว่างข้อมูลต่อ

// เข้าสู่ระบบ

// printf("Desired service: ");
// scanf("%s", general.service);
// printf("Date you want to reserve (dd/mm/yyyy): ");
// scanf("%s", general.datein);
// printf("Time you want to reserve: (Open10.00 - close19.00): ");
// scanf("%s", general.timein);

// printf("Book a dental appointment for the general public\n");
// printf("First Name: ");
// scanf("%s", general.fname);
// printf("Last Name: ");
// scanf("%s", general.lname);
// printf("Date of birth (dd/mm/yyyy): ");
// scanf("%s", general.date);
// printf("Age: ");
// scanf("%d", &general.age);
// printf("Id Card: ");
// scanf("%s", general.id_card);
// printf("Phone Number: ");
// scanf("%s", general.pnumber);
// printf("Desired service: ");
// scanf("%s", general.service);
// printf("Date you want to reserve (dd/mm/yyyy): ");
// scanf("%s", general.datein);
// printf("Time you want to reserve: (Open10.00 - close19.00): ");
// scanf("%s", general.timein);

// persons *p;
// p = (persons *)malloc(sizeof(persons));
// // if (p != NULL)
// // {
// //     head = p;
// // }
// if (p == NULL)
// {
//     // Handle memory allocation failure here
//     printf("Not enough memory");
//     exit(1);
// }

// strcpy(p->fname, general.fname);
// strcpy(p->lname, general.lname);
// strcpy(p->date, general.date);
// p->age = general.age;
// strcpy(p->id_card, general.id_card);
// strcpy(p->pnumber, general.pnumber);
// strcpy(p->service, general.service);
// strcpy(p->datein, general.datein);
// strcpy(p->timein, general.timein);
// p->next = NULL;

// if (head == NULL)
// {
//     head = p;
//     current = p;
// }
// else
// {
//     current->next = p;
//     current = p;
// }
// system("cls");
// printf("===============Successfuly================\n");
// printf("Name: %s %s\n", general.fname, general.lname);
// printf("Desired service: %s\n", general.service);
// printf("Date you want to reserve: %s\n", general.datein);
// printf("Time you want to reserve: %s\n", general.timein);
// printf("Your reservation is complete.\n");
// printf("Want to book for another service again? (y/n): ");
// scanf(" %c", &ch);
// system("cls");