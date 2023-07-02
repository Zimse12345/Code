// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
const double eps=1e-9;
int n,len,m,ed[N],id[N];
int ch[N][26],fail[N],tot,tg[N];
double f[1024][1024],P[N];
char s[N];
queue<int> Q;

signed main(){
    n=read(),len=read(),m=read();
    for(int i=0;i<m;i++){
        P[i]=read();
        P[i]=P[i]/double(read());
    }
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        int p=0;
        for(int j=0,c=0;j<len;j++){
            c=s[j]-'A';
            if(!ch[p][c])ch[p][c]=++tot;
            p=ch[p][c];
        }
        ed[i]=p,tg[p]=1;
    }
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int c=0;c<m;c++){
            if(ch[u][c]){
                if(u)fail[ch[u][c]]=ch[fail[u]][c];
                Q.push(ch[u][c]);
            }
            else ch[u][c]=ch[fail[u]][c];
        }
    }
    f[0][tot+1]=1.0;
    for(int i=0;i<=tot;i++){
        f[i][i]+=1.0;
        if(!tg[i])for(int c=0;c<m;c++){
            f[ch[i][c]][i]-=P[c];
        }
    }
    for(int i=0;i<=tot;i++)id[i]=i;
    for(int i=0;i<=tot;i++){
        int t=i;
        for(int j=i;j<=tot;j++)if(abs(f[j][i])>abs(f[t][i]))t=j;
        for(int j=0;j<=tot+1;j++)swap(f[i][j],f[t][j]);
        swap(id[i],id[t]);
        for(int j=1;j<=tot;j++)if(j^i){
            double v=f[j][i]/f[i][i];
            for(int k=0;k<=tot+1;k++)f[j][k]-=v*f[i][k];
        }
    }
    for(int i=1;i<=n;i++){
        int x=id[ed[i]];
        printf("%.2lf\n",f[x][tot+1]/f[x][x]);
    }
    return 0;
}

