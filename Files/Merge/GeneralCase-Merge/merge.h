#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////// DEFINES

#define STRING_SIZE_NAME_SURNAME 51

#define NAME_FILE_STUDENT "estudiantes.dat"
#define NAME_FILE_EMPLOYEES "empleados.dat"

/////////////////////////////////////// STRUCTURES
typedef struct
{
    unsigned    id;
    char        surname[STRING_SIZE_NAME_SURNAME],
                name[STRING_SIZE_NAME_SURNAME];
    double      salary;
} tEmployee;

typedef struct
{
    unsigned    id;
    char        surname[STRING_SIZE_NAME_SURNAME],
                name[STRING_SIZE_NAME_SURNAME];
    float       average;
} tStudent;

///////////////////////////////////////

////// MENU OPTIONS

void optionCreateTestFiles();
int optionOpenTestFiles(FILE **pfEmp, FILE **pfStud);
void optionUpdateFile(FILE *pfEmp, FILE *pfStud);
void optionShowStudentsFile(FILE *pf);
void optionShowEmployeesFile(FILE *pf);

////// FUNCTIONS

int createTestFiles();
void exerciseUpdateFiles(FILE *pfEmp, FILE *pfStud);
void updateEmployeeFile(FILE *pfEmp, const tEmployee *emp);
int compareStudAndEmp(const tStudent *stud, const tEmployee *emp);
void updateCriteria(const tStudent *stud, tEmployee *emp);

void showStudent(const tStudent *stud);
void showEmployee(const tEmployee *emp);

///////////////////////////////////////
