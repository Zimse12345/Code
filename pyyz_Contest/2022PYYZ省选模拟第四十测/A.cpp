#pragma GCC optimize(2)
#pragma GCC target("avx")
#include <cstdio>
#include <algorithm>

const int N=3e6+7;
int n,T,a[N],b[N],c[N],d[N],m,q[N],l=1,r;
inline void p(int x){putchar(48+x),putchar(' '),--n;}

signed main(){
	scanf("%d%d",&n,&T);char C;
	for(int i=1,s=0;i<=n;i++){
		do{C=getchar();}while((C|1)^49);
		if(C^48)b[++m]=s,s=0;
		else ++s;
	}
	for(int i=1,x=1,S=0,s=0,k;i<=m;i++){
		c[i]=c[i-1]+b[i],S+=1-b[i],d[i]=-S;
		while(l<=r&&d[i]>d[q[r]])--r;q[++r]=i;
		while(c[i]-c[x-1]+d[q[l]]+S>T){++x;if(x>q[l])++l;}
		k=T-(c[i]-c[x-1]+std::max(d[q[l]],d[x-1])+S),a[i]=c[i]-c[x-1];
		if(k>0)a[i]+=std::min(k,b[x-1]);
		a[i]=c[i]-a[i]-s,s+=a[i];
		for(int j=1;j<=a[i];j++)p(0);p(1);
	}while(n)p(0);
	return 0;
}

