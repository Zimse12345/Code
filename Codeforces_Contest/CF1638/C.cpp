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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],b[N],t;

signed main(){
	T=read();
	while(T--){
		n=read(),t=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			int mx=a[i];
			while(t&&a[i]<b[t])mx=max(mx,b[t]),--t;
			b[++t]=mx;
		}
		printf("%d\n",t);
		for(int i=1;i<=n;i++)b[i]=0;
	}
	return 0;
}

