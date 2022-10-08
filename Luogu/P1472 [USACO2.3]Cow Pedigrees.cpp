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

const int N=1e3+7,Mod=9901,INF=1e9+7;
int n,k,f[N][N],g[N];

signed main(){
	n=read(),k=read();
	f[1][1]=1,g[1]=1;
	for(int i=2;i<=k;i++){
		for(int j=2;j<n;j+=2){
			for(int x=1;x<=j;x+=2){
				f[i][j+1]=(f[i][j+1]+f[i-1][x]*(g[j-x]-f[i-1][j-x])%Mod)%Mod;
				f[i][j+1]=(f[i][j+1]+f[i-1][x]*(g[j-x]-f[i-1][j-x])%Mod)%Mod;
				f[i][j+1]=(f[i][j+1]+f[i-1][x]*f[i-1][j-x])%Mod;
			}
		}
		for(int j=2;j<n;j+=2)g[j+1]=(g[j+1]+f[i][j+1])%Mod;
	}
	printf("%lld\n",(f[k][n]+Mod)%Mod);
	return 0;
}
