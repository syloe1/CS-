#include <stdio.h>
#include <cstring> // 包含用于 strcmp 的头文件

int main(int argc, char *argv[]) {
    char str1[] = "hello world";
    char str2[] = "hello world";
    char* str3 = "he llo world";
    char* str4 = "hello world";

    if (strcmp(str1, str2) == 0)
        printf("str1 and str2 are same.\n");
    else
        printf("str1 and str2 are not same.\n");

    if (strcmp(str3, str4) == 0)
        printf("str3 and str4 are same.\n");
    else
        printf("str3 and str4 are not same.\n");

    return 0;
}
