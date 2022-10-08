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
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int p=0,tag=1;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]>a[p])p=i;
		}
		for(int i=p-1;i>=1;i--)if(a[i]>a[i+1])tag=0;
		for(int i=p+1;i<=n;i++)if(a[i]>a[i-1])tag=0;
		if(tag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

