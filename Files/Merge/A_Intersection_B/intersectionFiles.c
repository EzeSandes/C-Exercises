#include "interseccionArchs.h"

#define ALL_OK     1
#define ERROR       0

////////////////////////////////////////

int intersectionFiles_StdAndEmp(FILE *pfStud, FILE *pfEmp)
{
    tEstudiante student;
    tEmployee employee;

    FILE *pfIntersection;

    int comp;

    pfIntersection = fopen(NAME_FILE_INTERSECTION, "wb");
    if(!pfIntersection)
    {
        perror(NAME_FILE_INTERSECTION);
        return ERROR;
    }

    rewind(pfStud);
    rewind(pfEmp);

    fread(&student, sizeof(tStudent), 1, pfStud);
    fread(&employee, sizeof(tEmployee), 1, pfEmp);
    while(!feof(pfStud) && !feof(pfEmp))
    {
        comp = compare_StdAndEmp(&student, &employee);

        if(!comp)
        {
            fwrite(&student, sizeof(tStudent), 1, pfIntersection);

            
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

    fclose(pfIntersection);
    return ALL_OK;
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
