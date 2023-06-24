// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define M ((L+R)/2)
namespace OI{const int INF=1.01e18,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
const double eps=1e-9;
int n,k,h[N],tag,cur,f[N],g[N],cnt[N],sum[N],pre[N],Y[N],ans;
unsigned que[N],l,r;
char s[N];

inline void dp(int d){
    l=r=1,que[1]=1;
    for(int i=2,_f;i<=n+1;i++){
        f[i]=INF;
        while(l<r&&(Y[que[l+1]]-Y[que[l]])<(i-1)*(que[l+1]-que[l]))++l;
        _f=(cnt[i-1]+1)*(i-1)-sum[i-1]+d+Y[que[l]]-(i-1)*que[l];
        if(_f<f[i])f[i]=_f,g[i]=g[que[l]]+1;
        Y[i]=f[i]+pre[i-1];
        while(l<r&&(Y[i]-Y[que[r]])*(que[r]-que[r-1])<=(Y[que[r]]-Y[que[r-1]])*(i-que[r]))--r;
        que[++r]=i;
        if(g[i]>k){
            g[n+1]=INF;
            return;
        }
    }
    return;
}

signed main(){
    n=read(),k=read();
    int L=0,R=0;
    scanf("%s",s+1);
    for(int i=1;i<=n*2;i++){
        if(s[i]=='A')++h[cur+1];
        else ++cur,h[cur+1]=h[cur];
    }
    h[n+1]=INF;
    for(int i=1;i<=n;i++){
        R+=n-h[i]+1;
        if(h[i]<i)tag+=i-h[i],h[i]=i;
        cnt[h[i]]++,sum[h[i]]+=h[i];
    }
    for(int i=1;i<=n;i++){
        cnt[i]+=cnt[i-1],sum[i]+=sum[i-1];
        pre[i]=pre[i-1]+h[i];
    }
    int mid=R;
    while(L<=R){
        dp(M);
        if(g[n+1]<=k)mid=M,R=M-1,ans=f[n+1]-k*mid+tag;
        else L=M+1;
    }
    _wri(ans);
    return 0;
}
