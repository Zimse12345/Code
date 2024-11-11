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
#define int long long

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
const int N = 1e6 + 10, M = N << 1;


struct node{
    int X,A;
    node(int X=0,int A=0):X(X),A(A){}
    bool operator < (const node& _)const{return X<_.X;}
}p[N];
int n,m,x[N],a[N];
void solve(){
    cin>>n>>m;
    long long ans=0,sum=0;
    bool tag=true;
    for(int i=1;i<=m;i++)cin>>p[i].X;
    for(int i=1;i<=m;i++)cin>>p[i].A;
    sort(p+1,p+m+1);
    for(int i=1;i<=m;i++)x[i]=p[i].X,a[i]=p[i].A,sum+=p[i].A;
    a[0]=1,x[m+1]=n+1;
    for(int i=0;i<=m;i++){
        if(x[i]+a[i]<x[i+1]){
            tag=false;
            break;
        }
        ans+=(x[i+1]-x[i]-1)*(x[i+1]-x[i])/2+(x[i+1]-x[i])*(a[i]-(x[i+1]-x[i]));
        a[i+1]+=(a[i]-(x[i+1]-x[i]));
    }
    if(sum!=n)tag=false;
    if(!tag)ans=-1;
    printf("%lld\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
