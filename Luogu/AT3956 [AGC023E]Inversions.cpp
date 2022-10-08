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
int n,a[N],S,ans,cnt[N],inv2,f[N],g[N],r0[N];

inline void add(int& x,int y){(x+=y)%=Mod;return;}

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

struct TreeArray{
    int tr[N];
    inline void ub(int& x){x+=(x&(-x));return;}
    inline void db(int& x){x-=(x&(-x));return;}
    inline void a(int x,int y){for(;x<N;ub(x))add(tr[x],y);return;}
    inline int q(int x){int s=0;for(;x;db(x))add(s,tr[x]);return s;}
    inline void clear(){for(int i=0;i<N;i++)tr[i]=0;return;}
}tot,sum;

signed main(){
    inv2=inv(2),S=1;
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),++cnt[a[i]];
    for(int i=n-1;i>=1;i--)cnt[i]+=cnt[i+1];
    f[0]=g[0]=1;
    for(int i=1,j=1;i<=n;i++){
        cnt[i]-=(n-i),S=(S*cnt[i])%Mod;
        f[i]=(f[i-1]*cnt[i])%Mod,g[i]=(g[i-1]*max(1ll,cnt[i]-1))%Mod;
        if(cnt[i]==1){
            for(int k=j;k<i;k++)r0[k]=i;
            j=i;
        }
        if(cnt[i]<=0){
            printf("0\n");
            return 0;
        }
        if(i==n){
            for(int k=j;k<=n;k++)r0[k]=n+1;
        }
    }
    for(int i=1;i<=n;i++){
        tot.a(a[i],1);
        sum.a(a[i],g[a[i]]*inv(f[a[i]])%Mod);
    }
    for(int i=1,x=0;i<=n;i++){
        tot.a(a[i],-1);
        sum.a(a[i],-g[a[i]]*inv(f[a[i]])%Mod);
        x=tot.q(a[i])-tot.q(a[i]-1);
        add(ans,x*S%Mod*inv2%Mod);
        if(r0[a[i]]-1>a[i]){
            x=sum.q(r0[a[i]]-1)-sum.q(a[i]);
            add(ans,x*f[a[i]]%Mod*f[n]%Mod*inv(g[a[i]])%Mod*inv2%Mod);
        }
    }
    tot.clear();
    sum.clear();
    for(int i=1;i<=n;i++){
        tot.a(a[i],1);
        sum.a(a[i],g[a[i]]*inv(f[a[i]])%Mod);
    }
    for(int i=n,x=0,y=0;i>=1;i--){
        tot.a(a[i],-1);
        sum.a(a[i],-g[a[i]]*inv(f[a[i]])%Mod);
        if(r0[a[i]]-1>a[i]){
            x=sum.q(r0[a[i]]-1)-sum.q(a[i]),y=tot.q(r0[a[i]]-1)-tot.q(a[i]);
            add(ans,S*y%Mod-x*f[a[i]]%Mod*f[n]%Mod*inv(g[a[i]])%Mod*inv2%Mod);
        }
        x=tot.q(n)-tot.q(r0[a[i]]-1);
        add(ans,S*x%Mod);
    }
    add(ans,Mod);
    printf("%lld\n",ans);
	return 0;
}
