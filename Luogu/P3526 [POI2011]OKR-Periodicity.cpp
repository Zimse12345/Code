// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
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
int T,n,bd[N],cur;
char str[N],ans[N],a[N];

void solve(int l,int r){
    int tag=0;
    for(int i=l+1;i<=r;i++)if(str[i]!=str[i-1])tag=1;
    if(!tag){
        for(int i=l;i<=r;i++)ans[i]='0';
        return;
    }
    bd[l]=l-1;
    for(int i=l+1,j=l-1;i<=r;i++){
        while(j>=l&&str[i]!=str[j+1])j=bd[j];
        if(str[i]==str[j+1])++j;
        bd[i]=j;
    }
    if(bd[r]==l-1){
        for(int i=l;i<r;i++)ans[i]='0';
        ans[r]='1';
        return;
    }
    int len=r-l+1,s=len-(bd[r]-l+1);
    if(s*2<=len){
        solve(r-(len%s+s)+1,r);
        for(int i=r-(len%s+s);i>=l;i--)ans[i]=ans[i+s];
        return;
    }
    s=bd[r]-l+1;
    solve(l,l+s-1);
    cur=0;
    for(int i=l;i<=l+s-1;i++)a[++cur]=ans[i];
    for(int i=l+s;i<=r-s;i++)a[++cur]='0',ans[i]='0';
    for(int i=l;i<=l+s-1;i++)a[++cur]=ans[i],ans[r-s+1+i-l]=ans[i];
    bd[1]=0;
    for(int i=2,j=0;i<=cur;i++){
        while(j&&a[i]!=a[j+1])j=bd[j];
        if(a[i]==a[j+1])++j;
        bd[i]=j;
    }
    if(bd[cur]!=s)ans[r-s]='1';
    return;
}

signed main(){
    T=read();
    while(T--){
        scanf("%s",str+1);
        n=strlen(str+1);
        solve(1,n);
        for(int i=1;i<=n;i++)pc(ans[i]);
        pc(10);
    }
    return 0;
}

