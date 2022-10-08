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

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=1e9+7,INF=1e9+7;
int n,m;

struct dsu{
int fa[N],sz[N];

inline void init(){
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	return;
}
	
int F(int x){
	if(fa[x]^x)fa[x]=F(fa[x]);
	return fa[x];
}

inline void link(int x,int y){
	x=F(x),y=F(y);
	if(x^y){
		if(sz[x]<sz[y])swap(x,y);
		fa[y]=x,sz[x]+=sz[y];
	}
	return;
}
}s[20];

int _lg2[N],vis[N],cnt;

signed main(){
	for(int i=2;i<N;i++)_lg2[i]=_lg2[i/2]+1;
	n=read(),m=read();
	for(int i=0;i<20;i++)s[i].init();
	for(int i=1,l1,r1,l2,r2;i<=m;i++){
		l1=read(),r1=read(),l2=read(),r2=read();
		int len=r1-l1+1,t=_lg2[len];
		s[t].link(l1,l2);
		s[t].link(r1-(1<<t)+1,r2-(1<<t)+1);
	}
	for(int i=19;i>=1;i--){
		for(int j=1;j<=n-(1<<i)+1;j++){
			int fa=s[i].F(j);
			s[i-1].link(fa,j);
			s[i-1].link(fa+(1<<(i-1)),j+(1<<(i-1))); 
		}
	}
	for(int i=1;i<=n;i++){
		int fa=s[0].F(i);
		if(!vis[fa])vis[fa]=1,++cnt;
	}
	ll ans=9;
	for(int i=2;i<=cnt;i++)ans=ans*10%Mod;
	printf("%lld\n",ans);
	return 0;
}

