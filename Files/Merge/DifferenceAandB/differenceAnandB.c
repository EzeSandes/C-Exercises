#include "DifferenceAandB.h"

#define ALL_OK     1
#define ERROR       0

/// B - A is equals with the difference that pfA will be the ptrFile of pfB

int diferenciaAmenosB_EstYEmp(FILE *pfA, FILE *pfB)
{
    tStudent student;
    tEmployee employee;

    FILE *pfNew;

    int comp;

    pfNew = fopen(FILE_NAME_DIFFERENCE_A_AND_B, "wb");
    if(!pfNew)
    {
        perror(FILE_NAME_DIFFERENCE_A_AND_B);
        return ERROR;
    }

    rewind(pfA);
    rewind(pfB);

    fread(&student, sizeof(tStudent), 1, pfA);
    fread(&employee, sizeof(tEmployee), 1, pfB);

    while(!feof(pfA) && !feof(pfB))
    {
        comp = compare_StdAndEmp(&student, &employee);

        if(!comp)
        {
            fread(&student, sizeof(tStudent), 1, pfA);
            fread(&employee, sizeof(tEmployee), 1, pfB);
        }

        if(comp < 0)
        {
            fwrite(&student.person, sizeof(tPerson), 1, pfNew);
            fread(&student, sizeof(tStudent), 1, pfA);
        }

        if(comp > 0)
        {
            fread(&employee, sizeof(tEmployee), 1, pfB);
        }
    }

    while(!feof(pfA))
    {
        fwrite(&student.person, sizeof(tPerson), 1, pfNew);
        fread(&student, sizeof(tStudent), 1, pfA);
    }

    fclose(pfNew);
    return ALL_OK;
}
