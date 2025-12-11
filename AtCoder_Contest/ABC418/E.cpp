#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
#define int long long
const int N = 4e6 + 10;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

inline int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

int n,x[N],y[N],ans,t;
map<int,int> mp; 
vector<int> s[N];
inline void solve() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int dx=x[i]-x[j],dy=y[i]-y[j];
            int d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            if(dx<0)dx=-dx,dy=-dy;
            int g=gcd(dx,dy);
            dx/=g,dy/=g;
            int h=dx*1000000000+dy;
            if(!mp[h])mp[h]=++t;
            s[mp[h]].push_back(d);
//            printf("(%lld %lld ) mp[%lld]=%lld\n",i,j,h,mp[h]);
        }
    }
    int _a=0;
    for(int i=1;i<=t;i++){
        int sz=s[i].size();
        ans+=sz*(sz-1)/2;
        sort(s[i].begin(),s[i].end());
//        for(int j=0;j<sz;j++)printf("%lld ",s[i][j]);
//        printf("     ");
        for(int l=0;l<sz;){
            int r=l;
            while(r+1<sz&&s[i][r+1]==s[i][r])++r;
//            printf("(%lld %lld ) ",l,r);
            _a+=(r-l+1)*(r-l)/2;
            l=r+1;
        }
//        printf("%lld ans=%lld\n",i,ans);
    }
    printf("%lld\n",ans-_a/2);
}
signed main() {
    int _ = 1; 
    while (_--) solve();
    return 0;
}
