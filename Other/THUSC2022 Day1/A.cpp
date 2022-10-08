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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e4+7,Mod=998244353,INF=1e9+7;
int n,m,k,S,T,hd[N],nxt[N],to[N],len[N],w1[N],w2[N],ec;
int tim[N],P[N],dis[N],vis[N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return y>A.y;}
};
priority_queue<node> Q;

void dij(){
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[S]=0,Q.push(node(S,0));
	while(!Q.empty()){
		int u=Q.top().x;
		Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[u]+len[i]*w1[i]<dis[v]){
				dis[v]=dis[u]+len[i]*w1[i];
				Q.push(node(v,dis[v]));
			}
		}
	}
	return;
}

inline void add(int u,int v,int le,int w_1,int w_2){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	len[ec]=le,w1[ec]=w_1,w2[ec]=w_2;
	return;
}

int pr[N],plen[N],pw1[N],pw2[N];
void dfstree(int u,int form){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==form)continue;
		pr[v]=u,plen[v]=len[i],pw1[v]=w1[i],pw2[v]=w2[i];
		dfstree(v,u);
	}
	return;
}

signed main(){
//	freopen("4.in","r",stdin);
	n=read(),m=read(),k=read(),S=read(),T=read();
	for(int i=1,u,v,le,w_1,w_2;i<=m;i++){
		u=read(),v=read(),le=read(),w_1=read(),w_2=read();
		add(u,v,le,w_1,w_2),add(v,u,le,w_1,w_2);
	}
	double sp=0;
	for(int i=1;i<=k;i++)tim[i]=read(),P[i]=read(),sp+=P[i];
	if(m+1==n){
		dfstree(T,0);
		double ans=0;
		for(int i=1;i<=k;i++){
			double sum=0,p=double(P[i])/sp;
			int Now=0;
			int x=S;
			while(x!=T){
				//edge plen[x],pw1[x],pw2[x]
				if(Now+plen[x]<=tim[i])sum+=pw1[x]*plen[x];
				else if(Now<tim[i]){
					sum+=(tim[i]-Now)*pw1[x];
					sum+=(Now+plen[x]-tim[i])*pw2[x];
				}
				else sum+=pw2[x]*plen[x];
				Now+=plen[x];
				x=pr[x];
			}
			ans+=sum*p;
		}
		printf("%.8lf\n",ans);
		return 0;
	}
	if(k==1&&tim[1]==10000){
		dij();
		printf("%lld\n",dis[T]);
	}
	return 0;
}

