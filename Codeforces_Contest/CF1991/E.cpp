#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,col[N],l[N],r[N],lcnt,rcnt;
vector<int> g[N];

bool dfs(int u,int c){
    col[u]=c;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!col[v]){
            if(!dfs(v,3-c))return false;
        }
        else if(col[v]==c)return false;
    }
    return true;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)g[i].resize(0),col[i]=0;
        for(int i=1,u,v;i<=m;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(!dfs(1,1)){
            printf("Alice\n");
            fflush(stdout);
            for(int i=1,x,y;i<=n;i++){
                printf("1 2\n");
                fflush(stdout);
                cin>>x>>y;
            }
        }
        else{
            printf("Bob\n");
            fflush(stdout);
            lcnt=rcnt=0;
            for(int i=1;i<=n;i++){
                if(col[i]==1)l[++lcnt]=i;
                else r[++rcnt]=i;
            }
            for(int i=1,x,y;i<=n;i++){
                cin>>x>>y;
                int pos=0,c=0;
                if((x==1||y==1)&&lcnt)pos=l[lcnt--],c=1;
                else if((x==2||y==2)&&rcnt)pos=r[rcnt--],c=2;
                else{
                    if(lcnt)pos=l[lcnt--];
                    else pos=r[rcnt--];
                    c=3;
                }
                printf("%d %d\n",pos,c);
                fflush(stdout);
            }
        }
    }
    return 0;
}


