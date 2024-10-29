#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <iostream>
#include <cstring>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 1e6 + 10, M = N << 1;
int n,m,k,a[N],v[N],sum,pre[N];
map<int,int> mp;

bool check(int l,int r,int K,int V){
    int L=l,R=r,p=l-1;
    while(L<=R){
        int mid=(L+R)/2;
        if(v[mid]<=V)p=mid,L=mid+1;
        else R=mid-1;
    }
    return K<(V+1)*(p-l+1)-(pre[p]-pre[l-1]);
}

bool ck(int p,int ad){
    if(p<=n-m)return check(n-m+1,n,k-sum-ad,v[p]+ad);
    return check(n-m,n,k-sum+1,v[p]+ad);
}

void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>a[i],v[i]=a[i],sum+=a[i];
    if(n==m){
        for(int i=1;i<=n;i++)printf("0 ");
        printf("\n");
        return;
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+v[i];
    v[0]=-1;
    for(int i=1;i<=n;i++)if(v[i]!=v[i-1]){
        int L=0,R=k-sum,res=-1;
        while(L<=R){
            int mid=(L+R)/2;
            if(ck(i,mid))res=mid,R=mid-1;
            else L=mid+1; 
        }
        mp[v[i]]=res;
    }
    for(int i=1;i<=n;i++)printf("%lld ",mp[a[i]]);
    printf("\n");
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
