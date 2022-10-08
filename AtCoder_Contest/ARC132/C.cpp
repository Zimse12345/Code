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

const int N=4e3+7,Mod=998244353,INF=1e9+7;
int n,d,a[N],f[N][N];

signed main(){
	n=read(),d=read();
	int D=(1<<(d*2+1))-1;
	for(int i=1;i<=n;i++)a[i]=read();
	f[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=D;j++)if(f[i][j]){
			for(int k=0;k<=d*2;k++){
				int c=i+1+k-d;
				if(c<1||c>n||(a[i+1]!=-1&&c!=a[i+1])||((1<<k)&(j>>1)))continue;
				int _i=i+1,_j=((j>>1)|(1<<k));
				f[_i][_j]=(f[_i][_j]+f[i][j])%Mod;
			}
		}
	}
	int ans=f[n][(1<<(d+1))-1];
	printf("%lld\n",ans);
	return 0;
}

