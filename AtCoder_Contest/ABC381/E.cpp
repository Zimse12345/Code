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

int n,q,p1[N][30],p2[N][30],sum[N];
char s[N];
void solve(){
    cin>>n>>q;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1];
        if(s[i]=='/')++sum[i];
        p2[i][0]=p2[i-1][0];
        if(s[i]=='2')p2[i][0]=i;
    }
    for(int i=n;i>=1;i--){
        p1[i][0]=p1[i+1][0];
        if(s[i]=='1')p1[i][0]=i;
    }
    for(int d=1;d<=20;d++){
        for(int i=1;i<=n;i++){
            if(p2[i][d-1])p2[i][d]=p2[p2[i][d-1]-1][d-1];
        }
        for(int i=n;i>=1;i--){
            if(p1[i][d-1])p1[i][d]=p1[p1[i][d-1]+1][d-1];
        }
    }
    while(q--){
        int l,r,ans=1;
        cin>>l>>r;
        for(int d=20;d>=0;d--)if(p1[l][d]&&p2[r][d]){
            int L=p1[l][d]+1;
            int R=p2[r][d]-1;
            if(L<=R&&sum[R]-sum[L-1]>0)ans+=(1<<d)*2,l=L,r=R;
        }
        if(sum[r]-sum[l-1]<=0)ans=0;
        printf("%d\n",ans);
    }
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
