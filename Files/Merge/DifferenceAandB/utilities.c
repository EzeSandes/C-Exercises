int comparation_StdAndEmp(const tStudent *std, const tEmployee *emp)
{
    int res;

    if((res = strcmp(est->person.surname, emp->person.surname)) == 0)
        if((res = strcmp(est->persona.name, emp->persona.name)) == 0)
            return est->person.id - emp->person.id;

    return res;
}
