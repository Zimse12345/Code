/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
*Description:
************************/

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
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define pb push_back
#define ll long long
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=10114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int T,n,m,cnt1,cnt2,hd[N],nxt[N],to[N],ec,tag[N],a[N];
int dfn[N],low[N],tot,ring[N],dis[N],vis[N],ddis[N],mx[N];
int t1[N],t2[N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& _)const{return y>_.y;}
};

void dij(){
	priority_queue<node> q;
	for(int i=1;i<=n;i++)dis[i]=INF*3,vis[i]=0;
	dis[1]=0,q.push(node(1,0));
	while(!q.empty()){
		int u=q.top().x;
		q.pop();
		if(vis[u]++)continue;
		if(u!=1&&tag[u]==0)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.push(node(v,dis[v]));
			}
		}
	}
	return;
}

void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

//void dfs(int u,int from){
//	int son=0;
//	dfn[u]=low[u]=++tot;
//	for(int i=hd[u],v;i;i=nxt[i]){
//		v=to[i];
//		if(v==from||tag[v]==0)continue;
//		++son;
//		ring[v]=1;
//		if(dfn[v])_min(low[u],dfn[v]),ring[u]=1;
//		else{
//			dfs(v,u);
//			_min(low[u],low[v]);
//			if(low[v]<=dfn[u])ring[u]=1;
//		}
//	}
//	if(son)ring[u]=1;
//	return;
//}
//
//void dfs2(int u){
//	for(int i=hd[u],v;i;i=nxt[i]){
//		v=to[i];
//		if(tag[v]==0||ring[v])continue;
//		ring[v]=1,dfs2(v);
//	}
//	return;
//}
//
//void dfs3(int u,int from){
//	ring[u]=-1;
//	for(int i=hd[u],v;i;i=nxt[i]){
//		v=to[i];
//		if(v==from||ring[v]>0||tag[v]==0)continue;
//		dfs3(v,u);
//		_max(mx[u],mx[v]+1);
//	}
////	printf("(%d %d)\n",u,mx[u]);
//	return;
//}
//
//void dfs4(int u,int from,int fd){
//	ddis[u]=max(fd,mx[u]);
//	int mxs=-1,mxp=0,ses=-1;
//	for(int i=hd[u],v;i;i=nxt[i]){
//		v=to[i];
//		if(v==from||ring[v]>0||tag[v]==0)continue;
//		if(mx[v]>mxs)ses=mxs,mxs=mx[v],mxp=v;
//		else if(mx[v]>ses)ses=mx[v];
//	}
//	for(int i=hd[u],v;i;i=nxt[i]){
//		v=to[i];
//		if(v==from||ring[v]>0||tag[v]==0)continue;
//		if(v==mxp)dfs4(v,u,max(fd,ses+1));
//		else dfs4(v,u,max(fd,mxs+1));
//	}
//	return;
//}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		cnt1=read(),cnt2=read();
		for(int i=1;i<=cnt1;i++)a[i]=read();
		for(int i=1;i<=cnt2;i++)tag[read()]=1;
		for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
//		for(int i=1;i<=n;i++)if(tag[i])dfs(i,0);
//		for(int i=1;i<=n;i++)if(ring[i])dfs2(i);
		for(int i=1;i<=n;i++){
			for(int j=hd[i];j;j=nxt[j])if(tag[to[j]])t1[i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=hd[i];j;j=nxt[j])if(t1[to[j]]&&tag[to[j]])t2[i]=1;
		}
//		for(int i=1;i<=n;i++){
////			printf("[%d %d %d]\n",i,tag[i],ring[i]);
//			if(ring[i]==0&&tag[i]){
//				dfs3(i,0);
//				dfs4(i,0,0);
//			}
//			if(ring[i]>0)ddis[i]=INF;
//		}
//		for(int i=1;i<=n;i++){
//			if(!tag[i]){
//				for(int j=hd[i];j;j=nxt[j])if(tag[to[j]])_max(ddis[i],ddis[to[j]]+1);
//			}
//		}
		dij();
//		for(int i=1;i<=n;i++)printf("ddis[%d]=%d %d\n",i,dis[i],mx[i]);
		for(int i=1;i<=n;i++){
			if(t2[i])ddis[i]=INF;
			else if(t1[i])ddis[i]=1;
		}
		int sum=0,ans=0;
		for(int i=1;i<=cnt1;i++)sum=min(INF*2,sum+ddis[a[i]]);
		for(int i=1;i<=cnt1;i++){
			if(dis[a[i]]<=sum-ddis[a[i]]+1)ans=1;
		}
		_ck(ans);
		for(int i=1;i<=n;i++)ring[i]=dfn[i]=hd[i]=mx[i]=ddis[i]=tag[i]=t1[i]=t2[i]=0;
		tot=ec=0;
	}
    return 0;
}


