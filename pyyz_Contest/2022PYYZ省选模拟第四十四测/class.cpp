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

const int N=5001,Mod=1e9+7,INF=1e9+7;
int n,m,hd[N],nxt[N*2],to[N*2],len[N*2],ec;
int fa[N],cnt[N],ans,C[N][N],F[N][N],H[N*2];
inline int ldl(int x,int k=Mod-2){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;return;}

void dfs(int u,int from,int fw){
	fa[u]=from,cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,len[i]),cnt[u]+=cnt[v];
	}
	if(from){
		for(int s=0;s<=2*m;s++)ans=(ans+F[cnt[u]][s]*F[n-cnt[u]][2*m-s]%Mod*H[s]%Mod*fw)%Mod;
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	C[0][0]=1;
	for(int i=1;i<N;i++){
		C[i][0]=1;
		for(int j=1;j<N;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
	for(int i=0;i<N;i++){
		F[i][0]=1;
		for(int j=1;j<N;j++)F[i][j]=(F[i][j-1]*i)%Mod;
	}
	for(int a=0;a<N;a++)for(int b=0;b<N;b++)H[a+b]=(H[a+b]+C[m][a]*C[m][b]%Mod*(min(a,m-b)+min(b,m-a)))%Mod;
	dfs(1,0,0);
	printf("%lld\n",ans%Mod);
	return 0;
}

