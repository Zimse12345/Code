// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
//#include <windows.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
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
int n,tot;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node &_)const{
        if(x==_.x)return y<_.y;
        return x<_.x;
    }
};
vector<node> p[40];
set<node> s;
set<int> ans;

signed main(){
//    oF("ans.txt");
    
    n=read();
    p[1].pb(node(0,0));
    for(int i=2;i<=n;i++){
        s.clear();
        for(int x=1,y;x<i;x++){
            y=i-x;
            for(vector<node>::iterator l=p[x].begin();l!=p[x].end();l++){
                for(vector<node>::iterator r=p[y].begin();r!=p[y].end();r++){
                    s.insert(node((l->x)+(r->x)+y,(l->y)+(r->y)+x*y+x*(r->x)+y*(l->x)));
                }
            }
        }
        for(set<node>::iterator it=s.begin();it!=s.end();it++)p[i].pb(*it);
//        if(i>=27)MessageBox(NULL," "," ",MB_OK);
    }
    for(int i=n;i<=n;i++){
        ans.clear();
        for(vector<node>::iterator it=p[i].begin();it!=p[i].end();it++)ans.insert(it->y);
        _wri(ans.size());
        for(set<int>::iterator it=ans.begin();it!=ans.end();it++)wri(*it);
        pc(10);
    }
    return 0;
}

