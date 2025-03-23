#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=3.01e6,inf=1e18;
int n,m,v[N],a[N],b[N],c[N],ans=inf,w[N];
int sum,res,k;

struct TreeArray{
    int tr[N];
    inline void ub(int& x){x+=(x&(-x));return;}
    inline void db(int& x){x-=(x&(-x));return;}
    inline void a(int x,int y){x+=N/2;for(;x<N;ub(x))tr[x]+=y;return;}
    inline int q(int x){x+=N/2;int s=0;for(;x;db(x))s+=tr[x];return s;}
}t,T;

void add(int x){
    res+=T.q(x);
    res+=x*(t.q(1000001)-t.q(x)+1);
    t.a(x,1);
    T.a(x,x);
    return;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(a[i]==1&&b[i]==1)v[++m]=c[i];
    }
    sort(v+1,v+m+1);
    for(int i=1;i<=n;i++){
        if(a[i]==0&&b[i]==1)w[++k]=c[i];
        if(a[i]==1&&b[i]==0)w[++k]=-c[i];
        if(a[i]==1)sum+=c[i];
    }
    sort(w+1,w+k+1);
    T.a(-1000001,sum);
    for(int i=1;i<=k;i++)sum+=w[i],res+=sum,t.a(w[i],1),T.a(w[i],w[i]);
    ans=res;
    for(int i=m;i>=1;i--){
        add(v[i]);
        add(-v[i]);
        ans=min(ans,res);
    }
    printf("%lld\n",ans);
    return 0;
}


