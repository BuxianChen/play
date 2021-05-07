**leetcode 1486**

链接：https://leetcode-cn.com/problems/xor-operation-in-an-array

**题目**

给你两个整数，n 和 start 。
数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。
请返回 nums 中所有元素按位异或（XOR）后得到的结果。

 

示例 1：
输入：n = 5, start = 0
输出：8
解释：数组 nums 为 [0, 2, 4, 6, 8]，其中 (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 。
     "^" 为按位异或 XOR 运算符。

示例 2：
输入：n = 4, start = 3
输出：8
解释：数组 nums 为 [3, 5, 7, 9]，其中 (3 ^ 5 ^ 7 ^ 9) = 8.

示例 3：
输入：n = 1, start = 7
输出：7

示例 4：
输入：n = 10, start = 5
输出：2

提示：

1 <= n <= 1000
0 <= start <= 1000
n == nums.length

**思路**

异或运算的性质：

- $x\oplus y=y\oplus x$（交换律）
- 结合律
- $x\oplus0=x$
- $x\oplus x=0$

此题还需要用到如下性质：

- <font color=red>$(4k)\oplus (4k+1)\oplus (4k+2)\oplus(4k+3)=0$（其中$k$为非负整数）</font>

题目中要求计算（注意到提示里确保了不会发生整数溢出上限问题）

$x\oplus(x+2)\oplus(x+4)\oplus\cdots$

从二进制表示看，求和序列中每一项的最低位都不发生变化，因此可转化为：

$x\oplus(x+2)\oplus(x+4)\oplus\cdots=(y\oplus(y+1)\oplus(y+2)\oplus\cdots)*2+lowbit$

其中$y=x>>1$。而$lowbit=1$当且仅当$x$与$n$同为奇数，否则$lowbit=0$。

接下来，需要使用如下性质：
$$
\begin{align}
&y\oplus(y+1)\oplus(y+2)\oplus\cdots\oplus(y+n-1)\\
=&\text{xorsum}(y+n-1){\color{red} \oplus}\text{xorsum}(y-1)
\end{align}
$$
其中$\text{xorsum}(z)=0\oplus1\oplus2\oplus\cdots\oplus z$。

**代码解析**

```c++
// 计算0^1^2^...^x
int sumXor(int x){
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}
// 主函数
int xorOperation(int n, int start) {
    int x = start >> 1;
    return (sumXor(n + x - 1) ^ sumXor(x - 1)) << 1 | (n & start & 1);
}
```

注意：最低位的计算使用了`n & start & 1`的写法判断`n`与`start`是否均为奇数，并且加上最低位直接利用了按位或。

