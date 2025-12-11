#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,m,M,k,tag[N],s[N];
struct edge{
    int to,id;
    edge(int to=0,int id=0):to(to),id(id){}
};
vector<edge> g[N];

inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}

inline int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}

void dfs(int u,int from,int t){
    s[u]=t;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i].to;
        if(v==from)continue;
        dfs(v,u,t^tag[g[u][i].id]);
    }
    return;
}

vector<int> f[100];

inline void FWT_OR(vector<int>& F,int x){
    if(x==1){
        for (int o = 2, k = 1; o <= M; o <<= 1, k <<= 1)
		for (int i = 0; i < M; i += o)
			for (int j = 0; j < k; j++){
			    F[i+j+k] += F[i+j];
			    if(F[i+j+k]>=Mod)F[i+j+k]-=Mod;
            }
    }
	else{
	    for (int o = 2, k = 1; o <= M; o <<= 1, k <<= 1)
		for (int i = 0; i < M; i += o)
			for (int j = 0; j < k; j++){
			    F[i+j+k] -= F[i+j];
			    if(F[i+j+k]<0)F[i+j+k]+=Mod;
            }
    }
	return;
}

signed main(){
    n=read(),m=read(),k=read();
    M=(1ll<<m);
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        g[u].push_back(edge(v,i));
        g[v].push_back(edge(u,i));
    }
    for(int i=0,u;i<m;i++){
        u=read();
        tag[u]=(1ll<<i);
    }
    dfs(1,0,0);
    f[1].resize(M);
    for(int i=1,u,v;i<=k;i++){
        u=read(),v=read();
        ++f[1][s[u]^s[v]];
    }
    FWT_OR(f[1],1);
    for(int t=2;t<=m;t++){
        f[t]=f[t-1];
        int invt=fpow(t);
        for(int i=0;i<M;i++){
            f[t][i]=(1ll*f[t][i]*(f[1][i]-t+1+Mod))%Mod;
            if(f[t][i])f[t][i]=1ll*f[t][i]*invt%Mod;
        }
    }
    int l=1,r=m,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        FWT_OR(f[mid],-1);
        if(f[mid][M-1])ans=mid,r=mid-1;
        else l=mid+1;
    }
    if(!ans){
        printf("-1\n");
        return 0;
    }
    printf("%d %d\n",ans,f[ans][M-1]);
//    while(f[t][M-1]==0){
//        if(t>=m){
//            printf("-1\n");
//            return 0;
//        }
//        ++t;
//        if(t==2){
//            f[t]=f[t-1];
//            FWT_OR(f[t],1);
//            FWT_OR(f[1],1);
//        }
//        int invt=fpow(t);
//        for(int i=0;i<M;i++){
//            f[t][i]=(f[t][i]*(f[1][i]-t+1+Mod))%Mod;
//            if(f[t][i])(f[t][i]*=invt)%=Mod;
//        }
//        f[t+1]=f[t];
//        FWT_OR(f[t],-1);
//    }
//    printf("%lld %lld\n",t,(f[t][M-1]+Mod)%Mod);
    return 0;
}


