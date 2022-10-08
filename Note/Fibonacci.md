斐波那契数列

$$fib_0=0,fib_1=1,fib_i=fib_{i-2}+fib_{i-1}$$

$fib$ 的生成函数为 $F$

$$F(x)=\sum_{i=0}^{\infty}F[i]x^i$$

$$F(x)=F[0]+F[1]x+F[2]x^2+...$$

$$xF(x)=F[0]x+F[1]x^2+F[2]x^3...$$

$$x^2F(x)=F[0]x^2+F[1]x^3+F[2]x^4$$

$$F(x)-xF(x)-x^2F(x)=F[1]x=x$$

$$(1-x-x^2)F(x)=x$$

$$F(x)=\frac{x}{1-x-x^2}$$

$$F(x)=-\frac{x}{(x-x_1)(x-x_2)}$$

$$
\begin{cases}
x_1+x_2=-1\\
x_1x_2=-1
\end{cases}
$$

$$
\begin{cases}
x_1=\frac{1+\sqrt{5}}{2}\\
x_2=\frac{1-\sqrt{5}}{2}
\end{cases}
$$

$$F(x)=-(\frac{a_1}{x-x_1}+\frac{a_2}{x-x_2})$$

$$\frac{a_1(x-x_2)+a_2(x-x_1)}{(x-x_1)(x-x_2)}=\frac{x}{(x-x_1)(x-x_2)}$$

$$a_1x-a_1x_2+a_2x-a_2x_1=x$$

$$
\begin{cases}
a_1+a_2=1\\
-a_1x_2-a_2x_1=0
\end{cases}
$$

$$
\begin{cases}
a_1=\frac{x_1}{x_1-x_2}\\
a_2=\frac{-x_2}{x_1-x_2}\\
\end{cases}
$$

$$
\begin{cases}
a_1=\frac{5+\sqrt{5}}{10}\\
a_2=\frac{5-\sqrt{5}}{10}\\
\end{cases}
$$

$$F[n]=[x^n](\frac{a_1}{x_1-x}+\frac{a_2}{x_2-x})$$

$$F[n]=[x^n](\frac{\frac{a_1}{x_1}}{1-\frac{x}{x_1}})+[x^n](\frac{\frac{a_2}{x_2}}{1-\frac{x}{x_2}})$$

$$F[n]=\frac{a_1}{x_1^{n+1}}+\frac{a_2}{x_2^{n+1}}$$

$$F[n]=\frac{\frac{5+\sqrt{5}}{10}}{(\frac{1+\sqrt{5}}{2})^{n+1}}+\frac{\frac{5-\sqrt{5}}{10}}{(\frac{1-\sqrt{5}}{2})^{n+1}}$$

$$F[n]=\frac{\frac{5+\sqrt{5}}{10}}{(\frac{1+\sqrt{5}}{2})^n\frac{1+\sqrt{5}}{2}}+\frac{\frac{5-\sqrt{5}}{10}}{(\frac{1-\sqrt{5}}{2})^n\frac{1-\sqrt{5}}{2}}$$

$$F[n]=\frac{1+\frac{\sqrt{5}}{5}}{(\frac{1+\sqrt{5}}{2})^n(1+\sqrt{5})}+\frac{1-\frac{\sqrt{5}}{5}}{(\frac{1-\sqrt{5}}{2})^n(1-\sqrt{5})}$$

$$F[n]=\frac{(1+\frac{\sqrt{5}}{5})(1-\sqrt{5})}{(\frac{1+\sqrt{5}}{2})^n(1+\sqrt{5})(1-\sqrt{5})}+\frac{(1-\frac{\sqrt{5}}{5})(1+\sqrt{5})}{(\frac{1-\sqrt{5}}{2})^n(1-\sqrt{5})(1+\sqrt{5})}$$

$$F[n]=\frac{-\frac{4}{5}\sqrt{5}}{-4(\frac{1+\sqrt{5}}{2})^n}+\frac{\frac{4}{5}\sqrt{5}}{-4(\frac{1-\sqrt{5}}{2})^n}$$

$$F[n]=\frac{\sqrt{5}}{5}((\frac{1+\sqrt{5}}{2})^n-(\frac{1-\sqrt{5}}{2})^n)$$

### [P4451 [国家集训队]整数的lqp拆分](https://www.luogu.com.cn/problem/P4451)

$$g_n=\sum_{\sum_{i=1}^ma_i=n,a_i>0}\prod_{i=1}^mfib_{a_i}$$

令 $g_0=1$

$$g_n=[n=0]+\sum_{i=0}^{n-1}g_ifib_{n-i}$$

$g$ 的生成函数为 $G$

$$G(x)=\sum_{n=0}^{\infty}([n=0]+\sum_{i=0}^{n-1}g_ifib_{n-i})x^n$$

$$G(x)=1+\sum_{n=1}^{\infty}\sum_{i=0}^{n-1}g_ifib_{n-i}x^n$$

$$G(x)=1+F(x)\times G(x)$$

$$G(x)=\frac{1}{1-F(x)}$$

$$G(x)=\frac{1}{1-\frac{x}{1-x-x^2}}$$

$$G(x)=\frac{1-x-x^2}{1-2x-x^2}$$

$$G(x)=1+\frac{x}{1-2x-x^2}$$

$$(x-x_1)(-x-x_2)=1-2x-x^2$$

$$
\begin{cases}
x_1-x_2=2\\
x_1x_2=1
\end{cases}
$$

$$
\begin{cases}
x_1=-\sqrt{2}+1\\
x_2=-\sqrt{2}-1
\end{cases}
$$

$$G(x)=1+\frac{a_1}{x-x_1}+\frac{a_2}{-x-x_2}$$

$$G(x)=1+\frac{(-x-x_2)a_1+(x-x_1)a_2}{(x-x_1)(-x-x_2)}$$

$$
\begin{cases}
a_2-a_1=1\\
x_2a_1+x_1a_2=0
\end{cases}
$$

$$
\begin{cases}
a_1=-\frac{x_1}{x_1+x_2}\\
a_2=\frac{x_2}{x_1+x_2}
\end{cases}
$$

$$
\begin{cases}
a_1=\frac{-\sqrt{2}+1}{2\sqrt{2}}\\
a_2=\frac{\sqrt{2}+1}{2\sqrt{2}}
\end{cases}
$$

忽略 $1$

$$G[n]=[x^n](\frac{a_1}{x_1-x}+\frac{a_2}{-x_2-x})$$

$$G[n]=[x^n](\frac{\frac{a_1}{x_1}}{1-\frac{x}{x_1}}+\frac{\frac{a_2}{-x_2}}{1-\frac{x}{-x_2}})$$

$$G[n]=\frac{a_1}{x_1^{n+1}}+\frac{a_2}{(-x_2)^{n+1}}$$

$$G[n]=-\frac{\frac{1-\sqrt{2}}{2\sqrt{2}}}{(1-\sqrt{2})^{n+1}}+\frac{\frac{\sqrt{2}+1}{2\sqrt{2}}}{(\sqrt{2}+1)^{n+1}}$$

$$G[n]=-\frac{\frac{1}{2\sqrt{2}}}{(1-\sqrt{2})^n}+\frac{\frac{1}{2\sqrt{2}}}{(\sqrt{2}+1)^n}$$

$$G[n]=\frac{1}{2\sqrt{2}}(\frac{1}{(1+\sqrt{2})^n}-\frac{1}{(1-\sqrt{2})^n})$$
