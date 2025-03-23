#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int p[N],T,n,ans[N],t,vis[N]; 

signed main(){
    p[1]=1;
    for(int i=2;i<N;i++)if(!p[i]){
        for(int j=i+i;j<N;j+=i)p[j]=1;
    }
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)vis[i]=0;
        t=0;
        int x=1;
        for(int i=n/3+1;i<=n-n/3;i++)if(!p[i])x=i;
        int l=x-1,r=x+1;
        while(l>=1&&r<=n)ans[++t]=l,ans[++t]=r,vis[l]=vis[r]=1,--l,++r;
        for(int i=1;i<=n;i++)if(!vis[i])ans[++t]=i;
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}


