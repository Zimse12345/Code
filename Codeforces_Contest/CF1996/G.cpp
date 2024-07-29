#include <bits/stdc++.h>
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2) 
using namespace std;

const int N=1.01e6;
int T,n,m,a[N],b[N],que[N];
vector<int> R[N];
int ad[N*4];

struct node{
    int mn,cnt;
    node(int mn=0,int cnt=0):mn(mn),cnt(cnt){}
}t[N*4];

void pushdown(int id){
    if(ad[id]!=0){
        t[id].mn+=ad[id];
        if(Rid<N*4)ad[Lid]+=ad[id],ad[Rid]+=ad[id];
        ad[id]=0;
    }
    return;
}

void build(int id,int L,int R){
    t[id]=node(0,R-L+1),ad[id]=0;
    if(L!=R)build(Lid,L,M),build(Rid,M+1,R);
    return;
}

node merge(node l,node r){
    node p=node(min(l.mn,r.mn),0);
    if(p.mn==l.mn)p.cnt+=l.cnt;
    if(p.mn==r.mn)p.cnt+=r.cnt;
    return p;
}

void update(int id,int L,int R,int l,int r,int x){
    pushdown(id);
    if(l<=L&&r>=R)ad[id]+=x,pushdown(id);
    else if(R<l||r<L)return;
    else{
        update(Lid,L,M,l,r,x),update(Rid,M+1,R,l,r,x);
        t[id]=merge(t[Lid],t[Rid]);
    }
    return;
}

node query(int id,int L,int R,int l,int r){
    pushdown(id);
    if(l<=L&&r>=R)return t[id];
    else if(R<l||r<L)return node(1000000,0);
    else return merge(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        build(1,1,n*2);
        for(int i=1;i<=n*2;i++)R[i].resize(0);
        for(int i=1;i<=m;i++){
            cin>>a[i]>>b[i];
            if(b[i]<a[i])swap(a[i],b[i]);
            R[a[i]].push_back(b[i]);
            update(1,1,n*2,a[i],b[i]-1,1);
        }
        int ans=1;
        node p=query(1,1,n*2,1,n-1);
        if(p.mn==0)ans=max(ans,p.cnt+1);
        for(int i=1;i<n;i++){
            for(unsigned j=0;j<R[i].size();j++){
                update(1,1,n*2,i,R[i][j]-1,-1);
                update(1,1,n*2,R[i][j],i+n-1,1);
                R[R[i][j]].push_back(i+n);
            }
            p=query(1,1,n*2,i+1,i+n-1);
            if(p.mn==0)ans=max(ans,p.cnt+1);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}


