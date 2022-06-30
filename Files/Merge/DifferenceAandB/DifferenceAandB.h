#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////// DEFINES

#define LENGTH_CAD 51

#define FILE_NAME_STUDENTS    "students.dat"
#define FILE_NAME_EMPLOYEES    "employees.dat"

#define FILE_NAME_DIFFERENCE_A_AND_B   "differenceAandB.dat"

///////////////////////////////////////

typedef struct
{
    unsigned    id;
    char        surname[LENGTH_CAD],
                name[LENGTH_CAD];
}tPerson;

typedef struct
{
    tPersona    person;
    double      salary;
} tEmployee;

typedef struct
{
    tPersona    person;
    float       average;
} tStudent;

int differenceFiles_StdAndEmp(FILE *pfA, FILE *pfB);
int compare_StdAndEmp(const tStudent *std, const tEmployee *emp);
