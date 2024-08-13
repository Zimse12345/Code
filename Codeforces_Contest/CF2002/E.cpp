#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,ans[N];
struct node{
    int v,t;
    node(int v=0,int t=0):v(v),t(t){}
}que[N];
int l,r;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        l=n,r=n;
        for(int i=1,v,t,s=0;i<=n;i++){
            cin>>t>>v;
            if(i==1){
                que[l]=node(v,t);
                s=ans[1]=t;
                continue;
            }
            int _t=0;
            while(t&&l<=r){
                if(que[l].v==v){
                    _t+=que[l].t,++l;
                    continue;
                }
                int m=min(t,que[l].t);
                que[l].t-=m,t-=m,_t+=m;
                if(!que[l].t)++l;
            }
            _t+=t;
            que[--l]=node(v,_t);
            if(l==r)s=_t;
            ans[i]=s;
        }
        for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
        printf("\n");
    }
    return 0;
}


