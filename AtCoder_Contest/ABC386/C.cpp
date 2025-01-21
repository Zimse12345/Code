#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int k,n,m;
char s[N],t[N];
map<int,bool> f,vis;

bool dfs(int x,int y,int z){
    if(z<0)return false;
    if(x>n&&y>m)return true;
    if(x>n&&m-y+1<=z)return true;
    if(y>m&&n-x+1<=z)return true;
    int v=x+y*(n+1)+z*(n+1)*(m+1);
    if(vis[v])return f[v];
    vis[v]=1;
    
    if(s[x]==t[y])f[v]|=dfs(x+1,y+1,z);
    else f[v]|=dfs(x+1,y+1,z-1);
    f[v]|=dfs(x+1,y,z-1);
    f[v]|=dfs(x,y+1,z-1);
    return f[v];
}

signed main(){
    cin>>k;
    scanf("%s",s+1);
    scanf("%s",t+1);
    n=strlen(s+1);
    m=strlen(t+1);
    if(dfs(1,1,k))printf("Yes\n");
    else printf("No\n");
    return 0;
}


