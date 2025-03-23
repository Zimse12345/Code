#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18;
int n,q;
struct node{
    int a,b;
    node(int a=0,int b=0):a(a),b(b){}
    bool operator < (const node& _)const{
        if(b==_.b)return a>_.a;
        return b<_.b;
    }
}p[N];
priority_queue<int> Q;

signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>p[i].a>>p[i].b;
    }
    sort(p+1,p+n+1);
    while(q--){
        int k=0,ans=-inf;
        cin>>k;
        while(!Q.empty())Q.pop();
        for(int i=1,s=0;i<=n;i++){
            s-=p[i].b;
            Q.push(-(p[i].a+p[i].b));
            if(i>k)s-=Q.top(),Q.pop();
            if(i>=k)ans=max(ans,s);
        }
        printf("%lld\n",ans);
    }
    return 0;
}


