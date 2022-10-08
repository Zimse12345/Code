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

const int N=1e2+7,Mod=1e9+7,INF=1e9+7;
int k,f[N];

signed main(){
	k=read();
	f[1]=1;
	for(int i=2;i<=k;i++){
		for(int a=3;a<=6;a++)for(int b=3;b<=6;b++){
			f[i]=(f[i]+f[i-1]*f[i-1])%Mod;
		}
	}
	printf("%lld\n",(f[k]*6)%Mod);
	return 0;
}

