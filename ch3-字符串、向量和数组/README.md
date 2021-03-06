字符串、向量和数组
==============

## 命名空间

### 头文件不应包含using声明

可能会导致命名冲突

## 标准库类型string

### 初始化

1. 直接初始化
2. 拷贝初始化

## 字符串

### 定义

```cpp
string s1 = "hello";
string s2("world");
string s3(10, 'a');
```

### 操作

```cpp
// 是否为空
s.empty();

// 字符个数
s.size();

// 随机访问
s[n];

// 连接
s1+s2;
```

### 处理字符

头文件：``cctype``

```cpp
// 是否是小写，大写为isupper
islower(c);

// 是否是字母
isalpha(c);

// 是否是数字
isdigit(c);

// 是否是空格（包括空格、制表符、回车符、换行符、进纸符）
isspace(c);

// 转换为小写，大写为toupper
tolower(c);
```

### 遍历

```cpp
for(declaration: expression)
```

## 标准库类型vector

vector是模板而非类型，由``vector``生成的类型必须包含``vector``中元素的类型，如``vector<int>``

### 定义和初始化

```cpp
vector<T> v1;
vector<T> v2(v1);
vector<T> v2 = v1;
vector<T> v3(n, val);
vector<T> v4(n);
vector<T> v5{a, b, c};
vector<T> v5={a, b, c};
```

### 操作

```cpp
// 是否为空
v.empty();

// 元素个数
v.size();

// 容量
v.capacity();

// 尾端添加元素
v.push_back(1);

// 随机访问
v[n];
```

``vector``对象（以及``string``对象）的下标运算符可用于访问已存在的元素，而不能用于添加元素

## 迭代器

### 使用

```cpp
// 表示v的第一个元素
v.begin();

// 表示v尾元素的下一个位置，被称作尾后迭代器
v.end();

// 如果对象是常量，则返回const_iterator
v.cbegin();
v. cend();
```

如果容器为空，则``begin``和``end``返回的是同一个迭代器，都是尾后迭代器

### 运算符

```cpp
// 迭代器所指元素的引用
*iter;

// 结合解引用和成员访问操作：相当于 (*iter)->item;
iter->item;

// 指向下一个元素
++iter;

// 指向下n个元素
iter + n;

// 判断两个迭代器是否相等（不等），如果都指向同一个元素或者都是同一个容器的尾后迭代器，则相等。反之，不等。
iter1 != iter2;
```

### 术语

迭代器

1. 迭代器概念本身
2. 指容器定义的迭代器类型
3. 指某个迭代器对象

## 数组

### 定义和初始化

数组中元素的个数也属于数组类型的一部分，编译的时候维度应该是已知的。即，维度必须是一个常量表达式。

```cpp
// 常量表达式
constexpr unsigned sz = 10;

// 不是常量表达式
unsigned cnt = 10;

// 合法
int arr[10];

// 合法
int arr[sz];

// 当get_size是常量表达式时正确
int arr[get_size()];
```

注意

1. 必须指定数组的类型，不允许使用``auto``由初始值的列表推断类型
2. 和``vector``一样，数组的元素应为对象，因此不存在引用的数组
3. 如果声明时未指定维度，编译器会根据初始值的数量计算并推测出来
4. 如果声明时指定了维度，那么初始值的总数量不应超出指定的大小
5. 如果初始值的总数量小于维度的大小，则用初始值初始化靠前的元素，剩下元素被初始化为默认值
6. 不能将数组的内容拷贝给其他数组作为初始值
7. 不能用数组为其他数组赋值

一些编译器支持数组的赋值，即``编译器扩展``。一般来说，避免使用非标准特性，不利于迁移到其他编译器

### 访问

在使用数组下标的时候，通常将其定义为``size_t``类型。``size_t``是一种机器相关的无符号类型，它被设计的足够大以便能表示内存中任意对象的大小。

注意：检查下标的值。大多数常见的安全问题都源于缓冲区溢出错误。当数组或其他类似数据结构的下标越界并试图访问非法内存区域时，就会产生此类错误。

### 指针和数组

在大多数表达式中，使用数组类型的对象其实是使用一个指向该数组首元素的指针

指针也是迭代器

```cpp
int a[] = {1,2,3};
int *b = begin(a); // c++11
int *e = end(a); // c++11
for (;b != e;b++)
    cout << *b << endl;
```

注意：一个指针如果如果指向了某种内置类型数组的尾元素的“下一位置”，则其具备与vector的``end``函数返回的与迭代器类似的功能。特别注意，尾后指针不能执行解引用和递增操作。

```cpp
int a[] = {1,2,3};
int *p = &a[2];
cout << *p << endl;     // 3
cout << p[-2] << endl;  // 1
```

注意：内置的下标运算符所用的索引值不是无符号类型，这一点与``vector``和``string``不一样

### 与旧代码的接口

1. 允许使用以空字符结束的字符数组来初始化``string``对象或为``string``对象赋值
2. 在``string``对象的加法运算中，允许使用以空字符结束的字符数组作为其中一个运算对象（不能两个运算对象都是）；在``string``对象的复合赋值运算中，允许使用以空字符结束的字符数组作为右侧的运算对象

上述性质不可反过来：如果程序的某处需要一个C风格的字符串，无法用``string``对象来代替它。

```cpp
char *str = s; // 错误
const char *str = s.c_str(); // 正确，返回一个C风格字符串
```

注意：如果执行完``c_str()``函数后程序想一直都能使用其返回的数组，最好将该数组重新拷贝一份。

### 使用数组来初始化vector类型

```cpp
int a[] = {1,2,3};
vector<int> b(begin(a), end(a));
```

建议：尽量使用标准库类型而非数组。

- [x] 尽量使用``vector``和迭代器
- [ ] 避免使用内置数组和指针
- [x] 尽量使用string
- [ ] 避免使用C风格的基于数组的字符串

### 多维数组

严格来说，C++语言没有多维数组，通常说的多维数组其实就是数组的数组。

对于二维数组来说，通常把第一个维度称作行，第二个维度称作列。

```cpp
int a[3][4] = {0};

for (auto &row: a) {
    for (auto col: row) {
        cout << col << endl;
    }
}
```

注意：要使用范围``for``语句处理多维数组，除了最内层的循环外，其他所有循环的控制变量都是引用类型

```cpp
// 整型指针的数组
int *p[4];

// 指向含有4个整数的数组
int (*p)[4];
```

### 类型别名简化多维数组的指针

1. using
2. typedef