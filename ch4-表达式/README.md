表达式
=====

## 优先级

### 处理复合表达式

1. 使用括号
2. 如果改变了某个运算对象的值，在表达式的其他地方不要再使用这个运算对象。
3. 第2条规则的例外：当改变运算对象的子表达式本身就是另外一个子表达式的运算对象时该规则无效

### 算术运算符

```cpp
int i = 1024;
int j = -i;     // -1024
bool ok = true;
bool ok2 = -ok; // true
```

``bool``类型提升为``int``，true变为1，-1非0，所以转换为``bool``为true

溢出

```cpp
short i = 32767;
i += 1;
cout << i << endl; // -32768
```

该值发生``环绕（wrapped arround）``，符号位本来是0，由于溢出被改成了1，于是结果变成一个负值。

### 递增递减运算符

除非必须，否则不用递增/递减运算符的后置版本

