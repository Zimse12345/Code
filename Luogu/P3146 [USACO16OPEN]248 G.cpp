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
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=250,Mod=998244353,INF=1e12+7;
int n,a[N],f[N][N],vis[N][N],ans;

int dp(int l,int r){
	if(vis[l][r]++)return f[l][r];
	if(l==r)f[l][r]=a[l];
	else{
		for(int i=l;i<r;i++){
			int L=dp(l,i),R=dp(i+1,r);
			if(L==R)f[l][r]=max(f[l][r],L+1);
		}
	}
	return f[l][r];
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int l=1;l<=n;l++)for(int r=l;r<=n;r++)ans=max(ans,dp(l,r));
	printf("%lld\n",ans);
	return 0;
}
