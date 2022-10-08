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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N],t[N]; 

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)t[i]=s[i];
		sort(t+1,t+n+1);
		int c=0;
		for(int i=1;i<=n;i++)if(s[i]!=t[i])++c;
		printf("%d\n",c);
	}
	return 0;
}

