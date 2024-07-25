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

using namespace std;

const int inf = 1e9 + 7;
const int mod = 998244353;
const int N = 2e6 + 10, M = N << 1;

int n,c,k,a[N],p[N],d0[N],f[N];
char str[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y>_.y;}
}s[N];

void solve(){
    cin>>n>>c>>k;
    scanf("%s",str+1);
    for(int i=0;i<c;i++)p[i]=d0[i]=0;
    for(int i=0;i<(1<<c);i++)f[i]=0;
    for(int i=1;i<=n;i++){
        a[i]=str[i]-'A';
        for(int j=0;j<c;j++)s[j]=node(j,p[j]);
        sort(s,s+c);
        int D0=(1<<a[i]);
        p[a[i]]=i,d0[a[i]]=0;
        for(int j=0;j<c;j++)if(s[j].x!=a[i]){
            d0[s[j].x]=D0;
            D0|=(1<<s[j].x);
            if(p[s[j].x]<=i-k)f[(1<<c)-1-d0[s[j].x]]=1;
        }
    }
    f[(1<<c)-1-(1<<a[n])]=1;
    int ans=c;
    for(int i=(1<<c)-1;i>0;i--){
        if(f[i]){
            for(int j=0;j<c;j++)if(i&(1<<j))f[i-(1<<j)]|=1;
        }
        else{
            int cnt=0;
            for(int j=0;j<c;j++)if(i&(1<<j))++cnt;
            ans=min(ans,cnt);
        }
    }
    printf("%d\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}

