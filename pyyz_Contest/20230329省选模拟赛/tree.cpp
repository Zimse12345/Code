#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>

#define int long long

using namespace std;

inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}

const int N=1000007;

int n,fa[N],hd[N],nxt[N*2],to[N*2],ec;
int sz[N],f[N],g[N],v[N],mn=1e18,Sum[N],a[N],tot;

inline void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

void dfs(int u){
	sz[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		dfs(v);
		sz[u]+=sz[v];
		f[u]+=f[v]+sz[v];
	}
	return;
}

void dfs2(int u){
	int sumf=g[u]+n-sz[u];
	for(int i=hd[u];i;i=nxt[i])sumf+=f[to[i]]+sz[to[i]];
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		g[v]=sumf-f[v]-sz[v];
		dfs2(v);
	}
	Sum[u]=n+sumf;
	mn=min(mn,Sum[u]);
	return;
}

signed main(){
	n=read();
	for(int i=2;i<=n;i++)fa[i]=read(),add(fa[i],i);
	dfs(1);
	dfs2(1);
	for(int u=1;u<=n;u++)if(Sum[u]==mn){
		int sum=Sum[u];
		v[0]=1;
		for(int i=hd[u];i;i=nxt[i])a[++tot]=sz[to[i]];
		if(n-sz[u])a[++tot]=n-sz[u];
		sort(a+1,a+tot+1);
		for(int l=1,r=0,sum=0;l<=tot;l=r+1){
			r=l;
			while(r<tot&&a[r+1]==a[r])++r;
			int len=r-l+1;
			for(int p=1;p<=len;p*=2){
				sum=min(n/2,sum+a[l]*p);
				len-=p;
				for(int j=sum;j>=a[l]*p;j--)v[j]|=v[j-a[l]*p];
				if(v[n/2]||v[(n-1)/2])break;
			}
			if(len){
				sum=min(n/2,sum+a[l]*len);
				for(int j=sum;j>=a[l]*len;j--)v[j]|=v[j-a[l]*len];
			}
			if(v[n/2]||v[(n-1)/2])break;
		}
		for(int i=n/2;i>=0;i--)if(v[i]){
			sum+=i*(n-1-i);
			break;
		}
		printf("%lld\n",sum);
		break;
	}
	return 0;
}
