#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "files.h"

#define     ERROR   0
#define     ALL_OK 1

float calculateAverage(const int *vec, int numElem);

////////////////////////////

float calculateAverage(const int *vec, int numElem)
{
    int i;
    float sum = 0;

    for(i = 0; i < numElem; i++)
    {
        sum += *vec;
        vec++;
    }

    return sum / numElem;
}

///////////////////////////////////////////////////////

int enterStudent(tstdm *std)
{
    /// THE ORDER DOESN'T MATTER
    tDate date = { .day = 8, .month = 4, .year = 2022};
//    tDate date = { .day = 8, .month = 4, .year = 2022};
//    tDate date = { day : 8, month : 4, year : 2022};
//    tDate date = { month : 4, day : 8, year : 2022};

    /// THE ORDER MATTER
//    tDate date = { 8, 4, 2022};

    printf("ID: ");
    scanf("%u", &std->id);

    if(!std->id)
        return 0;

    printf("\nName and Surname: ");
    fflush(stdin);
    gets(std->nAndS);

    printf("\nAverage: ");
    scanf("%f", &std->avg);

    std->dateOfAdm = date;

    return ;
}

////////////////////////////

int loadStudent(tStudent *std)
{
    int i,
        *pNotes = std->notes;

/// THE ORDER DOESN'T MATTER
    tDate date = { .day = 8, .month = 4, .year = 2022};
//    tDate date = { .day = 8, .month = 4, .year = 2022};
//    tDate date = { day : 8, month : 4, year : 2022};
//    tDate date = { month : 4, day : 8, year : 2022};

    /// THE ORDER MATTER
//    tDate date = { 8, 4, 2022};

    printf("\n\nId(0 --> Exit): ");
    scanf("%u", &std->id);

    if(!std->id)
        return 0;

    printf("\nName and Surname: ");
    fflush(stdin);
    gets(std->nAndS);


    for(i = 0; i < sizeof(std->notes) / sizeof(int); i++)
    {
        printf("\nNote %d: ", i + 1);
        scanf("%d", pNotes);
        pNotes++;
    }

    std->avg = calculateAverage(std->notes, sizeof(std->notes) / sizeof(int));

    std->dateOfAdm = date;

    return ALL_OK;
}

////////////////////////////

void showStudent(const tStudent *std)
{
    int i;
    int *pNotes = (int *)std->notes;

    printf("\n\n//////////////////");
    printf("\nId: %u", std->id);
    printf("\nName and Surname: %s", std->nAndS);

    printf("\nNotes: ");
    for(i = 0; i < sizeof(std->notes) / sizeof(int); i++)
    {
        printf(" %d |", *pNotes);
        pNotes++;
    }

//    printf("\nNotes: %d | %d | %d |", std->notes[0], std->notes[1], std->notes[2]);
    printf("\nAverage: %.2f", std->avg);
    printf("\nDate of Admission: %d / %d / %d", std->dateOfAdm.day, std->dateOfAdm.month, std->dateOfAdm.year);
}

////////////////////////////

int createBinFile(const char *fileName)
{
    FILE *pf = fopen(fileName, "wb");

    if(!pf)
        return ERROR;

    fclose(pf);
    return ALL_OK;
}

////////////////////////////

int openBinFile(const char *fileName, FILE **pf, const char *mode)
{
    *pf = fopen(fileName, mode);

    return *pf ? ALL_OK : ERROR;
}

////////////////////////////

int loadBinFile(FILE *pf)
{
    tStudent std;

    if(!pf)
        return ERROR;

    while(loadStudent(&alu))
        fwrite(&std, sizeof(tStudent), 1, pf);

    return ALL_OK;
}
////////////////////////////

void optionCreateBinFile()
{
    char fileName[SIZE_CAD] = "students.dat";

    printf("\n\n/////////////////////////");
    printf("\n\n\t\t\t\tCreate File.");

//    printf("\nName of the file to be created: ");
//    fflush(stdin);
//    gets(fileName);

    printf(createBinFile(fileName)? "\nFile successfully created." :
                   "\nERROR to create the file.");

    printf("\n/////////////////////////");
}

////////////////////////////

void optionOpenBinFile(FILE **pf)
{
    char fileName[SIZE_CAD] = "students.dat";

    printf("\n\n/////////////////////////");
    printf("\n\n\t\t\t\tOpen Bin File.");

//    printf("\nName of the file to be opened: ");
//    fflush(stdin);
//    gets(fileName);

    printf(openBinFile(fileName, pf, "r+b")? "\nFile successfully opened." :
                   "\nERROR to open the file");

    printf("\n\n/////////////////////////\n\n");
}

////////////////////////////

void optionLoadBinFile(FILE *pf)
{
    printf("\n\n/////////////////////////");

    printf("\n\n\t\t\t\tLoad Bin File.");

    printf(loadBinFile(pf)? "\n\nFile successfully loaded." : "\n\nERROR to load the files");
    printf("\n\n/////////////////////////\n\n");
}

////////////////////////////

void optionShowBinFile(FILE *pf)
{
    tStudent std;

    if(!pf)
    {
        printf("\nERROR showing the file. Is it opened correctly?.\n");
        printf("\n\n/////////////////////////\n\n");
        return;
    }

    printf("\n\n/////////////////////////");
    printf("\n\n\t\t\t\tShow records of the file.");

    rewind(pf);
    fread(&std, sizeof(tStudent), 1, pf);
    while(!feof(pf))
    {
        showStudent(&std);
        fread(&std, sizeof(tStudent), 1, pf);
    }

    printf("\n\n/////////////////////////\n\n");
}

////////////////////////////
////////////////////////////
