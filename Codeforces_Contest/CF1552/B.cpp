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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N][5];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=0;i<5;i++)a[1][i]=read();
		int t=1,tag=1;
		for(int i=2;i<=n;i++){
			int p=0;
			for(int j=0;j<5;j++){
				a[i][j]=read();
				if(a[i][j]<a[t][j])++p;
			}
			if(p>=3)t=i;
		}
		for(int i=1;i<=n;i++)if(i!=t){
			int p=0;
			for(int j=0;j<5;j++){
				if(a[t][j]<a[i][j])++p;
			}
			if(p<3){tag=0;break;}
		}
		if(tag)printf("%d\n",t);
		else printf("-1\n");
	}
	return 0;
}

