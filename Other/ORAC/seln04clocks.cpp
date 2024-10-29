#include <bits/stdc++.h>
using namespace std;

int n,m;
int s[32];
vector<bool> vis;

bool dfs(int x){
    if(vis[x])return false;
    int c=0;
    for(int i=0;i<m*2;i++)if(x&(1<<i))++c;
    if(c==m*2)return true;
    c=c/2+1;
    for(int i=0;i<m*2;i++)if(!(x&(1<<i))){
        int j=i+c;
        if(j>=m*2)j=m*4-j-1;
        if(i!=j&&!(x&(1<<j))){
            s[c]=i+1;
            if(dfs(x|(1<<i)|(1<<j)))return true;
        }
    }
    vis[x]=1;
    return false;
}

signed main(){
    freopen("clockin.txt","r",stdin);
    freopen("clockout.txt","w",stdout);
    
    cin>>n;
    m=(n-1)/6;
    vis.resize(1<<(m*2));
    if(!dfs(0))printf("!\n"); 
    
    for(int i=1;i<=m;i++)printf("0 %d %d\n",i,m+i+s[i]);
    return 0;
}


