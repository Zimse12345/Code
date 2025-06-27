#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,g[N],cnt,vis[N],T,in[N];
char s[N],t[N];

signed main(){
    cin>>n;
    scanf("%s%s",s+1,t+1);
    for(int i=1;i<=n;i++){
        int x=s[i]-'a'+1,y=t[i]-'a'+1;
        if(!g[x])g[x]=y,++in[y];
        if(g[x]!=y){
            printf("-1\n");
            return 0;
        }
    }
    int ring=0,tag=0;
    for(int i=1;i<=26;i++){
        if(g[i]){
            if(g[i]!=i)++cnt;
            int x=i;
            ++T;
            while(!vis[x])vis[x]=T,x=g[x];
            if(vis[x]==T&&x&&g[x]!=x){
                int X=x,ttag=0;
                while(1){
                    if(in[x]>1)ttag=1;
                    x=g[x];
                    if(x==X)break;
                }
                if(ttag){
                    tag=1;
                }
                else ++ring;
            }
            if(x!=i)tag=1;
        }
        else tag=1;
    }
    if(ring&&!tag){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",cnt+ring);
    return 0;
}


