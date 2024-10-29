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

const int inf = 1e9;
const int mod = 998244353;
const int N = 1e6 + 10, M = N << 1;
int n,q,f[N],g[N];

int _abs(int x){
    return x<0?-x:x;
}

int calc(int from,int to,int t){
    if(from<t){
        if(to<t)return _abs(from-to);
        return from+(n-to);
    }
    else{
        if(to>t)return _abs(from-to);
        return (n-from)+to;
    }
}

int goR(int x,int y){
    if(x<=y)return y-x;
    return n-x+y;
}

int goL(int x,int y){
    if(x>=y)return x-y;
    return n-y+x;
}

void solve(){
    cin>>n>>q;
    char preH='L';
    int pre=1;
    for(int i=1;i<=n;i++)f[i]=inf;
    f[2]=0;
    while(q--){
        char c;
        int p;
        cin>>c>>p;
        for(int i=1;i<=n;i++)g[i]=inf;
        if(c!=preH){
            for(int i=1;i<=n;i++){
                //(i,pre) -> (p,pre)
                if(p!=pre)g[pre]=min(g[pre],f[i]+calc(i,p,pre));
                int rp=p+1,lp=p-1;
                if(rp>n)rp=1;
                if(lp<1)lp=n;
                //(i,pre) -> (p,p+1) 
                if(goR(i,p)>=goR(pre,p))g[rp]=min(g[rp],f[i]+goR(i,p)+goR(pre,rp));
                //(i,pre) -> (p,p-1)
                if(goL(i,p)>=goL(pre,p))g[lp]=min(g[lp],f[i]+goL(i,p)+goL(pre,lp));
            }
        }
        else{
            for(int i=1;i<=n;i++){
                //(i,pre) -> (i,p)
                if(p!=i)g[i]=min(g[i],f[i]+calc(pre,p,i));
                int rp=p+1,lp=p-1;
                if(rp>n)rp=1;
                if(lp<1)lp=n;
                //(i,pre) -> (p+1,p)
                if(goR(pre,p)>=goR(i,p))g[rp]=min(g[rp],f[i]+goR(pre,p)+goR(i,rp));
                //(i,pre) -> (p-1,p)
                if(goL(pre,p)>=goL(i,p))g[lp]=min(g[lp],f[i]+goL(pre,p)+goL(i,lp)); 
            }
        }
        for(int i=1;i<=n;i++)f[i]=g[i];
        preH=c,pre=p;
    }
    int ans=inf;
    for(int i=1;i<=n;i++)ans=min(ans,f[i]);
    printf("%d\n",ans);
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
