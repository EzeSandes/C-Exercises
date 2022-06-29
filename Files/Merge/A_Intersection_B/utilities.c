int comparation_StdAndEmp(const tStudent *std, const tEmployee *emp)
{
    int res;

    if((res = strcmp(est->person.surname, emp->person.surname)) == 0)
        if((res = strcmp(est->persona.name, emp->persona.name)) == 0)
            return est->person.id - emp->person.id;

    return res;
}

int showFileIntersection()
{
    FILE    *pfStd;
    tStudent student;

    pfStd = fopen(FILE_NAME_INTERSECTION, "rb");
    if(!pfStd)
    {
        perror("\nERROR. pfIntersection");
        return ERROR;
    }

    fread(&student, sizeof(tStudent), 1, pfStd);
    while(!feof(pfStd))
    {
        showStudent(&student);
        fread(&student, sizeof(tStudent), 1, pfStd);
    }

    fclose(pfStd);
    return ALL_OK;
}

void showStudent(const tStudent *std)
{
    printf("\n\n///////");
    printf("\n\nSurname: %s", std->person.surname);
    printf("\nName: %s", std->person.name);
    printf("\nID: %u", std->person.id);
    printf("\nAverage: %.2f", std->average);
}
