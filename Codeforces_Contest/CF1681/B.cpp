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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],b[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int m=read();
		for(int i=1;i<=m;i++)b[i]=read();
		int pos=1;
		for(int i=m;i>=1;i--){
			if(pos+b[i]<=n)pos+=b[i];
			else pos=pos-n+b[i];
		}
		printf("%d\n",a[pos]);
	}
	return 0;
}

