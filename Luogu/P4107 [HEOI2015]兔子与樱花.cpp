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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,m,c[N],ans;
int hd[N],nxt[N],to[N],ec,son[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x+y<A.x+A.y;}}s[N];

void dfs(int u){
	int t=0;
	for(int i=hd[u];i;i=nxt[i])dfs(to[i]);
	for(int i=hd[u];i;i=nxt[i])s[++t]=node(c[to[i]],son[to[i]]);
	sort(s+1,s+t+1);
	for(int i=1;i<=t;i++){
		if(c[u]+s[i].x+s[i].y+son[u]-1<=m)c[u]+=s[i].x,son[u]+=s[i].y-1,++ans;
		else break;
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1,k;i<=n;i++){
		son[i]=k=read();
		while(k--)add(i,read()+1);
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}

