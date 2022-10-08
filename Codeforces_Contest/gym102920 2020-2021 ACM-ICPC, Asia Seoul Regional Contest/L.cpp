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
int n,a[N],ans;

void sol(int L,int R,int l,int r){
    if(R<L)return;
    if(l==r){
        for(int i=L;i<=R;i++)ans=max(ans,(a[i]+a[l])*(i-l));
        return;
    }
    int M=(L+R)>>1,v=0,pos=0;
    for(int i=l;i<=r;i++){
        int _v=(a[M]+a[i])*(M-i);
        if(v<_v)v=_v,pos=i;
    }
    ans=max(ans,(a[M]+a[pos])*(M-pos));
    sol(M+1,R,pos,r);
    v=0,pos=0;
    for(int i=r;i>=l;i--){
        int _v=(a[M]+a[i])*(M-i);
        if(v<_v)v=_v,pos=i;
    }
    sol(L,M-1,l,pos);
    return;
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sol(1,n,1,n);
    printf("%lld\n",ans);
    return 0;
}
