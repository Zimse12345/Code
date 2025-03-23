#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,k,a[N],b[N],c[N];

struct node{
    int v,x,y,z;
    node(int v=0,int x=0,int y=0,int z=0):v(v),x(x),y(y),z(z){}
    bool operator < (const node& _)const{return v<_.v;}
};
priority_queue<node> Q;
map<int,int> vis;

int hs(int x,int y,int z){
    return (x*(n+1)+y)*(n+1)+z;
}

node nd(int x,int y,int z){
    return node(a[x]*b[y]+b[y]*c[z]+c[z]*a[x],x,y,z);
}

signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)cin>>b[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)cin>>c[i];
    sort(c+1,c+n+1);
    Q.push(nd(n,n,n));
    while(1){
        node p=Q.top();
        Q.pop();
        int h=hs(p.x,p.y,p.z);
        if(vis[h])continue;
        vis[h]=1;
        --k;
        if(k==0){
            printf("%lld\n",p.v);
            break;
        }
        if(p.x>1)Q.push(nd(p.x-1,p.y,p.z));
        if(p.y>1)Q.push(nd(p.x,p.y-1,p.z));
        if(p.z>1)Q.push(nd(p.x,p.y,p.z-1));
    }
    return 0;
}


