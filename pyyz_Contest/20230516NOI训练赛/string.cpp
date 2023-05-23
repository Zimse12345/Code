// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1.01e6,SZ=26;
int n,q,bd[N],Ans[N];
char str[N];
vector<int> g[N];
int sz[N];

struct SAM{
    int tot,pre;
    struct node{
        int to[SZ],len,link;
    }t[N];
    void init(){t[0].link=-1;return;}

    void ins(int c){
        int id=++tot,p=pre;
        t[id].len=t[p].len+1,sz[id]=1;
        while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
        if(p==-1)t[id].link=0;
        else{
            int q=t[p].to[c];
            if(t[q].len==t[p].len+1)t[id].link=q;
            else{
                int cp=++tot;
                t[cp]=t[q],t[cp].len=t[p].len+1;
                while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
                t[q].link=t[id].link=cp;
            }
        }
        pre=id;
        return;
    }
}sam;

void sub1(){
    Ans[1]=-1;
    for(int i=2;i<=n;i++){
        int pos=0;
        while(pos<n){
            pos+=i-1;
            if(pos<n)++Ans[i];
        }
    }
    while(q--){
        int l=read(),r=read();
        _write(Ans[r-l+1]);
    }
    return;
}

void sub2(){
    while(q--){
        int l=read(),r=read(),ans=0;
        if(l==r){
            _write(-1);
            continue;
        }
        bd[l]=0;
        for(int i=l+1,j=0;i<=r;i++){
            while(j&&str[l+j]!=str[i])j=bd[j];
            if(str[l+j]==str[i])++j;
            bd[i-l+1]=j;
        }
        for(int i=1,j=0;i<=n;i++){
            while(j&&str[l+j]!=str[i])j=bd[j];
            if(str[l+j]==str[i])++j;
            if(j==r-l+1)j=(str[l]==str[i]?1:0),++ans;
        }
        _write(ans);
    }
    return;
}

void dfs(int u){
    for(unsigned i=0;i<g[u].size();i++){
        dfs(g[u][i]);
        sz[u]+=sz[g[u][i]];
    }
    return;
}

signed main(){
    // ifile("string.in");
    // ofile("string.out");
    
    n=read(),q=read();
    scanf("%s",str+1);
    int tag_A=1;
    for(int i=1;i<=n;i++)if(str[i]!='a')tag_A=0;
    if(tag_A){
        sub1();
        return 0;
    }
    if(n<=30000&&q<=30000){
        sub2();
        return 0;
    }
    sam.init();
    for(int i=1;i<=n;i++)sam.ins(str[i]-'a');
    for(int i=1;i<=sam.tot;i++)g[sam.t[i].link].pb(i);
    dfs(0);
    while(q--){
        int l=read(),r=read();
        if(l==r){
            _write(-1);
            continue;
        }
        int pos=0;
        for(int i=l;i<=r;i++)pos=sam.t[pos].to[str[i]-'a'];
        _write(sz[pos]);
    }
    return 0;
}

/*
9 3
ioioioioi
1 1
1 3
1 5
*/
