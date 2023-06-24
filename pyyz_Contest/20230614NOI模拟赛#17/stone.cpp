// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
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

#include <cctype>
const int MB=1<<20;
struct FastIO{
    char ib[MB+100],*p,*q;
    char ob[MB+100],*r,stk[128];
    int tp;
    FastIO(){p=q=ib,r=ob,tp=0;}
    ~FastIO(){fwrite(ob,1,r-ob,stdout);}
    char read_char(){
        if(p==q){
            p=ib,q=ib+fread(ib,1,MB,stdin);
            if(p==q)return 0;
        }
        return *p++;
    }
    template<typename T>
    void read_int(T& x){
        char c=read_char(),l=0;
        for(x=0;!isdigit(c);c=read_char())l=c;
        for(;isdigit(c);c=read_char())x=x*10-'0'+c;
        if(l=='-')x=-x;
    }
    
    void write_char(char c){
        if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
        *r++=c;
    }
    template<typename T>
    void write_int(T x){
        if(x<0)write_char('-'),x=-x;
        do stk[++tp]=x%10+'0';
        while(x/=10);
        while(tp)write_char(stk[tp--]);
    }
}IO;

const int N=1.01e7;
int n,a[N],ans,l[N],r[N],h[N],top;

signed main(){
    iF("stone.in");
    oF("stone.out");

    IO.read_int(n);
    for(int i=1;i<=n;i++)IO.read_int(a[i]);
    a[n+1]=INF,top=1,l[1]=r[1]=n+1,h[1]=INF;
    for(int i=n;i>=1;i--){
        while(a[i]>h[top]){
            int len=r[top]-l[top]+1;
            int k=min(h[top-1]-h[top],(a[i]-h[top]+1)/(1+len));
            a[i]-=len*k,h[top]+=k,ans+=(1+len)*len/2*k;
            if(h[top]==h[top-1])--top,l[top]=l[top+1];
            else if(h[top]==h[top-1]-1){
                k=a[i]-h[top];
                if(k>0)ans+=(len-k+1+len)*k/2,a[i]-=k,r[top]-=k,l[top-1]-=k;
            }
            else if(a[i]>h[top]){
                ++top,l[top]=l[top-1],r[top]=r[top-1],h[top]=h[top-1];
                k=a[i]-h[top];
                ans+=(len-k+1+len)*k/2,a[i]-=k,r[top]-=k;
                l[top-1]=r[top]+1,h[top-1]++;
            }
        }
        if(a[i]==h[top])--l[top];
        else ++top,l[top]=r[top]=i,h[top]=a[i];
        ans%=1000000007;
    }
    _wri(ans);
    return 0;
}
