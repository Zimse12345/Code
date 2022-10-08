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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=1e9+7,INF=1e9+7;
int n,a[N],ans,fac[N],vis[N],tr[N];

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}

inline int fpow(int x,int k){
    int res=1;
    while(k){
        if(k&1ll)res=(res*x)%Mod;
        x=(x*x)%Mod,k/=2;
    }
    return res;
}

inline int inv(int x){
    return fpow(x,Mod-2);
}

inline int calc(int x){
    return fac[x]*x%Mod*(x-1)%Mod*inv(4)%Mod;
}

inline int qsum(int l,int r){
    return ((l+r)*(r-l+1)/2)%Mod;
}

signed main(){
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=(fac[i-1]*i)%Mod;
    n=read();
    for(int  i=1;i<=n;i++)a[i]=read();
    ans=calc(n);
    int s=0,ss=0;
    for(int i=1;i<=n;i++){
        int tot=n-i+1;
        int mn=(a[i]-sum(a[i])+1);
        int cnt=(tot-mn+1)*fac[n-i]%Mod;
        ans=(ans-cnt*s)%Mod;
        ans=(ans-(tot-mn+1)*calc(n-i))%Mod;
        ans=(ans-cnt*ss)%Mod;
        ans=(ans-qsum(mn-1,tot-1)*fac[n-i])%Mod;
        ss-=sum(n)-sum(a[i]);
        s+=sum(n)-sum(a[i]),add(a[i],1);
        ss+=(a[i]-sum(a[i]));
        s%=Mod,ss%=Mod;
        if(vis[a[i]]++)break;
    }
    ans=(ans%Mod+Mod)%Mod;
    printf("%lld\n",ans);
	return 0;
}
