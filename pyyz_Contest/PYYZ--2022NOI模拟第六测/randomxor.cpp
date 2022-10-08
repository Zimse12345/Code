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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,L,a[N],b[N],f[N],g[N],sum[N],tag[N],ans;

signed main(){
	n=read(),m=read(),L=read();
	for(int i=0;i<n;i++)a[i]=read();
	for(int i=0;i<m;i++)b[i]=read();
	f[0]=1;
	int z=(1<<n);
	for(int i=0;i<z;i++){
		for(int j=0;j<n;j++)if(i&(1<<j))sum[i]^=a[j];
		for(int j=0;j<m;j++)if(sum[i]==b[j])tag[i]=1;
	}
	for(int T=1;T<=L;T++){
		for(int i=0;i<z;i++)g[i]=f[i],f[i]=0;
		for(int i=0;i<z;i++)if(!tag[i]){
			for(int j=0;j<n;j++){
				f[i]+=g[i^(1<<j)];
				if(f[i]>=Mod)f[i]-=Mod;
			}
		}
	}
	for(int i=0;i<z;i++){
		ans+=f[i];
		if(ans>=Mod)ans-=Mod;
	}
	printf("%d\n",ans);
	return 0;
}

