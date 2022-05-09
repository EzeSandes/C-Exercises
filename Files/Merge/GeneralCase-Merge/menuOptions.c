#include "merge.h"

#define OK  1
#define ERROR 0

///////////////////////////////////////

void optionCreateTestFiles()
{
    printf("\n\n//////////////////////////////");
    printf("\n\nCreating Test Files...");
    createTestFiles();
    printf("\n\nTest Files successfully created");
    printf("\n\n//////////////////////////////");
}

///////////////////////////////////////

int optionOpenTestFiles(FILE **pfEmp, FILE **pfStd)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nOpening test files...");

    *pfEmp = fopen(NAME_FILE_EMPLOYEES, "r+b"); // r+b because I'll update this file.
    if(!*pfEmp)
    {
        printf("\n");
        perror(NAME_FILE_EMPLOYEES);
        return ERROR;
    }

    *pfStd = fopen(NAME_FILE_STUDENT, "rb");
    if(!*pfEst)
    {
        fclose(*pfEmp);
        printf("\n");
        perror(NAME_FILE_STUDENT);
        return ERROR;
    }

    printf("\nTest Files successfully opened.");
    return OK;
}

///////////////////////////////////////

void optionUpdateFile(FILE *pfEmp, FILE *pfStud)
{
    printf("\n\n//////////////////////////////");
    printf("\n\nUpdating...");
    exerciseUpdateFiles(pfEmp, pfStud);
    printf("\nFile/s updated.");
    printf("\n\n//////////////////////////////");
}

///////////////////////////////////////

void optionShowStudentsFile(FILE *pf)
{
    tStudent student;

    rewind(pf);

    printf("\n\n//////////////////////////////");
    printf("\n\nShowing file of students.\n\n");

    fread(&student, sizeof(tStudent), 1, pf);
    while(!feof(pf))
    {
        showStudent(&student);
        fread(&student, sizeof(tStudent), 1, pf);
    }

    printf("\n\n//////////////////////////////");
}

///////////////////////////////////////

void optionShowEmployeesFile(FILE *pf)
{
    tEmployee employee;

    rewind(pf);

    printf("\n\n//////////////////////////////");
    printf("\n\nShowing file of Employees.\n\n");

    fread(&employee, sizeof(tEmployee), 1, pf);
    while(!feof(pf))
    {
        mostrarEmpleado(&employee);
        fread(&employee, sizeof(tEmployee), 1, pf);
    }

    printf("\n\n//////////////////////////////");
}

///////////////////////////////////////
