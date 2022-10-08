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

const int N=2e5+7,Mod=998244353,INF=1e8;
int n,s,t,hd[N],h[N],nxt[N],ec=1,d[N],cnt,ans;
int dx[8]={-1,-2,-2,-1,1,2,2,1},dy[8]={-2,-1,1,2,2,1,-1,-2};
char str[300][300];
inline int c(int x,int y){return (x-1)*n+y;}
struct edge{int u,v,val;edge(int u=0,int v=0,int val=0):u(u),v(v),val(val){}}E[N];
inline void add(int u,int v,int val){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,val);return;}
inline void Add(int u,int v,int val){add(u,v,val),add(v,u,0);return;}

queue<int> Q;
bool bfs(){
	for(int i=1;i<=n;i++)d[i]=0;
	d[s]=1,Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=hd[u];i;i=nxt[i])if(E[i].val&&!d[E[i].v])d[E[i].v]=d[u]+1,Q.push(E[i].v);
	}
	return d[t];
}

int dfs(int u,int maxf){
	if(u==t||!maxf)return maxf;
	int flow=0;
	for(int i=h[u];i;i=nxt[i]){
		if(E[i].val&&d[E[i].v]==d[u]+1){
			int f=dfs(E[i].v,min(maxf,E[i].val));
			flow+=f,maxf-=f,E[i].val-=f,E[i^1].val+=f;
			if(!maxf)break;
		}
		h[u]=nxt[h[u]];
	}
	return flow;
}

void dinic(){
	while(bfs()){
		for(int i=1;i<=n;i++)h[i]=hd[i];
		ans+=dfs(s,INF);
	}
	return;
}

signed main(){
	n=read(),s=n*n+1,t=s+1;
	for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(str[i][j]=='0'){
			++cnt;
			if((i+j)&1){
				for(int k=0;k<8;k++){
					int x=i+dx[k],y=j+dy[k];
					if(1<=x&&x<=n&&1<=y&&y<=n&&str[x][y]=='0')Add(c(i,j),c(x,y),1);
				}
				Add(s,c(i,j),1);
			}
			else Add(c(i,j),t,1);
		}
	}
	n=t;
	dinic();
	printf("%d\n",cnt-ans);
	return 0;
}

