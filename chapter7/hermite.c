/**
 **计算Hermite polynomial 的值
 **输入： n,x: 用于标识值
 **输出polynomial的返回值
 */

int hermite( int n, int x) {
    if(n <= 0)
        return 1;
    if(n == 1)
        return 2*x;
    if(n >= 2)
        return 2 * x * hermite( n-1, x) 
            - 2 * (n-1) * hermite( n-2, x);
}
