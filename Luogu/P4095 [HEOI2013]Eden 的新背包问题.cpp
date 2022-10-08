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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,q,a[N],b[N],c[N],f[N][N],g[N][N];

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),c[i]=read();
	for(int i=1,p,v,m,P,V;i<=n;i++){
		for(int k=0;k<N;k++)f[i][k]=f[i-1][k];
		p=a[i],v=b[i],m=c[i];
		for(int j=1;j<=m;j*=2){
			m-=j,P=j*p,V=j*v;
			for(int k=N-1;k>=P;k--)f[i][k]=max(f[i][k],f[i][k-P]+V);
		}
		P=m*p,V=m*v;
		for(int k=N-1;k>=P;k--)f[i][k]=max(f[i][k],f[i][k-P]+V);
		for(int k=1;k<N;k++)f[i][k]=max(f[i][k],f[i][k-1]);
	}
	for(int i=n,p,v,m,P,V;i>=1;i--){
		for(int k=0;k<N;k++)g[i][k]=g[i+1][k];
		p=a[i],v=b[i],m=c[i];
		for(int j=1;j<=m;j*=2){
			m-=j,P=j*p,V=j*v;
			for(int k=N-1;k>=P;k--)g[i][k]=max(g[i][k],g[i][k-P]+V);
		}
		P=m*p,V=m*v;
		for(int k=N-1;k>=P;k--)g[i][k]=max(g[i][k],g[i][k-P]+V);
		for(int k=1;k<N;k++)g[i][k]=max(g[i][k],g[i][k-1]);
	}
	q=read();
	for(int i=1,d,e,ans;i<=q;i++){
		d=read()+1,e=read(),ans=0;
		for(int j=0;j<=e;j++)ans=max(ans,f[d-1][j]+g[d+1][e-j]);
		printf("%d\n",ans);
	}
	return 0;
}
