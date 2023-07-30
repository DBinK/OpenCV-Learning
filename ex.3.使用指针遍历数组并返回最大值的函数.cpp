/*
③请编写一个函数 findMax，接受一个整数数组和数组大小作为参数，
返回数组中的最大值。要求使用指针来遍历数组，而不是使用下
标。    
*/

#include <iostream>

// 定义函数 findMax，接受一个整数数组和数组大小作为参数，
// 返回数组中的最大值
int findMax(int* arr, int size) {
    // 定义指向数组首元素和末元素的指针
    int* ptr = arr;
    int* end = arr + size;

    // 定义一个变量存储最大值
    int maxVal = *ptr;

    // 遍历数组，更新最大值
    while (ptr < end) {
        if (*ptr > maxVal) {
            maxVal = *ptr;
        }
        ptr++;
    }

    // 返回最大值
    return maxVal;
}

int main() {
    // 定义一个整数数组
    int arr[] = {1, 3, 5, 2, 4};

    // 计算数组的大小
    int size = sizeof(arr) / sizeof(int);

    // 调用 findMax 函数，输出数组的最大值
    std::cout << "数组的最大值为：" << findMax(arr, size) << std::endl;

    return 0;
}

/*
代码3实现了一个使用指针遍历数组并返回最大值的函数。
该函数首先定义了指向数组首元素和末元素的指针，然后遍历数组并更新最大值，最后返回最大值。
该函数使用指针来遍历数组，而不是使用下标。这种方式可以提高代码的效率，同时也更加灵活。
*/