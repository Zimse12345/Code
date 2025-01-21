#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m1,m2,f[2][N],U[N],V[N],ans;

int F(int id,int x){
    if(f[id][x]!=x)f[id][x]=F(id,f[id][x]);
    return f[id][x];
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m1>>m2;
        ans=0;
        for(int i=1;i<=n;i++)f[0][i]=f[1][i]=i;
        for(int i=1;i<=m1;i++)cin>>U[i]>>V[i];
        for(int i=1,u,v;i<=m2;i++){
            cin>>u>>v;
            u=F(1,u),v=F(1,v);
            if(u!=v)f[1][v]=u;
        }
        for(int i=1,u,v;i<=m1;i++){
            u=F(1,U[i]),v=F(1,V[i]);
            if(u!=v)++ans;
            else{
                u=F(0,U[i]),v=F(0,V[i]);
                if(u!=v)f[0][v]=u;
            }
        }
        for(int i=1;i<=n;i++){
            int u=i,v=F(1,i);
            u=F(0,u),v=F(0,v);
            if(u!=v)f[0][v]=u,++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}


