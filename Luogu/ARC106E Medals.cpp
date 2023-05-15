// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
#define M ((L+R)/2)

namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=4.01e6;
int n,k,a[N],f[N],sta[N],popc[N];

inline int lowbit(int x){
    return x&(-x);
}

bool check(int x){
    for(int i=0;i<(1<<n);i++)f[i]=0;
    for(int i=1;i<=x;i++)++f[sta[i]];
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++)if(j&(1<<i))f[j]+=f[j^(1<<i)];
    }
    for(int i=0;i<(1<<n);i++){
        if((x-f[(1<<n)-1-i])<popc[i]*k)return false;
    }
    return true;
}

signed main(){
    for(int i=1;i<N;i++)popc[i]=popc[i^lowbit(i)]+1;
    n=read(),k=read();
    for(int i=0;i<n;i++)a[i]=read();
    int L=0,R=2*n*k,ans=R;
    for(int i=1;i<=R;i++){
        for(int j=0;j<n;j++){
            if(((i-1)/a[j])%2==0)sta[i]|=(1<<j);
        }
    }
    while(L<=R){
        if(check(M))ans=M,R=M-1;
        else L=M+1;
    }
    _write(ans);
    return 0;
}

