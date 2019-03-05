以下$p$为质数，$p_i$为第$i$个质数

min25筛可以在（假装）$O\left(\frac{n^{\frac34}}{\log n}\right)$的时间复杂度内求积性函数前缀和，要求$f(p)$是关于$p$的低次多项式

-------------

设$s_n=\sum\limits_{p\leq n}p^k$，可以求出所有的$s_{\left\lfloor\frac ni\right\rfloor}$

```
let s[i]=1^k+...+i^k
for p=2 to n
	for i=n to p^2
		s[i]-=(s[i/p]-s[p-1])*p^k
```

这里是$O\left(k^2+k\sqrt n+\frac{n^{\frac34}}{\log n}\right)$

-------------------------------------

求出$s$后可以求得$g_n=\sum\limits_{p\leq n}f(p)$

设$h_{n,i}=\sum\limits_{j=2}^n[\min p|j\ge p_j]f(j)$，有$h_{n,i}=\sum\limits_{j\geq i}\sum\limits_{\substack{p_j^e\leq n\\e\geq1}}f\left(p_j^e\right)\left(h_{\left\lfloor\frac n{p_j^e}\right\rfloor,j+1}+1\right)$

外层sigma只用算到最大的$j$满足$p_j^2\leq n$，剩下的部分是$g_n-g_{p_j}$

这里是$O(n^{1-\epsilon})$，实测在较小的数据范围表现得和$O\left(\frac{n^{\frac34}}{\log n}\right)$差不多，还要乘上算/递推$f\left(p^k\right)$的时间