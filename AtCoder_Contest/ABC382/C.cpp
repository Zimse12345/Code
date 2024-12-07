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

int n,m,a[N],b[N],ans[N];
struct node{
    int v,pos;
    node(int v=0,int pos=0):v(v),pos(pos){}
    bool operator < (const node& _)const{return v<_.v;}
}A[N],B[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        A[i]=node(a[i],i);
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        B[i]=node(b[i],i);
    }
    sort(A+1,A+n+1);
    sort(B+1,B+m+1);
    int t=1,s=n+1;
    for(int i=1;i<=m;i++){
        while(t<=n&&B[i].v>=A[t].v)s=min(s,A[t].pos),++t;
        if(s<=n)ans[B[i].pos]=s;
        else ans[B[i].pos]=-1;
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
