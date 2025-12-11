#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,k,t[N],tt[N];
char s[N];
vector<int> g[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            if(s[i]=='B')t[i]=1;
            else t[i]=0;
        }
        for(int i=1,u,v;i<=m;i++){
            cin>>u>>v;
            g[u].push_back(v);
        }
        while(k--){
            for(int i=1;i<=n;i++){
                tt[i]=1;
                for(unsigned j=0;j<g[i].size();j++){
                    if(t[g[i][j]])tt[i]=0;
                }
            }
            for(int i=1;i<=n;i++){
                t[i]=1;
                for(unsigned j=0;j<g[i].size();j++){
                    if(tt[g[i][j]])t[i]=0;
                }
            }
        }
        if(!t[1])printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}


