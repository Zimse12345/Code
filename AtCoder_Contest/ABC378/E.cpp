#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5.01e5;
int n,m,a[N],ans,sum;

struct TreeArray{
    int tr[N];
    inline void ub(int& x){x+=(x&(-x));return;}
    inline void db(int& x){x-=(x&(-x));return;}
    inline void a(int x,int y){x++;for(;x<N;ub(x))tr[x]+=y;return;}
    inline int q(int x){x++;int s=0;for(;x;db(x))s+=tr[x];return s;}
    inline void clear(int sz=N){for(int i=0;i<sz;i++)tr[i]=0;return;}
}cnt;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]=(a[i]+a[i-1])%m;
    cnt.a(0,1);
    for(int i=1;i<=n;i++){
        ans+=cnt.q(a[i])*a[i]+(i-cnt.q(a[i]))*(a[i]+m)-sum;
        sum+=a[i];
        cnt.a(a[i],1);
    }
    printf("%lld\n",ans);
    return 0;
}


