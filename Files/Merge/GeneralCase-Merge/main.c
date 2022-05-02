#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

int main()
{
    FILE    *pfEmp = NULL,
            *pfStud = NULL;

    int option;

    do{
        printf("\n\n0: Exit\
               \n1: Create Tests Files(%s, %s)\
               \n2: Open Tests Files \
               \n3: Show %s\
               \n4: Show %s\
               \n5: Updated by Merge %s",
               NAME_FILE_STUDENTS, NAME_FILE_EMPLOYEES,
               NAME_FILE_STUDENTS, NAME_FILE_EMPLOYEES,
               NAME_FILE_EMPLOYEES);

        printf("\n\nChoose an option: ");
        scanf("%d", &option);

        switch(option)
        {
        case 0:
            break;

        case 1:
            optionShowTestFiles();
            break;

        case 2:
            optionOpenTestFiles(&pfEmp, &pfStud);
            break;

        case 3:
            optionShowStudentsFile(pfStud);
            break;

        case 4:
            optionShowEmployeesFile(pfEmp);
            break;

        case 5:
            optionUpdateFile(pfEmp, pfStud);
            break;

        default:
            printf("\nIncorrect option. Try again.");
            break;
        }

    }while(option);

    if(pfEmp || pfStud)
    {
        fclose(pfEmp);
        fclose(pfStud);
    }

    printf("\n\nExiting...\nSuccessful exit.");
    return EXIT_SUCCESS;
}
