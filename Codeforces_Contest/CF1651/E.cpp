#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e3+7,Mod=998244353,INF=1e9+7;
int n,lc[N],rc[N],ans;
inline void add(int u,int v){if(lc[u])rc[u]=v;else lc[u]=v;return;}
inline int c(int x){if(x<=0)return 0;return x*(x+1)/2;}

int f(int from,int to,int L,int R){
	if(from>n)from-=n;if(to>n)to-=n;if(L>n)L-=n;if(R>n)R-=n;if(R==-1)R=n+1;
	if(R<L)swap(L,R);
	if(to==-1)return c(L-1)+c(R-L-1)+c(n-R);
	if(L<from&&R>to)return (from-L)*(R-to);
	if(R<from)return (from-R)*(n-to+1);
	if(L>to)return from*(L-to);
	return 0;
}

signed main(){
	n=read();
	for(int i=1,x,y;i<=n*2;i++)x=read(),y=read(),add(x,y),add(y,x);
	for(int mid=1;mid<=n*2;mid++){
		int pr_a=mid,pr_b=mid;
		int a=lc[mid],b=rc[mid],Ls=mid,Rs=mid,Lt=n+1,Rt=-1,t=0;
		if(Ls>n)Ls-=n,Rs-=n;
		while(1){
			if(t)ans+=f(Ls,Rs,a,b)*f(Lt,Rt,0,-1);
			else ans+=f(Ls,Rs,0,-1)*f(Lt,Rt,a,b);
			if(a==b)break;
			int _a=a,_b=b;if(_a>n)_a-=n;if(_b>n)_b-=n;
			if(t)Ls=min(Ls,min(_a,_b)),Rs=max(Rs,max(_a,_b));
			else  Lt=min(Lt,min(_a,_b)),Rt=max(Rt,max(_a,_b));
			if(lc[a]==pr_a)pr_a=a,a=rc[a];
			else pr_a=a,a=lc[a];
			if(lc[b]==pr_b)pr_b=b,b=rc[b];
			else pr_b=b,b=lc[b];
			t^=1;
		} 
	}
	int cnt=0;
	for(int a=1;a<=n;a++)for(int b=a;b<=n;b++)cnt+=(b-a+1)*(n*(n+1)/2)*2;
	ans=(cnt-ans)/2;
	printf("%lld\n",ans);
	return 0;
}

