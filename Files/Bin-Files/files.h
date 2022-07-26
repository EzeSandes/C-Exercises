#define SIZE_CAD 51

typedef struct
{
    char cad[SIZE_CAD];
} tCad;

typedef struct
{
    int day,
        month,
        year;
} tDate;

typedef struct sStudent
{
    unsigned    id;
    char        nAndS[SIZE_CAD];
    float       avg;
    tDate      dateOfAdm;
    int         notes[3];
//    struct sStudent *professor;
} tStudent;


int enterStudent(tStudent *std);
int loadStudent(tStudent *std);
void showStudent(const tStudent *std);


int createBinFile(const char *fileName);
int openBinFile(const char *fileName, FILE **pf, const char *mode);
int loadBinFile(FILE *pf);

void optionCreateBinFile();
void optionOpenBinFile(FILE **pf);
void optionLoadBinFile(FILE *pf);
void optionShowBinFile(FILE *pf);
