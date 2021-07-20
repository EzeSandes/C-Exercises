#define ERROR      0 
#define TODO_OK    1

int wordCounter(const char *cad)
{ 
    int band = ERROR; 
    int cont = 0;  // word count 
  
    // Scan all characters one by one 
    while (*cad) 
    { 
        // If next character is a separator, set the  
        // state as OUT 
        if (*cad == ' ' || *cad == '\n' || *cad == '\t') // It can be a MACRO Like "IS_SPACE(x) ((x) == ' ' || (x) == '\n' || (x) == '\t')"
            band = ERROR; 
  
        // If next character is not a word separator and  
        // state is OUT, then set the state as IN and  
        // increment word count 
        else if (band == ERROR) 
        { 
            band = TODO_OK; 
            cont++; 
        } 
  
        // Move to next character 
        cad++; 
    } 
  
    return cont; 
} 
