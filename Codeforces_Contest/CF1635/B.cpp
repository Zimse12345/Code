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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],b[N],c[N];

signed main(){
	T=read();
	while(T--){
        n=read(),m=0,b[n+1]=b[n+2]=0,a[0]=a[n+1]=INF;
        for(int i=1;i<=n;i++)a[i]=read(),c[i]=0;
        for(int i=1;i<=n;i++)b[i]=(a[i]>a[i-1]&&a[i]>a[i+1])?1:0;
        for(int i=1;i<=n;i++)if(b[i])c[i+b[i+2]]=1,++m,b[i+2]=0;
        printf("\n%d\n",m);
        for(int i=1;i<=n;i++)printf("%d ",c[i]?max(a[i-1],a[i+1]):a[i]);
	}
	return 0;
}
