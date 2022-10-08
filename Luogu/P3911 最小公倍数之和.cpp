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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,c[N],prime[N],tot,pr[N],mu[N],f[N],ans;

signed main(){
    mu[1]=f[1]=1;
    for(int i=2;i<N;i++){
        if(!pr[i])prime[++tot]=i,pr[i]=i,mu[i]=-1,f[i]=1-i;
        for(int j=1;j<=tot&&prime[j]*i<N;j++){
            pr[prime[j]*i]=prime[j],mu[prime[j]*i]=-mu[i],f[prime[j]*i]=(1-prime[j])*f[i];
            if(pr[i]==prime[j]){mu[prime[j]*i]=0,f[prime[j]*i]=f[i];break;}
        }
    }
	n=read();
    while(n--)++c[read()];
    for(int i=1,g;i<N;i++){
        g=0;
        for(int j=1;i*j<N;j++)g+=j*c[i*j];
        g=g*g;
        ans+=i*g*f[i];
    }
    printf("%lld\n",ans);
	return 0;
}
