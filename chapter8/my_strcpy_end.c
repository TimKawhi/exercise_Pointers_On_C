/*
**字符串拷贝函数，返回一个指向目标参数末尾的指针
*/

#include<string.h>

char *
my_strcpy_end(char *dst, char const *source) 
{
    while( (*dst++ = *source++) != '\0')
        ;
    
    return dst - 1;

    //another method
    /*
    strcpy( dst, source);
    return dst + strlen(dst);
    */
}
