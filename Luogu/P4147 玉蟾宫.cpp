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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int n,m,a[N][N],ans,f[N],L[N],R[N];

void sol(){
	for(int i=1;i<=m;i++)f[i]=0,L[i]=1,R[i]=m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==0)f[j]=0;
			else ++f[j];
		}
		for(int j=1,s=0;j<=m;j++){
			L[j]=max(L[j],s+1);
			if(f[j]==0)s=j,L[j]=1;
		}
		for(int j=m,s=m+1;j>=1;j--){
			R[j]=min(R[j],s-1);
			if(f[j]==0)s=j,R[j]=m;
		}
		for(int j=1;j<=m;j++)ans=max(ans,f[j]*(R[j]-L[j]+1));
	}
	return;
}

signed main(){
	n=read(),m=read();
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			if(c=='F')a[i][j]=1;
		}
	}
	sol();
	printf("%d\n",3*ans);
	return 0;
}
