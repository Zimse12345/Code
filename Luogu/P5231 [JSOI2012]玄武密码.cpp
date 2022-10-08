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

const int N=1e7+7,Mod=998244353,INF=1e9+7;
int n,m,to[N][4],fail[N],mp[256],tot,tag[N];
char s[N],t[100010][110];
queue<int> Q;

signed main(){
    mp['N']=0,mp['S']=1,mp['W']=2,mp['E']=3;
    n=read(),m=read();
    scanf("%s",s+1);
    for(int i=1;i<=m;i++){
        scanf("%s",t[i]+1);
        int len=strlen(t[i]+1),pos=0;
        for(int j=1,x=0;j<=len;j++){
            x=mp[t[i][j]];
            if(!to[pos][x])to[pos][x]=++tot;
            pos=to[pos][x];
        }
    }
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int i=0;i<4;i++){
            if(to[u][i]){
                if(u)fail[to[u][i]]=to[fail[u]][i];
                Q.push(to[u][i]);
            }
            else to[u][i]=to[fail[u]][i];
        }
    }
    for(int i=1,p=0,x;i<=n;i++){
        p=to[p][mp[s[i]]],x=p;
        while(!tag[x])tag[x]=1,x=fail[x];
    }
    for(int i=1;i<=m;i++){
        int ans=0,pos=0,len=strlen(t[i]+1);
        for(int j=1,x=0;j<=len;j++){
            pos=to[pos][mp[t[i][j]]];
            if(tag[pos])ans=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
