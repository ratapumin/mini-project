#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct DeleteviceData
{
    char id_card[14];
    char username[20];
    int day;
    int month;
    int year;
    float time;

} DeleteData;

typedef struct DeleteList
{
    DeleteData data;
    struct DeleteList *next;
} DeleteList;

void delectService(int isdeleteService, customers customerData)
{

    int found = 0;
    int i = 0;
    int case_delete;
    char ch = 'y';
    DeleteData *deletedata = NULL;
    DeleteList *deletelist = NULL, *head = NULL, *current = NULL, *ptr = NULL, *prev = NULL;

    printf("You: f:%s l:%s id:%s\n",
           customerData.fname,
           customerData.lname,
           customerData.id_card);
    printf("===============================================\n");
    printf("                DELETE BOOKING                 \n");
    printf("===============================================\n");
    FILE *deleteservicefile;
    deleteservicefile = fopen("./CSV/service.csv", "r");
    if (!deleteservicefile)
    {
        perror("Error opening file");
        exit(1);
    }
    char line[1024];
    int row = 0;
    int column = 0;
    while (fgets(line, sizeof(line), deleteservicefile))
    {
        // if (row == 0)
        // {
        //     strtok(line, ",");
        //     row++;
        //     continue;
        // }
        char *token = strtok(line, ",");
        char *save_id_card, *save_username;
        int save_day, save_month, save_year, save_time;

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
            save_time = atoi(token);
            token = strtok(NULL, ",");
        }

        deletedata = (DeleteData *)malloc(sizeof(DeleteData));
        strcpy(deletedata->id_card, save_id_card);
        strcpy(deletedata->username, save_username);
        deletedata->day = save_day;
        deletedata->month = save_month;
        deletedata->year = save_year;
        deletedata->time = save_time;

        if (deletedata == NULL)
        {
            perror("can not service!\n");
            exit(1);
        }
        deletelist = (DeleteList *)malloc(sizeof(DeleteList));
        deletelist->data = *deletedata;
        deletelist->next = NULL;

        if (!head)
        {
            head = deletelist;
            current = head;
        }
        else
        {
            current->next = deletelist;
            current = current->next;
        }
        if (deletelist != NULL)
        {
            if (strcmp(customerData.id_card, deletelist->data.id_card) == 0 &&
                strcmp(customerData.username, deletelist->data.username) == 0)
            {
                found = 1;
                printf("===============================================\n");
                printf("BOOKING = %d\n", i + 1);
                printf("===============================================\n");
                printf("ID Card: %s\n", deletelist->data.id_card);
                printf("Username: %s\n", deletelist->data.username);
                printf("Day/Month/Year: %d/%d/%d\n",
                       deletelist->data.day, deletelist->data.month, deletelist->data.year);
                printf("Timer Service: %.2f\n", deletelist->data.time);
                printf("===============================================\n");

                i++;
            }
            printf("\n");
        }
        else
        {
            printf("No booking information\n");
            printf("===============================\n");
            break;
        }
    }
    fclose(deleteservicefile);
    printf("EIEI\n");

    if (found)
    {
        printf("Enter The booking number you want to edit: ");
        scanf("%d", &case_delete);
        if (case_delete < 1 || case_delete > i)
        {
            printf("Invalid booking number. Please enter a valid number.\n");
        }
        else
        {
            while (ch != 'n')
            {
                int current_booking = 0;
                ptr = head;
                prev = NULL;

                while (ptr != NULL)
                {
                    if (strcmp(customerData.id_card, ptr->data.id_card) == 0 &&
                        strcmp(customerData.username, ptr->data.username) == 0)
                    {
                        current_booking++;

                        if (current_booking == case_delete)
                        {
                            system("cls");
                            printf("===============================================\n");
                            printf("BOOKING = %d\n", case_delete);
                            printf("===============================================\n");
                            printf("ID Card: %s\n", ptr->data.id_card);
                            printf("Username: %s\n", ptr->data.username);
                            printf("Day/Month/Year: %d/%d/%d\n",
                                   ptr->data.day, ptr->data.month, ptr->data.year);
                            printf("Timer Service: %.2f\n", ptr->data.time);
                            printf("===============================================\n");
                            printf("Do you want to delete this booking?(Y/N): ");
                            scanf(" %c", &ch);
                            getchar();

                            if (ch == 'y')
                            {
                                if (prev == NULL)
                                {
                                    head = ptr->next;
                                }
                                else
                                {
                                    prev->next = ptr->next;
                                }
                                free(ptr);
                                printf("\nDelete in Booking successful!!\n");
                                customerMenu(1);
                            }
                            break;
                        }
                    }
                    prev = ptr;
                    ptr = ptr->next;
                }
                customerMenu(1);
            }
        }
    }

} // end

// system("cls");
// printf("===============================================\n");
// printf("BOOKING = %d\n", case_delete);
// printf("===============================================\n");
// printf("ID Card: %s\n", ptr->data.id_card);
// printf("Username: %s\n", ptr->data.username);
// printf("Day/Month/Year: %d/%d/%d\n",
//        ptr->data.day, ptr->data.month, ptr->data.year);
// printf("Timer Service: %.2f\n", ptr->data.time);
// printf("===============================================\n");

// printf("===============================================\n");
// printf("BOOKING = %d\n", case_delete);
// printf("===============================================\n");
// printf("ID Card: %s\n", ptr->data.id_card);
// printf("Username: %s\n", ptr->data.username);
// printf("Day/Month/Year: %d/%d/%d\n",
//        ptr->data.day, ptr->data.month, ptr->data.year);
// printf("Timer Service: %.2f\n", ptr->data.time);
// printf("===============================================\n");

// if (current_booking != case_delete)
// {
//     printf("Invalid booking number. Please enter a valid number.\n");
// }

// printf("Remaining Data in the Node:\n");
// ptr = head;
// while (ptr != NULL)
// {
//     printf("===============================================\n");
//     printf("ID Card: %s\n", ptr->data.id_card);
//     printf("Username: %s\n", ptr->data.username);
//     printf("Day/Month/Year: %d/%d/%d\n",
//            ptr->data.day, ptr->data.month, ptr->data.year);
//     printf("Timer Service: %.2f\n", ptr->data.time);
//     printf("===============================================\n");
//     ptr = ptr->next;
// }
