#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void EditService(int isEditService, customers customarData)
{
    int case_edit;
    char save_id_card[13];
    // printf("You: %s %s %s", customerData.fname, customerData.lname, customerData.id_card);
    FILE *editservicefile;
    editservicefile = fopen("./CSV/service.csv", "r");
    if (!editservicefile)
    {
        perror("Error opening file");
        exit(1);
    }
    char line[1024];
    int row = 0;
    int column = 0;

    while (fgets(line, 1024, editservicefile))
    {
        sscanf(line, "%[^,]", save_id_card);
        if (strcmp(customerData.id_card, save_id_card) == 0)
        {
            printf("You: %s %s %s", customerData.fname, customerData.lname, customerData.id_card);

            column = 0;
            row++;

            if (row == 1)
                continue;
            char *value = strtok(line, ",");
            while (value)
            {
                if (column == 0)
                {
                    printf("id_card: ");
                }
                if (column == 1)
                {
                    printf("\tusername: ");
                }
                if (column == 2)
                {
                    printf("\tdate: ");
                }
                if (column == 3)
                {
                    printf("\tmonth: ");
                }
                if (column == 4)
                {
                    printf("\tyear: ");
                }
                if (column == 5)
                {
                    printf("\ttime: ");
                }
                printf("%s ", value);
                value = strtok(NULL, ",");
                column++;
            }
            printf("\n");
        }
        else
        {
            printf("No booking information\n");
            break;
        }
    }
    fclose(editservicefile);
}