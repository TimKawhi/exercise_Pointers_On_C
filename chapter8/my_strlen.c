/*
**安全的字符串长度函数，能返回字符串长度，即使未以NUL结尾。
** size是存储字符串的缓冲区长度
*/

#include<string.h>
#include<stddef.h>

size_t
my_strlen(char const *str, int size) 
{
    register size_t  length;
    
    for(size_t length = 0; length < size; length++)
    {
        if( *str++ == '\0')
            break;
    }

    return length;
    
}
