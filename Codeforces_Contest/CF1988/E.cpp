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
#define int long long

using namespace std;

const int inf = 1e9 + 7;
const int mod = 998244353;
const int N = 5e5 + 10, M = N << 1;
int n,a[N],sum[N],L[N],LL[N],R[N],RR[N],mn[N][20];

void add(int l,int r,int x){
    if(1<=l&&l<=r&&r<=n)sum[l]+=x,sum[r+1]-=x;
    return;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mn[i][0]=a[i];
        for(int j=0;j<19;j++){
            if(i-(1<<j)>0)mn[i][j+1]=min(mn[i][j],mn[i-(1<<j)][j]);
            else mn[i][j+1]=0;
        }
    }
    for(int i=1;i<=n;i++){
        int p=i;
        for(int j=19;j>=0;j--)if(mn[p][j]>=a[i])p-=(1<<j);
        L[i]=p;
        if(p)--p;
        for(int j=19;j>=0;j--)if(mn[p][j]>=a[i])p-=(1<<j);
        LL[i]=p;
    }
    for(int i=0;i<20;i++)mn[n+1][i]=0;
    for(int i=n;i>=1;i--){
        mn[i][0]=a[i];
        for(int j=0;j<19;j++){
            if(i+(1<<j)<=n)mn[i][j+1]=min(mn[i][j],mn[i+(1<<j)][j]);
            else mn[i][j+1]=0;
        }
    }
    for(int i=1;i<=n;i++){
        int p=i;
        for(int j=19;j>=0;j--)if(mn[p][j]>=a[i])p+=(1<<j);
        R[i]=p;
        if(p<=n)++p;
        for(int j=19;j>=0;j--)if(mn[p][j]>=a[i])p+=(1<<j);
        RR[i]=p;
    }
    for(int i=0;i<=n+1;i++)sum[i]=0;
    for(int i=1;i<=n;i++){
        add(1,L[i]-1,(i-L[i])*(R[i]-i)*a[i]);
        add(R[i]+1,n,(i-L[i])*(R[i]-i)*a[i]);
        add(L[i]+1,i-1,(i-L[i]-1)*(R[i]-i)*a[i]);
        add(i+1,R[i]-1,(i-L[i])*(R[i]-i-1)*a[i]);
        add(L[i],L[i],(i-LL[i]-1)*(R[i]-i)*a[i]);
        add(R[i],R[i],(i-L[i])*(RR[i]-i-1)*a[i]);
    }
    for(int i=1;i<=n;i++)sum[i]+=sum[i-1],printf("%lld ",sum[i]);
    printf("\n");
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
