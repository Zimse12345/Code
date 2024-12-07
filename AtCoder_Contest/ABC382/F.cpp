#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
//#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 2e5 + 10;

int n,m,cnt,ans[N],t[N*8],tag[N*8];
struct node{
    int h,l,r,id;
    node(int h=0,int l=0,int r=0,int id=0):h(h),l(l),r(r),id(id){}
    bool operator < (const node& _)const{return h<_.h;}
}a[N];

void build(int id,int L,int R){
    t[id]=n+1;
    if(L!=R){
        build(id*2,L,(L+R)/2);
        build(id*2+1,(L+R)/2+1,R);
    }
}

void pushdown(int id){
    if(tag[id]){
        t[id]=min(t[id],tag[id]);
        tag[id*2]=tag[id];
        tag[id*2+1]=tag[id];
        tag[id]=0;
    }
}

void update(int id,int L,int R,int l,int r,int x){
    pushdown(id);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)tag[id]=x,t[id]=min(t[id],x);
    else{
        update(id*2,L,(L+R)/2,l,r,x);
        update(id*2+1,(L+R)/2+1,R,l,r,x);
        t[id]=min(t[id*2],t[id*2+1]);
    }
}

int query(int id,int L,int R,int l,int r){
    pushdown(id);
    if(r<L||R<l)return n+1;
    if(l<=L&&r>=R)return t[id];
    return min(query(id*2,L,(L+R)/2,l,r),query(id*2+1,(L+R)/2+1,R,l,r));
}

void solve(){
    cin>>n>>m>>cnt;
    for(int i=1;i<=cnt;i++){
        int h,l,r;
        cin>>h>>l>>r;
        r=l+r-1;
        a[i]=node(h,l,r,i);
    }
    build(1,1,m);
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--){
        int q=query(1,1,m,a[i].l,a[i].r)-1;
        ans[a[i].id]=q;
        update(1,1,m,a[i].l,a[i].r,q);
    }
    for(int i=1;i<=cnt;i++)printf("%d\n",ans[i]);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
