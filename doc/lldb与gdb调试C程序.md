# lldb运行程序

```shell
lldb main
```
# 设置断点

## 行断点

```shell
breakpoint set --file foo.c --line 12
breakpoint set -f foo.c -l 12
br s -f foo.c -l 12
b foo.c:12
```

## 符号断点:给方法设置点

```shell
b test
```

## 列出所有断点

```shell
br list
```

## 删除断点

```shell
br del 1
```

# 分步调试

## 跳过:next

```shell
next
n
```

## 进入:step into

```shell
step
s
```

## 继续:跳到下一个断点

```shell
c
```

# 查看变量

## 打印变量内容

```shell
p [varName]
```

## 列出当前栈帧变量

```shell
frame variable
fr v
```

## 切换栈帧

```shell
frame select
fr s
```

## 调用栈

```shell
bt
```

# 设置观察点

```shell
w s v [varName]
```