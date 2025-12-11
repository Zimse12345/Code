#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=512,inf=1e18;
int n,m,d[N][N],k,t,p[N],q;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(i!=j)d[i][j]=inf;
    }
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);
    }
    cin>>k>>t;
    for(int i=1;i<=k;i++){
        cin>>p[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            d[p[i]][p[j]]=min(d[p[i]][p[j]],t);
        }
    }
    for(int mid=1;mid<=n;mid++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][mid]+d[mid][j]);
            }
        }
    }
    cin>>q;
    while(q--){
        int ty=0,x=0,y=0,z=0;
        cin>>ty;
        if(ty==1){
            cin>>x>>y>>z;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    d[i][j]=min(d[i][j],min(d[i][x]+z+d[y][j],d[i][y]+z+d[x][j]));
                }
            }
        }
        else if(ty==2){
            cin>>x;
            for(int i=1;i<=k;i++){
                d[x][p[i]]=min(d[x][p[i]],t);
                d[p[i]][x]=min(d[p[i]][x],t);
            }
            p[++k]=x;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    d[i][j]=min(d[i][j],d[i][x]+d[x][j]);
                    d[i][x]=min(d[i][x],d[i][j]+d[j][x]);
                    d[x][i]=min(d[x][i],d[x][j]+d[j][i]);
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    d[i][j]=min(d[i][j],d[i][x]+d[x][j]);
                    d[i][x]=min(d[i][x],d[i][j]+d[j][x]);
                    d[x][i]=min(d[x][i],d[x][j]+d[j][i]);
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    d[i][j]=min(d[i][j],d[i][x]+d[x][j]);
                    d[i][x]=min(d[i][x],d[i][j]+d[j][x]);
                    d[x][i]=min(d[x][i],d[x][j]+d[j][i]);
                }
            }
        }
        else{
            int s=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(d[i][j]<inf)s+=d[i][j];
                }
            }
            printf("%lld\n",s);
        }
    }
    return 0;
}


