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

const int N=3e4+7,Mod=998244353,INF=10000000;
int n,t,v[N],c[N],f[N],g[N],ans=INF;

signed main(){
	n=read(),t=read();
	int mx=0,T=0;
	for(int i=1;i<=n;i++)v[i]=read(),mx=max(mx,v[i]);
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<N;i++)f[i]=g[i]=INF;
	T=mx+t;
	for(int i=1;i<=n;i++){
		for(int j=v[i];j<=T;j++)g[j]=min(g[j],g[j-v[i]]+1);
	}
	
	for(int i=1,m,V;i<=n;i++){
		m=c[i];
		for(int j=1;j<=m;j*=2){
			V=j*v[i],m-=j;
			for(int k=T;k>=V;k--)f[k]=min(f[k],f[k-V]+j);
		}
		V=m*v[i];
		for(int k=T;k>=V;k--)f[k]=min(f[k],f[k-V]+m);
	}
	
	for(int i=t;i<T;i++)ans=min(ans,f[i]+g[i-t]);
	if(ans>=INF-1000)ans=-1;
	printf("%d\n",ans);
	return 0;
}
