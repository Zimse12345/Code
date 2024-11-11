#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 2e6 + 10, M = N << 1;

int n,q,h[N],mx[N];
int stk[N],top,ans[N];

#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

void build(int id,int L,int R){
    if(L==R)mx[id]=h[L];
    else{
        build(Lid,L,M),build(Rid,M+1,R);
        mx[id]=max(mx[Lid],mx[Rid]);
    }
    return;
} 

int query(int id,int L,int R,int l,int r){
    if(r<L||R<l)return 0;
    if(l<=L&&r>=R)return mx[id];
    return max(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

struct node{
    int l,id;
    node(int l=0,int id=0):l(l),id(id){}
};
vector<node> Q[N];

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>h[i];
    build(1,1,n);
    for(int i=1,l,r;i<=q;i++){
        cin>>l>>r;
        Q[r].push_back(node(l,i));
    }
    for(int i=n;i>=1;i--){
        for(unsigned j=0;j<Q[i].size();j++){
            int v=query(1,1,n,Q[i][j].l+1,i);
            int L=1,R=top,res=0;
            while(L<=R){
                if(h[stk[M]]>v)res=M,L=M+1;
                else R=M-1;
            }
            ans[Q[i][j].id]=res;
        }
        while(top&&h[i]>h[stk[top]])--top;
        stk[++top]=i;
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
