#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int n,k,fa[N],dep[N],t[N],m,ch[N];
vector<int> g[N]; 
int a[N],b[N];

inline void solve() {
    cin>>n>>k;
    ++t[0],m=0;
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        ++ch[fa[i]];
        dep[i]=dep[fa[i]]+1,++t[dep[i]];
        m=max(m,dep[i]);
    }
    for(int i=1;i<=n;i++)if(!ch[i])m=min(m,dep[i]);
    a[0]=1;
    int ans=0,S=0;
    for(int l=0,r=0;l<=m;){
        r=l;
        while(r<m&&t[r]==t[r+1])++r;
        int len=r-l+1;
        for(int i=0;i<=20;i++)if(len>=(1ll<<i)){
            int V=(1ll<<i)*t[l],tag=0;
            S+=V;
            for(int j=n;j>=0;j--){
                b[j]=a[j];
                if(j>=V)b[j]|=a[j-V];
                if(b[j]&&((j<=k&&S-j<=n-k)||(j<=n-k&&S-j<=k)))tag=1;
            }
            if(tag){
                for(int j=0;j<=n;j++)a[j]=b[j];
                ans+=(1ll<<i),len-=(1ll<<i);
            }
            else S-=V;
        }
        for(int i=20;i>=0;i--)if(len>=(1ll<<i)){
            int V=(1ll<<i)*t[l],tag=0;
            S+=V;
            for(int j=n;j>=0;j--){
                b[j]=a[j];
                if(j>=V)b[j]|=a[j-V];
                if(b[j]&&((j<=k&&S-j<=n-k)||(j<=n-k&&S-j<=k)))tag=1;
            }
            if(tag){
                for(int j=0;j<=n;j++)a[j]=b[j];
                ans+=(1ll<<i),len-=(1ll<<i);
            }
            else S-=V;
        }
        l=r+1;
        if(len)break;
    }
    printf("%d\n",ans);
    for(int i=0;i<=n;i++)a[i]=t[i]=ch[i]=0;
}
signed main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}
