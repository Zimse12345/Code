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
int T,n,m;
char a[N],b[N];

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		scanf("%s %s",a+1,b+1);
		int tag=1;
		for(int i=2;i<=m;i++)if(b[i]!=a[n-m+i])tag=0;
		int h=0;
		for(int i=1;i<=n-m+1;i++)if(a[i]==b[1])h=1;
		if(!h)tag=0;
		if(tag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

