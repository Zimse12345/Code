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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353;
int n,m,W[N],fa[N],cnt[N];
struct edge{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator < (const edge& A)const{return w<A.w;}
}e[N];
struct R{
	int p,q;
	R(int p=0,int q=1):p(p),q(q){}
	bool operator < (const R& A)const{return (double(p)/double(q))<(double(A.p)/double(A.q));}
}ans;
inline int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int F(int x){
	if(fa[x]!=x)fa[x]=F(fa[x]);
	return fa[x];
}

signed main(){
	n=read(),m=read(),ans=R(1000000,1);
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		e[i]=edge(u,v,w);
	}
	sort(e+1,e+m+1);
	int S=read(),T=read();
	for(int i=1;i<=m;i++){
		R s=R(0,0);
		for(int j=1;j<=n;j++)fa[j]=j,cnt[j]=1;
		for(int j=i;j<=m;j++){
			int u=e[j].u,v=e[j].v,w=e[j].w,A=F(u),B=F(v);
			if(A!=B){
				if(cnt[A]<cnt[B])swap(A,B);
				fa[B]=A,cnt[A]+=cnt[B];
			}
			if(F(S)==F(T)){
				s=R(w,e[i].w);
				break;
			}
		}
		if(s.q!=0&&s<ans)ans=s;
	}
	if(ans.p/ans.q>=500000)printf("IMPOSSIBLE\n");
	else{
		int g=gcd(ans.p,ans.q);
		ans.p/=g,ans.q/=g;
		if(ans.q==1)printf("%lld\n",ans.p);
		else printf("%lld/%lld\n",ans.p,ans.q);
	}
	return 0;
}
