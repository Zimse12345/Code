本文档记录在学习OI过程中总结的解题思想和策略

### ( 1 ) 动态规划

##### $~~$ 1.线性dp

考虑如下形式的dp

$$ dp_i=min\{dp_j+w(j+1,i)\}_{j < i} $$

也可以是 $max$ ,这里只讨论 $min$ 的情况

对于最一般的情况,可以直接 $O(?)$ 计算 $w(i,j)$ 或从 $w(i,j)$ 转移到 $w(i,j+1)$ ,可以 $O(?n^2)$ 进行转移

如果要更优的时间复杂度,可以进行以下优化

决策单调性优化dp,一般需要满足的形式,对于两个位置 $i_1,i_2$ 有两个决策点 $x_1,x_2$,如果 $i_1<i_2$ 则 $x_1 \le x_2$

如何证明?

$$
\begin{cases}
dp_{x_1}+w(x_1+1,i_1) \le dp_{x_2}+w(x_2+1,i_1)\\
dp_{x_2}+w(x_2+1,i_2) \le dp_{x_1}+w(x_1+1,i_2)
\end{cases}
$$

$$ w(x_1+1,i_1)-w(x_1+1,i_2) \le w(x_2+1,i_1)-w(x_2+1,i_2) $$

$$ w(x_1+1,i_1)+w(x_2+1,i_2) \le w(x_2+1,i_1)+w(x_1+1,i_2) $$

只需证明上述不等式即可

回到决策单调性优化,最简单的一种情况,当 $x$ 为 $i$ 的最优决策点时 $dp_y+w(y+1,i) \ge dp_x+w(x+1,i)$ ,这时候只需要用一个指针维护最优决策点 $x$,一但发现决策点 $x+1$ 不会更劣就右移指针

大多数情况没有这么简单,一般要用一个单调栈/队列维护所有有效的决策点,对于一个决策点 $x$ ,令 $f_x(i)=dp_x+w(x+1,i)$ ,转移时就是找到最小的 $f_x(i)$ ,依次枚举考虑 $i$ 的过程中 $i$ 是单调递增的,如果 $\forall_{j \ge i} f_x(j) \le f_y(j)$ , $y$ 这个决策点就没有任何存在的价值了,可以被移除单调栈/队列

分两种情况讨论

第一种情况,对于两个决策点 $x \le y$ , 存在一个中心点 $mid_{x,y}$ 满足

$$
\begin{cases}
\forall_{j \le mid_{x,y}}f_x(j) < f_y(j)\\
\forall_{j > mid_{x,y}}f_x(j) \ge f_y(j)
\end{cases}
$$

也就是说决策点 $x$ 在 $mid$ 及之前是更优的,之后就完全被 $y$ 取代了

在单调队列中找 $i$ 的最优决策点

考虑单调队列的队首决策点 $x$ 和次队首决策点 $y$ ,如果发现 $mid_{x,y} \ge i$ ,$x$ 就被移除队首

移除结束后发现队首决策点 $x$ 就是 $i$ 的最优决策点

把决策点 $i$ 加入队列中时次队尾决策点 $x$ ,队尾决策点 $y$ ,如果 $mid_{y,i} \le mid_{x,y}$ , $y$ 就被移除队尾

移除结束后把 $i$ 加入队尾

第二种情况

$$
\begin{cases}
\forall_{j \le mid_{x,y}}f_y(j) < f_x(j)\\
\forall_{j > mid_{x,y}}f_y(j) \ge f_x(j)
\end{cases}
$$

$y$ 在 $mid_{x,y}$ 之后被 $x$  取代

栈顶决策点 $y$ 和次栈顶决策点 $x$ ,如果 $mid_{x,y} \ge i$ ,$y$ 就被移除栈

栈顶决策点 $x$ 即为 $i$ 的最优决策点

栈顶决策点 $y$ 和次栈顶决策点 $x$ ,如果 $mid_{x,y} \le mid_{y,i}$ , $y$ 就被移除栈,最后把 $i$ 加入栈顶

现在的问题在于如何找到 $mid_{x,y}$

对于大多数的问题,可以二分一个 $mid$ 在 $\log$ 时间复杂度内完成

但也有一部分问题 $w(i,j)$ 是难以直接计算的,只能从 $w(i,j-1)$ 推出来

此时如果满足 $dp_i$ 和 $dp_j$ 互不干涉,就可以二分考虑的点 $i$ ,暴力找出 $i$ 的最优决策点 $x$ ,此时小于 $i$ 的位置决策点小于等于 $x$ ,大于等于 $i$ 的位置决点大于等于 $x$ ,这样一直递归下去即可

一般对于分层dp,从上一层的状态转移到当前层的状态满足互不干涉的性质,要求互不干涉的原因是可以在计算 $i$ 之前的dp值前可以先计算出 $dp_i$

递归的时间复杂度是 $O(n \log{n})$ 的

更复杂的情况

$$ dp_i = min\{dp_j+A_jB_i+C_j+D_i\}_{j < i}$$

其中 $A_j,C_j$ 只和 $j$ 有关, $B_i,D_i$ 之和 $i$ 有关

这时可以考虑斜率优化

转换为

$$ dp_j+C_j=B_iA_j+D_i-dp_i $$

形如

$$ y=kx+b$$

每一个决策点 $j$ 就对于平面上一个点 $(x,y)=(B_i,dp_j+C_j)$

$B_i$ 就是给定一个直线的斜率

现在要求这条给定斜率的直线穿过给定点,交 $y$ 轴于点 $b$ ,这时 $dp_i=D_i-b$

要 $dp_i$ 尽可能小只需要找到最小的 $b$ 即可

根据不同题目的各个参数是否具备单调性 , 只需要以不同方式维护这些决策点 (一般是凸包) 即可解决

##### $~~$ 2.树形DP

##### $~~$ 3.状压DP