#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

#define int long long

using namespace std;

inline int read(){
    int x=0,y=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')y=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
    return x*y;
}

const int N=10007,Mod=998244353;
int n,S2[N][N],ans,fac[N];

inline void addmod(int &x,int y){
    (x+=y)%=Mod;
    return;
}

inline int f(int x,int y){
    return S2[n][x]*S2[n][y]%Mod*fac[x]%Mod*fac[y]%Mod;
}

signed main(){
    // freopen("cover.in","r",stdin);
    // freopen("cover.out","w",stdout);
    
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
    n=read();
    S2[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)S2[i][j]=(S2[i-1][j-1]+S2[i-1][j]*j)%Mod;
    }
    for(int i=1;i<=n;i++){
        addmod(ans,2*f(i,i));
        if(i>1)addmod(ans,f(i,i-1));
        if(i<n)addmod(ans,f(i,i+1));
    }
    printf("%lld\n",ans);
    return 0;
}


