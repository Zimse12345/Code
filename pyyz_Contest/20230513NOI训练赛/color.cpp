// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)

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

const int N=1.01e5,SZ=400;
int n,m,a[N],L[N],R[N],bc,bel[N];
int f[256][256],cnt[N],Inv[N];
signed CntL[256][256][SZ+1],CntR[256][256][SZ+1];

signed main(){
    // ifile("color.in");
    // ofile("color.out");
    
    for(int i=0;i<N;i++)Inv[i]=inv(i);
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int l=1,r=0;l<=n;l=r+1){
        r=min(n,l+SZ-1);
        ++bc,L[bc]=l,R[bc]=r;
        for(int i=l;i<=r;i++)bel[i]=bc;
    }
    for(int i=1;i<=bc;i++){
        int p=L[i],s=1;
        for(int j=i;j<=bc;j++){
            while(p<=R[j]){
                s=s*Inv[cnt[a[p]]+1]%Mod;
                ++cnt[a[p]];
                s=s*(cnt[a[p]]+1)%Mod;
                ++p;
            }
            f[i][j]=s;
            if(i>1){
                for(int k=L[i-1];k<=R[i-1];k++)CntL[i][j][k-L[i-1]]=cnt[a[k]];
            }
            if(j<bc){
                for(int k=L[j+1];k<=R[j+1];k++)CntR[i][j][k-L[j+1]]=cnt[a[k]];
            }
        }
        f[i][i-1]=1;
        for(int j=1;j<=100000;j++)cnt[j]=0;
    }
    m=read();
    int ans=0;
    while(m--){
        int l=read()^ans,r=read()^ans;
        int bl=bel[l],br=bel[r];
        if(bl==br){
            ans=1;
            for(int i=l;i<=r;i++){
                ans=ans*Inv[cnt[a[i]]+1]%Mod;
                ++cnt[a[i]];
                ans=ans*(cnt[a[i]]+1)%Mod;
            }
            for(int i=l;i<=r;i++)cnt[a[i]]=0;
        }
        else{
            ans=f[bl+1][br-1];
            for(int i=l;i<L[bl+1];i++){
                if(!cnt[a[i]])cnt[a[i]]=CntL[bl+1][br-1][i-L[bl]];
                ans=ans*Inv[cnt[a[i]]+1]%Mod;
                ++cnt[a[i]];
                ans=ans*(cnt[a[i]]+1)%Mod;
            }
            for(int i=r;i>R[br-1];i--){
                if(!cnt[a[i]])cnt[a[i]]=CntR[bl+1][br-1][i-L[br]];
                ans=ans*Inv[cnt[a[i]]+1]%Mod;
                ++cnt[a[i]];
                ans=ans*(cnt[a[i]]+1)%Mod;
            }
            for(int i=l;i<L[bl+1];i++)cnt[a[i]]=0;
            for(int i=r;i>R[br-1];i--)cnt[a[i]]=0;
        }
        _write(ans);
    }
    return 0;
}

