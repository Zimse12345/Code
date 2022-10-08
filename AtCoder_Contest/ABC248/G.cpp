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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],hd[N],nxt[N*2],to[N*2],ec,tag[N];
int f[N],cnt[N],ans,rt,g[N],Ans;
vector<int> val[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return qp(x,Mod-2);}

void dfs1(int u,int from){
	f[u]=0,cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||!tag[v])continue;
		dfs1(v,u);
		cnt[u]+=cnt[v],f[u]+=f[v]+cnt[v];
	}
	f[u]%=Mod;
	return;
}

void dfs2(int u,int from){
	if(from!=0)f[u]=(f[from]-cnt[u]*2+cnt[rt])%Mod;
	ans=(ans+f[u])%Mod;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||!tag[v])continue;
		dfs2(v,u);
	}
	tag[u]=0;
}

const int M=100000;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),val[a[i]].push_back(i);
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	for(int i=M;i>=1;i--){
		for(int j=i;j<=M;j+=i){
			for(unsigned k=0;k<val[j].size();k++)tag[val[j][k]]=1;
		}
		for(int j=i;j<=M;j+=i){
			for(unsigned k=0;k<val[j].size();k++){
				rt=val[j][k],ans=0;
				dfs1(rt,0);
				f[rt]+=cnt[rt]-1;
				dfs2(rt,0);
				g[i]=(g[i]+ans)%Mod;
			}
		}
		g[i]=(g[i]*inv(2))%Mod;
		for(int j=i*2;j<=M;j+=i)g[i]=(g[i]-g[j])%Mod;
		Ans=(Ans+i*g[i])%Mod;
	}
	Ans=(Ans+Mod)%Mod;
	printf("%lld\n",Ans);
	return 0;
}

