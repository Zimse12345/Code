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
int T,n,a[N],s[2][N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)s[0][i]=s[1][i]=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			int t=i&1;
			s[t][a[i]]=max(s[t][a[i]],s[t^1][a[i]]+1);
//			++s[t][a[i]];
//			++s[t][a[i]];
//			if(a[i-1]==a[i])s[t][a[i]]=max(s[t][a[i]],s[t^1][a[i]]+1);
		}
		for(int i=1;i<=n;i++)printf("%d ",max(s[0][i],s[1][i]));
		printf("\n");
	}
	return 0;
}

