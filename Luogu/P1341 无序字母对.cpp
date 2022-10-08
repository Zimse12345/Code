#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,g[256][256],deg[256],ans[N],t;
char s[8];

void dfs(int u){
    for(int i=0;i<256;i++)if(g[u][i]){
        --g[u][i],--g[i][u];
        dfs(i);
    }
    ans[++t]=u;
    return;
}

signed main(){
	n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        ++g[s[0]][s[1]],++g[s[1]][s[0]];
        ++deg[s[0]],++deg[s[1]];
    }
    int s=0,c=0;
    for(int i=0;i<256;i++){
        if(deg[i]&1){
            ++c;
            if(!s)s=i;
        }
    }
    if(c>2){
        printf("No Solution\n");
        return 0;
    }
    if(!s){
        for(int i=0;i<256;i++)if(deg[i]){s=i;break;}
    }
    dfs(s);
    for(int i=t;i>=1;i--)printf("%c",ans[i]);
    printf("\n");
	return 0;
}
