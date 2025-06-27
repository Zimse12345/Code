#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,d,m,h[N],pos[N],ans,f[N];
int mx[N*4];

#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

void build(int id,int L,int R){
    mx[id]=-1;
    if(L!=R)build(Lid,L,M),build(Rid,M+1,R);
    return;
}

void update(int id,int L,int R,int x,int y){
    mx[id]=max(mx[id],y);
    if(L!=R){
        if(x<=M)update(Lid,L,M,x,y);
        else update(Rid,M+1,R,x,y);
    }
    return;
}

int query(int id,int L,int R,int l,int r){
    if(r<L||R<l)return -1;
    if(l<=L&&r>=R)return mx[id];
    return max(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    cin>>n>>d>>m;
    build(1,1,n);
    for(int i=1;i<=n;i++){
        cin>>h[i];
        pos[h[i]]=i;
    }
    for(int i=1,x;i<=n;i++){
        x=pos[i];
        if(i-d>0)update(1,1,n,pos[i-d],f[pos[i-d]]);
        f[x]=query(1,1,n,max(1,x-m),min(n,x+m))+1;
        ans=max(ans,f[x]);
    }
    printf("%d\n",ans);
    return 0;
}


