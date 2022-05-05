#include "merge.h"

#define OK  1
#define ERROR 0

int createTestFiles()
{
  FILE      *pfStud,
            *pfEmp;

    tEmployee employees[] =
    {
        {75, "Albez", "Victoria", 10000},
        {32, "Alvez", "Martin", 10000},
        {96, "Alvorado", "Martin", 10000},
        {99, "Armando", "Rau", 10000},
        {74, "Armando", "Raul", 10000},
        {63, "Augusto", "Esteban", 10000},
        {97, "Augusto", "Esteban", 10000},
        {56, "Azcuenaga", "Federico", 10000},
        {33, "Basili", "Andres", 1000},
        {45, "Beca", "Facundo", 10000},
        {03, "Beka", "Facundo", 10000},
        {39, "Cisco", "Esteban", 20000},
        {24, "Coco", "Eduardo", 10000},
        {31, "Estrella", "Maria", 10000},
        {23, "Estrella", "Mauricio", 10000},
        {13, "Estrella", "Patricio", 20000},
        {29, "Gonzalez", "Gonzalo", 10000},
        {58, "Gonzalez", "Lucas", 10000},
        {30, "Gonzalez", "Luciano", 10000},
        {75, "Jaime", "Nick", 10000},
        {88, "Jaime","Nicolas", 10000},
        {10, "Lopez", "Facundo", 10000},
        {68, "Lopez", "Leonardo", 10000},
        {21, "Mujica", "Pablo", 10000},
        {65, "Mujica", "Pepito", 10000},
        {20, "Perez", "Esteban", 10000},
        {55, "Perez", "Juan", 10000},
        {50, "Perez", "Juan", 10000},
        {83, "Torres", "Esteban", 20000},
        {46, "Torres", "Federico", 10000},
        {12, "Torres", "Leila", 10000},
        {66, "Torrez", "Janette", 10000},
        {11, "Trump", "Pato Donald", 10000},
        {77, "Victoria", "Victoria", 10000},
        {75, "Zuckov", "Vicky", 20000},
        {71, "Zuckov", "Vasili", 10000},
    };

    tStudent students[] =
    {
        {02, "AA", "A", 8},
        {32, "Alvez", "Martin", 7.8},
        {96, "Alvorado", "Martin", 5},
        {99, "Armando", "Rau", 7},
        {74, "Armando", "Raul", 6},
        {63, "Augusto", "Esteban", 8},
        {31, "Estrella", "Maria", 6},
        {23, "Estrella", "Mauricio", 8.5},
        {13, "Estrella", "Patricio", 9},
        {75, "Jaime", "Nick", 5},
        {88, "Jaime", "Nicolas", 4.5},
        {10, "Lopez", "Facundo", 8},
        {68, "Lopez", "Leonardo", 2},
        {21, "Mujica", "Pablo", 9},
        {65, "Mujica", "Pepito", 6.5},
        {20, "Perez", "Esteban", 8},
        {55, "Perez", "Juan", 6.9},
        {50, "Perez", "Juan", 9},
        {11, "Trump", "Pato Donald", 8.5},
    };

    pfStud = fopen(NAME_FILE_STUDENT, "wb");
    if(!pfStud)
    {
        perror("\nERROR. pfEst");
        return ERROR;
    }

    pfEmp = fopen(NAME_FILE_EMPLOYEES, "wb");
    if(!pfEmp)
    {
        perror("\nERROR. pfEmp");
        fclose(pfStud);
        return ERROR;
    }

    fwrite(students, sizeof(students), 1, pfStud);
    fwrite(employees, sizeof(employees), 1, pfEmp);

    fclose(pfStud);
    fclose(pfEmp);
    return OK;
}

////////////////////

void exerciseUpdateFiles(FILE *pfEmp, FILE *pfStud)
{
    int comp;
    tEmployee employee;
    tStudent student;

    // I make sure I'm at the beginning of the files
    rewind(pfEmp);
    rewind(pfStud);

    fread(&student, sizeof(tStudent), 1, pfStud);
    fread(&employee, sizeof(tEmployee), 1, pfEmp);
    while(!feof(pfStud) && !feof(pfEmp))
    {
        comp = compareStudAndEmp(&student, &employee);

        if(!comp)// == 0
        {
            updateCriteria(&student, &employee);
            updateEmployeeFile(pfEmp, &employee);
            fread(&student, sizeof(tStudent), 1, pfStud);
            fread(&employee, sizeof(tEmployee), 1, pfEmp);
        }

        if(comp < 0)
        {
            fread(&student, sizeof(tStudent), 1, pfStud);
        }

        if(comp > 0)
        {
            fread(&employee, sizeof(tEmployee), 1, pfEmp);
        }
    }
}

////////////////////

int compareStudAndEmp(const tStudent *stud, const tEmployee *emp)
{
    int res;

    if((res = strcmp(stud->surname, emp->surname)) == 0)
        if((res = strcmp(stud->name, emp->name)) == 0)
            return stud->id - emp->id;

    return res;
}

////////////////////

void updateCriteria(const tStudent *stud, tEmployee *emp)
{
    float percentIncrease = 0.728;

    // I update all that I want here.
    // If in the future I had more conditions, I would put them here.
    if(stud->average > 7)
    {
        emp->salary += emp->salary * percentIncrease;
    }
}

////////////////////

void updateEmployeeFile(FILE *pfEmp, const tEmployee *emp)
{
    fseek(pfEmp, -(long)sizeof(tEmployee), SEEK_CUR);
    fwrite(emp, sizeof(tEmployee), 1, pfEmp);
    fseek(pfEmp, 0L, SEEK_CUR);
}

////////////////////

void showStudent(const tStudent *stud)
{
    printf("\n\n///////");
    printf("\n\nSurname: %s", stud->surname);
    printf("\nName: %s", stud->name);
    printf("\nID: %u", stud->id);
    printf("\nAverage: %.2f", stud->average);
}

////////////////////

void showEmployee(const tEmployee *emp)
{
    printf("\n\n///////");
    printf("\n\nSurname: %s", emp->surname);
    printf("\nName: %s", emp->name);
    printf("\nID: %u", emp->id);
    printf("\nSalary: %.2f", emp->salary);
}

////////////////////
////////////////////
