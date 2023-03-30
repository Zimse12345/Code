/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
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

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
#define int __int128
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000000000000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int T,n,m,q,hd[N],nxt[N],to[N],len[N],ec;
int dis[1024][1024],mx[N],mxb[N],stk[N],top,ans;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){} 
    bool operator < (const node& _)const{
    	if(y==_.y)return x<_.x;
		return y<_.y;
	}
};
vector<node> p;

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

int rpos(int x,int y){
    int L=0,R=INF,res=-1;
    while(L<=R){
        int M=(L+R)/2;
        if(p[x].x+M*p[x].y>=p[y].x+M*p[y].y)res=M,L=M+1;
        else R=M-1;
    }
    return res;
}

int calc(int l,int r,int x){
	l=max(l,n+1);
	if(r<l)return 0;
    return ((l+r)*p[x].y+p[x].x*2)*(r-l+1)/2;
}

signed main(){
    // ifile("wool.in");
    // ofile("wool.out");

    T=read();
    while(T--){
        n=read(),m=read(),q=read(),ans=0;
        for(int i=1;i<=n;i++)mx[i]=0,mxb[i]=-INF;
        p.resize(0);
        for(int i=1,u,v,w;i<=m;i++){
            u=read(),v=read(),w=read();
            add(u,v,w),add(v,u,w);
            _max(mx[u],w),_max(mx[v],w);
        }
        dis[0][1]=0,mxb[1]=0;
        for(int i=2;i<=n;i++)dis[0][i]=-INF;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)dis[i][j]=-INF;
            for(int j=1;j<=n;j++){
                for(int k=hd[j];k;k=nxt[k]){
                    _max(dis[i][to[k]],dis[i-1][j]+len[k]);
                }
            }
            int mxd=0;
            for(int j=1;j<=n;j++){
            	_max(mxb[j],dis[i][j]-i*mx[j]);
            	_max(mxd,dis[i][j]);
        	}
        	if(i<=q)addmod(ans,mxd);
		}
        for(int i=1;i<=n;i++)if(mxb[i]>-INF)p.pb(node(mxb[i],mx[i]));
        sort(p.begin(),p.end()),top=0;
        for(unsigned i=0;i<p.size();i++){
        	if(i+1<p.size()&&p[i].y==p[i+1].y)continue;
            while(top>1&&rpos(stk[top-1],stk[top])>rpos(stk[top],i))--top;
            stk[++top]=i;
        }
        int pre=0;
        for(int i=1;i<top;i++){
            int r=rpos(stk[i],stk[i+1]);
            _min(r,q);
            addmod(ans,calc(pre+1,r,stk[i]));
            pre=r;
        }
        if(pre<q)addmod(ans,calc(pre+1,q,stk[top]));
        _write(ans);
        for(int i=1;i<=n;i++)hd[i]=0;
        ec=0;
    }
    return 0;
}
