/*
④请编写一个函数 countVowels，接受一个指向字符串的指针作为参
数，返回字符串中元音字母（a、e、i、o、u）的数量。
*/

#include <iostream>
#include <cstring>

// 定义函数 countVowels，接受一个指向字符串的指针作为参数，
// 返回字符串中元音字母（a、e、i、o、u）的数量
int countVowels(char* str) {
    // 定义元音字母数组
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    // 定义指向字符串首元素和末元素的指针
    char* ptr = str;
    char* end = str + strlen(str);

    // 定义变量存储元音字母数量
    int count = 0;

    // 遍历字符串，统计元音字母的数量
    while (ptr < end) {
        // 判断当前字符是否为元音字母
        for (int i = 0; i < sizeof(vowels); i++) {
            if (*ptr == vowels[i]) {
                count++;
            }
        }
        ptr++;
    }

    // 返回元音字母的数量
    return count;
}

int main() {
    // 定义一个字符串
    char str[] = "This is a test.";

    // 调用 countVowels 函数，输出字符串中元音字母的数量
    std::cout << "字符串中元音字母的数量为：" << countVowels(str) << std::endl;

    return 0;
}

/*
代码4实现了一个计算字符串中元音字母数量的函数。该
函数首先定义了元音字母数组和指向字符串首元素和末元素的指针，然后遍历字符串并统计元音字母的数量，最后返回数量。
该函数使用了指针遍历字符串，同时也使用了字符串库中的函数strlen来计算字符串长度。
该函数可以用于统计字符串中特定字符的数量，如元音字母、辅音字母等。
*/