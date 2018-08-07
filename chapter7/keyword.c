/*
**主要为了引入指针数组的概念
*/

#include<string.h>

char const *keyword[] = {
    "do",
    "for",
    "if",
    "register",
    "return",
    "switch",
    "while",
    NULL
};
//这里加的NULL是种技巧，对于指针数组来说



int lookup_keyword( char const * const desired_word, char const *keyword_tabel[]) 
{
    char const **kwp;
    
    for( kwp = keyword_tabel; kwp != NULL; kwp++) 
        if(strcmp( desired_word, *kwp) == 0)
            return kwp - keyword_tabel;
        
        /*
        **没有找到
        */
        return -1;

}

