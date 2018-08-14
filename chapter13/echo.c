/*
**一个打印其命令行参数的程序
**非常像UNIX的echo命令
*/
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    /*
    **打印参数，知道遇到NULL指针(未使用argc)。程序名被跳过
    */
    while( *++argv != NULL )
       printf( "%s\n", *argv );

    return EXIT_SUCCESS;
}
