#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,f[4][N];
char s[N]; 

inline int fpow(long long x,int y=Mod-2)
{int z=1;while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    f[0][0]=1;
    for(int i=1,c=0;i<=n;i++){
        if(s[i]==')')--c;
        for(int u=0;u<4;u++){
            int v=u;
            if(!c)v&=1;
            (f[v][i]+=f[u][i-1]*fpow(2))%=Mod;
        }
        for(int u=0;u<4;u++){
            int v=u;
            if(s[i]=='('){
                if(u&1)continue;
                if(c)v|=2;
                (f[v][i]+=f[u][i-1]*fpow(2))%=Mod;
            }
            else{
                if((u&2)&&c)continue;
                v|=1;
                if(!c)v&=1;
                (f[v][i]+=f[u][i-1]*fpow(2))%=Mod;
            }
        }
        if(s[i]=='(')++c;
        if(c==1){
            (f[0][i]+=f[2][i])%=Mod;
            (f[1][i]+=f[3][i])%=Mod;
            f[2][i]=f[3][i]=0;
        }
    }
    int ans=(f[0][n]+f[1][n]+f[2][n]+f[3][n])%Mod;
    printf("%lld\n",ans);
    return 0;
}


