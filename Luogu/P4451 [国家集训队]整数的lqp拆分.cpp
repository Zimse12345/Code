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

const int N=1e2+7,Mod=1e9+7,INF=1e9+7;
inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=(qrx*10+qrc-48)%(Mod-1),qrc=getchar();return qrx*qry;}

int n,sq2=59713600;
inline int qp(int x,int k=Mod-2){
    int res=1;
    while(k){
        if(k&1ll)res=(res*x)%Mod;
        x=(x*x)%Mod,k/=2;
    }
    return res;
}

signed main(){
    n=read();
    int ans=qp(2*sq2);
    ans*=(qp(qp(1+sq2,n))-qp(qp(1-sq2,n)));
    if(n%2==0)ans=-ans;
    ans=(ans%Mod+Mod)%Mod;
    printf("%lld\n",ans);
    return 0;
}
