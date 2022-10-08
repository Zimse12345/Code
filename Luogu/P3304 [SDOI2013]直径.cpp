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

const int N=4e5+7,Mod=998244353;
int n,hd[N],nxt[N],to[N],ct,ans;
ll len[N],f[N],g[N],k[N],q[N],D;

void add(int u,int v,int w){
	to[++ct]=v,len[ct]=w,nxt[ct]=hd[u],hd[u]=ct;
	return;
}

void dfs(int u,int from){
	ll m1=0,m2=0,w;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i],w=len[i];
		if(v==from)continue;
		dfs(v,u);
		if(f[v]+w>f[u])f[u]=f[v]+w;
		if(f[v]+w>m1)m2=m1,m1=f[v]+w;
		else if(f[v]+w>m2)m2=f[v]+w;
		if(k[v]>k[u])k[u]=k[v];
	}
	g[u]=m1+m2,D=max(D,g[u]),q[u]=m2;
	if(g[u]>k[u])k[u]=g[u];
	return;
}

void dfs2(int u,int from,int tag,int tag2){
	int o=0,oo=0;ll x=f[u],w;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i],w=len[i];
		if(v==from)continue;
		if(f[v]+w==x)++o;
		if(f[v]+w==q[u])++oo;
	}
	if(tag==0&&g[u]<D){
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(v==from)continue;
			if(k[v]>=D){dfs2(v,u,0,tag2);break;}
		}
	}
	if(tag==0&&o<=2&&g[u]==D){
		int tag=0;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(v==from)continue;
			if(k[v]==D){tag=1;break;}
		}
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i],w=len[i]+f[v];
			if(v==from)continue;
			if(w==x||(w==q[u]&&oo==1)){
				if(tag==0&&(!(w==q[u]&&oo==1&&tag2==1)))++ans,dfs2(v,u,1,tag2);
				else if(k[v]==D)dfs2(v,u,0,tag2|(g[u]==D?1:0));
			}
		}
	}
	if(tag==1&&o<=1){
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i],w=len[i]+f[v];
			if(v==from)continue;
			if(w==x){
				++ans,dfs2(v,u,1,tag2);
				break;
			}
		}
	}
	return;
}

int main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)if(g[i]==D){
		dfs2(1,0,0,0);
		break;
	}
	printf("%lld\n%d\n",D,ans);
	return 0;
}
