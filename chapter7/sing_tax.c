/*
**计算1995年美国联邦政府对每位公民征收的个人所得税
*/

#include<float.h>

static double income_limits[]
    = { 0,   23350,  56550,   117950,  256500, DBL_MAX};
static float  base_tax[]
    = { 0,   3502.5, 12798.5, 31832.5, 8170.5};
static float percentage[]
    = { .15, .28,    .31,     .36,     .396};

double
single_tax( double income) 
{
    int category;

    /*
    **找到正确的收入类别，DBL_MAX被添加到这个列表的末尾，保证
    ××循环不会进行的太久。
    */
   for( category = 1; income >= income_limits[ category ];
        category += 1)
        ;
    category -= 1;

    /**
    **计算税
    */
   return base_tax[ category ] + percentage[ category ] *
    ( income - income_limits[ category ]);
}
