#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,L,l[N],r[N];

struct node{
    int x,v;
    node(int x=0,int v=0):x(x),v(v){}
    bool operator < (const node& _)const{return x<_.x;}
}a[N];
priority_queue<int> Q;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>L;
        while(!Q.empty())Q.pop();
        for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
        for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].v;
        sort(a+1,a+m+1);
        int ans=0,p=1,t=1;
        for(int i=1;i<=n;i++){
            while(t<=m&&a[t].x<l[i]){
                Q.push(a[t].v);
                ++t;
            }
            while(l[i]-1+p<=r[i]){
                if(Q.empty()){
                    ans=-1;
                    break;
                }
                p+=Q.top(),Q.pop(),++ans;
            }
            if(ans==-1)break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


