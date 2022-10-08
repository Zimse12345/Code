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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m,k,v[N][N],f[107][35][35][35],ans,fac[N],cc[N][N]; 

int qp(int x,int K){
	int res=1;
	while(K){
		if(K&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,K/=2;
	}
	return res;
}

int inv(int x){
	return qp(x,Mod-2);
}

int C(int x,int y){
	return fac[x]*inv(fac[y])%Mod*inv(fac[x-y])%Mod;
}

signed main(){
	n=read(),m=read(),k=read();
	fac[0]=1;
	for(int i=1;i<=30;i++)fac[i]=(fac[i-1]*i)%Mod;
	for(int i=0;i<=m;i++){
		v[i][0]=1,v[i][1]=read();
		for(int j=2;j<=30;j++)v[i][j]=(v[i][j-1]*v[i][1])%Mod;
	}
	for(int i=0;i<=30;i++){
		for(int j=0;j<=i;j++){
			cc[i][j]=C(i,j);
		}
	}
	
	f[0][0][0][0]=1;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=min(k,i);j++){
			for(int d=0;d<=n;d++){
				for(int t=0;t<=31;t++){
					for(int c=0;d+c<=n;c++){
						int T=t+c,nT=T/2,nJ=j+(T&1);
						f[i+1][nJ][d+c][nT]=(f[i+1][nJ][d+c][nT]+f[i][j][d][t]*v[i][c]%Mod*cc[n-d][c]%Mod)%Mod;
					}
				}
			}
		}
	}
	for(int i=0;i<=k;i++){
		for(int j=0;j<=31;j++){
			int t=i;
			for(int p=0;p<=5;p++)if(j&(1<<p))++t;
			if(t<=k)ans=(ans+f[m+1][i][n][j])%Mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

