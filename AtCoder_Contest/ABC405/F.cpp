#include <bits/stdc++.h>
using namespace std;

const int N=2.01e6;
int n,m,q,ans[N];
int ad[N*8];

#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

void update(int id,int L,int R,int l,int r,int v){
    if(r<L||R<l)return;
    if(l<=L&&r>=R)ad[id]+=v;
    else{
        update(Lid,L,M,l,r,v);
        update(Rid,M+1,R,l,r,v);
    }
    return;
}

int query(int id,int L,int R,int x){
    if(L==R)return ad[id];
    if(x<=M)return query(Lid,L,M,x)+ad[id];
    else return query(Rid,M+1,R,x)+ad[id];
}

struct node{
    int t,l,r;
    node(int t=0,int l=0,int r=0):t(t),l(l),r(r){}
};
vector<node> upt[N],qry[N];

signed main(){
    cin>>n>>m;
    for(int i=1,a,b;i<=m;i++){
        cin>>a>>b;
        if(b<a)swap(a,b);
        upt[a].push_back(node(1,a,b));
        upt[b+1].push_back(node(-1,a,b)); 
    }
    cin>>q;
    for(int i=1,a,b;i<=q;i++){
        cin>>a>>b;
        if(b<a)swap(a,b);
        qry[a].push_back(node(i,b,0));
        qry[b].push_back(node(i,a,0));
    }
    for(int i=1;i<=n*2;i++){
        for(unsigned j=0;j<upt[i].size();j++){
            update(1,1,n*2,upt[i][j].l,upt[i][j].r,-upt[i][j].t);
            ad[1]+=upt[i][j].t;
        }
        for(unsigned j=0;j<qry[i].size();j++){
            ans[qry[i][j].t]+=query(1,1,n*2,qry[i][j].l);
        }
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}


