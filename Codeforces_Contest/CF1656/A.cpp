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
inline void cf(int x){if(x)printf("YES\n");else printf("NO");}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int mx=-INF,mi=INF,pos1=0,pos2=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			if(a[i]>mx)mx=a[i],pos1=i;
			if(a[i]<mi)mi=a[i],pos2=i;
		}
		printf("%d %d\n",pos2,pos1);
	}
	return 0;
}

