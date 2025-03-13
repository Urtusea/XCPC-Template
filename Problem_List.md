有一个很推荐的系统性教学的网站：https://usaco.guide/

# 基础

## 语法基础

1. 函数

简单的来说，我们可以将多个可以复用的模块封装成模块，方便调试和编写我们的程序

进阶：函数式编程，将整个程序理解为多个函数的复合过程

2. 指针

在算竞中较为 useless，除了偶尔需要使用到的 迭代器（C++中的另类指针）

3. 引用

引用和传输指针区别不大，引用的底层是指针实现，是对指针的一个更加安全的封装

注意引用在传递完后或者初始化完后，对象就无法更改，而指针是可变的

4. 结构体，类

在 C++ 中，我们姑且可以将 struct 和 class 看成一个东西，除了默认的访问和继承权限不同

struct 是 public，class 是 private

## 算法基础

1. 模拟

唉牛魔的，这没啥好说的，就当是大一写的那种 xxx 管理系统吧

- [P2482 [SDOI2010] 猪国杀](https://www.luogu.com.cn/problem/P2482)

2. 递归回溯分治

递归就是 DFS 罢了，回溯是我们可以保证我们的路径始终是一条链，然后每次可以撤销最后一次操作，分治就是再将我们递归搜到的小问题，合并成我当前的最优解

- [P3612 [USACO17JAN] Secret Cow Code S](https://www.luogu.com.cn/problem/P3612)
- [P1010 [NOIP 1998 普及组] 幂次方](https://www.luogu.com.cn/problem/P1010)
- [P7883 平面最近点对（加强加强版）](https://www.luogu.com.cn/problem/P7883)

3. 递推

最经典就是 fibonacci 啊，递推是我们将记忆化 dfs 扩展成 dp 的基础，也是我们组合数学推式子的一个基础

- [P1028 [NOIP 2001 普及组] 数的计算](https://www.luogu.com.cn/problem/P1028)
- [P1044 [NOIP 2003 普及组] 栈](https://www.luogu.com.cn/problem/P1044)

4. 贪心

贪心就是一直去考虑我们当前的最优解，不顾长远

主要是要注意 后悔贪心 和 邻项扰动

后悔贪心主要是答案的函数呈现是一个凸包函数的话我们可以使用后悔贪心（后悔贪心起码是铜上位题了，除了特别板），这种还有拓展证明，详细自己网上搜 Slope Trick

阅读材料：

- https://www.cnblogs.com/Plozia/p/16142283.html
- https://www.cnblogs.com/cccomfy/p/17743031.html
- https://codeforces.com/blog/entry/47821
- https://sam571128.codes/2021/10/23/Slope-Trick/
- [题单](https://www.luogu.com.cn/training/559292)

邻项扰动就是考虑我的数组以某种形式排序，或者我的选择方式是按某种顺序的情况下，我交换数组两个数，或者交换两个选择顺序，变得更差，就能证明我以我当前的这种形式排序，是最优的，**注意有些情况有两种最优**

- [P1080 [NOIP 2012 提高组] 国王游戏](https://www.luogu.com.cn/problem/P1080)
- [P2123 皇后游戏](https://www.luogu.com.cn/problem/P2123)