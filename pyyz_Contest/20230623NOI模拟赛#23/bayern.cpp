// Author:Zimse  Data:2023-06-
// CF794G
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.01e9,Mod=1000000007;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=4.01e6;
char s[2][N];
int n,len[2],cntF[2],cntD[2],cntU[2];
int fac[N],ifac[N],ans,p2[N],c00;
int mu[N],pr[N],prime[N],tot;

inline int C(int x,int y){
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

inline int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

inline int calc(int x,int y){
    if(x<0)x=-x,y=-y;
    if(y<0)return 0;
    if(x==0&&y==0)return c00;
    if(x==0||y==0)return 0;
    int g=gcd(x,y);
    x/=g,y/=g;
    return p2[n/max(x,y)+1]-2;
}

signed main(){
    iF("bayern.in");
    oF("bayern.out");

    fac[0]=ifac[0]=p2[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod,p2[i]=p2[i-1]*2%Mod;
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=1;i--)ifac[i]=ifac[i+1]*(i+1)%Mod;
    mu[1]=1;
    for(int i=2;i<N;i++){
        if(!pr[i])pr[i]=i,mu[i]=-1,prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<N;j++){
            pr[i*prime[j]]=prime[j],mu[i*prime[j]]=-mu[i];
            if(pr[i]==prime[j]){mu[i*prime[j]]=0;break;}
        }
    }

    for(int i=0;i<2;i++){
        scanf("%s",s[i]);
        len[i]=strlen(s[i]);
        for(int j=0;j<len[i];j++){
            // if(s[i][j]=='A')s[i][j]='F';
            // if(s[i][j]=='B')s[i][j]='D';
            if(s[i][j]=='F')++cntF[i];
            else if(s[i][j]=='D')++cntD[i];
            else ++cntU[i];
        }
    }
    n=read();
    for(int l=1,r;l<=n;){
        r=n/(n/l);
        int sum=0;
        for(int i=l;i<=r;i++)_mod(sum,p2[i]);
        for(int d=1;d<=n/l;d++)_mod(c00,sum*mu[d]*(n/l/d)%Mod*(n/l/d));
        l=r+1;
    }
    for(int i=-cntU[1];i<=cntU[0];i++){
        _mod(ans,calc(cntF[0]-cntF[1]+i,cntD[1]-cntD[0]+cntU[1]-cntU[0]+i)*C(cntU[0]+cntU[1],i+cntU[1]));
    }
    int tag=1;
    if(len[0]!=len[1])tag=0;
    else{
        for(int i=0;i<len[0];i++){
            if(s[0][i]=='F'&&s[1][i]=='D')tag=0;
            if(s[0][i]=='D'&&s[1][i]=='F')tag=0;
        }
    }
    if(tag){
        int cnt=0;
        for(int i=0;i<len[0];i++){
            if(s[0][i]=='?'&&s[1][i]=='?')++cnt;
        }
        int sum=p2[n+1]-2;
        sum=(sum*sum-calc(0,0))%Mod;
        _mod(ans,sum*p2[cnt]);
    }
    _mod(ans,Mod);
    _wri(ans);
    return 0;
}

