/*  reverse the string
**  关键在于两指针擦肩而过的时候就该停止，不然等于没反转
*/

#include<stdio.h>

void reverse_string(char *string) {
    char *last_char;  //存放最后一个字符
    for(last_char = string; *last_char != '\0'; last_char++)
                        ;
    last_char--;

    while(string < last_char) {
        char temp;
        temp = *string;
        *string++ = *last_char;
        *last_char-- = temp;
    }

}

/* test */
int main(int argc, char const *argv[])
{
    char test[] = "abcdefg";
    reverse_string(test);
    puts(test);

    return 0;
}
