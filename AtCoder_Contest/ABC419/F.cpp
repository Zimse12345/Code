#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
#define int long long
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
const int N=2e4+7,Mod=998244353,INF=1e9+7;
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}
int n,m,tot,ans;
int ch[N][26],fail[N],tag[N],f[110][100][256];
char s[N];
queue<int> Q;

inline void solve() {
    n=read(),m=read();
    for(int i=0,len;i<n;i++){
        scanf("%s",s),len=strlen(s);
        int pos=0;
        for(int j=0;j<len;j++){
            if(!ch[pos][s[j]-'a'])ch[pos][s[j]-'a']=++tot;
            pos=ch[pos][s[j]-'a'];
        }
        tag[pos]=(1<<i);
    }
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<26;i++){
            if(ch[u][i]){
                if(u)fail[ch[u][i]]=ch[fail[u]][i];
                Q.push(ch[u][i]);
            }
            else ch[u][i]=ch[fail[u]][i];
        }
        tag[u]|=tag[fail[u]];
    }
    f[0][0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=tot;j++){
            for(int k=0;k<26;k++){
                for(int z=0;z<(1ll<<n);z++){
                    (f[i][ch[j][k]][z|tag[ch[j][k]]]+=f[i-1][j][z])%=Mod;
                }
            }
        }
    }
    for(int i=0;i<=tot;i++)(ans+=f[m][i][(1ll<<n)-1])%=Mod;
    printf("%lld\n",ans);
}
signed main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}
