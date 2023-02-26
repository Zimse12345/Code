/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

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
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define pb push_back
#define ll long long
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
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

const int N=1024;

int n,m,tag[N][N],tot;
char str[N][N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
}p[N*N];
bool vis_[N*2][N*2];
queue<node> q;

signed main(){
//	ifile("t.in");
    n=read(),m=read();
    for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str[i][j]=='o'){
                if(str[i+1][j]=='o'&&str[i-1][j]=='o'&&str[i][j+1]=='o'&&str[i][j-1]=='o'){
                    tag[i][j]=1;
                }
            }
        }
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++)if(i==0||i==n+1||j==0||j==m+1)str[i][j]='#';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)if(str[i][j]=='o'){
        	if(!tag[i][j])p[++tot]=node(i,j);
		}
    }
    q.push(node(0,0));
    while(!q.empty()){
        int x=q.front().x,y=q.front().y;
        q.pop();
        if(vis_[x+N][y+N]==1)continue;
        vis_[x+N][y+N]=1;
        int U=1,D=1,L=1,R=1;
        for(int i=1;i<=tot;i++){
            tag[p[i].x+x][p[i].y+y]=1;
            if(str[p[i].x+x-1][p[i].y+y]=='#')U=0;
            if(str[p[i].x+x+1][p[i].y+y]=='#')D=0;
            if(str[p[i].x+x][p[i].y+y-1]=='#')L=0;
            if(str[p[i].x+x][p[i].y+y+1]=='#')R=0;
        }
        if(U)q.push(node(x-1,y));
        if(D)q.push(node(x+1,y));
        if(L)q.push(node(x,y-1));
        if(R)q.push(node(x,y+1));
    }
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans+=tag[i][j];
    _write(ans);
    return 0;
}
