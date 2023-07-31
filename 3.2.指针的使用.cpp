/*

题目二：指针的使用 请编写一个函数，接受两个整数作为参数，并交换这两个整数的值。使用指针来实现交换。

*/


#include <iostream>

// 定义一个交换函数，使用指针作为参数
void swap(int* a, int* b) {
    // 交换a和b指向的值
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // 初始化两个变量
    int num1 = 10;
    int num2 = 20;

    // 输出交换前的值
    std::cout << "交换前：" << std::endl;
    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;

    // 调用交换函数，传递num1和num2的地址
    swap(&num1, &num2);

    // 输出交换后的值
    std::cout << "交换后：" << std::endl;
    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;

    return 0;
}

/*

在C++中，可以使用指针来实现交换两个整数变量的值。具体实现方法是：定义一个函数，该函数接受两个指向整数类型的指针作为参数，然后将这两个指针所指向的变量的值进行交换。

下面是一个示例代码，演示如何使用指针实现交换两个整数变量的值：

```
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int num1 = 10;
  int num2 = 20;

  std::cout << "交换前：" << std::endl;
  std::cout << "num1 = " << num1 << std::endl;
  std::cout << "num2 = " << num2 << std::endl;

  swap(&num1, &num2);

  std::cout << "交换后：" << std::endl;
  std::cout << "num1 = " << num1 << std::endl;
  std::cout << "num2 = " << num2 << std::endl;

  return 0;
}
```

在上述代码中，我们定义了一个 swap 函数，该函数接受两个指向整数类型的指针 a 和 b 作为参数。在函数内部，我们首先定义了一个临时变量 temp，用于保存指针 a 所指向的变量的值。然后，我们将指针 a 所指向的变量的值赋值给指针 b 所指向的变量，将指针 b 所指向的变量的值赋值给指针 a 所指向的变量，最后将临时变量 temp 的值赋值给指针 b 所指向的变量。

在主函数中，我们定义了两个整数变量 num1 和 num2，并输出它们的值。然后，我们调用 swap 函数，并将 num1 和 num2 的地址作为参数传递给该函数，从而实现交换它们的值。最后，我们再次输出 num1 和 num2 的值，以验证它们的值已经成功交换。

输出结果：

```
交换前：
num1 = 10
num2 = 20
交换后：
num1 = 20
num2 = 10
```

可以看到，经过 swap 函数的调用，num1 和 num2 的值已经成功交换了。

*/
