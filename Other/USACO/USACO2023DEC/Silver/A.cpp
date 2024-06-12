#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,INF=1e18;
int n,m,k,ans;
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
}a[N];
set<node> s;

signed main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>a[i].x,cin>>a[i].y;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int x=0;
        while(!s.empty()){
            set<node>::iterator it=s.begin();
            node p=*it;
            if(p.x+k>a[i].x)break;
            s.erase(it);
            int t=min(a[i].y,p.y);
            a[i].y-=t,p.y-=t,ans+=t,x+=t;
            if(p.y)s.insert(p);
            if(!a[i].y)break;
        }
        int t=min(m,a[i].y);
        if(t+x)s.insert(node(a[i].x,t+x));
        m-=t,ans+=t;
    }
    printf("%lld\n",ans);
    return 0;
}


