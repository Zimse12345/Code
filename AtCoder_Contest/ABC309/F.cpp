#include <bits/stdc++.h>
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)
using namespace std;

const int N=1.01e6,INF=1.01e9;
int n,val[N],m;
int mn[N*5],V;
map<int,int> mp;
struct node{
    int x,y,z;
    node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    bool operator < (const node &_)const{return z<_.z;}
}p[N];

void build(int id,int L,int R){
    mn[id]=INF;
    if(L!=R)build(Lid,L,M),build(Rid,M+1,R);
    return;
}

void update(int id,int L,int R,int x,int y){
    mn[id]=min(mn[id],y);
    if(L!=R){
        if(x<=M)update(Lid,L,M,x,y);
        else update(Rid,M+1,R,x,y);
    }
    return;
}

int query(int id,int L,int R,int l,int r){
    if(l<=L&&r>=R)return mn[id];
    else if(r<L||R<l)return INF;
    return min(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y>>p[i].z;
        if(p[i].y<p[i].x)swap(p[i].x,p[i].y);
        if(p[i].z<p[i].y)swap(p[i].y,p[i].z);
        if(p[i].y<p[i].x)swap(p[i].x,p[i].y);
        val[++m]=p[i].x,val[++m]=p[i].y,val[++m]=p[i].z;
    }
    sort(val+1,val+m+1);
    for(int i=1;i<=m;i++)if(val[i]!=val[i-1])mp[val[i]]=++V;
    for(int i=1;i<=n;i++)p[i].x=mp[p[i].x],p[i].y=mp[p[i].y],p[i].z=mp[p[i].z];
    build(1,1,V);
    sort(p+1,p+n+1);
    for(int l=1,r;l<=n;){
        r=l;
        while(r<n&&p[r+1].z==p[r].z)++r;
        for(int i=l;i<=r;i++){
            if(query(1,1,V,1,p[i].x-1)<p[i].y){
                printf("Yes\n");
                return 0;
            }
        }
        for(int i=l;i<=r;i++)update(1,1,V,p[i].x,p[i].y);
        l=r+1;
    }
    printf("No\n");
    return 0;
}


