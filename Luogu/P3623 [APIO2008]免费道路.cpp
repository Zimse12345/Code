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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,k,fa[N],cnt[N],tag[N];
struct edge{int u,v,ty;edge(int u=0,int v=0,int ty=0):u(u),v(v),ty(ty){}}e[N];
inline int F(int x){if(fa[x]^x)fa[x]=F(fa[x]);return fa[x];}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1,u,v,ty;i<=m;i++)u=read(),v=read(),ty=read(),e[i]=edge(u,v,ty);
	for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
	for(int c=1;c>=0;c--){for(int i=1,x,y;i<=m;i++){if(e[i].ty==c){
		x=F(e[i].u),y=F(e[i].v);
		if(x^y){if(cnt[x]<cnt[y])swap(x,y);fa[y]=x,cnt[x]+=cnt[y];if(c==0)e[i].ty=-1,--k;}
	}}}
	if(k<0){
		printf("no solution\n");
		return 0;
	}
	for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
	for(int c=-1;c<=1;c++){for(int i=1,x,y;i<=m;i++){if(e[i].ty==c){
		if(k==0&&c==0)continue;
		x=F(e[i].u),y=F(e[i].v);
		if(x^y){if(cnt[x]<cnt[y])swap(x,y);fa[y]=x,cnt[x]+=cnt[y];if(c==0)--k;tag[i]=1;}
	}}}
	if(k>0){
		printf("no solution\n");
		return 0;
	}
	for(int i=1;i<=m;i++)if(tag[i])printf("%d %d %d\n",e[i].u,e[i].v,max(e[i].ty,0));
	return 0;
}

