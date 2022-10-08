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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int n,f[N],g[N],P,sum,h;

signed main(){
	n=read(),P=read();
	
	g[1]=1,g[2]=-1;
	for(int i=1;i<=n;i++){
		h=(h+g[i]),f[i]=(sum+h)%P,sum=(sum+f[i])%P;
		for(int j=2;j*i<=n;j++){
			g[i*j]=(g[i*j]+f[i])%P;
			if(i*j+j<=n)g[i*j+j]=(g[i*j+j]-f[i])%P;
		}
	}
	f[n]=(f[n]+P)%P;

	printf("%lld\n",f[n]);
	return 0;
}