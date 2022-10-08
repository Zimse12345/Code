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

const int N=2e4+7,Mod=1e9+7,INF=1e9+7;
int Len,m,ch[N][26],fail[N],tot,tag[N];
char n[N],s[N];
int f[2000][2000][2],ans;
queue<int> Q;

signed main(){
	scanf("%s",n+1),Len=strlen(n+1);
    for(int i=1;i<=Len;i++)n[i]-='0';
    m=read();
    for(int i=1,len,pos;i<=m;i++){
        scanf("%s",s);
        len=strlen(s),pos=0;
        for(int j=0;j<len;j++){
            if(!ch[pos][s[j]-'0'])ch[pos][s[j]-'0']=++tot;
            pos=ch[pos][s[j]-'0'];
        }
        tag[pos]=1;
    }
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<10;i++){
            if(ch[u][i]){
                if(u)fail[ch[u][i]]=ch[fail[u]][i];
                Q.push(ch[u][i]);
            }
            else ch[u][i]=ch[fail[u]][i];
        }
        tag[u]|=tag[fail[u]];
    }
    for(int i=1;i<=Len;i++){
        for(int k=1;k<=(i==1?n[1]:9);k++)if(!tag[ch[0][k]]){
            if(i==1&&k==n[1])f[i][ch[0][k]][0]++;
            else f[i][ch[0][k]][1]++;
        }
        for(int j=0;j<=tot;j++){
            for(int k=0;k<10;k++)if(!tag[ch[j][k]]){
                (f[i][ch[j][k]][1]+=f[i-1][j][1])%=Mod;
                if(k<n[i])(f[i][ch[j][k]][1]+=f[i-1][j][0])%=Mod;
                else if(k==n[i])(f[i][ch[j][k]][0]+=f[i-1][j][0])%=Mod;
            }
        }
    }
    for(int j=0;j<=tot;j++){
        (ans+=f[Len][j][0])%=Mod;
        (ans+=f[Len][j][1])%=Mod;
    }
    printf("%d\n",ans);
	return 0;
}
