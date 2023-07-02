// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int __int128
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
int X[N],Y[N],T,n;
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node &_)const{
        if(x==_.x)return y<_.y;
        return x<_.x;
    }
};
set<node> s[16];

signed main(){
    s[0].insert(node(0,0));
    for(int i=0;i<10;i++){
        X[i]=i,Y[i]=s[i].size();
        for(set<node>::iterator it=s[i].begin();it!=s[i].end();it++){
            int x=it->x,y=it->y;
            s[i+1].insert(node(x,y));
            s[i+1].insert(node(x-2,y-1));
            s[i+1].insert(node(x-2,y+1));
            s[i+1].insert(node(x-1,y-2));
            s[i+1].insert(node(x-1,y+2));
            s[i+1].insert(node(x+1,y-2));
            s[i+1].insert(node(x+1,y+2));
            s[i+1].insert(node(x+2,y-1));
            s[i+1].insert(node(x+2,y+1));
        }
    }
    T=read();
    for(int i=1;i<=T;i++){
        n=read();
        int ans=0;
        if(n<7)ans=Y[n];
        else{
            for(int i=7;i<=9;i++){
                int s1=Y[i],s2=1;
                for(int j=7;j<=9;j++)if(i^j){
                    s1=s1*(n-X[j]);
                    s2=s2*(X[i]-X[j]);
                }
                ans+=s1/s2;
            }
        }
        printf("Case #"),wr(i),printf(": "),_wri(ans);
    }
    return 0;
}

