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

const int N=1.01e6;
int n,f[N][3],vis[N],ans,rm=26,F[N][32],G[N][32],C[32][32],fac[32];
char s[N];

signed main(){
    C[0][0]=1,fac[0]=1;
    for(int i=1;i<32;i++){
        fac[i]=fac[i-1]*i%Mod;
        C[i][0]=1;
        for(int j=1;j<32;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
        }
    }
    scanf("%s",s+1);
    n=strlen(s+1);
    f[n+1][0]=1;
    for(int i=n;i>=1;i--){
        if(s[i]=='?'){
            f[i][0]=f[i+1][0]*26%Mod;
            f[i][1]=(f[i+1][0]*26+f[i+1][1]*26)%Mod;
            f[i][2]=(f[i+1][1]*26+f[i+1][2]*52)%Mod;
        }
        else if('A'<=s[i]&&s[i]<='Z'){
            f[i][1]=(f[i+1][0]+f[i+1][1])%Mod;
            f[i][2]=f[i+1][2];
        }
        else{
            f[i][0]=f[i+1][0];
            f[i][2]=(f[i+1][2]+f[i+1][1])%Mod;
        }
    }
    int q=0;
    F[0][0]=1;
    for(int i=0;i<=n;i++){
        if(i)for(int j=0;j<=26;j++){
            addmod(F[i][j],F[i-1][j]*26);
            addmod(F[i][j+1],F[i-1][j]);
        }
        for(int j=0;j<=26;j++){
            for(int k=0;k<=j;k++)addmod(G[i][j],F[i][k]*C[j][k]%Mod*fac[k]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int c='A';c<='Z';c++)if(s[i]==c||s[i]=='?'){
            if(vis[c]==1){
                addmod(ans,f[i+1][2]*G[q][rm]);
            }
            else if(vis[c]==0&&q){
                addmod(ans,f[i+1][2]*q%Mod*G[q-1][rm-1]);
            }
        }
        if('A'<=s[i]&&s[i]<='Z'&&vis[s[i]]==0)--rm;
        vis[s[i]]++;
        if('A'<=s[i]&&s[i]<='Z'&&vis[s[i]]>1)break;
        if(s[i]=='?')++q;
    }
    q=0;
    for(int i=1;i<=n;i++)if(s[i]=='?')++q;
    ans=(fpow(52,q)-ans+Mod)%Mod;
    _write(ans);
    return 0;
}

