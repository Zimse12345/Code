#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N=2.01e7;
int pr[N],prime[N/10],tot;
int T,n,m,l,r;
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{
        if(x==_.x)return y<_.y;
        return x<_.x;
    }
}que[N/10];
set<node> S;

inline int gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}

signed main(){
    for(int i=2;i<N;i++){
        if(!pr[i])prime[++tot]=i,pr[i]=i;
        for(int j=1;j<=tot&&prime[j]*i<N;j++){
            pr[prime[j]*i]=prime[j];
            if(pr[i]==prime[j])continue;
        }
    }
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>r;
        if(r<l)swap(l,r);
        int v=n;
        while(pr[v]!=v)--v;
        long long ans=1ll*(v-1)*l+1ll*v*r;
        int L=1,R=0;
        S.clear();
        for(int i=v-1;i>=v-100&&i>=1;i--){
            que[++R]=node(i,v),S.insert(node(i,v));
            if(pr[i]==i&&i<v-10)break;
        }
//        que[++R]=node(1,1),S.insert(node(1,1));
        while(L<=R){
            ans=max(ans,1ll*que[L].x*l+1ll*que[L].y*r);
            ++que[L].x;
            if(que[L].x<que[L].y&&gcd(que[L].x,que[L].y)==1&&S.find(node(que[L].x,que[L].y))==S.end())que[++R]=que[L],S.insert(que[L]);
            --que[L].x,++que[L].y;
            if(que[L].y<=n&&gcd(que[L].x,que[L].y)==1&&S.find(node(que[L].x,que[L].y))==S.end())que[++R]=que[L],S.insert(que[L]);
            ++L;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


