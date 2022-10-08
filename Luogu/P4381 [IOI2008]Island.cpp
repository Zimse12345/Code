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
int n,hd[N],to[N*2],nxt[N*2],c[N*2],ct,rev[N*2];
int vis[N],st[N],top,ring[N];
int h,nx[N],pr[N],x[N],t;
ll st2[N],len[N],y[N],f[N][2],L[N],R[N],g[N],ans;

inline void add(int u,int v,int w){
	to[++ct]=v,c[ct]=w,nxt[ct]=hd[u],hd[u]=ct;
	return;
}

void dfs(int u,int from){
	vis[u]=1,st[++top]=u,st2[top]=c[from];
	for(int i=hd[u],v;i;i=nxt[i]){
		if(rev[i]==from)continue;
		v=to[i];
		if(vis[v]&&!ring[v]){
			int p=v;
			while(st[top]!=v){
				nx[p]=st[top],pr[st[top]]=p;
				p=st[top],ring[p]=1,len[p]=st2[top],--top;
			}
			ring[v]=1,--top,h=v,nx[p]=v,pr[v]=p,len[v]=c[i];
		}
		else if(!vis[v])dfs(v,i);
	}
	if(st[top]==u)--top;
	return;
}

void dp(int u,int from){
	ll m1=0,m2=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];ll w=c[i];
		if(v==from||ring[v])continue;
		dp(v,u),f[u][0]=max(f[u][0],f[v][0]+w),f[u][1]=max(f[u][1],f[v][1]);
		if(f[v][0]+w>m1)m2=m1,m1=f[v][0]+w;
		else if(f[v][0]+w>m2)m2=f[v][0]+w;
	}
	f[u][1]=max(f[u][1],m1+m2);
	return;
}

signed main(){
	n=read();
	for(int i=1,v,w;i<=n;i++){
		v=read(),w=read(),add(i,v,w),add(v,i,w);
		rev[ct]=ct-1,rev[ct-1]=ct;
	}
	for(int i=1,p;i<=n;i++)if(!vis[i]){
		h=t=top=0,dfs(i,0);ll res=0;
		if(h==0)h=i,pr[i]=nx[i]=i;p=h;
		do{x[++t]=p,y[t]=len[p],p=nx[p];}while(p!=h);
		for(int j=1;j<=t;j++)dp(x[j],0),res=max(res,f[x[j]][1]);
		for(ll j=2,s=f[x[1]][0]+y[1];j<=t;j++)res=max(res,s+f[x[j]][0]),s=max(s+y[j],f[x[j]][0]+y[j]);
		for(ll j=1,s=f[x[1]][0],dis=0;j<=t;j++)L[j]=s,dis+=y[j],s=max(s,dis+f[x[j+1]][0]);
		for(ll j=t,s=f[x[t]][0],dis=0;j>=1;j--)dis+=y[j],s=max(s,dis+f[x[j]][0]),R[j]=s;
		for(int j=2;j<=t;j++)res=max(res,L[j-1]+R[j]);
		ans+=res;
	}
	printf("%lld\n",ans);
	return 0;
}
