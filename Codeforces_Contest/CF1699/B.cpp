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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,m;

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int I=1;I<=n/2;I++){
			for(int i=1;i<=m/2;i++){
				if(i&1)printf("%d %d ",1^(I&1),0^(I&1));
				else printf("%d %d ",0^(I&1),1^(I&1));
			}
			printf("\n");
			for(int i=1;i<=m/2;i++){
				if(i&1)printf("%d %d ",0^(I&1),1^(I&1));
				else printf("%d %d ",1^(I&1),0^(I&1));
			}
			printf("\n");
		}
	}
	return 0;
}

