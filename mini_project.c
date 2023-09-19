#include <stdio.h>
#include <stdlib.h> // Use <stdlib.h> for malloc
#include <string.h>

typedef struct person
{
    char fname[50];
    char lname[50];
    char date[10];
    int age;
    char id_card[13];
    char service[50];
    char datein[10];
    char timein[10];
    char pnumber[10];
    struct person *next;
} persons;

int main()
{
    int choice, case_emp;
    persons general, *head = NULL, *current, *ptr;
    char ch = 'y';

    while (1)
    {
        printf("Book a dental appointment online\n");
        printf("1: General public\n");
        printf("2: Employee\n");
        printf("3: Exit\n"); // Move the "Exit" option to the main menu
        printf("Select the desired item: ");
        scanf("%d", &choice);
        printf("===============================\n");

        switch (choice)
        {
        case 1:
            while (ch != 'n')
            {
                printf("Book a dental appointment for the general public\n");
                printf("First Name: ");
                scanf("%s", general.fname);
                printf("Last Name: ");
                scanf("%s", general.lname);
                printf("Date of birth (dd/mm/yyyy): ");
                scanf("%s", general.date);
                printf("Age: ");
                scanf("%d", &general.age);
                printf("Id Card: ");
                scanf("%s", general.id_card);
                printf("Phone Number: ");
                scanf("%s", general.pnumber);
                printf("Desired service: ");
                scanf("%s", general.service);
                printf("Date you want to reserve (dd/mm/yyyy): ");
                scanf("%s", general.datein);
                printf("Time you want to reserve: (Open10.00 - close19.00): ");
                scanf("%s", general.timein);

                persons *p;
                p = (persons *)malloc(sizeof(persons));
                // if (p != NULL)
                // {
                //     head = p;
                // }
                if (p == NULL)
                {
                    // Handle memory allocation failure here
                    printf("Not enough memory");
                    exit(1);
                }

                strcpy(p->fname, general.fname);
                strcpy(p->lname, general.lname);
                strcpy(p->date, general.date);
                p->age = general.age;
                strcpy(p->id_card, general.id_card);
                strcpy(p->pnumber, general.pnumber);
                strcpy(p->service, general.service);
                strcpy(p->datein, general.datein);
                strcpy(p->timein, general.timein);
                p->next = NULL;

                if (head == NULL)
                {
                    head = p;
                    current = p;
                }
                else
                {
                    current->next = p;
                    current = p;
                }
                system("cls");
                printf("===============Successfuly================\n");
                printf("Name: %s %s\n", general.fname, general.lname);
                printf("Desired service: %s\n", general.service);
                printf("Date you want to reserve: %s\n", general.datein);
                printf("Time you want to reserve: %s\n", general.timein);
                printf("Your reservation is complete.\n");
                printf("Want to book for another service again? (y/n): ");
                scanf(" %c", &ch);
                system("cls");
            }
            ch = '\0';
            break;
        case 2:
            printf("Menu for employees\n");
            printf("1: Dental appointment queue list\n");
            printf("2: Book a dental appointment\n");
            printf("Select the desired item: ");
            scanf("%d", &case_emp);
            switch (case_emp)
            {
            case 1:
                if (head == NULL)
                {
                    printf("Not Have Customer !\n");
                }
                else
                {
                    ptr = head;
                    while (ptr != NULL)
                    {

                        printf("========================\n");
                        printf("Name: %s %s\n", ptr->fname, ptr->lname);
                        printf("Desired service: %s\n", ptr->service);
                        printf("Date you want to reserve: %s\n", ptr->datein);
                        printf("Time you want to reserve: %s\n", ptr->timein);
                        printf("Your reservation is complete.\n");
                        ptr = ptr->next;
                    }
                }
                break;
            case 2:
            {
                system("cls");
                printf("Book a dental appointment for the general public\n");
                printf("First Name: ");
                scanf("%s", general.fname);
                printf("Last Name: ");
                scanf("%s", general.lname);
                printf("Date of birth (dd/mm/yyyy): ");
                scanf("%s", general.date);
                printf("Age: ");
                scanf("%d", &general.age);
                printf("Id Card: ");
                scanf("%s", general.id_card);
                printf("Phone Number: ");
                scanf("%s", general.pnumber);
                printf("Desired service: ");
                scanf("%s", general.service);
                printf("Date you want to reserve (dd/mm/yyyy): ");
                scanf("%s", general.datein);
                printf("Time you want to reserve: (Open10.00 - close19.00): ");
                scanf("%s", general.timein);

                persons *q;
                q = (persons *)malloc(sizeof(persons));
                strcpy(q->fname, general.fname);
                strcpy(q->lname, general.lname);
                strcpy(q->date, general.date);
                q->age = general.age;
                strcpy(q->id_card, general.id_card);
                strcpy(q->pnumber, general.pnumber);
                strcpy(q->service, general.service);
                strcpy(q->datein, general.datein);
                strcpy(q->timein, general.timein);
                q->next = NULL;

                printf("Your add case is complete.\n");
                // printf("Want to book for another service again? (y/n): ");
                // scanf(" %c", &ch);
                current = head;
                if (head == NULL)
                {
                    head = q;
                }
                else
                {
                    while (current)
                    {
                        if (!current->next)
                        {
                            current->next = q;
                            break;
                        }
                        current = current->next;
                    }
                }
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