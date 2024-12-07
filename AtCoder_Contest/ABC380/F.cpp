#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

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
const int N = 1e6 + 10;
int n,n1,n2,n3,a[N];
map<int,int> vis,res;

int dfs(int x){
    int xx=x;
    if(vis[x])return res[x];
    vector<int> t(20,0);
    for(int i=n-1;i>=0;i--)t[i]=x%3,x/=3;
    t[n]=2;
    for(int i=0;i<n;i++)if(t[i]==0){
        for(int j=0;j<n+1;j++)if(t[j]==2&&a[i]>a[j]){
            swap(t[i],t[j]);
            x=0;
            for(int k=0;k<n;k++){
                if(t[k]==0)x=x*3+1;
                if(t[k]==2)x=x*3+2; 
                if(t[k]==1)x=x*3;
            }
            if(!dfs(x)){
                vis[xx]=1,res[xx]=1;
                return 1;
            }
            swap(t[i],t[j]);
        }
    }
    vis[xx]=1,res[xx]=0;
    return 0;
}

void solve(){
    cin>>n1>>n2>>n3;
    int x=0;
    for(int i=0;i<n1;i++)cin>>a[n],++n,x=x*3;
    for(int i=0;i<n2;i++)cin>>a[n],++n,x=x*3+1;
    for(int i=0;i<n3;i++)cin>>a[n],++n,x=x*3+2;
    if(dfs(x))printf("Takahashi\n");
    else printf("Aoki\n");
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
