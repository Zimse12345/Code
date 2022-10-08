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

const int N=2e4+7,Mod=1e4+7,INF=1e9+7;
int n,m,tot,ans;
int ch[N][26],fail[N],tag[N],f[200][N][2];
char s[N];
queue<int> Q;

signed main(){
	n=read(),m=read();
    for(int i=1,len;i<=n;i++){
        scanf("%s",s),len=strlen(s);
        int pos=0;
        for(int j=0;j<len;j++){
            if(!ch[pos][s[j]-'A'])ch[pos][s[j]-'A']=++tot;
            pos=ch[pos][s[j]-'A'];
        }
        tag[pos]=1;
    }
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<26;i++){
            if(ch[u][i]){
                if(u)fail[ch[u][i]]=ch[fail[u]][i];
                Q.push(ch[u][i]),tag[ch[u][i]]|=tag[ch[fail[u]][i]];
            }
            else ch[u][i]=ch[fail[u]][i];
        }
    }
    f[0][0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=tot;j++){
            for(int k=0;k<26;k++){
                (f[i][ch[j][k]][1]+=f[i-1][j][1])%=Mod;
                if(tag[ch[j][k]])(f[i][ch[j][k]][1]+=f[i-1][j][0])%=Mod;
                else (f[i][ch[j][k]][0]+=f[i-1][j][0])%=Mod;
            }
        }
    }
    for(int i=0;i<=tot;i++)(ans+=f[m][i][1])%=Mod;
    printf("%d\n",ans);
	return 0;
}
