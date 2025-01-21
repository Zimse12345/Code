#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,ans[N];

void sol(int x,int y,int C){
    ans[x]=C,ans[y]=C^1;
    if(x+2==y)ans[x+1]=2;
    else if((y-x-1)&1){
        ans[x+1]=2;
        for(int i=x+2,c=1;i<y;i++,c^=1){
            ans[i]=c^C;
        }
    }
    else{
        for(int i=x+1,c=1;i<y;i++,c^=1){
            ans[i]=c^C;
        }
    }
    return;
}

signed main(){
    cin>>T;
    while(T--){
        int n,x,y;
        cin>>n>>x>>y;
        sol(x,y,0);
        sol(y,n+x,1);
        for(int i=1;i<=n;i++){
            if(i<x)printf("%d ",ans[i+n]);
            else printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}


