#include <bits/stdc++.h>
using namespace std;

const int N=16;
int n,m,k,ans;
char s[N][N];

void dfs(int x,int y,int z){
    if(z==0){
        ++ans;
        return;
    }
    s[x][y]='#';
    if(x>0&&s[x-1][y]=='.')dfs(x-1,y,z-1);
    if(x+1<n&&s[x+1][y]=='.')dfs(x+1,y,z-1);
    if(y>0&&s[x][y-1]=='.')dfs(x,y-1,z-1);
    if(y+1<m&&s[x][y+1]=='.')dfs(x,y+1,z-1);
    s[x][y]='.';
    return;
}

signed main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if(s[i][j]=='.')dfs(i,j,k);
    }
    printf("%d\n",ans);
    return 0;
}


