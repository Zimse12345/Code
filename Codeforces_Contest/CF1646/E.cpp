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

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],s,vis[N],ans=1,t[N*24];

signed main(){
	n=read(),m=read();
    for(int i=2;i<=n;i++)if(!vis[i]){
        int x=i,y=0;
        while(x<=n)vis[x]=1,++y,x*=i;
        ++a[y],s=max(s,y);
    }
    for(int i=1,sum=0;i<=s;i++){
        for(int j=1;j<=m;j++){
            if(!t[j*i])t[j*i]=1,++sum;
        }
        ans+=sum*a[i];
    }
    printf("%lld\n",ans);
	return 0;
}
