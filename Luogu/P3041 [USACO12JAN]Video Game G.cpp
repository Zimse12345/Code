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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,ch[N][3],fail[N],tag[N],tot,f[N][N],ans;
char s[N];
queue<int> Q;

signed main(){
	n=read(),m=read();
    for(int i=1,len,pos;i<=n;i++){
        scanf("%s",s);
        len=strlen(s),pos=0;
        for(int j=0;j<len;j++){
            if(!ch[pos][s[j]-'A'])ch[pos][s[j]-'A']=++tot;
            pos=ch[pos][s[j]-'A'];
        }
        tag[pos]++;
    }
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<3;i++){
            if(ch[u][i]){
                if(u)fail[ch[u][i]]=ch[fail[u]][i];
                Q.push(ch[u][i]);
            }
            else ch[u][i]=ch[fail[u]][i];
        }
        tag[u]+=tag[fail[u]];
    }
    for(int j=1;j<=tot;j++)f[0][j]=-INF;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=tot;j++)f[i][j]=-INF;
        for(int j=0;j<=tot;j++){
            for(int k=0;k<3;k++)f[i][ch[j][k]]=max(f[i][ch[j][k]],f[i-1][j]+tag[ch[j][k]]);
        }
    }
    for(int i=0;i<=tot;i++)ans=max(ans,f[m][i]);
    printf("%d\n",ans);
	return 0;
}
