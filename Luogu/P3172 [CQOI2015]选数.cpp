#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=1e9+7,INF=1e9+7;
int n,K,L,R,prime[N],pr[N],tot,mu[N],ans,premu[N];
map<int,int> PreMu;
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}

int sum_mu(int x){
    if(x<N)return premu[x];
    if(PreMu[x])return PreMu[x];
    int res=1;
    for(int l=2,r;l<=x;){
        r=x/(x/l);
        res-=sum_mu(x/l)*(r-l+1);
        res%=Mod;
        l=r+1;
    }
    PreMu[x]=res;
    return res;
}

signed main(){
    mu[1]=1;
    for(int i=2;i<N;i++){
        if(!pr[i])pr[i]=i,prime[++tot]=i,mu[i]=-1;
        for(int j=1;j<=tot&&prime[j]*i<N;j++){
            pr[prime[j]*i]=prime[j],mu[prime[j]*i]=-mu[i];
            if(pr[i]==prime[j]){mu[prime[j]*i]=0;break;}
        }
    }
    for(int i=1;i<N;i++)premu[i]=premu[i-1]+mu[i];
    n=read(),K=read(),L=read(),R=read();
    L=(L-1)/K,R=R/K;
    for(int l=1,r;l<=R;){
        if(l<=L)r=min(L/(L/l),R/(R/l));
        else r=R/(R/l);
        ans=(ans+(sum_mu(r)-sum_mu(l-1))*qp(R/l-L/l,n))%Mod;
        l=r+1;
    }
    ans=(ans+Mod)%Mod;
    printf("%lld\n",ans);
    return 0;
}
