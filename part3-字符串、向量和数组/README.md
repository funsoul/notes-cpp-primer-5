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