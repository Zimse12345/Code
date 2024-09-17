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
const int N = 1.01e6;
int n,p[N],a[N],k[N],v[N],PK[N],vis[N],ring[N],cnt,rk[N],to[N],ra[N];
int prime[N],m,pr[N],id[N];

bool ck(int M,int x){
    int _M=M;
    while(M>1){
        int p=pr[M],c=0,pk=1;
        while(pr[M]==p)M/=p,++c,pk*=p;
        if(k[p]){
            if(x%min(PK[p],pk)!=v[p]%min(PK[p],pk))return false;
        }
    }
    M=_M;
    while(M>1){
        int p=pr[M],c=0,pk=1;
        while(pr[M]==p)M/=p,++c,pk*=p;
        if(c>k[p])k[p]=c,PK[p]=pk,v[p]=x%pk;
    }
    return true;
}

void solve(){
    for(int i=2;i<N;i++){
        if(!pr[i])pr[i]=i,prime[++m]=i,id[i]=m;
        for(int j=1;j<=m&&i*prime[j]<N;j++){
            pr[i*prime[j]]=prime[j];
            if(pr[i]==prime[j])break;
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)cin>>a[i],ra[a[i]]=i;
    for(int i=1;i<=n;i++){
        int I=i;
        if(!vis[a[I]]){
            cnt=0;
            while(!vis[a[I]]){
                ring[++cnt]=a[I];
                rk[a[I]]=cnt-1;
                vis[a[I]]=1;
                I=p[I];
            }
            sort(ring+1,ring+cnt+1);
            for(int j=1;j<=cnt;j++)if(ck(cnt,rk[ring[j]])){
                int X=i,Y=ra[ring[j]];
                while(!to[a[X]])to[a[X]]=a[Y],X=p[X],Y=p[Y];
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",to[a[i]]);
    printf("\n");
    return; 
}

signed main(){
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}


