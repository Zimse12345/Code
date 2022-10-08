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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=1e9+7,INF=1e9+7;
int n,k,nxt[N],pre[N],vis[N][N],f[N][N],tot[N],g[N],ans;

int dp(int l,int r){
	if(vis[l][r]++)return f[l][r];
	if(r-l<1)return 0;
	for(int i=l;i<=r;i++)if(nxt[i]>r||pre[i]<l)return 0;
	f[l][r]=g[tot[r]-tot[l-1]];
	for(int mid=l+1;mid<r;mid++)(f[l][r]-=dp(l,mid)*g[tot[r]-tot[mid]])%=Mod;
	return f[l][r];
}

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n*2;i++)tot[i]=1,nxt[i]=-INF,pre[i]=INF;
	g[0]=1;
	for(int i=1;i<=n;i++)g[i*2]=g[i*2-2]*(i*2-1)%Mod;
	for(int i=1,l,r;i<=k;i++){
		l=read(),r=read(),tot[l]=tot[r]=0;
		if(r<l)swap(l,r);
		nxt[l]=r,pre[r]=l;
	}
	for(int i=1;i<=n*2;i++)tot[i]+=tot[i-1];
	for(int i=1;i<=n*2;i++){
		for(int j=i+1;j<=n*2;j++){
			(ans+=dp(i,j)*g[tot[n*2]-tot[j]+tot[i-1]])%=Mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

