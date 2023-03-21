/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <bitset>

#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=40007,SZ=26;

int T,n,k;
char str[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{
        if(y-x+1==_.y-_.x+1){
            for(int i=0;i<y-x+1;i++){
                if(str[x+i]<str[_.x+i])return true;
                if(str[x+i]>str[_.x+i])return false;
            }
            return true;
        }
        return y-x+1<_.y-_.x+1;
    }
};
vector<node> ans,_ans;

struct SAM{
    int tot,pre,f[N];
    vector<int> g[N];
    struct nd{
        int to[SZ],len,link,ed;
        bitset<N/2> s;
    }t[N];

    void init(){
        for(int i=0;i<=tot;i++)g[i].resize(0),f[i]=0;
        memset(t,0,sizeof (nd)*(tot+1));
        t[0].link=-1,tot=pre=0;
        return;
    }

    void ins(int c,int pos){
        int id=++tot,p=pre;
        t[id].len=t[p].len+1,t[id].s[pos]=1,t[id].ed=pos;
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

    void build(){
        for(int i=1;i<=tot;i++){
            g[t[i].link].pb(i);
        }
        return;
    }

    inline int calc(const bitset<N/2>& s,const int& lim){
        int pre=0,res=0;
        while(1){
            int x=s._Find_next(pre);
            if(x>n)break;
            int l=max(pre,x-lim)+1;
            res+=x-l+1,pre=x;
            if(res>k)return res;
        }
        return res;
    }

    void dfs(int u,int from){
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i];
            dfs(v,u),t[u].s|=t[v].s;
        }
        if(u){
            int L=t[t[u].link].len+1,R=t[u].len,res=0;
            for(unsigned i=0;i<g[u].size();i++)if(f[g[u][i]])_min(R,f[g[u][i]]);
            if(R-L+1<=12){
            	while(R>=L&&calc(t[u].s,R)>=k)res=R,--R;
            }
            else{
                while(L<=R){
                	int M=(L+R)/2;
                	if(calc(t[u].s,M)>=k)res=M,R=M-1;
                	else L=M+1;
            	}
            }
            if(res&&calc(t[u].s,res)==k)ans.pb(node(t[u].ed-res+1,t[u].ed));
            f[u]=res;
        }
        return;
    }
}sam;

signed main(){
    // ifile("two.in");
    // ofile("two.out");

    T=read();
    while(T--){
        scanf("%s",str+1),n=strlen(str+1);
        k=read();
        sam.init();
        for(int i=1;i<=n;i++)sam.ins(str[i]-'a',i);
        sam.build();
        sam.dfs(0,-1);
        if(!ans.size()){
            printf("NOTFOUND!\n");
            continue;
        }
        sort(ans.begin(),ans.end());
        for(int i=ans[0].x;i<=ans[0].y;i++)pc(str[i]);
        pc(10);
        ans.resize(0);
    }
    return 0;
}
