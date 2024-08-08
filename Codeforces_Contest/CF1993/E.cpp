#include <bits/stdc++.h>
using namespace std;

const int N=32;
int T,n,m,a[N][N],v[N][N],R[N],C[N],A;
int t[N][N];
long long f[65536][N];
vector<int> vec[65536];
long long inf=1000000000000000000;

inline int _abs(int x){
    return x<0?-x:x;
}

signed main(){
    cin>>T;
    for(int i=0;i<(1<<15);i++){
        for(int j=0;j<15;j++)if(i&(1<<j))vec[i].push_back(j);
    }
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)R[i]=0;
        for(int i=1;i<=m;i++)C[i]=0;
        A=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                R[i]^=a[i][j];
                C[j]^=a[i][j];
                A^=a[i][j];
            }
        }
        long long ans=inf;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int x=1;x<=n;x++){
                    for(int y=1;y<=m;y++){
                        v[x][y]=a[x][y];
                        if(x==i)v[x][y]=C[y];
                        if(y==j)v[x][y]=R[x];
                    }
                }
                v[i][j]=A;
                
                for(int x=1;x<=n;x++){
                    for(int y=x+1;y<=n;y++){
                        t[x-1][y-1]=0;
                        for(int p=1;p<=m;p++)t[x-1][y-1]+=_abs(v[x][p]-v[y][p]);
                        t[y-1][x-1]=t[x-1][y-1];
                    }
                }
                unsigned M=(1<<n);
                for(unsigned z=1;z<M;z++){
                    for(unsigned x=0;x<vec[z].size();x++)f[z][x]=inf;
                }
                for(int x=0;x<n;x++)f[1<<x][0]=0;
                for(unsigned z=1;z<M;z++){
                    for(unsigned x=0;x<vec[z].size();x++){
                        unsigned Z=z^(1<<vec[z][x]);
                        for(unsigned y=0;y<vec[Z].size();y++)f[z][x]=min(f[z][x],f[Z][y]+t[vec[z][x]][vec[Z][y]]);
                    }
                }
                long long sum=0,mn=inf;
                for(int x=0;x<n;x++)mn=min(mn,f[(1<<n)-1][x]);
                sum+=mn;
                
                for(int x=1;x<=m;x++){
                    for(int y=x+1;y<=m;y++){
                        t[x-1][y-1]=0;
                        for(int p=1;p<=n;p++)t[x-1][y-1]+=_abs(v[p][x]-v[p][y]);
                        t[y-1][x-1]=t[x-1][y-1];
                    }
                }
                M=(1<<m);
                for(unsigned z=1;z<M;z++){
                    for(unsigned x=0;x<vec[z].size();x++)f[z][x]=inf;
                }
                for(int x=0;x<m;x++)f[1<<x][0]=0;
                for(unsigned z=1;z<M;z++){
                    for(unsigned x=0;x<vec[z].size();x++){
                        unsigned Z=z^(1<<vec[z][x]);
                        for(unsigned y=0;y<vec[Z].size();y++)f[z][x]=min(f[z][x],f[Z][y]+t[vec[z][x]][vec[Z][y]]);
                    }
                }
                mn=inf;
                for(int x=0;x<m;x++)mn=min(mn,f[(1<<m)-1][x]);
                sum+=mn;
                ans=min(ans,sum);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}



