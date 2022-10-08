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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,a[N],b[N],Rt[N],ch[N*64][2],nc,sum[N*64];
int hd[N],to[N],nxt[N],ec;
int fa[N],cnt[N],dep[N],son[N],dfn[N],top[N],tot;

inline void add(int u,int v){
	to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;
	return;
}

void dfs1(int u,int from,int dp){
	fa[u]=from,cnt[u]=1,dep[u]=dp;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u,dp+1),cnt[u]+=cnt[v];
		if(cnt[v]>cnt[son[u]])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int tp){
	dfn[u]=++tot,top[u]=tp;
	if(son[u])dfs2(son[u],u,tp);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int query(int l,int r,int x){
	int p1=Rt[l-1],p2=Rt[r],res=0;
	for(int i=30;i>=0;i--){
		int pr=(x&(1<<i))?0:1;
		if(sum[ch[p2][pr]]-sum[ch[p1][pr]]>0)res+=(1<<i),p1=ch[p1][pr],p2=ch[p2][pr];
		else p1=ch[p1][pr^1],p2=ch[p2][pr^1];
	}
	return res;
}

signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0,0),dfs2(1,0,1);
	for(int i=1;i<=n;i++)b[dfn[i]]=a[i];
	for(int i=1,p,f;i<=n;i++){
		Rt[i]=p=++nc,f=Rt[i-1];
		for(int j=30;j>=0;j--){
			ch[p][0]=ch[f][0],ch[p][1]=ch[f][1];
			if(b[i]&(1<<j))ch[p][1]=++nc,sum[nc]=sum[ch[f][1]]+1,f=ch[f][1];
			else ch[p][0]=++nc,sum[nc]=sum[ch[f][0]]+1,f=ch[f][0];
			p=nc;
		}
	}
	
	for(int i=1,op,x,y,z,ans;i<=q;i++){
		op=read(),x=read(),ans=0;
		if(op==2)y=read();
		z=read();
		if(op==1)ans=query(dfn[x],dfn[x]+cnt[x]-1,z);
		else{
			while(top[x]!=top[y]){
				if(dfn[top[x]]<dfn[top[y]])swap(x,y);
				ans=max(ans,query(dfn[top[x]],dfn[x],z)),x=fa[top[x]];
			}
			if(dep[x]>dep[y])swap(x,y);
			ans=max(ans,query(dfn[x],dfn[y],z));
		}
		printf("%d\n",ans);
	}
	return 0;
}
