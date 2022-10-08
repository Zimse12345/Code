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

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,b=41,mod=1e9+7;
char s[N],t[N];
int n,m,q,pos[N],tot,B[N],sh[N],th[N],mp[1024];
bool f[200000][16],g[200000][16];

inline bool Cmp(int l1,int r1,int l2,int r2){
    if(r1<l1)return true;
    if(l1<1||l2<1||r1>m||r2>n)return false;
    return ((th[r1]-th[l1-1]*B[r1-l1+1])%mod+mod)%mod==((sh[r2]-sh[l2-1]*B[r2-l2+1])%mod+mod)%mod;
}

signed main(){
    for(int i=0;i<26;i++)mp[i+'a']=i+1;
    B[0]=1;
    for(int i=1;i<N;i++)B[i]=(B[i-1]*b)%mod;
	scanf("%s",s+1);
    n=strlen(s+1);
    s[++n]='?';
    for(int i=1;i<=n;i++)sh[i]=(sh[i-1]*b+mp[s[i]])%mod;
    for(int i=1;i<=n;i++)if(s[i]=='*'||s[i]=='?')pos[++tot]=i;
    q=read();
    while(q--){
        scanf("%s",t+1);
        m=strlen(t+1);
        for(int i=1;i<=m;i++)th[i]=(th[i-1]*b+mp[t[i]])%mod;
        if(!Cmp(1,pos[1]-1,1,pos[1]-1)){
            printf("NO\n");
            continue;
        }
        f[pos[1]-1][1]=1,g[0][1]=f[0][1];
        for(int j=1;j<=m;j++)g[j][1]=(g[j-1][1]|f[j][1]);
        for(int i=2;i<=tot;i++){
            int d=pos[i]-pos[i-1]-1;
            for(int j=0;j<=m;j++){
                if(Cmp(j-d+1,j,pos[i-1]+1,pos[i]-1)){
                    if(s[pos[i-1]]=='?'){if(j-d-1>=0)f[j][i]|=f[j-d-1][i-1];}
                    else f[j][i]|=g[j-d][i-1];
                }
            }
            g[0][i]=f[0][i];
            for(int j=1;j<=m;j++)g[j][i]=(g[j-1][i]|f[j][i]);
        }
        int ans=f[m][tot];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=tot;j++){
                f[i][j]=g[i][j]=0;
            }
        }
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}