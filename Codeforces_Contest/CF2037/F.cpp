#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e9;
int T,n,m,k,h[N],x[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
}s[N];

bool ck(int a){
    int cnt=0;
    for(int i=1;i<=n;i++){
        int d=(h[i]+a-1)/a;
        d=m-d;
        if(d>=0)s[++cnt]=node(x[i]-d,1),s[++cnt]=node(x[i]+d+1,-1);
    }
    s[cnt+1].x=1e18;
    sort(s+1,s+cnt+1);
    int mx=0;
    for(int i=1,v=0;i<=cnt;i++){
        v+=s[i].y;
        if(s[i].x!=s[i+1].x)mx=max(mx,v);
    }
    return mx>=k;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)cin>>h[i];
        for(int i=1;i<=n;i++)cin>>x[i];
        int L=1,R=inf,ans=-1;
        while(L<=R){
            int M=(L+R)/2;
            if(ck(M))ans=M,R=M-1;
            else L=M+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


