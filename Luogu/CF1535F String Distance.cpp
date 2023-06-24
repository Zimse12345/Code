// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
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

const int N=2.01e5;
int n,Len,ch[N][26],tot,ed[N],_n,lcp[N];
vector<char> s[N],S[N];
char _s[N];
long long ans[4];

struct str{
    int cnt[26],id;
    bool operator < (const str &_)const{
        for(int i=0;i<26;i++){
            if(cnt[i]<_.cnt[i])return true;
            if(cnt[i]>_.cnt[i])return false;
        }
        return false;
    }
}a[N];

void dfs(int p,int cur){
    if(cur==Len){
        ++_n,S[_n].resize(0);
        for(int i=0;i<Len;i++)S[_n].pb(_s[i]);
        return;
    }
    for(int i=0;i<26;i++)if(ch[p][i]){
        _s[cur]=i,dfs(ch[p][i],cur+1);
    }
    return;
}

void sol(int l,int r){
    for(int i=l;i<=r;i++){
        int p=0;
        for(int j=0,c;j<Len;j++){
            c=s[a[i].id][j];
            if(!ch[p][c])ch[p][c]=++tot;
            p=ch[p][c];
        }
        ++ed[p];
    }
    _n=0,dfs(0,0);

    for(int i=1;i<_n;i++){
        lcp[i]=0;
        while(lcp[i]<Len&&S[i][lcp[i]]==S[i+1][lcp[i]])++lcp[i];
    }
    for(int i=1;i<=_n;i++){
        int Lcp=n;
        for(int j=i+1;j<=_n;j++){
            _min(Lcp,lcp[j-1]);
            if(Lcp==n)++ans[0];
            else{
                int p=Lcp,tag=1;
                while(p+1<n&&S[i][p]<=S[i][p+1])++p;
                for(int k=p+1;k<Len;k++)if(S[i][k]!=S[j][k]){
                    tag=0;
                    break;
                }
                if(tag)++ans[1];
                else ++ans[2];
            }
        }
    }

    for(int i=0;i<=tot;i++){
        for(int j=0;j<26;j++)ch[i][j]=0;
        ed[i]=0;
    }
    tot=0;
    return;
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",_s);
        Len=strlen(_s),a[i].id=i;
        for(int j=0,c;j<Len;j++){
            c=_s[j]-'a';
            s[i].pb(c),++a[i].cnt[c];
        }
    }
    sort(a+1,a+n+1);
    for(int l=1,r;l<=n;){
        r=l;
        while(r<n&&!(a[r]<a[r+1]||a[r+1]<a[r]))++r;
        sol(l,r);
        l=r+1;
    }
    ans[3]=1ll*n*(n-1)/2-ans[0]-ans[1]-ans[2];
    printf("%lld\n",ans[1]+ans[2]*2+ans[3]*1337);
    return 0;
}

