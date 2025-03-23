#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,a[N],ans;

struct TreeArray{
    int tr[N];
    inline void ub(int& x){x+=(x&(-x));return;}
    inline void db(int& x){x-=(x&(-x));return;}
    inline void a(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
    inline int q(int x){int s=0;for(;x;db(x))s+=tr[x];return s;}
}t;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t.a(a[i],1);
        int v=i-t.q(a[i]);
        ans+=1ll*(i-1+i-v)*v/2;
    }
    printf("%lld\n",ans);
    return 0;
}


