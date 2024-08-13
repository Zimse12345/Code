#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,a[N],U[N],V[N],f[N];
vector<int> p[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0;i<=n;i++)a[i]=0,p[i].resize(0);
        for(int i=1;i<=m;i++){
            cin>>U[i]>>V[i];
            p[V[i]].push_back(U[i]);
        }
        for(int i=2;i<=n;i++){
            f[i]=f[i-1]+1;
            for(unsigned j=0;j<p[i].size();j++)f[i]=min(f[i],f[p[i][j]]+1);
        }
        for(int i=1,u,v;i<=m;i++){
            u=U[i],v=V[i];
            if(v-(f[u]+1)>u)++a[u+1],--a[v-(f[u]+1)];
        }
        for(int i=1;i<n;i++){
            a[i]+=a[i-1];
            if(a[i])printf("0");
            else printf("1");
        }
        printf("\n");
    }
    return 0;
}


