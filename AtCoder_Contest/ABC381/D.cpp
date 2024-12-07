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
const int N = 1e6 + 10;

int n,a[N],vis[N],ans,c1;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2,pre=1;i<=n;i+=2){
        if(a[i]!=a[i-1]){
            while(pre<=i)vis[a[pre]]=0,pre+=2;
        }
        else{
            while(vis[a[i]])vis[a[pre]]=0,pre+=2;
            vis[a[i]]=1;
        }
        ans=max(ans,i-pre+1);
    }
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=3,pre=2;i<=n;i+=2){
        if(a[i]!=a[i-1]){
            while(pre<=i)vis[a[pre]]=0,pre+=2;
        }
        else{
            while(vis[a[i]])vis[a[pre]]=0,pre+=2;
            vis[a[i]]=1;
        }
        ans=max(ans,i-pre+1);
    }
    printf("%d\n",ans); 
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
