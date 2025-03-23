#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],vis[N];

int query(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int res=0;
    cin>>res;
    return res;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int ans=1;
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=n;i++)cin>>a[i],vis[a[i]]=i;
        if(!vis[1]){
            if(query(1,n)==0)ans=0;
        }
        else if(!vis[n]){
            if(query(n,1)==0)ans=0;
        }
        else{
            int x=query(vis[1],vis[n]),y=query(vis[n],vis[1]);
            if(x==y&&x>=n-1&&y>=n-1)ans=1;
            else ans=0;
        }
        if(ans){
            printf("! B\n");
        }
        else{
            printf("! A\n");
        }
        fflush(stdout);
    }
    return 0;
}


