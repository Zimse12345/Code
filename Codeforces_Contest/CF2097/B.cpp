#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2.01e6,M=1024,Mod=1000000007;
int T,n,m,k,x[N],y[N],c[M][M],vis[N],f[N][2];

inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

struct edge{
    int v,id;
    edge(int v=0,int id=0):v(v),id(id){}
};
vector<edge> g[N];

int _abs(int X){
    return X<0?-X:X;
}

int id(int X,int Y){
    return X*(m+1)+Y;
}

void dfs(int u){
    for(unsigned i=0;i<g[u].size();i++){
        if(vis[g[u][i].id]++)continue;
        ++c[g[u][i].v/(m+1)][g[u][i].v%(m+1)];
        dfs(g[u][i].v);
    }
    return;
}

int Tag;
void dfs2(int u,int from){
    if(c[u/(m+1)][u%(m+1)]){
        Tag++;
        return;
    }
    c[u/(m+1)][u%(m+1)]=1;
    f[u][0]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(g[u][i].id==from)continue;
        dfs2(v,g[u][i].id);
        (f[u][0]*=f[v][0])%=Mod;
    }
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(g[u][i].id==from)continue;
        (f[u][1]+=f[u][0]*fpow(f[v][0])%Mod*(f[v][0]+f[v][1]))%=Mod;
    }
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        int ans=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                c[i][j]=0;
                g[id(i,j)].resize(0);
                f[id(i,j)][0]=f[id(i,j)][1]=0;
            }
        }
        for(int i=1;i<=k+1;i++){
            cin>>x[i]>>y[i];
            if(i>1){
                if(_abs(x[i]-x[i-1])+_abs(y[i]-y[i-1])!=2)ans=0;
                if(x[i]==x[i-1]){
                    c[x[i]][(y[i]+y[i-1])/2]++;
                }
                else if(y[i]==y[i-1]){
                    c[(x[i]+x[i-1])/2][y[i]]++;
                }
                else{
                    g[id(x[i],y[i-1])].push_back(edge(id(x[i-1],y[i]),i));
                    g[id(x[i-1],y[i])].push_back(edge(id(x[i],y[i-1]),i));
                    vis[i]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(c[i][j])dfs(id(i,j));
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(c[i][j]>1)ans=0;
                if(!c[i][j]){
                    if(g[id(i,j)].size()){
                        Tag=0;
                        dfs2(id(i,j),0);
                        if(Tag>2)ans=0;
                        else if(Tag)(ans*=2)%=Mod;
                        else (ans*=(f[id(i,j)][0]+f[id(i,j)][1]))%=Mod;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}


