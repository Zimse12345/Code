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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e3+7,Mod=998244353,INF=1e9+7;
int n,m,f[N][2],now;

signed main(){
	n=read(),m=read();
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		now^=1,f[0][now]=0;
		for(int j=1;j<=n;j++)f[j][now]=f[j-1][now^1];
		for(int j=1;j<=n;j++){
			int c=(j-(i-1)/m);
			if(c<0)c=0;
			f[j][now]=(f[j][now]+f[j][now^1]*c)%Mod;
		}
	}
	for(int i=1;i<=n;i++)printf("%lld\n",f[i][now]);
	return 0;
}
