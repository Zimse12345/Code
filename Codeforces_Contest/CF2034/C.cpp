#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int T,n,m,tag[N][N],vis[N][N];
char s[N][N];

int dfs(int x,int y,int t=0){
    if(t&&s[x][y]=='?')return 0;
    if(vis[x][y])return tag[x][y];
    vis[x][y]=1;
    if(tag[x][y])return 1;
    int res=1;
    if(s[x][y]=='?'){
        if(s[x-1][y]=='?'||s[x+1][y]=='?'||s[x][y-1]=='?'||s[x][y+1]=='?'){
            tag[x][y]=0;
            return 0;
        }
    }
    if(s[x][y]=='L'||s[x][y]=='?')res&=dfs(x,y-1,1);
    if(s[x][y]=='R'||s[x][y]=='?')res&=dfs(x,y+1,1);
    if(s[x][y]=='U'||s[x][y]=='?')res&=dfs(x-1,y,1);
    if(s[x][y]=='D'||s[x][y]=='?')res&=dfs(x+1,y,1);
    tag[x][y]=res;
    return res;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
            s[i][m+1]=' ';
        }
        for(int i=0;i<=m+1;i++)s[0][i]=s[n+1][i]=' ';
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                if(i==0||i==n+1||j==0||j==m+1)tag[i][j]=1;
                else tag[i][j]=0;
                vis[i][j]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!vis[i][j])dfs(i,j);
                if(!tag[i][j])++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


