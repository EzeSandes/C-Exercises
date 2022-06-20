int rStrLen(const char *str)
{
    if(*str == '\0')
        return 0;

    return 1 + rStrLen(str + 1);
}
