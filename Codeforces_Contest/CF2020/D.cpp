#include <bits/stdc++.h>
using namespace std;

const int N=2.01e5;
int T,n,m,f[11][N],p[N];

int Find(int x){
    if(p[x]!=x)p[x]=Find(p[x]);
    return p[x];
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int d=1;d<=10;d++){
            for(int i=1;i<=n;i++)f[d][i]=0;
        }
        while(m--){
            int a,d,k;
            cin>>a>>d>>k;
            f[d][a]++;
            f[d][a+k*d]--;
        }
        for(int i=1;i<=n;i++)p[i]=i;
        int ans=n;
        for(int d=1;d<=10;d++){
            for(int i=1;i<=n;i++){
                if(i>d)f[d][i]+=f[d][i-d];
                if(f[d][i]>0){
                    int x=Find(i),y=Find(i+d);
                    if(x!=y)p[x]=y,--ans;
                }
            }
        }
        printf("%d\n",ans);
    } 
    return 0;
}


