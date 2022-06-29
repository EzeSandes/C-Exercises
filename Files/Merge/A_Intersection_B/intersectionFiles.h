#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////// DEFINES

#define LENGTH_CAD 51

#define FILE_NAME_STUDENTS    "students.dat"
#define FILE_NAME_EMPLOYEES    "employees.dat"

#define FILE_NAME_INTERSECTION   "intersectionStdAndEmp.dat"

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

int intersectionFiles_StdAndEmp(FILE *pfStd, FILE *pfEmp);
int compare_StdAndEmp(const tStudent *std, const tEmployee *emp);
