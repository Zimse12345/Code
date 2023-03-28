/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-26
*Description:
*Other:
********************************/

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
#define ll long long
#define int long long
#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
//const int Mod=998244353;
const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

int n,X[N],Y[N],ans;

vector<int> px[N],py[N],dx[N],dy[N];

signed main(){
//     ifile("triangles.in");
//     ofile("triangles.out");
    n=read();
    for(int i=1;i<=n;i++){
        X[i]=read()+10000,Y[i]=read()+10000;
        px[X[i]].push_back(Y[i]);
        py[Y[i]].push_back(X[i]);
    }
    for(int i=0;i<=20001;i++){
        sort(px[i].begin(),px[i].end());
        int sz=px[i].size();
        for(int j=0,s=0;j<sz;j++){
            if(j)s+=j*(px[i][j]-px[i][j-1]);
            dx[i].push_back(s);
        }
        for(int j=sz-1,s=0;j>=0;j--){
            if(j!=sz-1)s+=(sz-1-j)*(px[i][j+1]-px[i][j]);
            dx[i][j]+=s;
            // printf("dx[%d][%d]=%d p=%d\n",i,j,dx[i][j],px[i][j]);
        }
        sort(py[i].begin(),py[i].end());
        sz=py[i].size();
        for(int j=0,s=0;j<sz;j++){
            if(j)s+=j*(py[i][j]-py[i][j-1]);
            dy[i].push_back(s);
        }
        for(int j=sz-1,s=0;j>=0;j--){
            if(j!=sz-1)s+=(sz-1-j)*(py[i][j+1]-py[i][j]);
            dy[i][j]+=s;
            // printf("dy[%d][%d]=%d p=%d\n",i,j,dy[i][j],py[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        int sz=px[X[i]].size();
        int sx=0,sy=0;
        int L=0,R=sz-1,pos=0;
        while(L<=R){
            if(px[X[i]][M]<=Y[i])pos=M,L=M+1;
            else R=M-1;
        }
        sx=dx[X[i]][pos];

        sz=py[Y[i]].size();
        L=0,R=sz-1,pos=0;
        while(L<=R){
            if(py[Y[i]][M]<=X[i])pos=M,L=M+1;
            else R=M-1;
        }
        sy=dy[Y[i]][pos];
        ans+=sx*sy;
        // printf("(%d %d %d) x=%d y=%d\n",i,sx,sy,X[i],Y[i]);
    }
    _write(ans%Mod);
    return 0;
}

