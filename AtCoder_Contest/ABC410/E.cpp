#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,H,M,ans,f[N],g[N];

signed main(){
    cin>>n>>H>>M;
    for(int i=0;i<H;i++)f[i]=-1;
    f[H]=M;
    for(int i=1,a,b;i<=n;i++){
        cin>>a>>b;
        for(int x=0;x<=H;x++)g[x]=-1;
        int tag=0;
        for(int x=0,y;x<=H;x++)if(f[x]!=-1){
            y=f[x];
            if(x>=a)g[x-a]=max(g[x-a],y),tag=1;
            if(y>=b)g[x]=max(g[x],y-b),tag=1;
        }
        for(int x=0;x<=H;x++)f[x]=g[x];
        if(!tag)break;
        ++ans;
    }
    printf("%d\n",ans);
    return 0;
}


