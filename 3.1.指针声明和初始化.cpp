/*

题目一：指针声明和初始化 请声明一个指针变量，指向整数类型，并将它初始化为指向一个整数变量。

*/

#include <iostream>

int main() {
  int num = 42;  // 定义一个整数变量并初始化为42
  int* ptr = &num;  // 声明一个指向整数类型的指针，并将其初始化为指向num的地址

  // 输出指针变量的值和指向的变量的值
  std::cout << "ptr 指针变量的值为: " << ptr << std::endl;
  std::cout << "ptr 指向的变量的值为: " << *ptr << std::endl;

  return 0;
}


/*
在C++中，可以通过使用 * 操作符来声明一个指向整数类型的指针变量，并通过使用 & 操作符来获取一个整数变量的地址，从而将指针变量初始化为指向该整数变量的指针。

下面是一个示例代码，演示如何声明一个指向整数类型的指针，并将其初始化为指向一个整数变量：

```
int main() {
  int num = 42;  // 定义一个整数变量并初始化为42
  int* ptr = &num;  // 声明一个指向整数类型的指针，并将其初始化为指向num的地址

  // 输出指针变量的值和指向的变量的值
  std::cout << "ptr 指针变量的值为: " << ptr << std::endl;
  std::cout << "ptr 指向的变量的值为: " << *ptr << std::endl;

  return 0;
}
```

在上述代码中，我们首先定义了一个整数变量 num 并将其初始化为42。然后，我们使用 & 操作符获取 num 的地址，并将其赋值给指针变量 ptr。最后，我们输出了指针变量的值和指向的变量的值。

输出结果：

```
ptr 指针变量的值为: 0x7ffeeb9a8a4c
ptr 指向的变量的值为: 42
```

可以看到，指针变量 ptr 的值为 num 变量的地址，而通过使用 *ptr 可以访问该地址上存储的值，即整数变量 num 的值。

*/