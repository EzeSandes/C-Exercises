#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

int main()
{

    int option;
    FILE    *pf = NULL;

    do
    {
         printf("\n0: Exit\
                \n1: Create Bin File\
                \n2: Open Bin File \
                \n3: Load Students Bin File\
                \n4: Show Students Bin File");

        printf("\n\nChoose an option(0 -> exit): ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
        case 0:
            printf("\n\nExiting...");
            printf("\nSuccessful exit. Thanks!");
            break;

        case 1:
            optionCreateBinFile();
            break;

        case 2:
            optionOpenBinFile(&pf);
            break;

        case 3:
            optionLoadBinFile(pf);
            break;

        case 4:
            optionShowBinFile(pf);
            break;

        default:
            printf("\nOption not correct. Please, try again.\n\n");
            break;
        }
    }
    while(option);

    fclose(pf);
    printf("\n\n");
    return 0;
}
